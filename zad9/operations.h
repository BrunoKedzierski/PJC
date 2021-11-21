//
// Created by bruno on 29.05.2021.
//

#ifndef UNTITLED12_OPERATIONS_H
#define UNTITLED12_OPERATIONS_H
#include "student.h"



namespace model{



    namespace predicates {


        bool is_of_legal_age(const myStudent::student &st);
    }

    namespace mappers{
        std::string to_string(const myStudent::student& st);

    }
}
#endif //UNTITLED12_OPERATIONS_H
