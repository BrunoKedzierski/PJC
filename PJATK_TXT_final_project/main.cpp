#include <iostream>
#include <vector>
#include <fstream>
#include "text_manipulations.h"
#include "legal_flags.h"
#include "driver.h"

int main(int args_count, const char* args[]) {



        if (pjatxt_driver::validate_flags(args_count, args)) {

            auto parsed_arguments = pjatxt_driver::parse(args_count, args);
             if (pjatxt_driver::validate_args(parsed_arguments))
                       pjatxt_driver::execute(parsed_arguments);
        }


}






