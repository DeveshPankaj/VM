//
// Created by devesh on 24/6/19.
//


#include "VM.h"

#define DEBUG false
#define __on_debug if(DEBUG)

vm::VM::VM() {
    this->memory_size = 16 * 16 + 1;
    this->memory = new data_block[memory_size];
    this->program_counter = 0;
    this->hlt = false;
    this->error = false;
}

void vm::VM::print_memory() {
    for (vm::data_block i = 0; i < this->memory_size; i++) {
        std::cout << this->memory[i] << " ";
        if (i % 8 == 0)std::cout << std::endl;
    }
}


void vm::VM::fetch_inst() {
    this->current_instruction = this->memory[this->program_counter];
    this->program_counter++;
    this->check_program_counter();
}

void vm::VM::decode_inst() {
    this->inst = (this->current_instruction & 0xf0000000); // instruction
    this->memo = (this->current_instruction & 0x0f000000); // memory allocation
    this->r1 = (this->current_instruction & 0x00ff0000); // source 1
    this->r2 = (this->current_instruction & 0x0000ff00); // source 2
    this->r3 = (this->current_instruction & 0x000000ff); // destination
    this->load_register();
}

void vm::VM::execute() {
    switch (this->inst) {
        case NUL:
            std::cout << "inst:0" << std::endl;
            break;

        case ADD:
            __on_debug std::cout << "inst: ADD " << this->r1 << " " << this->r2 << " " << this->r3 << " : ["
                                 << this->memory[this->r1] << " + " << this->memory[this->r2] << " => "
                                 << this->memory[this->r1] + this->memory[this->r2] << "]\n";

            // ADD
            this->memory[r3] = this->memory[this->r1] + this->memory[this->r2];

            break;

        case SUB:
            __on_debug std::cout << "inst: SUB " << this->r1 << " " << this->r2 << " " << this->r3 << " : ["
                                 << this->memory[this->r1] << " - " << this->memory[this->r2] << " => "
                                 << this->memory[this->r1] - this->memory[this->r2] << "]\n";

            // SUB
            this->memory[r3] = this->memory[this->r1] - this->memory[this->r2];
            break;

        case MUL:
            __on_debug std::cout << "inst: MUL " << this->r1 << " " << this->r2 << " " << this->r3 << " : ["
                                 << this->memory[this->r1] << " * " << this->memory[this->r2] << " => "
                                 << this->memory[this->r1] * this->memory[this->r2] << "]\n";

            // MUL
            this->memory[r3] = this->memory[this->r1] * this->memory[this->r2];
            break;

        case DIV:
            __on_debug std::cout << "inst: DIV " << this->r1 << " " << this->r2 << " " << this->r3 << " : ["
                                 << this->memory[this->r1] << " / " << this->memory[this->r2] << " => "
                                 << this->memory[this->r1] / this->memory[this->r2] << "]\n";

            // DIV
            this->memory[r3] = this->memory[this->r1] / this->memory[this->r2];
            break;

        case MOD:
            __on_debug std::cout << "inst: MOD " << this->r1 << " " << this->r2 << " " << this->r3 << " : ["
                                 << this->memory[this->r1] << " % " << this->memory[this->r2] << " => "
                                 << this->memory[this->r1] % this->memory[this->r2] << "]\n";

            // MOD
            this->memory[r3] = this->memory[this->r1] % this->memory[this->r2];
            break;

        case CMP_E:
            __on_debug std::cout << "inst: CMP_E " << this->r1 << " " << this->r2 << " " << this->r3 << " : ["
                                 << this->memory[this->r1] << " == " << this->memory[this->r2] << " => "
                                 << (this->memory[this->r1] == this->memory[this->r2]) << "]\n";

            // CMP_E
            this->memory[r3] = (this->memory[this->r1] == this->memory[this->r2]);
            break;

        case CMP_L:
            __on_debug std::cout << "inst: CMP_L " << this->memory[this->r1] << " < " << this->memory[this->r2] << " => "
                                      << (this->memory[this->r1] < this->memory[this->r2]) << "]\n";

            // CMP_L
            this->memory[r3] = (this->memory[this->r1] < this->memory[this->r2]);
            break;

        case CMP_G:
            __on_debug std::cout << "inst: CMP_G " << this->memory[this->r1] << " > " << this->memory[this->r2] << " => "
                                 << (this->memory[this->r1] > this->memory[this->r2]) << "]\n";

            // CMP_G
            this->memory[r3] = (this->memory[this->r1] > this->memory[this->r2]);
            break;

        case IF:
            __on_debug std::cout << "inst: IF " << this->r1 << ", " << this->r2 << ", " << this->memory[this->r3] << "\n";
            // set the pointer to *r1 if *r3 is true else set the pointer to *r2
            if(this->memory[this->r3]) this->program_counter = this->r1;                       // if condition always require one jump address
            else if(this->current_instruction & 0x02000000) this->program_counter = this->r2;  // jump to else if it is defined i.e. second LSB is set to 1

            // check if the invalid pointer is given
            this->check_program_counter();

            break;

        case CPY:
            __on_debug std::cout << "inst: CPY "  << this->r1 << " --> " << this->r2 << " : " << this->memory[this->r1] << " " << this->memory[this->r2] << std::endl;

            // copy from *r1 to *r2 ,, r3 is not used
            this->memory[this->r2] = this->memory[this->r1];
            break;

        case PRINT:
            __on_debug std::cout << "inst: PRINT " << std::endl;

            std::cout << this->memory[this->r1] << " ";
            break;

        case 0xc0000000:
            __on_debug std::cout << "inst:c" << std::endl;
            break;

        case 0xd0000000:
            __on_debug std::cout << "inst:d" << std::endl;
            break;

        case 0xe0000000:
            __on_debug std::cout << "inst:e" << std::endl;
            break;

        case 0xf0000000:
            __on_debug std::cout << "inst:f" << std::endl;
            if (this->memo == 0x0f000000) this->hlt = true;
            break;


        default:
            std::cout << "inst:none" << std::endl;
    }
}


bool vm::VM::isRunning() {
    return !this->hlt;
}

void vm::VM::load_register() {
    switch (this->memo) {
        case 0x00000000:
//            std::cout << "memo:0" << std::endl;  // 00000000
            this->r1 = (this->current_instruction & R1) >> 16;
            this->r2 = (this->current_instruction & R2) >> 8;
            this->r3 = (this->current_instruction & R3) >> 0;
//            std::cout << this->r1 << " " << this->r2 << " " << this->r3 << "\n";
            break;

        case 0x01000000:
//            std::cout << "memo:1" << std::endl;  // 00000001
            this->r1 = (this->current_instruction & R1) >> 16;
            this->r2 = (this->current_instruction & R2) >> 8;
            this->r3 = (this->current_instruction & R3) >> 0;
//            std::cout << this->r1 << " " << this->r2 << " " << this->r3 << "\n";
            break;

        case 0x02000000:
            __on_debug
            std::cout << "memo:2" << std::endl;  // 00000010
            break;

        case 0x03000000:
            __on_debug
            std::cout << "memo:3" << std::endl;  // 00000011
            break;

        case 0x04000000:
            __on_debug
            std::cout << "memo:4" << std::endl;  // 00000100
            break;

        case 0x05000000:
            __on_debug
            std::cout << "memo:5" << std::endl;  // 00000101
            break;

        case 0x06000000:
            __on_debug
            std::cout << "memo:6" << std::endl;  // 00000110
            break;

        case 0x07000000:
            __on_debug
            std::cout << "memo:7" << std::endl;  // 00000111
            break;

        case 0x08000000:
            __on_debug
            std::cout << "memo:8" << std::endl;
            break;

        case 0x09000000:
            __on_debug
            std::cout << "memo:9" << std::endl;
            break;

        case 0x0a000000:
            __on_debug
            std::cout << "memo:a" << std::endl;
            break;

        case 0x0b000000:
            __on_debug
            std::cout << "memo:b" << std::endl;
            break;

        case 0x0c000000:
            __on_debug
            std::cout << "memo:c" << std::endl;
            break;

        case 0x0d000000:
            __on_debug
            std::cout << "memo:d" << std::endl;
            break;

        case 0x0e000000:
            __on_debug
            std::cout << "memo:e" << std::endl;
            break;

        case 0x0f000000:
            __on_debug
            std::cout << "\nmemo:f" << std::endl;
            break;


        default:
            __on_debug
            std::cout << "memo:none" << std::endl;
    }
}


vm::data_block vm::VM::make_inst(vm::data_block inst, vm::data_block r1, vm::data_block r2, vm::data_block r3) {
    if (((r1 | r2 | r3) & 0xffffff00) != 0) {
        this->hlt = true;
        this->error = true;
        this->error_msg =
                "pointer out of memory [ r1: " + std::to_string(r1) + ", r2: " + std::to_string(r2) + ", r3: " +
                std::to_string(r3) + " ]";
    }
    return (inst | r1 << 16 | r2 << 8 | r3 << 0);
}


void vm::VM::load_program() {
    // __data_section
    this->memory[0] = this->make_inst(0);   // a
    this->memory[1] = this->make_inst(1);   // b
    this->memory[2] = this->make_inst(0);   // temp

    // constants
    this->memory[3] = this->make_inst(1);   // 1
    this->memory[4] = this->make_inst(0);   // 0

    // loop counter
    this->memory[5] = this->make_inst(20);

    this->memory[6] = this->make_inst(ADD, 0, 1, 2);    // (instruction, 0...255, 0...255, 0...255)
    this->memory[7] = this->make_inst(CPY, 1, 0, NUL);
    this->memory[8] = this->make_inst(CPY, 2, 1, NUL);

    this->memory[9] = this->make_inst(SUB, 5, 3, 5);
    this->memory[10] = this->make_inst(CMP_G, 5, 4, 2);
    this->memory[11] = this->make_inst(PRINT, 0);
    this->memory[12] = this->make_inst(IF, 6, 13, 2);

    this->memory[13] = this->make_inst(HLT, NUL, NUL, NUL);
}




void vm::VM::set_program_counter(vm::data_block pc) {
    this->program_counter = pc;
}


void vm::VM::check_program_counter() {
    if (this->program_counter >= this->memory_size) {
        this->hlt = true;
        this->error = true;
        this->error_msg = "error:invalid_pointer";
    }
}

void vm::VM::load_program_from_file(std::string file_name) {
    int64_t size;
    std::ifstream infile;
    infile.open(file_name, std::ios::in|std::ios::binary|std::ios::ate);

    infile.seekg(0, std::ios::end);
    size = infile.tellg();
    infile.seekg(0, std::ios::beg);
//    std::cout << "size " << size << '\n';

    int64_t program[size+1];

    this->memory = new vm::data_block[size+1];

    infile.read((char*)this->memory, size);

    infile.close();

//    size = size / sizeof(int64_t);
//    for(int i=0; i < size; i++){
//        std::cout << program[i] << '\n';
//    }
}
