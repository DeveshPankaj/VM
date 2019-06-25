//
// Created by devesh on 24/6/19.
//

#ifndef FALTU_C_VM_H
#define FALTU_C_VM_H

#include <stack>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "VM-inst.h"

namespace vm {
//    enum {          // inst r1 r2 r3
//        stack,      // 0x00 00 00 00
//        memory      // 0x10 00 00 00
//    };

    typedef int64_t data_block;


    class VM {
        std:: stack<vm::data_block> stack1;             // data stack
        std:: stack<vm::data_block> stack2;             // program stack
        data_block * memory;            // program memory
        data_block memory_size;
        data_block program_counter;
        data_block current_instruction;
        data_block inst;
        data_block r1;
        data_block r2;
        data_block r3;
        data_block memo;
        bool hlt;

        void load_register();
        void check_program_counter();
        vm::data_block make_inst(vm::data_block inst, vm::data_block r1 = NUL, vm::data_block r2 = NUL, vm::data_block r3 = NUL);

    public:
        std::string error_msg;
        vm::data_block exit_code;
        bool error;

        VM();
        void load_program();
        void print_memory();
        void fetch_inst();
        void decode_inst();
        void execute();

        bool isRunning();

        void set_program_counter(vm::data_block);

        void load_program_from_file(std::string);

        // just for debugging
        void save_program(int from, int to, std::string file_name) {
            int64_t v;
            std::ofstream file;
            file.open(file_name, std::ios::out | std::ios::binary);

            for(;from <= to; from++) {
                v = this->memory[from];
                file.write((char*)&v, sizeof(int64_t));
            }
            file.close();
        }
    };
}




#endif //FALTU_C_VM_H
