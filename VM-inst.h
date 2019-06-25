//
// Created by devesh on 25/6/19.
//

#ifndef FALTU_C_VM_INST_H
#define FALTU_C_VM_INST_H

#define NUL 0x00000000
#define ADD 0x10000000
#define SUB 0x20000000
#define MUL 0x30000000
#define DIV 0x40000000
#define MOD 0x50000000

#define CMP_E 0x60000000 // set *r3
#define CMP_L 0x70000000
#define CMP_G 0x80000000

                        // inst r1 r2 r3
#define IF 0x90000000   // 0x90 00 00 00 , inst = (1001) 00i0  'i' bit represent the else condition
#define CPY 0xa0000000  // 0xa0 00 00 00 , copy from *r1 to *r2 ,, r3 is not used
#define PRINT 0xb0000000  // print *r1 other bits will be used for formatting





#define HLT 0xff000000

#define R1 0x00ff0000
#define R2 0x0000ff00
#define R3 0x000000ff


#endif //FALTU_C_VM_INST_H
