#ifndef _AJIT_ACCESS_ROUTINES_H____
#define _AJIT_ACCESS_ROUTINES_H____

//
// This file contains some useful routines to simplify use
// of the AJIT processor by the programmer.
//

//////////////////////////////////////////////////////////////////////////////////////////////
// thread id.
//////////////////////////////////////////////////////////////////////////////////////////////
//
//
//  returns core-id and thread-id of the current core.
//
void ajit_get_core_and_thread_id(uint8_t* core_id, uint8_t* thread_id);

//
// This reads the contents of ASR-29.  The four bytes in the
// return value are
//  MSB                     LSB
//  0x52  0x50  <core-id> <thread-id>
//
inline uint32_t __ajit_read_core_thread_id_word__();


///////////////////////////////////////////////////////////////////////////////////////////////
//  Locks: these are implemented as assembly
///////////////////////////////////////////////////////////////////////////////////////////////
// Spin until int[mutex_address] is acquired.
void acquire_mutex_using_swap(int mutex_address);
// release mutex pointed to by mutex_address.
void release_mutex_using_swap(int mutex_address);

// ldstub versions.  byte[mutex_addres] is used.
void acquire_mutex_using_ldstub(int mutex_address);
void release_mutex_using_ldstub(int mutex_address);

///////////////////////////////////////////////////////////////////////////////////////////////
//  Register accesses
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//  Register accesses
///////////////////////////////////////////////////////////////////////////////////////////////

//
// initialize all iu gp-registers to 0. All globals and window
//  registers (across all windows) will be cleared.
//
inline void __ajit_clear_all_gp_registers__();


//
// cycle_count_register is ASR30 && ASR31
//    (the processor has a 64-bit cycle counter which starts
//      at reset and increments every clock cycle.  The
//      following routines allow you to access the high and
//      low words in the counter).
//
inline uint32_t __ajit_read_cycle_count_register_high__();
inline uint32_t __ajit_read_cycle_count_register_low__();

//
// reads high and low clock counters to return
// the value...   Returns the number of elapsed ticks
// where one tick is 256 clock cycles.
//   (Thus, if the clock is 100mhz, 1 tick is 2.56 micro-seconds).
// 
inline uint64_t __ajit_get_clock_time();
//
// sleep for specified number of clock cycles.
//
void __ajit_sleep__(uint32_t clock_cycles);


///////////////////////////////////////////////////////////////////////////////////////////////
//  MMU related stuff
///////////////////////////////////////////////////////////////////////////////////////////////

//
// SPARC-V8 defines a number of address spaces for accessing special
// registers etc.  The address space identifier (ASI) is an 8-bit
//
// The group of 4 below corresponds to data and instruction
// spaces.  The USER/SUPERVISOR asi's provide memory protection
// functionality (in conjunction with the MMU).
//
#define ASI_USER_INSTRUCTION            0x08
#define ASI_SUPERVISOR_INSTRUCTION      0x09
#define ASI_USER_DATA                   0x0A
#define ASI_SUPERVISOR_DATA             0x0B

//
// The group of 4 below  corresponds to MMU
// and Cache specific spaces.
#define ASI_MMU_REGISTER 		0x04	// MMU register
#define ASI_MMU_FLUSH_PROBE	 	0x03    // used in doing an MMU FLUSH/PROBE
#define ASI_FLUSH_I_D_CONTEXT		0x13	// A write with this ASI causes the data cache to be flushed.
#define ASI_MMU_BYPASS			0x20    // 0x20 to 0x2f is the range of bypass asi's.
						// with the bottom 4 bits becoming the top-4 bits
						// of the physical address (ingenious?)  We will
						// treat these top 4 bits as 0 when mapping device
						// addresses to physical..

//
// Addresses of MMU registers
//
#define MMU_REG_CONTROL			0x00000000  // control register address: 
						    // In the control register, bit 0 is the enable bit.
						    // bit 1 is the No-fault (NF bit)
						    // bit 8 (AJIT only) is the default cacheable bit,
						    // 	which if set, indicates that all accesses
						    // 	are cacheable, even if MMU is disabled.
#define MMU_REG_CONTEXT_TABLE_PTR	0x00000100  // MMU context table pointer address.
#define MMU_REG_CONTEXT			0x00000200  // MMU context register address.
#define MMU_REG_FSR			0x00000300  // MMU FSR register address.
#define MMU_REG_FAR			0x00000400  // MMU FAR register address.


//
// set default mmu cacheable bit to specified value.
//   (Sparc V8 ref manual specifies that when the MMU is
//    disabled, all returned lines to the caches are marked
//    as non-cacheable.  In AJIT, the nature of the cacheability
//    of the returned line is determined by a default-cacheable
//    bit, which is set/cleared by this function) 
//
//
//
//  pass dc_bit = 1 to set the default cacheable bit, 0 to clear it.
//
inline void __ajit_set_mmu_default_cacheable_bit__(uint8_t dc_bit);


//
// store word into mmu register
//
inline void __ajit_store_word_mmu_reg__(uint32_t value, uint32_t addr);

//
// store while bypassing the MMU.
//   (this is one way to access peripherals).
//
inline void __ajit_store_word_mmu_bypass__(uint32_t value, uint32_t addr);
#define __AJIT_STORE_WORD_MMU_BYPASS__(addr,value) {\
	__asm__ __volatile__("sta %0, [%1] %2\n\t" : : "r"(value), "r"(addr), "i"(ASI_MMU_BYPASS) : "memory");}
#define __AJIT_STORE_UBYTE_MMU_BYPASS__(addr,value) {\
	__asm__ __volatile__("stuba %0, [%1] %2\n\t" : : "r"(value), "r"(addr), "i"(ASI_MMU_BYPASS) : "memory");}

//
// load word from mmu register
//
inline uint32_t __ajit_load_word_mmu_reg__(uint32_t addr);
//
// load while bypassing mmu
//   (this is one way to access peripherals).
inline uint32_t __ajit_load_word_mmu_bypass__(uint32_t addr);
#define __AJIT_LOAD_WORD_MMU_BYPASS__(addr,value) {\
        __asm__ __volatile__("lda [%1] %2, %0\n\t" : "=r"(value) : "r"(addr), "i"(ASI_MMU_BYPASS));}
#define __AJIT_LOAD_UBYTE_MMU_BYPASS__(addr,value) {\
        __asm__ __volatile__("lduba [%1] %2, %0\n\t" : "=r"(value) : "r"(addr), "i"(ASI_MMU_BYPASS));}

	
///////////////////////////////////////////////////////////////////////////////////////////////
//  Cache related stuff
///////////////////////////////////////////////////////////////////////////////////////////////

//
// flush icache
// 
inline void __ajit_flush_icache__(void);


//
// flush_dcache
//
inline void __ajit_flush_dcache__(void);



///////////////////////////////////////////////////////////////////////////////////////////////
//  Cycle-count register
//     (cycle-count is maintained as a 64 bit register which is stored in ASR-30,31.)
///////////////////////////////////////////////////////////////////////////////////////////////
inline uint32_t __ajit_read_cycle_count_register_high__();
inline uint32_t __ajit_read_cycle_count_register_low__();

///////////////////////////////////////////////////////////////////////////////////////////////
//  Built-in peripherals
//     Timer, Serial, Interrupt-controller, Spi-master, Bootrom
///////////////////////////////////////////////////////////////////////////////////////////////
#include "device_addresses.h"


//---------------------------------------------------------------------------------------------
//   Note: there are two ways to access a serial (or any) peripheral.  
//      1.  use a MMU bypass method to write/read directly from the peripheral.
//      2.  use a normal load/store but mark peripheral addresses as non-cacheable
//      	by setting up the MMU page tables appropriately.
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// Timer
//---------------------------------------------------------------------------------------------
//
// bypass based methods.
//
inline void __ajit_write_timer_control_register__(uint32_t val);  // [31:1] -> timer count, [0] -> enable.
inline uint32_t __ajit_read_timer_control_register__();		  

//
//  normal load-store with non-cacheable page.
//
inline void __ajit_write_timer_control_register_via_vmap__(uint32_t val);  // [31:1] -> timer count, [0] -> enable.
inline uint32_t __ajit_read_timer_control_register_via_vmap__();		  


//---------------------------------------------------------------------------------------------
// Serial
//   Note: there are two ways to access a serial (or any) peripheral.  The following
//         use a MMU bypass method to write/read directly from the peripheral.
//---------------------------------------------------------------------------------------------
// masks

#define TX_ENABLE 	0x1 
#define RX_ENABLE 	0x2 
#define RX_INTR_ENABLE 	0x4 
#define TX_FULL   	0x8
#define RX_FULL   	0x10

inline void __ajit_write_serial_control_register__(uint32_t val);
#define __AJIT_WRITE_SERIAL_CONTROL_REGISTER__(val) {\
	__AJIT_STORE_WORD_MMU_BYPASS__(ADDR_SERIAL_CONTROL_REGISTER, val);}

inline uint32_t __ajit_read_serial_control_register__();
#define __AJIT_READ_SERIAL_CONTROL_REGISTER__(val) {\
	__AJIT_LOAD_WORD_MMU_BYPASS__(ADDR_SERIAL_CONTROL_REGISTER, val);}

inline void __ajit_write_serial_tx_register__(uint8_t val);
#define __AJIT_WRITE_SERIAL_TX_REGISTER__(val) {\
	__AJIT_STORE_UBYTE_MMU_BYPASS__(ADDR_SERIAL_TX_REGISTER, val);}

inline uint8_t __ajit_read_serial_tx_register__();
#define __AJIT_READ_SERIAL_TX_REGISTER__(val) {\
	__AJIT_LOAD_UBYTE_MMU_BYPASS__(ADDR_SERIAL_TX_REGISTER, val);}


inline uint8_t __ajit_read_serial_rx_register__();
#define __AJIT_READ_SERIAL_RX_REGISTER__(val) {\
	__AJIT_LOAD_UBYTE_MMU_BYPASS__(ADDR_SERIAL_RX_REGISTER, val);}

int   __ajit_serial_putchar__  (char c);
int   __ajit_serial_getchar__ ();

void  __ajit_serial_puts__ (char* s, uint32_t length);
void  __ajit_serial_gets__ (char* s, uint32_t length);

// configuration..
void __ajit_serial_configure__ (uint8_t enable_tx, uint8_t enable_rx, uint8_t enable_intr);
void __ajit_serial_uart_reset__ ();



//---------------------------------------------------------------------------------------------
//   Note: The second way to access a peripheral.  Directly load/store
//         from the peripheral address, using a normal user/supervisor data asi.
//         The MMU should be used to deal with the non-cacheability of these accesses
//         and to handle the mapping (In this case, typically virtual address == physical address)
//---------------------------------------------------------------------------------------------
//
inline void __ajit_write_serial_control_register_via_vmap__(uint32_t val);
inline uint32_t __ajit_read_serial_control_register_via_vmap__();
inline void __ajit_write_serial_tx_register_via_vmap__(uint8_t val);
inline uint8_t __ajit_read_serial_tx_register_via_vmap__();
inline uint8_t __ajit_read_serial_rx_register_via_vmap__();

int   __ajit_serial_putchar_via_vmap__  (char c);
int   __ajit_serial_getchar_via_vmap__ ();
void  __ajit_serial_puts_via_vmap__ (char* s, uint32_t length);
void  __ajit_serial_gets_via_vmap__ (char* s, uint32_t length);
void  __ajit_serial_configure_via_vmap__ (uint8_t enable_tx, uint8_t enable_rx, uint8_t enable_intr);
void __ajit_serial_uart_reset_via_vmap__ ();
void __ajit_serial_uart_reset_inner__ (uint8_t use_vmap);

// baud rate configuration register is a 32-bit register with the following
// fields
// [31:16]   baud_limit.
// [11:0]    baud_frequency.
// The baud-limit and baud frequency are calculated as follows
//   A = 16*clock_frequency
//    (A must be less than clock_frequency).
//  GCD = gcd (A, clock_frequency)
//  baud_frequency = A/GCD
//  baud_limit =  (clock_frequency/GCD)-baud_frequency.
// common values of baud-rate are 9600, 115200.
void  __ajit_serial_set_baudrate__ (uint32_t baud_rate, uint32_t clock_frequency);
void  __ajit_serial_set_baudrate_via_vmap__ (uint32_t baud_rate, uint32_t clock_frequency);
void  __ajit_serial_set_baudrate_inner__ (uint8_t use_vmap, uint32_t baud_rate, uint32_t clock_frequency);

//---------------------------------------------------------------------------------------------
// Interrupt-controller.
//---------------------------------------------------------------------------------------------
//
// val=0 to disable irc, val=1 to enable irc.
//
//
//  using mmu-bypass
inline void __ajit_write_irc_control_register__(uint32_t val);
#define __AJIT_WRITE_IRC_CONTROL_REGISTER__(val) {\
	__AJIT_STORE_WORD_MMU_BYPASS__(ADDR_INTERRUPT_CONTROLLER_CONTROL_REGISTER, val);}

inline uint32_t __ajit_read_irc_control_register__();
#define __AJIT_READ_IRC_CONTROL_REGISTER__(val) {\
	__AJIT_LOAD_WORD_MMU_BYPASS__(ADDR_INTERRUPT_CONTROLLER_CONTROL_REGISTER, val);}

#define __AJIT_IRC_DISABLE__ {int val; __AJIT_WRITE_IRC_CONTROL_REGISTER__(0); __AJIT_READ_IRC_CONTROL_REGISTER__(val);}


//
// using normal load/store with non-cacheable page.
//
inline void __ajit_write_irc_control_register_via_vmap__(uint32_t val);
inline uint32_t __ajit_read_irc_control_register_via_vmap__();



//---------------------------------------------------------------------------------------------
// Spi-master
//---------------------------------------------------------------------------------------------

//
// reg-id can be
//   0   data-reg-low
//   1   data-reg-high
//
//       These two registers (high concatenated with low) form a shift
//       register [15:0].  The MOSI output is either from bit 3/7/11/15 of
//       the 16-bit shifter register, depending on the transfer length 
//       set in the configure register (see below).
//
//   2   command (for write)/status (for read)
//
//       Command register format
//           unused spi-dev-addr  irq-en deselect-after-xfer  start-transfer
//              2        3             1             1             1
//   3   configure register
//   
//   	 Format
//   	   transfer_length clk_divide_count
//   	        2               4
//        The AJIT cpu clock is divided by using clk_divide_count: 
//               the clock-division is by (2**(clk_divide_count+1))
//        The transfer length ranges from 00-11 (4/8/12/16 bits)
//


//---------------------------------------------------------------------------------------------
// with mmu bypass..
//---------------------------------------------------------------------------------------------
inline void     __ajit_write_spi_master_register__(uint8_t reg_id, uint8_t reg_val);

// 
// use this to read the data-registers, status (command) register
// or the config register
//
// A status reg read returns 1 if the master is busy with the
// previous transfer and 0 else.
//
inline uint8_t __ajit_read_spi_master_register__(uint8_t reg_id);

//---------------------------------------------------------------------------------------------
// with normal load/store with non-cacheable page
//---------------------------------------------------------------------------------------------
inline void     __ajit_write_spi_master_register_via_vmap__(uint8_t reg_id, uint8_t reg_val);
inline uint8_t __ajit_read_spi_master_register_via_vmap__(uint8_t reg_id);

//---------------------------------------------------------------------------------------------
// GPIO!
//---------------------------------------------------------------------------------------------
// write gpio-out to GPIO_OUT pins and read back GPIO_IN pins.
inline uint32_t __ajit_gpio_xfer__(uint8_t gpio_out);
inline uint32_t __ajit_gpio_xfer_via_vmap__(uint8_t gpio_out);

//---------------------------------------------------------------------------------------------
// Trap
//---------------------------------------------------------------------------------------------
inline void __ajit_ta_0__ ();

//---------------------------------------------------------------------------------------------
// SQRT
//---------------------------------------------------------------------------------------------
// *b  = fsqrtd (*a), uses f0,f1,f2,f3 registers..
inline void __ajit_fsqrtd__ (uint32_t a, uint32_t b);
// *b  = fsqrts (*a), uses f0,f1 registers..
inline void __ajit_fsqrts__ (uint32_t a, uint32_t b);
// *b  = fitod (*a), uses f0,f2,f3 registers..
inline void __ajit_fitod__  (uint32_t a, uint32_t b);
// *b  = fitos (*a), uses f0,f1 registers..
inline void __ajit_fitos__  (uint32_t a, uint32_t b);
// *b  = fdtoi (*a), uses f0,f1,f2 registers..
inline void __ajit_fdtoi__  (uint32_t a, uint32_t b);
// *b  = fstoi (*a), uses f0,f1 registers..
inline void __ajit_fstoi__  (uint32_t a, uint32_t b);


//---------------------------------------------------------------------------------------------
// NOP
//---------------------------------------------------------------------------------------------
#define __AJIT_NOP()  {__asm__ __volatile__("nop;");}


#endif
