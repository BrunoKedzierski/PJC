//
// Created by bruno on 29.05.2021.
//

#include "operations.h"



bool model::predicates::is_of_legal_age(const myStudent::student &st) {

    if(st.getAge() >=18)
        return true;
    else
        return false;

}


std::string model::mappers::to_string(const myStudent::student &st) {

    return st.getName() + " " + st.getSurname() + " " + std::to_string(st.getAge());

}

