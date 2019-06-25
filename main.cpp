#include <iostream>
#include <fstream>
#include "VM.h"


int main(int args, char **argv) {

    vm::VM *vm1 = new vm::VM();



    if (args > 1) {
        // load program from binary file
        vm1->load_program_from_file(argv[1]);

    }else{

        // load sample program (fibonacci series)
        vm1->load_program();

        // save executable
        vm1->save_program(0, 13, "fibonacci.vmc");
    }

    vm1->set_program_counter(6);



//    vm1->print_memory();

    while (vm1->isRunning()) {
        vm1->fetch_inst();
        if (!vm1->isRunning())break;

        vm1->decode_inst();
        if (!vm1->isRunning())break;


        vm1->execute();
    }

    if (vm1->error) {
        std::cout << vm1->error_msg << std::endl;
    }
}
