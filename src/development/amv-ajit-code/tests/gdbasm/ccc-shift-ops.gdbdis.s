Dump of assembler code for function main:
   0x00000000 <+0>:	9d e3 bf 88	save  %sp, -120, %sp
   0x00000004 <+4>:	82 f8 40 22	sdivdcc  %g1, %g2, %g1
   0x00000008 <+8>:	a5 28 80 84	slld  %g2, %g4, %l2
   0x0000000c <+12>:	a5 28 a0 82	slld  %g2, 2, %l2
   0x00000010 <+16>:	8d 30 80 84	srld  %g2, %g4, %g6
   0x00000014 <+20>:	8d 30 a0 82	srld  %g2, 2, %g6
   0x00000018 <+24>:	a1 38 80 84	srad  %g2, %g4, %l0
   0x0000001c <+28>:	a1 38 a0 82	srad  %g2, 2, %l0
   0x00000020 <+32>:	f0 27 a0 44	st  %i0, [ %fp + 0x44 ]
   0x00000024 <+36>:	f2 27 a0 48	st  %i1, [ %fp + 0x48 ]
   0x00000028 <+40>:	c0 27 bf fc	clr  [ %fp + -4 ]
   0x0000002c <+44>:	82 10 20 01	mov  1, %g1
   0x00000030 <+48>:	c2 27 bf f8	st  %g1, [ %fp + -8 ]
   0x00000034 <+52>:	c0 27 bf f4	clr  [ %fp + -12 ]
   0x00000038 <+56>:	c2 07 a0 44	ld  [ %fp + 0x44 ], %g1
   0x0000003c <+60>:	80 a0 60 01	cmp  %g1, 1
   0x00000040 <+64>:	04 80 00 60	ble  0x1c0 <main+448>
   0x00000044 <+68>:	01 00 00 00	nop 
   0x00000048 <+72>:	10 80 00 19	b  0xac <main+172>
   0x0000004c <+76>:	01 00 00 00	nop 
   0x00000050 <+80>:	c2 07 bf f8	ld  [ %fp + -8 ], %g1
   0x00000054 <+84>:	83 28 60 02	sll  %g1, 2, %g1
   0x00000058 <+88>:	c4 07 a0 48	ld  [ %fp + 0x48 ], %g2
   0x0000005c <+92>:	82 00 80 01	add  %g2, %g1, %g1
   0x00000060 <+96>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x00000064 <+100>:	90 10 00 01	mov  %g1, %o0
   0x00000068 <+104>:	40 00 00 00	call  0x68 <main+104>
   0x0000006c <+108>:	01 00 00 00	nop 
   0x00000070 <+112>:	d0 27 bf f0	st  %o0, [ %fp + -16 ]
   0x00000074 <+116>:	03 00 00 00	sethi  %hi(0), %g1
   0x00000078 <+120>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x0000007c <+124>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x00000080 <+128>:	d0 07 bf f0	ld  [ %fp + -16 ], %o0
   0x00000084 <+132>:	92 10 00 01	mov  %g1, %o1
   0x00000088 <+136>:	40 00 00 00	call  0x88 <main+136>
   0x0000008c <+140>:	01 00 00 00	nop 
   0x00000090 <+144>:	84 10 00 08	mov  %o0, %g2
   0x00000094 <+148>:	03 00 00 00	sethi  %hi(0), %g1
   0x00000098 <+152>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x0000009c <+156>:	c4 20 40 00	st  %g2, [ %g1 ]
   0x000000a0 <+160>:	c2 07 bf f8	ld  [ %fp + -8 ], %g1
   0x000000a4 <+164>:	82 00 60 01	inc  %g1
   0x000000a8 <+168>:	c2 27 bf f8	st  %g1, [ %fp + -8 ]
   0x000000ac <+172>:	c4 07 bf f8	ld  [ %fp + -8 ], %g2
   0x000000b0 <+176>:	c2 07 a0 44	ld  [ %fp + 0x44 ], %g1
   0x000000b4 <+180>:	80 a0 80 01	cmp  %g2, %g1
   0x000000b8 <+184>:	06 bf ff e6	bl  0x50 <main+80>
   0x000000bc <+188>:	01 00 00 00	nop 
   0x000000c0 <+192>:	03 00 00 00	sethi  %hi(0), %g1
   0x000000c4 <+196>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x000000c8 <+200>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x000000cc <+204>:	90 10 00 01	mov  %g1, %o0
   0x000000d0 <+208>:	40 00 00 00	call  0xd0 <main+208>
   0x000000d4 <+212>:	01 00 00 00	nop 
   0x000000d8 <+216>:	84 10 00 08	mov  %o0, %g2
   0x000000dc <+220>:	03 00 00 00	sethi  %hi(0), %g1
   0x000000e0 <+224>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x000000e4 <+228>:	c4 20 40 00	st  %g2, [ %g1 ]
   0x000000e8 <+232>:	03 00 00 00	sethi  %hi(0), %g1
   0x000000ec <+236>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x000000f0 <+240>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x000000f4 <+244>:	05 00 00 00	sethi  %hi(0), %g2
   0x000000f8 <+248>:	90 10 a0 00	mov  %g2, %o0	! 0x0 <main>
   0x000000fc <+252>:	92 10 00 01	mov  %g1, %o1
   0x00000100 <+256>:	40 00 00 00	call  0x100 <main+256>
   0x00000104 <+260>:	01 00 00 00	nop 
   0x00000108 <+264>:	03 00 00 00	sethi  %hi(0), %g1
   0x0000010c <+268>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x00000110 <+272>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x00000114 <+276>:	c2 27 bf f4	st  %g1, [ %fp + -12 ]
   0x00000118 <+280>:	10 80 00 1b	b  0x184 <main+388>
   0x0000011c <+284>:	01 00 00 00	nop 
   0x00000120 <+288>:	d0 07 bf f4	ld  [ %fp + -12 ], %o0
   0x00000124 <+292>:	40 00 00 00	call  0x124 <main+292>
   0x00000128 <+296>:	01 00 00 00	nop 
   0x0000012c <+300>:	d0 27 bf ec	st  %o0, [ %fp + -20 ]
   0x00000130 <+304>:	03 00 00 00	sethi  %hi(0), %g1
   0x00000134 <+308>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x00000138 <+312>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x0000013c <+316>:	82 00 60 01	inc  %g1
   0x00000140 <+320>:	05 00 00 00	sethi  %hi(0), %g2
   0x00000144 <+324>:	90 10 a0 00	mov  %g2, %o0	! 0x0 <main>
   0x00000148 <+328>:	92 10 00 01	mov  %g1, %o1
   0x0000014c <+332>:	d4 07 bf ec	ld  [ %fp + -20 ], %o2
   0x00000150 <+336>:	40 00 00 00	call  0x150 <main+336>
   0x00000154 <+340>:	01 00 00 00	nop 
   0x00000158 <+344>:	d0 07 bf f4	ld  [ %fp + -12 ], %o0
   0x0000015c <+348>:	40 00 00 00	call  0x15c <main+348>
   0x00000160 <+352>:	01 00 00 00	nop 
   0x00000164 <+356>:	d0 27 bf f4	st  %o0, [ %fp + -12 ]
   0x00000168 <+360>:	03 00 00 00	sethi  %hi(0), %g1
   0x0000016c <+364>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x00000170 <+368>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x00000174 <+372>:	84 00 60 01	add  %g1, 1, %g2
   0x00000178 <+376>:	03 00 00 00	sethi  %hi(0), %g1
   0x0000017c <+380>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x00000180 <+384>:	c4 20 40 00	st  %g2, [ %g1 ]
   0x00000184 <+388>:	c2 07 bf f4	ld  [ %fp + -12 ], %g1
   0x00000188 <+392>:	80 a0 60 00	cmp  %g1, 0
   0x0000018c <+396>:	02 80 00 0f	be  0x1c8 <main+456>
   0x00000190 <+400>:	01 00 00 00	nop 
   0x00000194 <+404>:	03 00 00 00	sethi  %hi(0), %g1
   0x00000198 <+408>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x0000019c <+412>:	c4 00 40 00	ld  [ %g1 ], %g2
   0x000001a0 <+416>:	03 00 00 00	sethi  %hi(0), %g1
   0x000001a4 <+420>:	82 10 60 00	mov  %g1, %g1	! 0x0 <main>
   0x000001a8 <+424>:	c2 00 40 00	ld  [ %g1 ], %g1
   0x000001ac <+428>:	80 a0 80 01	cmp  %g2, %g1
   0x000001b0 <+432>:	06 bf ff dc	bl  0x120 <main+288>
   0x000001b4 <+436>:	01 00 00 00	nop 
   0x000001b8 <+440>:	10 80 00 04	b  0x1c8 <main+456>
   0x000001bc <+444>:	01 00 00 00	nop 
   0x000001c0 <+448>:	82 10 3f ff	mov  -1, %g1	! 0xffffffff
   0x000001c4 <+452>:	c2 27 bf fc	st  %g1, [ %fp + -4 ]
   0x000001c8 <+456>:	c2 07 bf fc	ld  [ %fp + -4 ], %g1
   0x000001cc <+460>:	b0 10 00 01	mov  %g1, %i0
   0x000001d0 <+464>:	81 e8 00 00	restore 
   0x000001d4 <+468>:	81 c3 e0 08	retl 
   0x000001d8 <+472>:	01 00 00 00	nop 
End of assembler dump.