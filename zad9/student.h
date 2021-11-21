//
// Created by bruno on 28.05.2021.
//

#ifndef UNTITLED12_STUDENT_H
#define UNTITLED12_STUDENT_H

#include <string>
namespace myStudent {
    struct student {
    private:
        std::string name;
        std::string surname;
        int age;
    public:
        const std::string &getName() const;

        void setName(const std::string &name);

        const std::string &getSurname() const;

        void setSurname(const std::string &surname);

        int getAge() const;

        void setAge(int age);

        student(const std::string &name, const std::string &surname, int age);

        student();

        void friend set_all(student &st, std::string str1, std::string str2, int a);

    };
}
#endif //UNTITLED12_STUDENT_H
