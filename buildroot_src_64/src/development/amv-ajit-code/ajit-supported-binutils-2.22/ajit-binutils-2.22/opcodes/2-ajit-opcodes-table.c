{"add",       F3(2,0x00,0),                         F3(~2,~0x00,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"add",       F3(2,0x00,1),                         F3(~2,~0x00,~1),                               "1,i,d",         0,                 ajit},               
{"add",       F3(2,0x00,1),                         F3(~2,~0x00,~1),                               "i,1,d",         0,                 ajit},               
{"addcc",     F3(2,0x10,0),                         F3(~2,~0x10,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"addcc",     F3(2,0x10,1),                         F3(~2,~0x10,~1),                               "1,i,d",         0,                 ajit},               
{"addcc",     F3(2,0x10,1),                         F3(~2,~0x10,~1),                               "i,1,d",         0,                 ajit},               
{"addd",      F4(2,0x00,0,1),                       F4(~2,~0x00,~0,~1),                            "1,2,d",         0,                 ajit},/*AJIT*/,      
{"adddcc",    F4(2,0x10,0,1),                       F4(~2,~0x10,~0,~1),                            "1,2,d",         0,                 ajit},/*AJIT*/,      
{"addx",      F3(2,0x08,0),                         F3(~2,~0x08,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"addx",      F3(2,0x08,1),                         F3(~2,~0x08,~1),                               "1,i,d",         0,                 ajit},               
{"addx",      F3(2,0x08,1),                         F3(~2,~0x08,~1),                               "i,1,d",         0,                 ajit},               
{"addxcc",    F3(2,0x18,0),                         F3(~2,~0x18,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"addxcc",    F3(2,0x18,1),                         F3(~2,~0x18,~1),                               "1,i,d",         0,                 ajit},               
{"addxcc",    F3(2,0x18,1),                         F3(~2,~0x18,~1),                               "i,1,d",         0,                 ajit},               
{"and",       F3(2,0x01,0),                         F3(~2,~0x01,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"and",       F3(2,0x01,1),                         F3(~2,~0x01,~1),                               "1,i,d",         0,                 ajit},               
{"and",       F3(2,0x01,1),                         F3(~2,~0x01,~1),                               "i,1,d",         0,                 ajit},               
{"andcc",     F3(2,0x11,0),                         F3(~2,~0x11,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"andcc",     F3(2,0x11,1),                         F3(~2,~0x11,~1),                               "1,i,d",         0,                 ajit},               
{"andcc",     F3(2,0x11,1),                         F3(~2,~0x11,~1),                               "i,1,d",         0,                 ajit},               
{"andd",      F4(2,0x01,0,1),                       F4(~2,~0x01,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"anddcc",    F4(2,0x11,0,1),                       F4(~2,~0x11,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"anddn",     F4(2,0x05,0,1),                       F4(~2,~0x05,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"anddncc",   F4(2,0x15,0,1),                       F4(~2,~0x15,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"andn",      F3(2,0x05,0),                         F3(~2,~0x05,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"andn",      F3(2,0x05,1),                         F3(~2,~0x05,~1),                               "1,i,d",         0,                 ajit},               
{"andncc",    F3(2,0x15,0),                         F3(~2,~0x15,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"andncc",    F3(2,0x15,1),                         F3(~2,~0x15,~1),                               "1,i,d",         0,                 ajit},               
{"bclr",      F3(2,0x05,0),                         F3(~2,~0x05,~0)|ASI(~0),                       "2,r",           F_ALIAS,           ajit},               /*andnrd,rs2,rd*/
{"bclr",      F3(2,0x05,1),                         F3(~2,~0x05,~1),                               "i,r",           F_ALIAS,           ajit},               /*andnrd,i,rd*/
{"bset",      F3(2,0x02,0),                         F3(~2,~0x02,~0)|ASI(~0),                       "2,r",           F_ALIAS,           ajit},               /*orrd,rs2,rd*/
{"bset",      F3(2,0x02,1),                         F3(~2,~0x02,~1),                               "i,r",           F_ALIAS,           ajit},               /*orrd,i,rd*/
{"btog",      F3(2,0x03,0),                         F3(~2,~0x03,~0)|ASI(~0),                       "2,r",           F_ALIAS,           ajit},               /*xorrd,rs2,rd*/
{"btog",      F3(2,0x03,1),                         F3(~2,~0x03,~1),                               "i,r",           F_ALIAS,           ajit},               /*xorrd,i,rd*/
{"btst",      F3(2,0x11,0),                         F3(~2,~0x11,~0)|RD_G0|ASI(~0),                 "1,2",             F_ALIAS,           ajit},               /*andccrs1,rs2,%g0*/
{"btst",      F3(2,0x11,1),                         F3(~2,~0x11,~1)|RD_G0,                         "i,1",             F_ALIAS,           ajit},               /*andccrs1,i,%g0*/
{"call",      F1(0x1),                              F1(~0x1),                                      "L",               F_JSR|F_DELAYED,   ajit},               
{"call",      F1(0x1),                              F1(~0x1),                                      "L,#",             F_JSR|F_DELAYED,   ajit},               
{"call",      F3(2,0x38,0)|RD(0xf),                 F3(~2,~0x38,~0)|RD(~0xf)|ASI_RS2(~0),          "1",             F_JSR|F_DELAYED,   ajit},               /*jmplrs1+%g0,%o7*/
{"call",      F3(2,0x38,0)|RD(0xf),                 F3(~2,~0x38,~0)|RD(~0xf)|ASI_RS2(~0),          "1,#",           F_JSR|F_DELAYED,   ajit},               
{"call",      F3(2,0x38,0)|RD(0xf),                 F3(~2,~0x38,~0)|RD(~0xf)|ASI(~0),              "1+2",           F_JSR|F_DELAYED,   ajit},               /*jmplrs1+rs2,%o7*/
{"call",      F3(2,0x38,0)|RD(0xf),                 F3(~2,~0x38,~0)|RD(~0xf)|ASI(~0),              "1+2,#",         F_JSR|F_DELAYED,   ajit},               
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf),                      "1+i",           F_JSR|F_DELAYED,   ajit},               /*jmplrs1+i,%o7*/
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf),                      "1+i,#",         F_JSR|F_DELAYED,   ajit},               
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf),                      "i+1",           F_JSR|F_DELAYED,   ajit},               /*jmpli+rs1,%o7*/
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf),                      "i+1,#",         F_JSR|F_DELAYED,   ajit},               
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf)|RS1_G0,               "i",             F_JSR|F_DELAYED,   ajit},               /*jmpl%g0+i,%o7*/
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf)|RS1_G0,               "i,#",           F_JSR|F_DELAYED,   ajit},               
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf)|SIMM13(~0),           "1",             F_JSR|F_DELAYED,   ajit},               /*jmplrs1+0,%o7*/
{"call",      F3(2,0x38,1)|RD(0xf),                 F3(~2,~0x38,~1)|RD(~0xf)|SIMM13(~0),           "1,#",           F_JSR|F_DELAYED,   ajit},               
{"clr",       F3(2,0x02,0),                         F3(~2,~0x02,~0)|RD_G0|RS1_G0|ASI_RS2(~0),      "d",             F_ALIAS,           ajit},               /*or%g0,%g0,d*/
{"clr",       F3(2,0x02,1),                         F3(~2,~0x02,~1)|RS1_G0|SIMM13(~0),             "d",             F_ALIAS,           ajit},               /*or%g0,0,d*/
{"clr",       F3(3,0x04,0),                         F3(~3,~0x04,~0)|RD_G0|ASI_RS2(~0),             "[1]",           F_ALIAS,           ajit},               /*st%g0,[rs1+%g0]*/
{"clr",       F3(3,0x04,0),                         F3(~3,~0x04,~0)|RD_G0|ASI(~0),                 "[1+2]",         F_ALIAS,           ajit},               
{"clr",       F3(3,0x04,1),                         F3(~3,~0x04,~1)|RD_G0,                         "[1+i]",         F_ALIAS,           ajit},               
{"clr",       F3(3,0x04,1),                         F3(~3,~0x04,~1)|RD_G0,                         "[i+1]",         F_ALIAS,           ajit},               
{"clr",       F3(3,0x04,1),                         F3(~3,~0x04,~1)|RD_G0|RS1_G0,                  "[i]",           F_ALIAS,           ajit},               
{"clr",       F3(3,0x04,1),                         F3(~3,~0x04,~1)|RD_G0|SIMM13(~0),              "[1]",           F_ALIAS,           ajit},               /*st%g0,[rs1+0]*/
{"clrb",      F3(3,0x05,0),                         F3(~3,~0x05,~0)|RD_G0|ASI_RS2(~0),             "[1]",           F_ALIAS,           ajit},               /*stb%g0,[rs1+%g0]*/
{"clrb",      F3(3,0x05,0),                         F3(~3,~0x05,~0)|RD_G0|ASI(~0),                 "[1+2]",         F_ALIAS,           ajit},               
{"clrb",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|RD_G0,                         "[1+i]",         F_ALIAS,           ajit},               
{"clrb",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|RD_G0,                         "[i+1]",         F_ALIAS,           ajit},               
{"clrb",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|RD_G0|RS1_G0,                  "[i]",           F_ALIAS,           ajit},               
{"clrb",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|RD_G0|SIMM13(~0),              "[1]",           F_ALIAS,           ajit},               /*stb%g0,[rs1+0]*/
{"clrh",      F3(3,0x06,0),                         F3(~3,~0x06,~0)|RD_G0|ASI_RS2(~0),             "[1]",           F_ALIAS,           ajit},               /*sth%g0,[rs1+%g0]*/
{"clrh",      F3(3,0x06,0),                         F3(~3,~0x06,~0)|RD_G0|ASI(~0),                 "[1+2]",         F_ALIAS,           ajit},               
{"clrh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|RD_G0,                         "[1+i]",         F_ALIAS,           ajit},               
{"clrh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|RD_G0,                         "[i+1]",         F_ALIAS,           ajit},               
{"clrh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|RD_G0|RS1_G0,                  "[i]",           F_ALIAS,           ajit},               
{"clrh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|RD_G0|SIMM13(~0),              "[1]",           F_ALIAS,           ajit},               /*sth%g0,[rs1+0]*/
{"cmp",       F3(2,0x14,0),                         F3(~2,~0x14,~0)|RD_G0|ASI(~0),                 "1,2",           0,                 ajit},               /*subccrs1,rs2,%g0*/
{"cmp",       F3(2,0x14,1),                         F3(~2,~0x14,~1)|RD_G0,                         "1,i",           0,                 ajit},               /*subccrs1,i,%g0*/
{"cpop1",     F3(2,0x36,0),                         F3(~2,~0x36,~1),                               "[1+2],d",         F_ALIAS,           ajit},               
{"cpop2",     F3(2,0x37,0),                         F3(~2,~0x37,~1),                               "[1+2],d",         F_ALIAS,           ajit},               
{"dec",       F3(2,0x04,1),                         F3(~2,~0x04,~1),                               "i,r",           F_ALIAS,           ajit},               /*subrd,imm,rd*/
{"dec",       F3(2,0x04,1)|SIMM13(0x1),             F3(~2,~0x04,~1)|SIMM13(~0x0001),               "r",               F_ALIAS,           ajit},               /*subrd,1,rd*/
{"deccc",     F3(2,0x14,1),                         F3(~2,~0x14,~1),                               "i,r",           F_ALIAS,           ajit},               /*subccrd,imm,rd*/
{"deccc",     F3(2,0x14,1)|SIMM13(0x1),             F3(~2,~0x14,~1)|SIMM13(~0x0001),               "r",               F_ALIAS,           ajit},               /*subccrd,1,rd*/
{"fabss",     F3F(2,0x34,0x009),                    F3F(~2,~0x34,~0x009)|RS1_G0,                   "f,g",             F_FLOAT,           ajit},               
{"faddd",     F3F(2,0x34,0x042),                    F3F(~2,~0x34,~0x042),                          "v,B,H",           F_FLOAT,           ajit},               
{"faddq",     F3F(2,0x34,0x043),                    F3F(~2,~0x34,~0x043),                          "V,R,J",           F_FLOAT,           ajit},               
{"fadds",     F3F(2,0x34,0x041),                    F3F(~2,~0x34,~0x041),                          "e,f,g",           F_FLOAT,           ajit},               
{"faddx",     F3F(2,0x34,0x043),                    F3F(~2,~0x34,~0x043),                          "V,R,J",           F_FLOAT|F_ALIAS,   ajit},               
{"fcmpd",     F3F(2,0x35,0x052),                    F3F(~2,~0x35,~0x052)|RD_G0,                    "v,B",             F_FLOAT,           ajit},               
{"fcmped",    F3F(2,0x35,0x056),                    F3F(~2,~0x35,~0x056)|RD_G0,                    "v,B",             F_FLOAT,           ajit},               
{"fcmpeq",    F3F(2,0x35,0x057),                    F3F(~2,~0x35,~0x057)|RD_G0,                    "V,R",           F_FLOAT,           ajit},               
{"fcmpes",    F3F(2,0x35,0x055),                    F3F(~2,~0x35,~0x055)|RD_G0,                    "e,f",             F_FLOAT,           ajit},               
{"fcmpex",    F3F(2,0x35,0x057),                    F3F(~2,~0x35,~0x057)|RD_G0,                    "V,R",           F_FLOAT|F_ALIAS,   ajit},               
{"fcmpq",     F3F(2,0x35,0x053),                    F3F(~2,~0x35,~0x053)|RD_G0,                    "V,R",           F_FLOAT,           ajit},               
{"fcmps",     F3F(2,0x35,0x051),                    F3F(~2,~0x35,~0x051)|RD_G0,                    "e,f",             F_FLOAT,           ajit},               
{"fcmpx",     F3F(2,0x35,0x053),                    F3F(~2,~0x35,~0x053)|RD_G0,                    "V,R",           F_FLOAT|F_ALIAS,   ajit},               
{"fdivd",     F3F(2,0x34,0x04e),                    F3F(~2,~0x34,~0x04e),                          "v,B,H",           F_FLOAT,           ajit},               
{"fdivq",     F3F(2,0x34,0x04f),                    F3F(~2,~0x34,~0x04f),                          "V,R,J",           F_FLOAT,           ajit},               
{"fdivs",     F3F(2,0x34,0x04d),                    F3F(~2,~0x34,~0x04d),                          "e,f,g",           F_FLOAT,           ajit},               
{"fdivx",     F3F(2,0x34,0x04f),                    F3F(~2,~0x34,~0x04f),                          "V,R,J",           F_FLOAT|F_ALIAS,   ajit},               
{"fdmulq",    F3F(2,0x34,0x06e),                    F3F(~2,~0x34,~0x06e),                          "v,B,J",           F_FLOAT,           ajit},               
{"fdmulx",    F3F(2,0x34,0x06e),                    F3F(~2,~0x34,~0x06e),                          "v,B,J",           F_FLOAT|F_ALIAS,   ajit},               
{"fdtoi",     F3F(2,0x34,0x0d2),                    F3F(~2,~0x34,~0x0d2)|RS1_G0,                   "B,g",             F_FLOAT,           ajit},               
{"fdtoq",     F3F(2,0x34,0x0ce),                    F3F(~2,~0x34,~0x0ce)|RS1_G0,                   "B,J",             F_FLOAT,           ajit},               
{"fdtos",     F3F(2,0x34,0x0c6),                    F3F(~2,~0x34,~0x0c6)|RS1_G0,                   "B,g",             F_FLOAT,           ajit},               
{"fitod",     F3F(2,0x34,0x0c8),                    F3F(~2,~0x34,~0x0c8)|RS1_G0,                   "f,H",             F_FLOAT,           ajit},               
{"fitoq",     F3F(2,0x34,0x0cc),                    F3F(~2,~0x34,~0x0cc)|RS1_G0,                   "f,J",             F_FLOAT,           ajit},               
{"fitos",     F3F(2,0x34,0x0c4),                    F3F(~2,~0x34,~0x0c4)|RS1_G0,                   "f,g",             F_FLOAT,           ajit},               
{"flush",     F3(2,0x3b,0),                         F3(~2,~0x3b,~0)|ASI_RS2(~0),                   "1",             0,                 ajit},               /*flushrs1+%g0*/
{"flush",     F3(2,0x3b,0),                         F3(~2,~0x3b,~0)|ASI(~0),                       "1+2",           0,                 ajit},               
{"flush",     F3(2,0x3b,1),                         F3(~2,~0x3b,~1),                               "1+i",           0,                 ajit},               
{"flush",     F3(2,0x3b,1),                         F3(~2,~0x3b,~1),                               "i+1",           0,                 ajit},               
{"flush",     F3(2,0x3b,1),                         F3(~2,~0x3b,~1)|RS1_G0,                        "i",             0,                 ajit},               /*flush%g0+i*/
{"flush",     F3(2,0x3b,1),                         F3(~2,~0x3b,~1)|SIMM13(~0),                    "1",             0,                 ajit},               /*flushrs1+0*/
{"fmovs",     F3F(2,0x34,0x001),                    F3F(~2,~0x34,~0x001)|RS1_G0,                   f,g,             F_FLOAT,           ajit},               
{"fmuld",     F3F(2,0x34,0x04a),                    F3F(~2,~0x34,~0x04a),                          v,B,H,           F_FLOAT,           ajit},               
{"fmulq",     F3F(2,0x34,0x04b),                    F3F(~2,~0x34,~0x04b),                          V,R,J,           F_FLOAT,           ajit},               
{"fmuls",     F3F(2,0x34,0x049),                    F3F(~2,~0x34,~0x049),                          e,f,g,           F_FLOAT,           ajit},               
{"fmulx",     F3F(2,0x34,0x04b),                    F3F(~2,~0x34,~0x04b),                          V,R,J,           F_FLOAT|F_ALIAS,   ajit},               
{"fnegs",     F3F(2,0x34,0x005),                    F3F(~2,~0x34,~0x005)|RS1_G0,                   f,g,             F_FLOAT,           ajit},               
{"fqtod",     F3F(2,0x34,0x0cb),                    F3F(~2,~0x34,~0x0cb)|RS1_G0,                   R,H,             F_FLOAT,           ajit},               
{"fqtoi",     F3F(2,0x34,0x0d3),                    F3F(~2,~0x34,~0x0d3)|RS1_G0,                   R,g,             F_FLOAT,           ajit},               
{"fqtos",     F3F(2,0x34,0x0c7),                    F3F(~2,~0x34,~0x0c7)|RS1_G0,                   R,g,             F_FLOAT,           ajit},               
{"fsmuld",    F3F(2,0x34,0x069),                    F3F(~2,~0x34,~0x069),                          e,f,H,           F_FLOAT|F_FSMULD,  ajit},               
{"fsqrtd",    F3F(2,0x34,0x02a),                    F3F(~2,~0x34,~0x02a)|RS1_G0,                   B,H,             F_FLOAT,           ajit},               
{"fsqrtq",    F3F(2,0x34,0x02b),                    F3F(~2,~0x34,~0x02b)|RS1_G0,                   R,J,             F_FLOAT,           ajit},               
{"fsqrts",    F3F(2,0x34,0x029),                    F3F(~2,~0x34,~0x029)|RS1_G0,                   f,g,             F_FLOAT,           ajit},               
{"fsqrtx",    F3F(2,0x34,0x02b),                    F3F(~2,~0x34,~0x02b)|RS1_G0,                   R,J,             F_FLOAT|F_ALIAS,   ajit},               
{"fstod",     F3F(2,0x34,0x0c9),                    F3F(~2,~0x34,~0x0c9)|RS1_G0,                   f,H,             F_FLOAT,           ajit},               
{"fstoi",     F3F(2,0x34,0x0d1),                    F3F(~2,~0x34,~0x0d1)|RS1_G0,                   f,g,             F_FLOAT,           ajit},               
{"fstoq",     F3F(2,0x34,0x0cd),                    F3F(~2,~0x34,~0x0cd)|RS1_G0,                   f,J,             F_FLOAT,           ajit},               
{"fsubd",     F3F(2,0x34,0x046),                    F3F(~2,~0x34,~0x046),                          v,B,H,           F_FLOAT,           ajit},               
{"fsubq",     F3F(2,0x34,0x047),                    F3F(~2,~0x34,~0x047),                          V,R,J,           F_FLOAT,           ajit},               
{"fsubs",     F3F(2,0x34,0x045),                    F3F(~2,~0x34,~0x045),                          e,f,g,           F_FLOAT,           ajit},               
{"fsubx",     F3F(2,0x34,0x047),                    F3F(~2,~0x34,~0x047),                          V,R,J,           F_FLOAT|F_ALIAS,   ajit},               
{"iflush",    F3(2,0x3b,0),                         F3(~2,~0x3b,~0)|ASI_RS2(~0),                   "1",             F_ALIAS,           ajit},               /*flushrs1+%g0*/
{"iflush",    F3(2,0x3b,0),                         F3(~2,~0x3b,~0)|ASI(~0),                       "1+2",           F_ALIAS,           ajit},               
{"iflush",    F3(2,0x3b,1),                         F3(~2,~0x3b,~1),                               "1+i",           F_ALIAS,           ajit},               
{"iflush",    F3(2,0x3b,1),                         F3(~2,~0x3b,~1),                               "i+1",           F_ALIAS,           ajit},               
{"iflush",    F3(2,0x3b,1),                         F3(~2,~0x3b,~1)|RS1_G0,                        "i",             F_ALIAS,           ajit},               
{"iflush",    F3(2,0x3b,1),                         F3(~2,~0x3b,~1)|SIMM13(~0),                    "1",             F_ALIAS,           ajit},               /*flushrs1+0*/
{"inc",       F3(2,0x00,1),                         F3(~2,~0x00,~1),                               "i,r",           F_ALIAS,           ajit},               /*addrd,imm,rd*/
{"inc",       F3(2,0x00,1)|SIMM13(0x1),             F3(~2,~0x00,~1)|SIMM13(~0x0001),               r,               F_ALIAS,           ajit},               /*addrd,1,rd*/
{"inccc",     F3(2,0x10,1),                         F3(~2,~0x10,~1),                               "i,r",           F_ALIAS,           ajit},               /*addccrd,imm,rd*/
{"inccc",     F3(2,0x10,1)|SIMM13(0x1),             F3(~2,~0x10,~1)|SIMM13(~0x0001),               r,               F_ALIAS,           ajit},               /*addccrd,1,rd*/
{"jmp",       F3(2,0x38,0),                         F3(~2,~0x38,~0)|RD_G0|ASI_RS2(~0),             "1",             F_UNBR|F_DELAYED,  ajit},               /*jmplrs1+%g0,%g0*/
{"jmp",       F3(2,0x38,0),                         F3(~2,~0x38,~0)|RD_G0|ASI(~0),                 "1+2",           F_UNBR|F_DELAYED,  ajit},               /*jmplrs1+rs2,%g0*/
{"jmp",       F3(2,0x38,1),                         F3(~2,~0x38,~1)|RD_G0,                         "1+i",           F_UNBR|F_DELAYED,  ajit},               /*jmplrs1+i,%g0*/
{"jmp",       F3(2,0x38,1),                         F3(~2,~0x38,~1)|RD_G0,                         "i+1",           F_UNBR|F_DELAYED,  ajit},               /*jmpli+rs1,%g0*/
{"jmp",       F3(2,0x38,1),                         F3(~2,~0x38,~1)|RD_G0|RS1_G0,                  "i",             F_UNBR|F_DELAYED,  ajit},               /*jmpl%g0+i,%g0*/
{"jmp",       F3(2,0x38,1),                         F3(~2,~0x38,~1)|RD_G0|SIMM13(~0),              "1",             F_UNBR|F_DELAYED,  ajit},               /*jmplrs1+0,%g0*/
{"jmpl",      F3(2,0x38,0),                         F3(~2,~0x38,~0)|ASI_RS2(~0),                   "1,d",           F_JSR|F_DELAYED,   ajit},               /*jmplrs1+%g0,d*/
{"jmpl",      F3(2,0x38,0),                         F3(~2,~0x38,~0)|ASI(~0),                       "1+2,d",         F_JSR|F_DELAYED,   ajit},               
{"jmpl",      F3(2,0x38,1),                         F3(~2,~0x38,~1),                               "1+i,d",         F_JSR|F_DELAYED,   ajit},               
{"jmpl",      F3(2,0x38,1),                         F3(~2,~0x38,~1),                               "i+1,d",         F_JSR|F_DELAYED,   ajit},               
{"jmpl",      F3(2,0x38,1),                         F3(~2,~0x38,~1)|RS1_G0,                        "i,d",           F_JSR|F_DELAYED,   ajit},               /*jmpl%g0+i,d*/
{"jmpl",      F3(2,0x38,1),                         F3(~2,~0x38,~1)|SIMM13(~0),                    "1,d",           F_JSR|F_DELAYED,   ajit},               /*jmplrs1+0,d*/
{"ld",        F3(3,0x00,0),                         F3(~3,~0x00,~0),                               "[1+2],d",       0,                 ajit},               
{"ld",        F3(3,0x00,0),                         F3(~3,~0x00,~0)|RS2_G0,                        "[1],d",         0,                 ajit},               /*ld[rs1+%g0],d*/
{"ld",        F3(3,0x00,1),                         F3(~3,~0x00,~1),                               "[1+i],d",       0,                 ajit},               
{"ld",        F3(3,0x00,1),                         F3(~3,~0x00,~1),                               "[i+1],d",       0,                 ajit},               
{"ld",        F3(3,0x00,1),                         F3(~3,~0x00,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"ld",        F3(3,0x00,1),                         F3(~3,~0x00,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*ld[rs1+0],d*/
{"ld",        F3(3,0x20,0),                         F3(~3,~0x20,~0),                               "[1+2],g",       0,                 ajit},               
{"ld",        F3(3,0x20,0),                         F3(~3,~0x20,~0)|RS2_G0,                        "[1],g",         0,                 ajit},               /*ld[rs1+%g0],d*/
{"ld",        F3(3,0x20,1),                         F3(~3,~0x20,~1),                               "[1+i],g",       0,                 ajit},               
{"ld",        F3(3,0x20,1),                         F3(~3,~0x20,~1),                               "[i+1],g",       0,                 ajit},               
{"ld",        F3(3,0x20,1),                         F3(~3,~0x20,~1)|RS1_G0,                        "[i],g",         0,                 ajit},               
{"ld",        F3(3,0x20,1),                         F3(~3,~0x20,~1)|SIMM13(~0),                    "[1],g",         0,                 ajit},               /*ld[rs1+0],d*/
{"ld",        F3(3,0x21,0),                         F3(~3,~0x21,~0)|RD(~0),                        "[1+2],F",       0,                 ajit},               
{"ld",        F3(3,0x21,0),                         F3(~3,~0x21,~0)|RS2_G0|RD(~0),                 [1],F,           0,                 ajit},               /*ld[rs1+%g0],d*/
{"ld",        F3(3,0x21,1),                         F3(~3,~0x21,~1)|RD(~0),                        "[1+i],F",       0,                 ajit},               
{"ld",        F3(3,0x21,1),                         F3(~3,~0x21,~1)|RD(~0),                        "[i+1],F",       0,                 ajit},               
{"ld",        F3(3,0x21,1),                         F3(~3,~0x21,~1)|RS1_G0|RD(~0),                 [i],F,           0,                 ajit},               
{"ld",        F3(3,0x21,1),                         F3(~3,~0x21,~1)|SIMM13(~0)|RD(~0),             [1],F,           0,                 ajit},               /*ld[rs1+0],d*/
{"ld",        F3(3,0x30,0),                         F3(~3,~0x30,~0),                               "[1+2],D",       0,                 ajit},               
{"ld",        F3(3,0x30,0),                         F3(~3,~0x30,~0)|RS2_G0,                        "[1],D",         0,                 ajit},               /*ld[rs1+%g0],d*/
{"ld",        F3(3,0x30,1),                         F3(~3,~0x30,~1),                               "[1+i],D",       0,                 ajit},               
{"ld",        F3(3,0x30,1),                         F3(~3,~0x30,~1),                               "[i+1],D",       0,                 ajit},               
{"ld",        F3(3,0x30,1),                         F3(~3,~0x30,~1)|RS1_G0,                        "[i],D",         0,                 ajit},               
{"ld",        F3(3,0x30,1),                         F3(~3,~0x30,~1)|SIMM13(~0),                    "[1],D",         0,                 ajit},               /*ld[rs1+0],d*/
{"ld",        F3(3,0x31,0),                         F3(~3,~0x31,~0),                               "[1+2],C",       0,                 ajit},               
{"ld",        F3(3,0x31,0),                         F3(~3,~0x31,~0)|RS2_G0,                        "[1],C",         0,                 ajit},               /*ld[rs1+%g0],d*/
{"ld",        F3(3,0x31,1),                         F3(~3,~0x31,~1),                               "[1+i],C",       0,                 ajit},               
{"ld",        F3(3,0x31,1),                         F3(~3,~0x31,~1),                               "[i+1],C",       0,                 ajit},               
{"ld",        F3(3,0x31,1),                         F3(~3,~0x31,~1)|RS1_G0,                        "[i],C",         0,                 ajit},               
{"ld",        F3(3,0x31,1),                         F3(~3,~0x31,~1)|SIMM13(~0),                    "[1],C",         0,                 ajit},               /*ld[rs1+0],d*/
{"lda",       F3(3,0x10,0),                         F3(~3,~0x10,~0),                               "[1+2]A,d",      0,                 ajit},               
{"lda",       F3(3,0x10,0),                         F3(~3,~0x10,~0)|RS2_G0,                        "[1]A,d",        0,                 ajit},               /*lda[rs1+%g0],d*/
{"ldd",       F3(3,0x03,0),                         F3(~3,~0x03,~0)|ASI_RS2(~0),                   "[1],d",         0,                 ajit},               /*ldd[rs1+%g0],d*/
{"ldd",       F3(3,0x03,0),                         F3(~3,~0x03,~0)|ASI(~0),                       "[1+2],d",       0,                 ajit},               
{"ldd",       F3(3,0x03,1),                         F3(~3,~0x03,~1),                               "[1+i],d",       0,                 ajit},               
{"ldd",       F3(3,0x03,1),                         F3(~3,~0x03,~1),                               "[i+1],d",       0,                 ajit},               
{"ldd",       F3(3,0x03,1),                         F3(~3,~0x03,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"ldd",       F3(3,0x03,1),                         F3(~3,~0x03,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*ldd[rs1+0],d*/
{"ldd",       F3(3,0x23,0),                         F3(~3,~0x23,~0)|ASI_RS2(~0),                   "[1],H",         0,                 ajit},               /*ldd[rs1+%g0],d*/
{"ldd",       F3(3,0x23,0),                         F3(~3,~0x23,~0)|ASI(~0),                       "[1+2],H",       0,                 ajit},               
{"ldd",       F3(3,0x23,1),                         F3(~3,~0x23,~1),                               "[1+i],H",       0,                 ajit},               
{"ldd",       F3(3,0x23,1),                         F3(~3,~0x23,~1),                               "[i+1],H",       0,                 ajit},               
{"ldd",       F3(3,0x23,1),                         F3(~3,~0x23,~1)|RS1_G0,                        "[i],H",         0,                 ajit},               
{"ldd",       F3(3,0x23,1),                         F3(~3,~0x23,~1)|SIMM13(~0),                    "[1],H",         0,                 ajit},               /*ldd[rs1+0],d*/
{"ldd",       F3(3,0x33,0),                         F3(~3,~0x33,~0)|ASI_RS2(~0),                   "[1],D",         0,                 ajit},               /*ldd[rs1+%g0],d*/
{"ldd",       F3(3,0x33,0),                         F3(~3,~0x33,~0)|ASI(~0),                       "[1+2],D",       0,                 ajit},               
{"ldd",       F3(3,0x33,1),                         F3(~3,~0x33,~1),                               "[1+i],D",       0,                 ajit},               
{"ldd",       F3(3,0x33,1),                         F3(~3,~0x33,~1),                               "[i+1],D",       0,                 ajit},               
{"ldd",       F3(3,0x33,1),                         F3(~3,~0x33,~1)|RS1_G0,                        "[i],D",         0,                 ajit},               
{"ldd",       F3(3,0x33,1),                         F3(~3,~0x33,~1)|SIMM13(~0),                    "[1],D",         0,                 ajit},               /*ldd[rs1+0],d*/
{"ldda",      F3(3,0x13,0),                         F3(~3,~0x13,~0),                               "[1+2]A,d",      0,                 ajit},               
{"ldda",      F3(3,0x13,0),                         F3(~3,~0x13,~0)|RS2_G0,                        "[1]A,d",        0,                 ajit},               /*ldda[rs1+%g0],d*/
{"ldsb",      F3(3,0x09,0),                         F3(~3,~0x09,~0)|ASI_RS2(~0),                   "[1],d",         0,                 ajit},               /*ldsb[rs1+%g0],d*/
{"ldsb",      F3(3,0x09,0),                         F3(~3,~0x09,~0)|ASI(~0),                       "[1+2],d",       0,                 ajit},               
{"ldsb",      F3(3,0x09,1),                         F3(~3,~0x09,~1),                               "[1+i],d",       0,                 ajit},               
{"ldsb",      F3(3,0x09,1),                         F3(~3,~0x09,~1),                               "[i+1],d",       0,                 ajit},               
{"ldsb",      F3(3,0x09,1),                         F3(~3,~0x09,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"ldsb",      F3(3,0x09,1),                         F3(~3,~0x09,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*ldsb[rs1+0],d*/
{"ldsba",     F3(3,0x19,0),                         F3(~3,~0x19,~0),                               "[1+2]A,d",      0,                 ajit},               
{"ldsba",     F3(3,0x19,0),                         F3(~3,~0x19,~0)|RS2_G0,                        "[1]A,d",        0,                 ajit},               /*ldsba[rs1+%g0],d*/
{"ldsh",      F3(3,0x0a,0),                         F3(~3,~0x0a,~0)|ASI_RS2(~0),                   "[1],d",         0,                 ajit},               /*ldsh[rs1+%g0],d*/
{"ldsh",      F3(3,0x0a,0),                         F3(~3,~0x0a,~0)|ASI(~0),                       "[1+2],d",       0,                 ajit},               
{"ldsh",      F3(3,0x0a,1),                         F3(~3,~0x0a,~1),                               "[1+i],d",       0,                 ajit},               
{"ldsh",      F3(3,0x0a,1),                         F3(~3,~0x0a,~1),                               "[i+1],d",       0,                 ajit},               
{"ldsh",      F3(3,0x0a,1),                         F3(~3,~0x0a,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"ldsh",      F3(3,0x0a,1),                         F3(~3,~0x0a,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*ldsh[rs1+0],d*/
{"ldsha",     F3(3,0x1a,0),                         F3(~3,~0x1a,~0),                               "[1+2]A,d",      0,                 ajit},               
{"ldsha",     F3(3,0x1a,0),                         F3(~3,~0x1a,~0)|RS2_G0,                        "[1]A,d",        0,                 ajit},               /*ldsha[rs1+%g0],d*/
{"ldstub",    F3(3,0x0d,0),                         F3(~3,~0x0d,~0)|ASI_RS2(~0),                   "[1],d",         0,                 ajit},               /*ldstub[rs1+%g0],d*/
{"ldstub",    F3(3,0x0d,0),                         F3(~3,~0x0d,~0)|ASI(~0),                       "[1+2],d",       0,                 ajit},               
{"ldstub",    F3(3,0x0d,1),                         F3(~3,~0x0d,~1),                               "[1+i],d",       0,                 ajit},               
{"ldstub",    F3(3,0x0d,1),                         F3(~3,~0x0d,~1),                               "[i+1],d",       0,                 ajit},               
{"ldstub",    F3(3,0x0d,1),                         F3(~3,~0x0d,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"ldstub",    F3(3,0x0d,1),                         F3(~3,~0x0d,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*ldstub[rs1+0],d*/
{"ldstuba",   F3(3,0x1d,0),                         F3(~3,~0x1d,~0),                               "[1+2]A,d",      0,                 ajit},               
{"ldstuba",   F3(3,0x1d,0),                         F3(~3,~0x1d,~0)|RS2_G0,                        "[1]A,d",        0,                 ajit},               /*ldstuba[rs1+%g0],d*/
{"ldub",      F3(3,0x01,0),                         F3(~3,~0x01,~0)|ASI_RS2(~0),                   "[1],d",         0,                 ajit},               /*ldub[rs1+%g0],d*/
{"ldub",      F3(3,0x01,0),                         F3(~3,~0x01,~0)|ASI(~0),                       "[1+2],d",       0,                 ajit},               
{"ldub",      F3(3,0x01,1),                         F3(~3,~0x01,~1),                               "[1+i],d",       0,                 ajit},               
{"ldub",      F3(3,0x01,1),                         F3(~3,~0x01,~1),                               "[i+1],d",       0,                 ajit},               
{"ldub",      F3(3,0x01,1),                         F3(~3,~0x01,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"ldub",      F3(3,0x01,1),                         F3(~3,~0x01,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*ldub[rs1+0],d*/
{"lduba",     F3(3,0x11,0),                         F3(~3,~0x11,~0),                               "[1+2]A,d",      0,                 ajit},               
{"lduba",     F3(3,0x11,0),                         F3(~3,~0x11,~0)|RS2_G0,                        "[1]A,d",        0,                 ajit},               /*lduba[rs1+%g0],d*/
{"lduh",      F3(3,0x02,0),                         F3(~3,~0x02,~0)|ASI_RS2(~0),                   "[1],d",         0,                 ajit},               /*lduh[rs1+%g0],d*/
{"lduh",      F3(3,0x02,0),                         F3(~3,~0x02,~0)|ASI(~0),                       "[1+2],d",       0,                 ajit},               
{"lduh",      F3(3,0x02,1),                         F3(~3,~0x02,~1),                               "[1+i],d",       0,                 ajit},               
{"lduh",      F3(3,0x02,1),                         F3(~3,~0x02,~1),                               "[i+1],d",       0,                 ajit},               
{"lduh",      F3(3,0x02,1),                         F3(~3,~0x02,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"lduh",      F3(3,0x02,1),                         F3(~3,~0x02,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*lduh[rs1+0],d*/
{"lduha",     F3(3,0x12,0),                         F3(~3,~0x12,~0),                               "[1+2]A,d",      0,                 ajit},               
{"lduha",     F3(3,0x12,0),                         F3(~3,~0x12,~0)|RS2_G0,                        "[1]A,d",        0,                 ajit},               /*lduha[rs1+%g0],d*/
{"mov",       F3(2,0x02,0),                         F3(~2,~0x02,~0)|ASI_RS2(~0),                   "1,d",           0,                 ajit},               /*orrs1,%g0,d*/
{"mov",       F3(2,0x02,1),                         F3(~2,~0x02,~1)|SIMM13(~0),                    "1,d",           0,                 ajit},               /*orrs1,0,d*/
{"mov",       F3(2,0x02,0),                         F3(~2,~0x02,~0)|RS1_G0|ASI(~0),                "2,d",           0,                 ajit},               /*or%g0,rs2,d*/
{"mov",       F3(2,0x02,1),                         F3(~2,~0x02,~1)|RS1_G0,                        "i,d",           0,                 ajit},               /*or%g0,i,d*/
{"mov",       F3(2,0x28,0),                         F3(~2,~0x28,~0)|RS1_G0|SIMM13(~0),             "y,d",           F_ALIAS,           ajit},               /*rd%y,r*/
{"mov",       F3(2,0x28,0),                         F3(~2,~0x28,~0)|SIMM13(~0),                    "M,d",           F_ALIAS,           ajit},               /*rd%asr1,r*/
{"mov",       F3(2,0x29,0),                         F3(~2,~0x29,~0)|RS1_G0|SIMM13(~0),             "p,d",           F_ALIAS,           ajit},               /*rd%psr,r*/
{"mov",       F3(2,0x2a,0),                         F3(~2,~0x2a,~0)|RS1_G0|SIMM13(~0),             "w,d",           F_ALIAS,           ajit},               /*rd%wim,r*/
{"mov",       F3(2,0x2b,0),                         F3(~2,~0x2b,~0)|RS1_G0|SIMM13(~0),             "t,d",           F_ALIAS,           ajit},               /*rd%tbr,r*/
{"mov",       F3(2,0x30,0),                         F3(~2,~0x30,~0)|ASI_RS2(~0),                   "1,m",           F_ALIAS,           ajit},               /*wrrs1,%g0,%asrX*/
{"mov",       F3(2,0x30,0),                         F3(~2,~0x30,~0)|ASI(~0),                       "1,2,m",         F_ALIAS,           ajit},               /*wrr,r,%asrX*/
{"mov",       F3(2,0x30,0),                         F3(~2,~0x30,~0)|RD_G0|ASI_RS2(~0),             "1,y",           F_ALIAS,           ajit},               /*wrrs1,%g0,%y*/
{"mov",       F3(2,0x30,0),                         F3(~2,~0x30,~0)|RD_G0|ASI(~0),                 "1,2,y",         F_ALIAS,           ajit},               /*wrr,r,%y*/
{"mov",       F3(2,0x30,0),                         F3(~2,~0x30,~0)|RD_G0|RS1_G0|ASI(~0),          "2,y",           F_ALIAS,           ajit},               /*wr%g0,rs2,%y*/
{"mov",       F3(2,0x30,0),                         F3(~2,~0x30,~0)|RS1_G0|ASI(~0),                "2,m",           F_ALIAS,           ajit},               /*wr%g0,rs2,%asrX*/
{"mov",       F3(2,0x30,1),                         F3(~2,~0x30,~1),                               "1,i,m",         F_ALIAS,           ajit},               /*wrr,i,%asrX*/
{"mov",       F3(2,0x30,1),                         F3(~2,~0x30,~1)|RD_G0,                         "1,i,y",         F_ALIAS,           ajit},               /*wrr,i,%y*/
{"mov",       F3(2,0x30,1),                         F3(~2,~0x30,~1)|RD_G0|RS1_G0,                  "i,y",           F_ALIAS,           ajit},               /*wr%g0,i,%y*/
{"mov",       F3(2,0x30,1),                         F3(~2,~0x30,~1)|RD_G0|SIMM13(~0),              "1,y",           F_ALIAS,           ajit},               /*wrrs1,0,%y*/
{"mov",       F3(2,0x30,1),                         F3(~2,~0x30,~1)|RS1_G0,                        "i,m",           F_ALIAS,           ajit},               /*wr%g0,i,%asrX*/
{"mov",       F3(2,0x30,1),                         F3(~2,~0x30,~1)|SIMM13(~0),                    "1,m",           F_ALIAS,           ajit},               /*wrrs1,0,%asrX*/
{"mov",       F3(2,0x31,0),                         F3(~2,~0x31,~0)|RD_G0|ASI_RS2(~0),             "1,p",           F_ALIAS,           ajit},               /*wrrs1,%g0,%psr*/
{"mov",       F3(2,0x31,0),                         F3(~2,~0x31,~0)|RD_G0|ASI(~0),                 "1,2,p",         F_ALIAS,           ajit},               /*wrr,r,%psr*/
{"mov",       F3(2,0x31,0),                         F3(~2,~0x31,~0)|RD_G0|RS1_G0|ASI(~0),          "2,p",           F_ALIAS,           ajit},               /*wr%g0,rs2,%psr*/
{"mov",       F3(2,0x31,1),                         F3(~2,~0x31,~1)|RD_G0,                         "1,i,p",         F_ALIAS,           ajit},               /*wrr,i,%psr*/
{"mov",       F3(2,0x31,1),                         F3(~2,~0x31,~1)|RD_G0|RS1_G0,                  "i,p",           F_ALIAS,           ajit},               /*wr%g0,i,%psr*/
{"mov",       F3(2,0x31,1),                         F3(~2,~0x31,~1)|RD_G0|SIMM13(~0),              "1,p",           F_ALIAS,           ajit},               /*wrrs1,0,%psr*/
{"mov",       F3(2,0x32,0),                         F3(~2,~0x32,~0)|RD_G0|ASI_RS2(~0),             "1,w",           F_ALIAS,           ajit},               /*wrrs1,%g0,%wim*/
{"mov",       F3(2,0x32,0),                         F3(~2,~0x32,~0)|RD_G0|ASI(~0),                 "1,2,w",         F_ALIAS,           ajit},               /*wrr,r,%wim*/
{"mov",       F3(2,0x32,0),                         F3(~2,~0x32,~0)|RD_G0|RS1_G0|ASI(~0),          "2,w",           F_ALIAS,           ajit},               /*wr%g0,rs2,%wim*/
{"mov",       F3(2,0x32,1),                         F3(~2,~0x32,~1)|RD_G0,                         "1,i,w",         F_ALIAS,           ajit},               /*wrr,i,%wim*/
{"mov",       F3(2,0x32,1),                         F3(~2,~0x32,~1)|RD_G0|RS1_G0,                  "i,w",           F_ALIAS,           ajit},               /*wr%g0,i,%wim*/
{"mov",       F3(2,0x32,1),                         F3(~2,~0x32,~1)|RD_G0|SIMM13(~0),              "1,w",           F_ALIAS,           ajit},               /*wrrs1,0,%wim*/
{"mov",       F3(2,0x33,0),                         F3(~2,~0x33,~0)|RD_G0|ASI_RS2(~0),             "1,t",           F_ALIAS,           ajit},               /*wrrs1,%g0,%tbr*/
{"mov",       F3(2,0x33,0),                         F3(~2,~0x33,~0)|RD_G0|ASI(~0),                 "1,2,t",         F_ALIAS,           ajit},               /*wrr,r,%tbr*/
{"mov",       F3(2,0x33,0),                         F3(~2,~0x33,~0)|RD_G0|RS1_G0|ASI(~0),          "2,t",           F_ALIAS,           ajit},               /*wr%g0,rs2,%tbr*/
{"mov",       F3(2,0x33,1),                         F3(~2,~0x33,~1)|RD_G0,                         "1,i,t",         F_ALIAS,           ajit},               /*wrr,i,%tbr*/
{"mov",       F3(2,0x33,1),                         F3(~2,~0x33,~1)|RD_G0|RS1_G0,                  "i,t",           F_ALIAS,           ajit},               /*wr%g0,i,%tbr*/
{"mov",       F3(2,0x33,1),                         F3(~2,~0x33,~1)|RD_G0|SIMM13(~0),              "1,t",           F_ALIAS,           ajit},               /*wrrs1,0,%tbr*/
{"mulscc",    F3(2,0x24,0),                         F3(~2,~0x24,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"mulscc",    F3(2,0x24,1),                         F3(~2,~0x24,~1),                               "1,i,d",         0,                 ajit},               
{"neg",       F3(2,0x04,0),                         F3(~2,~0x04,~0)|RS1_G0|ASI(~0),                2,d,             F_ALIAS,           ajit},               /*sub%g0,rs2,rd*/
{"neg",       F3(2,0x04,0),                         F3(~2,~0x04,~0)|RS1_G0|ASI(~0),                O,               F_ALIAS,           ajit},               /*sub%g0,rd,rd*/
{"nop",       F2(0,4),                              0xfeffffff,                                    ,                0,                 ajit},               /*sethi0,%g0*/
{"not",       F3(2,0x07,0),                         F3(~2,~0x07,~0)|ASI(~0),                       1,d,             F_ALIAS,           ajit},               /*xnorrs1,%0,rd*/
{"not",       F3(2,0x07,0),                         F3(~2,~0x07,~0)|ASI(~0),                       r,               F_ALIAS,           ajit},               /*xnorrd,%0,rd*/
{"or",        F3(2,0x02,0),                         F3(~2,~0x02,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"or",        F3(2,0x02,0),                         F3(~2,~0x02,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"or",        F3(2,0x02,1),                         F3(~2,~0x02,~1),                               "1,i,d",         0,                 ajit},               
{"or",        F3(2,0x02,1),                         F3(~2,~0x02,~1),                               "i,1,d",         0,                 ajit},               
{"orcc",      F3(2,0x12,0),                         F3(~2,~0x12,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"orcc",      F3(2,0x12,1),                         F3(~2,~0x12,~1),                               "1,i,d",         0,                 ajit},               
{"orcc",      F3(2,0x12,1),                         F3(~2,~0x12,~1),                               "i,1,d",         0,                 ajit},               
{"ord",       F4(2,0x02,0,1),                       F4(~2,~0x02,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"ordcc",     F4(2,0x12,0,1),                       F4(~2,~0x12,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"ordn",      F4(2,0x06,0,1),                       F4(~2,~0x06,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"ordncc",    F4(2,0x16,0,1),                       F4(~2,~0x16,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"orn",       F3(2,0x06,0),                         F3(~2,~0x06,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"orn",       F3(2,0x06,1),                         F3(~2,~0x06,~1),                               "1,i,d",         0,                 ajit},               
{"orncc",     F3(2,0x16,0),                         F3(~2,~0x16,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"orncc",     F3(2,0x16,1),                         F3(~2,~0x16,~1),                               "1,i,d",         0,                 ajit},               
{"rd",        F3(2,0x28,0),                         F3(~2,~0x28,~0)|RS1_G0|SIMM13(~0),             "y,d",           0,                 ajit},               /*rd%y,r*/
{"rd",        F3(2,0x28,0),                         F3(~2,~0x28,~0)|SIMM13(~0),                    "M,d",           0,                 ajit},               /*rd%asrX,r*/
{"rd",        F3(2,0x29,0),                         F3(~2,~0x29,~0)|RS1_G0|SIMM13(~0),             "p,d",           0,                 ajit},               /*rd%psr,r*/
{"rd",        F3(2,0x2a,0),                         F3(~2,~0x2a,~0)|RS1_G0|SIMM13(~0),             "w,d",           0,                 ajit},               /*rd%wim,r*/
{"rd",        F3(2,0x2b,0),                         F3(~2,~0x2b,~0)|RS1_G0|SIMM13(~0),             "t,d",           0,                 ajit},               /*rd%tbr,r*/
{"restore",   F3(2,0x3d,0),                         F3(~2,~0x3d,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"restore",   F3(2,0x3d,0),                         F3(~2,~0x3d,~0)|RD_G0|RS1_G0|ASI_RS2(~0),      "",              0,                 ajit},               /*restore%g0,%g0,%g0*/
{"restore",   F3(2,0x3d,1),                         F3(~2,~0x3d,~1),                               "1,i,d",         0,                 ajit},               
{"restore",   F3(2,0x3d,1),                         F3(~2,~0x3d,~1)|RD_G0|RS1_G0|SIMM13(~0),       "",              0,                 ajit},               /*restore%g0,0,%g0*/
{"ret",       F3(2,0x38,1)|RS1(0x1f)|SIMM13(8),     F3(~2,~0x38,~1)|SIMM13(~8),                    "",              F_UNBR|F_DELAYED,  ajit},               /*jmpl%i7+8,%g0*/
{"retl",      F3(2,0x38,1)|RS1(0x0f)|SIMM13(8),     F3(~2,~0x38,~1)|RS1(~0x0f)|SIMM13(~8),         ,                F_UNBR|F_DELAYED,  ajit},               /*jmpl%o7+8,%g0*/
{"rett",      F3(2,0x39,0),                         F3(~2,~0x39,~0)|RD_G0|ASI_RS2(~0),             "1",             F_UNBR|F_DELAYED,  ajit},               /*rettrs1,%g0*/
{"rett",      F3(2,0x39,0),                         F3(~2,~0x39,~0)|RD_G0|ASI(~0),                 "1+2",           F_UNBR|F_DELAYED,  ajit},               /*rettrs1+rs2*/
{"rett",      F3(2,0x39,1),                         F3(~2,~0x39,~1)|RD_G0,                         "1+i",           F_UNBR|F_DELAYED,  ajit},               /*rettrs1+X*/
{"rett",      F3(2,0x39,1),                         F3(~2,~0x39,~1)|RD_G0,                         "i+1",           F_UNBR|F_DELAYED,  ajit},               /*rettX+rs1*/
{"rett",      F3(2,0x39,1),                         F3(~2,~0x39,~1)|RD_G0|RS1_G0,                  "i",             F_UNBR|F_DELAYED,  ajit},               /*rettX+rs1*/
{"rett",      F3(2,0x39,1),                         F3(~2,~0x39,~1)|RD_G0|RS1_G0,                  "i",             F_UNBR|F_DELAYED,  ajit},               /*rettX*/
{"rett",      F3(2,0x39,1),                         F3(~2,~0x39,~1)|RD_G0|SIMM13(~0),              "1",             F_UNBR|F_DELAYED,  ajit},               /*rettrs1+0*/
{"save",      0x81e00000,                           ~0x81e00000,                                   "",              F_ALIAS,           ajit},               
{"save",      F3(2,0x3c,0),                         F3(~2,~0x3c,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"save",      F3(2,0x3c,1),                         F3(~2,~0x3c,~1),                               "1,i,d",         0,                 ajit},               
{"save",      F3(2,0x3c,1),                         F3(~2,~0x3c,~1),                               "i,1,d",         0,                 ajit},               /*Sunassemblercompatibility*/
{"sdiv",      F3(2,0x0f,0),                         F3(~2,~0x0f,~0)|ASI(~0),                       "1,2,d",         F_DIV32,           ajit},               
{"sdiv",      F3(2,0x0f,1),                         F3(~2,~0x0f,~1),                               "1,i,d",         F_DIV32,           ajit},               
{"sdiv",      F3(2,0x0f,1),                         F3(~2,~0x0f,~1),                               "i,1,d",         F_DIV32,           ajit},               
{"sdivcc",    F3(2,0x1f,0),                         F3(~2,~0x1f,~0)|ASI(~0),                       "1,2,d",         F_DIV32,           ajit},               
{"sdivcc",    F3(2,0x1f,1),                         F3(~2,~0x1f,~1),                               "1,i,d",         F_DIV32,           ajit},               
{"sdivcc",    F3(2,0x1f,1),                         F3(~2,~0x1f,~1),                               "i,1,d",         F_DIV32,           ajit},               
{"sdivd",     F4(2,0x0f,0,1),                       F4(~2,~0x0f,~0,~1),                            "1,2,d",         F_DIV32,           ajit},/*AJIT*/,      
{"sdivdcc",   F4(2,0x1f,0,1),                       F4(~2,~0x1f,~0,~1),                            "1,2,d",         F_DIV32,           ajit},/*AJIT*/,      
{"set",       F2(0x0,0x4),                          F2(~0x0,~0x4),                                 S0,d,            F_ALIAS,           ajit},               
{"sethi",     F2(0x0,0x4),                          F2(~0x0,~0x4),                                 h,d,             0,                 ajit},               
{"sll",       F3(2,0x25,0),                         F3(~2,~0x25,~0)|(1<<12)|(0x7f<<5),             "1,2,d",         0,                 ajit},               
{"sll",       F3(2,0x25,1),                         F3(~2,~0x25,~1)|(1<<12)|(0x7f<<5),             "1,X,d",         0,                 ajit},               
{"slld",      F5(2,0x25,0,0x1),                     F5(~2,~0x25,~0,~0x1),                          "1,2,d",         0,                 ajit},               /*AJIT*/
{"slld",      F5(2,0x25,1,0x1),                     F5(~2,~0x25,~1,~0x1),                          "1,Y,d",         0,                 ajit},               /*AJIT*/
{"smul",      F3(2,0x0b,0),                         F3(~2,~0x0b,~0)|ASI(~0),                       "1,2,d",         F_MUL32,           ajit},               
{"smul",      F3(2,0x0b,1),                         F3(~2,~0x0b,~1),                               "1,i,d",         F_MUL32,           ajit},               
{"smul",      F3(2,0x0b,1),                         F3(~2,~0x0b,~1),                               "i,1,d",         F_MUL32,           ajit},               
{"smulcc",    F3(2,0x1b,0),                         F3(~2,~0x1b,~0)|ASI(~0),                       "1,2,d",         F_MUL32,           ajit},               
{"smulcc",    F3(2,0x1b,1),                         F3(~2,~0x1b,~1),                               "1,i,d",         F_MUL32,           ajit},               
{"smulcc",    F3(2,0x1b,1),                         F3(~2,~0x1b,~1),                               "i,1,d",         F_MUL32,           ajit},               
{"smuld",     F4(2,0x0b,0,1),                       F4(~2,~0x0b,~0,~1),                            "1,2,d",         F_MUL32,           ajit},/*AJIT*/,      
{"smuldcc",   F4(2,0x1b,0,1),                       F4(~2,~0x1b,~0,~1),                            "1,2,d",         F_MUL32,           ajit},/*AJIT*/,      
{"spill",     F3(3,0x04,0),                         F3(~3,~0x04,~0)|ASI_RS2(~0),                   "d,[1]",         F_ALIAS,           ajit},               /*std,[rs1+%g0]*/
{"spill",     F3(3,0x04,0),                         F3(~3,~0x04,~0)|ASI(~0),                       "d,[1+2]",       F_ALIAS,           ajit},               
{"spill",     F3(3,0x04,1),                         F3(~3,~0x04,~1),                               "d,[1+i]",       F_ALIAS,           ajit},               
{"spill",     F3(3,0x04,1),                         F3(~3,~0x04,~1),                               "d,[i+1]",       F_ALIAS,           ajit},               
{"spill",     F3(3,0x04,1),                         F3(~3,~0x04,~1)|RS1_G0,                        "d,[i]",         F_ALIAS,           ajit},               
{"spill",     F3(3,0x04,1),                         F3(~3,~0x04,~1)|SIMM13(~0),                    "d,[1]",         F_ALIAS,           ajit},               /*std,[rs1+0]*/
{"spilld",    F3(3,0x07,0),                         F3(~3,~0x07,~0)|ASI_RS2(~0),                   "d,[1]",         F_ALIAS,           ajit},               /*stdd,[rs1+%g0]*/
{"spilld",    F3(3,0x07,0),                         F3(~3,~0x07,~0)|ASI(~0),                       "d,[1+2]",       F_ALIAS,           ajit},               
{"spilld",    F3(3,0x07,1),                         F3(~3,~0x07,~1),                               "d,[1+i]",       F_ALIAS,           ajit},               
{"spilld",    F3(3,0x07,1),                         F3(~3,~0x07,~1),                               "d,[i+1]",       F_ALIAS,           ajit},               
{"spilld",    F3(3,0x07,1),                         F3(~3,~0x07,~1)|RS1_G0,                        "d,[i]",         F_ALIAS,           ajit},               
{"spilld",    F3(3,0x07,1),                         F3(~3,~0x07,~1)|SIMM13(~0),                    "d,[1]",         F_ALIAS,           ajit},               /*stdd,[rs1+0]*/
{"sra",       F3(2,0x27,0),                         F3(~2,~0x27,~0)|(1<<12)|(0x7f<<5),             "1,2,d",         0,                 ajit},               
{"sra",       F3(2,0x27,1),                         F3(~2,~0x27,~1)|(1<<12)|(0x7f<<5),             "1,X,d",         0,                 ajit},               
{"srad",      F5(2,0x27,0,0x1),                     F5(~2,~0x27,~0,~0x1),                          "1,2,d",         0,                 ajit},               /*AJIT*/
{"srad",      F5(2,0x27,1,0x1),                     F5(~2,~0x27,~1,~0x1),                          "1,Y,d",         0,                 ajit},               /*AJIT*/
{"srl",       F3(2,0x26,0),                         F3(~2,~0x26,~0)|(1<<12)|(0x7f<<5),             "1,2,d",         0,                 ajit},               
{"srl",       F3(2,0x26,1),                         F3(~2,~0x26,~1)|(1<<12)|(0x7f<<5),             "1,X,d",         0,                 ajit},               
{"srld",      F5(2,0x26,0,0x1),                     F5(~2,~0x26,~0,~0x1),                          "1,2,d",         0,                 ajit},               /*AJIT*/
{"srld",      F5(2,0x26,1,0x1),                     F5(~2,~0x26,~1,~0x1),                          "1,Y,d",         0,                 ajit},               /*AJIT*/
{"st",        F3(3,0x04,0),                         F3(~3,~0x04,~0)|ASI_RS2(~0),                   "d,[1]",         0,                 ajit},               /*std,[rs1+%g0]*/
{"st",        F3(3,0x04,0),                         F3(~3,~0x04,~0)|ASI(~0),                       "d,[1+2]",       0,                 ajit},               
{"st",        F3(3,0x04,1),                         F3(~3,~0x04,~1),                               "d,[1+i]",       0,                 ajit},               
{"st",        F3(3,0x04,1),                         F3(~3,~0x04,~1),                               "d,[i+1]",       0,                 ajit},               
{"st",        F3(3,0x04,1),                         F3(~3,~0x04,~1)|RS1_G0,                        "d,[i]",         0,                 ajit},               
{"st",        F3(3,0x04,1),                         F3(~3,~0x04,~1)|SIMM13(~0),                    "d,[1]",         0,                 ajit},               /*std,[rs1+0]*/
{"st",        F3(3,0x24,0),                         F3(~3,~0x24,~0)|ASI_RS2(~0),                   "g,[1]",         0,                 ajit},               /*std[rs1+%g0]*/
{"st",        F3(3,0x24,0),                         F3(~3,~0x24,~0)|ASI(~0),                       "g,[1+2]",       0,                 ajit},               
{"st",        F3(3,0x24,1),                         F3(~3,~0x24,~1),                               "g,[1+i]",       0,                 ajit},               
{"st",        F3(3,0x24,1),                         F3(~3,~0x24,~1),                               "g,[i+1]",       0,                 ajit},               
{"st",        F3(3,0x24,1),                         F3(~3,~0x24,~1)|RS1_G0,                        "g,[i]",         0,                 ajit},               
{"st",        F3(3,0x24,1),                         F3(~3,~0x24,~1)|SIMM13(~0),                    "g,[1]",         0,                 ajit},               /*std,[rs1+0]*/
{"st",        F3(3,0x25,0),                         F3(~3,~0x25,~0)|RD_G0|ASI_RS2(~0),             "F,[1]",         0,                 ajit},               /*std,[rs1+%g0]*/
{"st",        F3(3,0x25,0),                         F3(~3,~0x25,~0)|RD_G0|ASI(~0),                 "F,[1+2]",       0,                 ajit},               
{"st",        F3(3,0x25,1),                         F3(~3,~0x25,~1)|RD_G0,                         "F,[1+i]",       0,                 ajit},               
{"st",        F3(3,0x25,1),                         F3(~3,~0x25,~1)|RD_G0,                         "F,[i+1]",       0,                 ajit},               
{"st",        F3(3,0x25,1),                         F3(~3,~0x25,~1)|RD_G0|RS1_G0,                  "F,[i]",         0,                 ajit},               
{"st",        F3(3,0x25,1),                         F3(~3,~0x25,~1)|RD_G0|SIMM13(~0),              "F,[1]",         0,                 ajit},               /*std,[rs1+0]*/
{"st",        F3(3,0x34,0),                         F3(~3,~0x34,~0)|ASI_RS2(~0),                   "D,[1]",         0,                 ajit},               /*std,[rs1+%g0]*/
{"st",        F3(3,0x34,0),                         F3(~3,~0x34,~0)|ASI(~0),                       "D,[1+2]",       0,                 ajit},               
{"st",        F3(3,0x34,1),                         F3(~3,~0x34,~1),                               "D,[1+i]",       0,                 ajit},               
{"st",        F3(3,0x34,1),                         F3(~3,~0x34,~1),                               "D,[i+1]",       0,                 ajit},               
{"st",        F3(3,0x34,1),                         F3(~3,~0x34,~1)|RS1_G0,                        "D,[i]",         0,                 ajit},               
{"st",        F3(3,0x34,1),                         F3(~3,~0x34,~1)|SIMM13(~0),                    "D,[1]",         0,                 ajit},               /*std,[rs1+0]*/
{"st",        F3(3,0x35,0),                         F3(~3,~0x35,~0)|ASI_RS2(~0),                   "C,[1]",         0,                 ajit},               /*std,[rs1+%g0]*/
{"st",        F3(3,0x35,0),                         F3(~3,~0x35,~0)|ASI(~0),                       "C,[1+2]",       0,                 ajit},               
{"st",        F3(3,0x35,1),                         F3(~3,~0x35,~1),                               "C,[1+i]",       0,                 ajit},               
{"st",        F3(3,0x35,1),                         F3(~3,~0x35,~1),                               "C,[i+1]",       0,                 ajit},               
{"st",        F3(3,0x35,1),                         F3(~3,~0x35,~1)|RS1_G0,                        "C,[i]",         0,                 ajit},               
{"st",        F3(3,0x35,1),                         F3(~3,~0x35,~1)|SIMM13(~0),                    "C,[1]",         0,                 ajit},               /*std,[rs1+0]*/
{"sta",       F3(3,0x14,0),                         F3(~3,~0x14,~0),                               "d,[1+2]A",      0,                 ajit},               
{"sta",       F3(3,0x14,0),                         F3(~3,~0x14,~0)|RS2(~0),                       "d,[1]A",        0,                 ajit},               /*stad,[rs1+%g0]*/
{"stb",       F3(3,0x05,0),                         F3(~3,~0x05,~0)|ASI_RS2(~0),                   "d,[1]",         0,                 ajit},               /*stbd,[rs1+%g0]*/
{"stb",       F3(3,0x05,0),                         F3(~3,~0x05,~0)|ASI(~0),                       "d,[1+2]",       0,                 ajit},               
{"stb",       F3(3,0x05,1),                         F3(~3,~0x05,~1),                               "d,[1+i]",       0,                 ajit},               
{"stb",       F3(3,0x05,1),                         F3(~3,~0x05,~1),                               "d,[i+1]",       0,                 ajit},               
{"stb",       F3(3,0x05,1),                         F3(~3,~0x05,~1)|RS1_G0,                        "d,[i]",         0,                 ajit},               
{"stb",       F3(3,0x05,1),                         F3(~3,~0x05,~1)|SIMM13(~0),                    "d,[1]",         0,                 ajit},               /*stbd,[rs1+0]*/
{"stba",      F3(3,0x15,0),                         F3(~3,~0x15,~0),                               "d,[1+2]A",      0,                 ajit},               
{"stba",      F3(3,0x15,0),                         F3(~3,~0x15,~0)|RS2(~0),                       "d,[1]A",        0,                 ajit},               /*stbad,[rs1+%g0]*/
{"stbar",     F3(2,0x28,0)|RS1(0xf),                F3(~2,~0x28,~0)|RD_G0|RS1(~0xf)|SIMM13(~0),    ,                0,                 ajit},               
{"std",       F3(3,0x07,0),                         F3(~3,~0x07,~0)|ASI_RS2(~0),                   "d,[1]",         0,                 ajit},               /*stdd,[rs1+%g0]*/
{"std",       F3(3,0x07,0),                         F3(~3,~0x07,~0)|ASI(~0),                       "d,[1+2]",       0,                 ajit},               
{"std",       F3(3,0x07,1),                         F3(~3,~0x07,~1),                               "d,[1+i]",       0,                 ajit},               
{"std",       F3(3,0x07,1),                         F3(~3,~0x07,~1),                               "d,[i+1]",       0,                 ajit},               
{"std",       F3(3,0x07,1),                         F3(~3,~0x07,~1)|RS1_G0,                        "d,[i]",         0,                 ajit},               
{"std",       F3(3,0x07,1),                         F3(~3,~0x07,~1)|SIMM13(~0),                    "d,[1]",         0,                 ajit},               /*stdd,[rs1+0]*/
{"std",       F3(3,0x26,0),                         F3(~3,~0x26,~0)|ASI_RS2(~0),                   "q,[1]",         0,                 ajit},               /*stdd,[rs1+%g0]*/
{"std",       F3(3,0x26,0),                         F3(~3,~0x26,~0)|ASI(~0),                       "q,[1+2]",       0,                 ajit},               
{"std",       F3(3,0x26,1),                         F3(~3,~0x26,~1),                               "q,[1+i]",       0,                 ajit},               
{"std",       F3(3,0x26,1),                         F3(~3,~0x26,~1),                               "q,[i+1]",       0,                 ajit},               
{"std",       F3(3,0x26,1),                         F3(~3,~0x26,~1)|RS1_G0,                        "q,[i]",         0,                 ajit},               
{"std",       F3(3,0x26,1),                         F3(~3,~0x26,~1)|SIMM13(~0),                    "q,[1]",         0,                 ajit},               /*stdd,[rs1+0]*/
{"std",       F3(3,0x27,0),                         F3(~3,~0x27,~0)|ASI_RS2(~0),                   "H,[1]",         0,                 ajit},               /*stdd,[rs1+%g0]*/
{"std",       F3(3,0x27,0),                         F3(~3,~0x27,~0)|ASI(~0),                       "H,[1+2]",       0,                 ajit},               
{"std",       F3(3,0x27,1),                         F3(~3,~0x27,~1),                               "H,[1+i]",       0,                 ajit},               
{"std",       F3(3,0x27,1),                         F3(~3,~0x27,~1),                               "H,[i+1]",       0,                 ajit},               
{"std",       F3(3,0x27,1),                         F3(~3,~0x27,~1)|RS1_G0,                        "H,[i]",         0,                 ajit},               
{"std",       F3(3,0x27,1),                         F3(~3,~0x27,~1)|SIMM13(~0),                    "H,[1]",         0,                 ajit},               /*stdd,[rs1+0]*/
{"std",       F3(3,0x36,0),                         F3(~3,~0x36,~0)|ASI_RS2(~0),                   "Q,[1]",         0,                 ajit},               /*stdd,[rs1+%g0]*/
{"std",       F3(3,0x36,0),                         F3(~3,~0x36,~0)|ASI(~0),                       "Q,[1+2]",       0,                 ajit},               
{"std",       F3(3,0x36,1),                         F3(~3,~0x36,~1),                               "Q,[1+i]",       0,                 ajit},               
{"std",       F3(3,0x36,1),                         F3(~3,~0x36,~1),                               "Q,[i+1]",       0,                 ajit},               
{"std",       F3(3,0x36,1),                         F3(~3,~0x36,~1)|RS1_G0,                        "Q,[i]",         0,                 ajit},               
{"std",       F3(3,0x36,1),                         F3(~3,~0x36,~1)|SIMM13(~0),                    "Q,[1]",         0,                 ajit},               /*stdd,[rs1+0]*/
{"std",       F3(3,0x37,0),                         F3(~3,~0x37,~0)|ASI_RS2(~0),                   "D,[1]",         0,                 ajit},               /*stdd,[rs1+%g0]*/
{"std",       F3(3,0x37,0),                         F3(~3,~0x37,~0)|ASI(~0),                       "D,[1+2]",       0,                 ajit},               
{"std",       F3(3,0x37,1),                         F3(~3,~0x37,~1),                               "D,[1+i]",       0,                 ajit},               
{"std",       F3(3,0x37,1),                         F3(~3,~0x37,~1),                               "D,[i+1]",       0,                 ajit},               
{"std",       F3(3,0x37,1),                         F3(~3,~0x37,~1)|RS1_G0,                        "D,[i]",         0,                 ajit},               
{"std",       F3(3,0x37,1),                         F3(~3,~0x37,~1)|SIMM13(~0),                    "D,[1]",         0,                 ajit},               /*stdd,[rs1+0]*/
{"stda",      F3(3,0x17,0),                         F3(~3,~0x17,~0),                               "d,[1+2]A",      0,                 ajit},               
{"stda",      F3(3,0x17,0),                         F3(~3,~0x17,~0)|RS2(~0),                       "d,[1]A",        0,                 ajit},               /*stdad,[rs1+%g0]*/
{"sth",       F3(3,0x06,0),                         F3(~3,~0x06,~0)|ASI_RS2(~0),                   "d,[1]",         0,                 ajit},               /*sthd,[rs1+%g0]*/
{"sth",       F3(3,0x06,0),                         F3(~3,~0x06,~0)|ASI(~0),                       "d,[1+2]",       0,                 ajit},               
{"sth",       F3(3,0x06,1),                         F3(~3,~0x06,~1),                               "d,[1+i]",       0,                 ajit},               
{"sth",       F3(3,0x06,1),                         F3(~3,~0x06,~1),                               "d,[i+1]",       0,                 ajit},               
{"sth",       F3(3,0x06,1),                         F3(~3,~0x06,~1)|RS1_G0,                        "d,[i]",         0,                 ajit},               
{"sth",       F3(3,0x06,1),                         F3(~3,~0x06,~1)|SIMM13(~0),                    "d,[1]",         0,                 ajit},               /*sthd,[rs1+0]*/
{"stha",      F3(3,0x16,0),                         F3(~3,~0x16,~0),                               "d,[1+2]A",      0,                 ajit},               
{"stha",      F3(3,0x16,0),                         F3(~3,~0x16,~0)|RS2(~0),                       "d,[1]A",        0,                 ajit},               /*stha,[rs1+%g0]*/
{"stsb",      F3(3,0x05,0),                         F3(~3,~0x05,~0)|ASI_RS2(~0),                   "d,[1]",         F_ALIAS,           ajit},               /*stbd,[rs1+%g0]*/
{"stsb",      F3(3,0x05,0),                         F3(~3,~0x05,~0)|ASI(~0),                       "d,[1+2]",       F_ALIAS,           ajit},               
{"stsb",      F3(3,0x05,1),                         F3(~3,~0x05,~1),                               "d,[1+i]",       F_ALIAS,           ajit},               
{"stsb",      F3(3,0x05,1),                         F3(~3,~0x05,~1),                               "d,[i+1]",       F_ALIAS,           ajit},               
{"stsb",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|RS1_G0,                        "d,[i]",         F_ALIAS,           ajit},               
{"stsb",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|SIMM13(~0),                    "d,[1]",         F_ALIAS,           ajit},               /*stbd,[rs1+0]*/
{"stsba",     F3(3,0x15,0),                         F3(~3,~0x15,~0),                               "d,[1+2]A",      F_ALIAS,           ajit},               
{"stsba",     F3(3,0x15,0),                         F3(~3,~0x15,~0)|RS2(~0),                       "d,[1]A",        F_ALIAS,           ajit},               /*stbad,[rs1+%g0]*/
{"stsh",      F3(3,0x06,0),                         F3(~3,~0x06,~0)|ASI_RS2(~0),                   "d,[1]",         F_ALIAS,           ajit},               /*sthd,[rs1+%g0]*/
{"stsh",      F3(3,0x06,0),                         F3(~3,~0x06,~0)|ASI(~0),                       "d,[1+2]",       F_ALIAS,           ajit},               
{"stsh",      F3(3,0x06,1),                         F3(~3,~0x06,~1),                               "d,[1+i]",       F_ALIAS,           ajit},               
{"stsh",      F3(3,0x06,1),                         F3(~3,~0x06,~1),                               "d,[i+1]",       F_ALIAS,           ajit},               
{"stsh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|RS1_G0,                        "d,[i]",         F_ALIAS,           ajit},               
{"stsh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|SIMM13(~0),                    "d,[1]",         F_ALIAS,           ajit},               /*sthd,[rs1+0]*/
{"stsha",     F3(3,0x16,0),                         F3(~3,~0x16,~0),                               "d,[1+2]A",      F_ALIAS,           ajit},               
{"stsha",     F3(3,0x16,0),                         F3(~3,~0x16,~0)|RS2(~0),                       "d,[1]A",        F_ALIAS,           ajit},               /*stha,[rs1+%g0]*/
{"stub",      F3(3,0x05,0),                         F3(~3,~0x05,~0)|ASI_RS2(~0),                   "d,[1]",         F_ALIAS,           ajit},               /*stbd,[rs1+%g0]*/
{"stub",      F3(3,0x05,0),                         F3(~3,~0x05,~0)|ASI(~0),                       "d,[1+2]",       F_ALIAS,           ajit},               
{"stub",      F3(3,0x05,1),                         F3(~3,~0x05,~1),                               "d,[1+i]",       F_ALIAS,           ajit},               
{"stub",      F3(3,0x05,1),                         F3(~3,~0x05,~1),                               "d,[i+1]",       F_ALIAS,           ajit},               
{"stub",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|RS1_G0,                        "d,[i]",         F_ALIAS,           ajit},               
{"stub",      F3(3,0x05,1),                         F3(~3,~0x05,~1)|SIMM13(~0),                    "d,[1]",         F_ALIAS,           ajit},               /*stbd,[rs1+0]*/
{"stuba",     F3(3,0x15,0),                         F3(~3,~0x15,~0),                               "d,[1+2]A",      F_ALIAS,           ajit},               
{"stuba",     F3(3,0x15,0),                         F3(~3,~0x15,~0)|RS2(~0),                       "d,[1]A",        F_ALIAS,           ajit},               /*stbad,[rs1+%g0]*/
{"stuh",      F3(3,0x06,0),                         F3(~3,~0x06,~0)|ASI_RS2(~0),                   "d,[1]",         F_ALIAS,           ajit},               /*sthd,[rs1+%g0]*/
{"stuh",      F3(3,0x06,0),                         F3(~3,~0x06,~0)|ASI(~0),                       "d,[1+2]",       F_ALIAS,           ajit},               
{"stuh",      F3(3,0x06,1),                         F3(~3,~0x06,~1),                               "d,[1+i]",       F_ALIAS,           ajit},               
{"stuh",      F3(3,0x06,1),                         F3(~3,~0x06,~1),                               "d,[i+1]",       F_ALIAS,           ajit},               
{"stuh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|RS1_G0,                        "d,[i]",         F_ALIAS,           ajit},               
{"stuh",      F3(3,0x06,1),                         F3(~3,~0x06,~1)|SIMM13(~0),                    "d,[1]",         F_ALIAS,           ajit},               /*sthd,[rs1+0]*/
{"stuha",     F3(3,0x16,0),                         F3(~3,~0x16,~0),                               "d,[1+2]A",      F_ALIAS,           ajit},               
{"stuha",     F3(3,0x16,0),                         F3(~3,~0x16,~0)|RS2(~0),                       "d,[1]A",        F_ALIAS,           ajit},               /*stha,[rs1+%g0]*/
{"sub",       F3(2,0x04,0),                         F3(~2,~0x04,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"sub",       F3(2,0x04,1),                         F3(~2,~0x04,~1),                               "1,i,d",         0,                 ajit},               
{"subcc",     F3(2,0x14,0),                         F3(~2,~0x14,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"subcc",     F3(2,0x14,1),                         F3(~2,~0x14,~1),                               "1,i,d",         0,                 ajit},               
{"subd",      F4(2,0x04,0,1),                       F4(~2,~0x04,~0,~1),                            "1,2,d",         0,                 ajit},/*AJIT*/,      
{"subdcc",    F4(2,0x14,0,1),                       F4(~2,~0x14,~0,~1),                            "1,2,d",         0,                 ajit},/*AJIT*/,      
{"subx",      F3(2,0x0c,0),                         F3(~2,~0x0c,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"subx",      F3(2,0x0c,1),                         F3(~2,~0x0c,~1),                               "1,i,d",         0,                 ajit},               
{"subxcc",    F3(2,0x1c,0),                         F3(~2,~0x1c,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"subxcc",    F3(2,0x1c,1),                         F3(~2,~0x1c,~1),                               "1,i,d",         0,                 ajit},               
{"swap",      F3(3,0x0f,0),                         F3(~3,~0x0f,~0)|ASI_RS2(~0),                   "[1],d",         0,                 ajit},               /*swap[rs1+%g0],d*/
{"swap",      F3(3,0x0f,0),                         F3(~3,~0x0f,~0)|ASI(~0),                       "[1+2],d",       0,                 ajit},               
{"swap",      F3(3,0x0f,1),                         F3(~3,~0x0f,~1),                               "[1+i],d",       0,                 ajit},               
{"swap",      F3(3,0x0f,1),                         F3(~3,~0x0f,~1),                               "[i+1],d",       0,                 ajit},               
{"swap",      F3(3,0x0f,1),                         F3(~3,~0x0f,~1)|RS1_G0,                        "[i],d",         0,                 ajit},               
{"swap",      F3(3,0x0f,1),                         F3(~3,~0x0f,~1)|SIMM13(~0),                    "[1],d",         0,                 ajit},               /*swap[rs1+0],d*/
{"swapa",     F3(3,0x1f,0),                         F3(~3,~0x1f,~0),                               "[1+2]A,d",      0,                 ajit},               
{"swapa",     F3(3,0x1f,0),                         F3(~3,~0x1f,~0)|RS2(~0),                       "[1]A,d",        0,                 ajit},               /*swapa[rs1+%g0],d*/
{"taddcc",    F3(2,0x20,0),                         F3(~2,~0x20,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"taddcc",    F3(2,0x20,1),                         F3(~2,~0x20,~1),                               "1,i,d",         0,                 ajit},               
{"taddcc",    F3(2,0x20,1),                         F3(~2,~0x20,~1),                               "i,1,d",         0,                 ajit},               
{"taddcctv",  F3(2,0x22,0),                         F3(~2,~0x22,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"taddcctv",  F3(2,0x22,1),                         F3(~2,~0x22,~1),                               "1,i,d",         0,                 ajit},               
{"taddcctv",  F3(2,0x22,1),                         F3(~2,~0x22,~1),                               "i,1,d",         0,                 ajit},               
{"tst",       F3(2,0x12,0),                         F3(~2,~0x12,~0)|RD_G0|ASI_RS2(~0),             "1",             0,                 ajit},               /*orccrs1,%g0,%g0*/
{"tst",       F3(2,0x12,0),                         F3(~2,~0x12,~0)|RD_G0|RS1_G0|ASI(~0),          "2",             0,                 ajit},               /*orcc%g0,rs2,%g0*/
{"tst",       F3(2,0x12,1),                         F3(~2,~0x12,~1)|RD_G0|SIMM13(~0),              "1",             0,                 ajit},               /*orccrs1,0,%g0*/
{"tsubcc",    F3(2,0x21,0),                         F3(~2,~0x21,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"tsubcc",    F3(2,0x21,1),                         F3(~2,~0x21,~1),                               "1,i,d",         0,                 ajit},               
{"tsubcctv",  F3(2,0x23,0),                         F3(~2,~0x23,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"tsubcctv",  F3(2,0x23,1),                         F3(~2,~0x23,~1),                               "1,i,d",         0,                 ajit},               
{"udiv",      F3(2,0x0e,0),                         F3(~2,~0x0e,~0)|ASI(~0),                       "1,2,d",         F_DIV32,           ajit},               
{"udiv",      F3(2,0x0e,1),                         F3(~2,~0x0e,~1),                               "1,i,d",         F_DIV32,           ajit},               
{"udiv",      F3(2,0x0e,1),                         F3(~2,~0x0e,~1),                               "i,1,d",         F_DIV32,           ajit},               
{"udivcc",    F3(2,0x1e,0),                         F3(~2,~0x1e,~0)|ASI(~0),                       "1,2,d",         F_DIV32,           ajit},               
{"udivcc",    F3(2,0x1e,1),                         F3(~2,~0x1e,~1),                               "1,i,d",         F_DIV32,           ajit},               
{"udivcc",    F3(2,0x1e,1),                         F3(~2,~0x1e,~1),                               "i,1,d",         F_DIV32,           ajit},               
{"udivd",     F4(2,0x0e,0,1),                       F4(~2,~0x0e,~0,~1),                            "1,2,d",         F_DIV32,           ajit},/*AJIT*/,      
{"udivdcc",   F4(2,0x1e,0,1),                       F4(~2,~0x1e,~0,~1),                            "1,2,d",         F_DIV32,           ajit},/*AJIT*/,      
{"umul",      F3(2,0x0a,0),                         F3(~2,~0x0a,~0)|ASI(~0),                       "1,2,d",         F_MUL32,           ajit},               
{"umul",      F3(2,0x0a,1),                         F3(~2,~0x0a,~1),                               "1,i,d",         F_MUL32,           ajit},               
{"umul",      F3(2,0x0a,1),                         F3(~2,~0x0a,~1),                               "i,1,d",         F_MUL32,           ajit},               
{"umulcc",    F3(2,0x1a,0),                         F3(~2,~0x1a,~0)|ASI(~0),                       "1,2,d",         F_MUL32,           ajit},               
{"umulcc",    F3(2,0x1a,1),                         F3(~2,~0x1a,~1),                               "1,i,d",         F_MUL32,           ajit},               
{"umulcc",    F3(2,0x1a,1),                         F3(~2,~0x1a,~1),                               "i,1,d",         F_MUL32,           ajit},               
{"umuld",     F4(2,0x0a,0,1),                       F4(~2,~0x0a,~0,~1),                            "1,2,d",         F_MUL32,           ajit},/*AJIT*/,      
{"umuldcc",   F4(2,0x1a,0,1),                       F4(~2,~0x1a,~0,~1),                            "1,2,d",         F_MUL32,           ajit},/*AJIT*/,      
{"unimp",     F2(0x0,0x0),                          0xffc00000,                                    n,               0,                 ajit},               
{"vaddd16",   F6(2,0x00,0,2,2),                     F6(~2,~0x00,~0,~2,~2),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vaddd32",   F6(2,0x00,0,2,4),                     F6(~2,~0x00,~0,~2,~4),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vaddd8",    F6(2,0x00,0,2,1),                     F6(~2,~0x00,~0,~2,~1),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vsmuld16",  F6(2,0x1a,0,2,2),                     F6(~2,~0x1a,~0,~2,~3),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vsmuld32",  F6(2,0x1a,0,2,4),                     F6(~2,~0x1a,~0,~2,~4),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vsmuld8",   F6(2,0x1a,0,2,1),                     F6(~2,~0x1a,~0,~2,~1),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vsubd16",   F6(2,0x04,0,2,2),                     F6(~2,~0x04,~0,~2,~3),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vsubd32",   F6(2,0x04,0,2,4),                     F6(~2,~0x04,~0,~2,~4),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vsubd8",    F6(2,0x04,0,2,1),                     F6(~2,~0x04,~0,~2,~1),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vumuld16",  F6(2,0x0a,0,2,2),                     F6(~2,~0x0a,~0,~2,~3),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vumuld32",  F6(2,0x0a,0,2,4),                     F6(~2,~0x0a,~0,~2,~4),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"vumuld8",   F6(2,0x0a,0,2,1),                     F6(~2,~0x0a,~0,~2,~1),                         "1,2,d",         0,                 ajit},/*AJIT*/,      
{"wr",        F3(2,0x30,0),                         F3(~2,~0x30,~0)|ASI_RS2(~0),                   "1,m",           F_ALIAS,           ajit},               /*wrrs1,%g0,%asrX*/
{"wr",        F3(2,0x30,0),                         F3(~2,~0x30,~0)|ASI(~0),                       "1,2,m",         0,                 ajit},               /*wrr,r,%asrX*/
{"wr",        F3(2,0x30,0),                         F3(~2,~0x30,~0)|RD_G0|ASI_RS2(~0),             "1,y",           F_ALIAS,           ajit},               /*wrrs1,%g0,%y*/
{"wr",        F3(2,0x30,0),                         F3(~2,~0x30,~0)|RD_G0|ASI(~0),                 "1,2,y",         0,                 ajit},               /*wrr,r,%y*/
{"wr",        F3(2,0x30,0),                         F3(~2,~0x30,~0)|RD_G0|RS1_G0|ASI(~0),          "2,y",           F_ALIAS,           ajit},               /*wr%g0,rs2,%y*/
{"wr",        F3(2,0x30,0),                         F3(~2,~0x30,~0)|RS1_G0|ASI(~0),                "2,m",           F_ALIAS,           ajit},               /*wr%g0,rs2,%asrX*/
{"wr",        F3(2,0x30,1),                         F3(~2,~0x30,~1),                               "1,i,m",         0,                 ajit},               /*wrr,i,%asrX*/
{"wr",        F3(2,0x30,1),                         F3(~2,~0x30,~1)|RD_G0,                         "1,i,y",         0,                 ajit},               /*wrr,i,%y*/
{"wr",        F3(2,0x30,1),                         F3(~2,~0x30,~1)|RD_G0|RS1_G0,                  "i,y",           F_ALIAS,           ajit},               /*wr%g0,i,%y*/
{"wr",        F3(2,0x30,1),                         F3(~2,~0x30,~1)|RS1_G0,                        "i,m",           F_ALIAS,           ajit},               /*wr%g0,i,%asrX*/
{"wr",        F3(2,0x31,0),                         F3(~2,~0x31,~0)|RD_G0|ASI_RS2(~0),             "1,p",           F_ALIAS,           ajit},               /*wrrs1,%g0,%psr*/
{"wr",        F3(2,0x31,0),                         F3(~2,~0x31,~0)|RD_G0|ASI(~0),                 "1,2,p",         0,                 ajit},               /*wrr,r,%psr*/
{"wr",        F3(2,0x31,0),                         F3(~2,~0x31,~0)|RD_G0|RS1_G0|ASI(~0),          "2,p",           F_ALIAS,           ajit},               /*wr%g0,rs2,%psr*/
{"wr",        F3(2,0x31,1),                         F3(~2,~0x31,~1)|RD_G0,                         "1,i,p",         0,                 ajit},               /*wrr,i,%psr*/
{"wr",        F3(2,0x31,1),                         F3(~2,~0x31,~1)|RD_G0|RS1_G0,                  "i,p",           F_ALIAS,           ajit},               /*wr%g0,i,%psr*/
{"wr",        F3(2,0x32,0),                         F3(~2,~0x32,~0)|RD_G0|ASI_RS2(~0),             "1,w",           F_ALIAS,           ajit},               /*wrrs1,%g0,%wim*/
{"wr",        F3(2,0x32,0),                         F3(~2,~0x32,~0)|RD_G0|ASI(~0),                 "1,2,w",         0,                 ajit},               /*wrr,r,%wim*/
{"wr",        F3(2,0x32,0),                         F3(~2,~0x32,~0)|RD_G0|RS1_G0|ASI(~0),          "2,w",           F_ALIAS,           ajit},               /*wr%g0,rs2,%wim*/
{"wr",        F3(2,0x32,1),                         F3(~2,~0x32,~1)|RD_G0,                         "1,i,w",         0,                 ajit},               /*wrr,i,%wim*/
{"wr",        F3(2,0x32,1),                         F3(~2,~0x32,~1)|RD_G0|RS1_G0,                  "i,w",           F_ALIAS,           ajit},               /*wr%g0,i,%wim*/
{"wr",        F3(2,0x33,0),                         F3(~2,~0x33,~0)|RD_G0|ASI_RS2(~0),             "1,t",           F_ALIAS,           ajit},               /*wrrs1,%g0,%tbr*/
{"wr",        F3(2,0x33,0),                         F3(~2,~0x33,~0)|RD_G0|ASI(~0),                 "1,2,t",         0,                 ajit},               /*wrr,r,%tbr*/
{"wr",        F3(2,0x33,0),                         F3(~2,~0x33,~0)|RD_G0|RS1_G0|ASI(~0),          "2,t",           F_ALIAS,           ajit},               /*wr%g0,rs2,%tbr*/
{"wr",        F3(2,0x33,1),                         F3(~2,~0x33,~1)|RD_G0,                         "1,i,t",         0,                 ajit},               /*wrr,i,%tbr*/
{"wr",        F3(2,0x33,1),                         F3(~2,~0x33,~1)|RD_G0|RS1_G0,                  "i,t",           F_ALIAS,           ajit},               /*wr%g0,i,%tbr*/
{"xnor",      F3(2,0x07,0),                         F3(~2,~0x07,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"xnor",      F3(2,0x07,1),                         F3(~2,~0x07,~1),                               "1,i,d",         0,                 ajit},               
{"xnor",      F3(2,0x07,1),                         F3(~2,~0x07,~1),                               "i,1,d",         0,                 ajit},               
{"xnorcc",    F3(2,0x17,0),                         F3(~2,~0x17,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"xnorcc",    F3(2,0x17,1),                         F3(~2,~0x17,~1),                               "1,i,d",         0,                 ajit},               
{"xnorcc",    F3(2,0x17,1),                         F3(~2,~0x17,~1),                               "i,1,d",         0,                 ajit},               
{"xnord",     F4(2,0x07,0,1),                       F4(~2,~0x07,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"xnordcc",   F4(2,0x17,0,1),                       F4(~2,~0x17,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
{"xor",       F3(2,0x03,0),                         F3(~2,~0x03,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"xor",       F3(2,0x03,1),                         F3(~2,~0x03,~1),                               "1,i,d",         0,                 ajit},               
{"xor",       F3(2,0x03,1),                         F3(~2,~0x03,~1),                               "i,1,d",         0,                 ajit},               
{"xorcc",     F3(2,0x13,0),                         F3(~2,~0x13,~0)|ASI(~0),                       "1,2,d",         0,                 ajit},               
{"xorcc",     F3(2,0x13,1),                         F3(~2,~0x13,~1),                               "1,i,d",         0,                 ajit},               
{"xorcc",     F3(2,0x13,1),                         F3(~2,~0x13,~1),                               "i,1,d",         0,                 ajit},               
{"xordcc",    F4(2,0x13,0,1),                       F4(~2,~0x13,~0,~1),                            "1,2,d",         0,                 ajit},               /*AJIT*/
