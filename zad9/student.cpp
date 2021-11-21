//
// Created by bruno on 29.05.2021.
//

#include "student.h"

namespace myStudent {
    const std::string &student::getName() const {
        return name;
    }

    void student::setName(const std::string &name) {
        student::name = name;
    }

    const std::string &student::getSurname() const {
        return surname;
    }

    void student::setSurname(const std::string &surname) {
        student::surname = surname;
    }

    int student::getAge() const {
        return age;
    }

    void student::setAge(int age) {
        student::age = age;
    }

    student::student(const std::string &name, const std::string &surname, int age) : name(name), surname(surname),
                                                                                     age(age) {}

    student::student() {}
}
