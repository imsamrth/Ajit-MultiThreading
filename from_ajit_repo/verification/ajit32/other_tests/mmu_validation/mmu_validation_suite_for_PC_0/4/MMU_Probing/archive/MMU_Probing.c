/*----------------------------------------------------------------------------
Filename:			MMU_Probing.c
Version:			1.00
Goal: 				Probing in MMU
Author:				Harshal Kalyane
Description:	
			Probing mainly used to check PDE and PTE from page directory. In this MMU
implementation only probe type 4 is implemented so it always return PTE. Please
refer Table H-4 from MMU reference manual. 



-----------------------------------------------------------------------------*/



#include<stdint.h>


//Mmu asi constants
#define ASI_MMU_REGISTER 		0x04
#define ASI_MMU_FLUSH_PROBE	 	0x03
#define ASI_FLUSH_I_D_CONTEXT		0x13

//#define ASI_MMU_BYPASS		0x2f
//Addresses of MMU registers
#define MMU_REG_CONTROL			0x00000000
#define MMU_REG_CONTEXT_TABLE_PTR	0x00000100
#define MMU_REG_CONTEXT			0x00000200
#define MMU_REG_FSR			0x00000300
#define MMU_REG_FAR			0x00000400
#define ASI_MMU_DIAGNOSTIC  0x04


//store word into mmu register
inline void store_word_mmureg(uint32_t value, uint32_t* addr)
{
	__asm__ __volatile__("sta %0, [%1] %2\n\t" : : "r"(value), "r"(addr),
			     "i"(ASI_MMU_REGISTER) : "memory");
}

//load word from mmu register
inline uint32_t load_word_mmureg(uint32_t* addr)
{
        uint32_t retval;
        __asm__ __volatile__("lda [%1] %2, %0\n\t" :
                             "=r"(retval) : "r"(addr), "i"(ASI_MMU_REGISTER));
        return retval;
}

//Mmu flush
inline void mmu_flush(uint32_t value, uint32_t* addr)
{
	__asm__ __volatile__("sta %0, [%1] %2\n\t"  : : "r"(value), "r"(addr), "i"(ASI_MMU_FLUSH_PROBE) : "memory");
}

//Mmu probe
inline uint32_t mmu_probe(uint32_t* addr)
{
        uint32_t retval;
        __asm__ __volatile__("lda [%1] %2, %0\n\t" :
                             "=r"(retval) : "r"(addr), "i"(ASI_MMU_FLUSH_PROBE));
        return retval;
}

//Mmu probe
inline uint32_t mmu_dig(uint32_t* addr)
{
        uint32_t retval;
        __asm__ __volatile__("lda [%1] %2, %0\n\t" :
                             "=r"(retval) : "r"(addr), "i"(ASI_MMU_DIAGNOSTIC));
        return retval;
}

//flush icache
inline void flush_icache(void)
{
	__asm__ __volatile__(" flush ");
}

//flush_dcache
inline void flush_dcache(void)
{
	__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
			     "i"(ASI_FLUSH_I_D_CONTEXT) : "memory");
}


//context switch.
//make a switch to a particular context
inline void context_switch(uint32_t context_number)
{
	//flush dcache
	__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
			     "i"(ASI_FLUSH_I_D_CONTEXT) : "memory");
	//flush icache
	__asm__ __volatile__(" flush ");
	//flush TLB
	__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t"  : : "i"(ASI_MMU_FLUSH_PROBE) : "memory");

	//write new context number into mmu context register
	__asm__ __volatile__("sta %0, [%1] %2\n\t" : : "r"(context_number), "r"(MMU_REG_CONTEXT),
			     "i"(ASI_MMU_REGISTER) : "memory");
	//flush dcache
	__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
			     "i"(ASI_FLUSH_I_D_CONTEXT) : "memory");
	//flush icache
	__asm__ __volatile__(" flush ");
	//flush TLB
	__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t"  : : "i"(ASI_MMU_FLUSH_PROBE) : "memory");


}



//Context table
uint32_t ContextTable[256]  __attribute__((aligned(0x1000)));
//Page tables for process 1:
uint32_t process1_L1PageTable[256] __attribute__((aligned(0x1000)));
uint32_t process1_L2PageTable[64]  __attribute__((aligned(0x1000)));
uint32_t process1_L3PageTable[64]  __attribute__((aligned(0x1000)));
//Page tables for process 2:
uint32_t process2_L1PageTable[256] __attribute__((aligned(0x1000)));
uint32_t process2_L2PageTable[64]  __attribute__((aligned(0x1000)));
uint32_t process2_L3PageTable[64]  __attribute__((aligned(0x1000)));


void strcpy(char dest[],char const src[]) 
{int i;
 for (i = 0; src[i] != 0; i++)  dest[i] = src[i];
}
uint64_t getSlice64(uint64_t reg, uint8_t h, uint8_t l)
{
	reg = reg << (63 - h);
	reg = reg >> ((63 - h) + l);
	return reg;
}

	
uint32_t setSlice32(uint32_t reg, uint8_t h, uint8_t l, uint32_t value)
{
	uint32_t mask = -1;
	mask = mask >> (31 - h + l);
	value = value & mask;
	value = value << l;

	mask = mask << l;
	reg = reg & ~mask;
	reg = reg | value;
	return reg;
}


uint32_t convertPhyAddrToPTD(uint64_t phy_addr)
{
	//Get bits 35:6 from phy addr and place them into bits 31:2 of PTD
	uint32_t PTD = 0;
	PTD= setSlice32(PTD, 31,2, getSlice64(phy_addr,35,6));

	//Mark bits1:0 = 0x1 to denote that its a PTD
	PTD= setSlice32(PTD, 1,0, 0x1);
	return PTD;
}



//NOTE : with function main() use the
//attribute "((section(".text.main")))"
//to ensure that main() is  put in the
//beginning of the ".text" section in the 
//generated executable.
int  startTest();
int  __attribute__((section(".text.main")))  main()
{
	//Initialize all registers
	__asm__ __volatile__( "mov %g0, %g1 \n\t "); __asm__ __volatile__( "mov %g0, %g2 \n\t ");
	__asm__ __volatile__( "mov %g0, %g3 \n\t "); __asm__ __volatile__( "mov %g0, %g4 \n\t ");
	__asm__ __volatile__( "mov %g0, %g5 \n\t "); __asm__ __volatile__( "mov %g0, %g6 \n\t ");
	__asm__ __volatile__( "mov %g0, %g7 \n\t ");
	
	__asm__ __volatile__( "mov %g0, %i0 \n\t "); __asm__ __volatile__( "mov %g0, %i1 \n\t ");
	__asm__ __volatile__( "mov %g0, %i2 \n\t "); __asm__ __volatile__( "mov %g0, %i3 \n\t ");
	__asm__ __volatile__( "mov %g0, %i4 \n\t "); __asm__ __volatile__( "mov %g0, %i5 \n\t ");
	__asm__ __volatile__( "mov %g0, %i6 \n\t "); __asm__ __volatile__( "mov %g0, %i7 \n\t ");
	
	__asm__ __volatile__( "mov %g0, %l0 \n\t "); __asm__ __volatile__( "mov %g0, %l1 \n\t ");
	__asm__ __volatile__( "mov %g0, %l2 \n\t "); __asm__ __volatile__( "mov %g0, %l3 \n\t ");
	__asm__ __volatile__( "mov %g0, %l4 \n\t "); __asm__ __volatile__( "mov %g0, %l5 \n\t ");
	__asm__ __volatile__( "mov %g0, %l6 \n\t "); __asm__ __volatile__( "mov %g0, %l7 \n\t ");
	
	__asm__ __volatile__( "mov %g0, %o0 \n\t "); __asm__ __volatile__( "mov %g0, %o1 \n\t ");
	__asm__ __volatile__( "mov %g0, %o2 \n\t "); __asm__ __volatile__( "mov %g0, %o3 \n\t ");
	__asm__ __volatile__( "mov %g0, %o4 \n\t "); __asm__ __volatile__( "mov %g0, %o5 \n\t ");
	__asm__ __volatile__( "mov %g0, %o6 \n\t "); __asm__ __volatile__( "mov %g0, %o7 \n\t ");

	startTest();
	return 0;

}


int  __attribute__((section(".text.main"))) startTest()
{

	
	uint32_t i;
	
	
	//Currently MMU is disabled and translation hasn't kicked in
	putString("\n---- Mmu disabled -----");

	//set context table pointer
	uint32_t context_table_ptr_value = convertPhyAddrToPTD((uint32_t)ContextTable);
	store_word_mmureg(context_table_ptr_value, (uint32_t*)MMU_REG_CONTEXT_TABLE_PTR);


	//Populate entries in the context table
	//Mark all entries in the context table invalid.
	//for(i=0;i<256;i++)ContextTable[i]=0;
	//set first two entries to a PTD
	ContextTable[0] = convertPhyAddrToPTD(((uint32_t)process1_L1PageTable));
	ContextTable[1] = convertPhyAddrToPTD(((uint32_t)process2_L1PageTable));

	
	//=========================
	//Populate L1 page tables
	//=========================
	//First, mark all entries as invalid
	//for(i=0;i<256;i++) 
	//{
		//process1_L1PageTable[i] =0x00;
		//process2_L1PageTable[i] =0x00;
	//}
	//next map all addresses in range 0xC0000000-0xFFFFFFFF
	//such that VA=PA
	for(i=0xC0; i<=0xFF; i++)
	{
		//PTE feilds :
		// C M R ACC ET
		// 1 0 0 011 10 = 0x8E
		uint32_t PPN = (i<<12);
		uint32_t PTE_level1 = (PPN<<8) | (0x8E);
		process1_L1PageTable[i] = PTE_level1;
		process2_L1PageTable[i] = PTE_level1;
	}
	//Place page table descriptors for 
	//address range 0x1000 0000 to 0x1100 0000
	process1_L1PageTable[0x10] = convertPhyAddrToPTD((uint32_t)process1_L2PageTable);
	process2_L1PageTable[0x10] = convertPhyAddrToPTD((uint32_t)process2_L2PageTable);

	
	//=========================
	//Populate L2 page tables
	//=========================
	//First, mark all entries as invalid
	//for(i=0;i<64;i++) 
	//{
		//process1_L2PageTable[i] =0x00;
		//process2_L2PageTable[i] =0x00;
	//}
	
	//Place page table descriptors for 
	//address range 0x1000 0000 to 0x1100 0000
	process1_L2PageTable[0x00] = convertPhyAddrToPTD((uint32_t)process1_L3PageTable);
	process2_L2PageTable[0x00] = convertPhyAddrToPTD((uint32_t)process2_L3PageTable);
	
	//=========================
	//Populate L3 page tables
	//=========================
	//First, mark all entries as invalid
	//for(i=0;i<64;i++) 
	//{
		//process1_L3PageTable[i] =0x00;
		//process2_L3PageTable[i] =0x00;
	//}
	//Place page table entries for 
	//address range 0x1000 0000 to 0x1100 0000
	uint32_t process1_PTE = ((0xA0<<12)<<8) | 0x8E ;
	uint32_t process2_PTE = ((0xB0<<12)<<8) | 0x8E ;
	process1_L3PageTable[0x00] = process1_PTE;
	process2_L3PageTable[0x00] = process2_PTE;


	//===================================================
	//write a test strings in memory using physical addr
	char* write_string = (char*)0xA0000000;
	strcpy(write_string, "\n ***** Hello. This is Process 1's test string at phy addr 0xA0000000***** \n");
	putString("\n---- Written test string  at phy addr = 0xA0000000 : ");
	putString(write_string);
	
	write_string = (char*)0xB0000000;
	strcpy(write_string, "\n ***** Hello. This is Process 2's test string at phy addr 0xB0000000***** \n");
	putString("\n---- Written test string  at phy addr = 0xB0000000 : ");
	putString(write_string);

	
	//There. all translation info has been given to the MMU.
	//Now enable the MMU by writing into MMU control register
	uint32_t MMU_control_word = 0x1; //set the Enable bit
	store_word_mmureg(0x0 , (uint32_t*) MMU_REG_CONTEXT);
	store_word_mmureg(MMU_control_word, (uint32_t*) MMU_REG_CONTROL);
	putString("\n---- Mmu enabled -----");


	//putString(read_string);
	
	//Test MMU probe functionality:
	//Obtain the PTE for some addresses and check if these are correct:
	//Get the page table entry for virtual address 0x10000000.
	//The entry should read = 0x0A0000EE.
	//putString("\nTesting Mmu flush/probe");
	//putString("\n Flushing entire TLB.....");
	//mmu_flush(0x0000, (uint32_t*)0x00000000); //address does not matter. The command flushes entire TLB 
	uint32_t probe_value = mmu_probe((uint32_t*)( 0x10000000 | 0x400));
	uint32_t expected_probe_value = 0x0A00008E;
	putString("\n PTE for addr 0x10000000 = "); putInt(probe_value);
	putString("\n Expected PTE            = "); putInt(expected_probe_value);
	if(probe_value!=expected_probe_value)
		{putString("\n!!!!!!!!!!!!!!!!!!!---------Test Failed----!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");}
	else
		{putString("\n---- Test Passed. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");}



	putString("\n---- Test Finished. Halting. -----");
	putString("\n");
	if(probe_value==expected_probe_value)
	{
		__asm__ __volatile__( "mov 0x1, %g6 \n\t ");//check point
	}
	else
	{
		__asm__ __volatile__( "mov 0x2, %g6 \n\t ");//check point
	}
	halt();
	

	return 0;
}

