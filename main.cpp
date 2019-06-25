#include <iostream>
#include <fstream>
#include "VM.h"



int main (int args, char ** argv) {

    vm::VM * vm1 = new vm::VM();

//    vm1->load_program();
//    vm1->save_program(0, 13, "fibonacci.vmc");


    vm1->load_program_from_file("fibonacci.vmc");

    vm1->set_program_counter(6);



//    vm1->print_memory();
    printf("\n");

    while (vm1->isRunning()) {
        vm1->fetch_inst();
        if(! vm1->isRunning())break;

        vm1->decode_inst();
        if(! vm1->isRunning())break;


        vm1->execute();
    }

    if(vm1->error) {
        std::cout << vm1->error_msg << std::endl;
    }
}
