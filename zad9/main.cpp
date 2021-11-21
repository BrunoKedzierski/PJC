#include <iostream>
#include "student.h"
#include "operations.h"
#include "vector"

std::vector<int> fill_range(const std::vector<int> &v, int start, int inc){

    auto result = std::vector<int>();

    result.push_back(start);
    start+=inc;
    for(int i = 1; i <v.size();i++){

        result.push_back(start);


        start+=inc;


    }
    return result;

}


namespace myStudent{
void set_all(myStudent::student &st, std::string str1,std::string str2, int a){

    st.name = str1;
    st.surname = str2;
    st.age = a;

}
}



int main() {
   auto st = myStudent::student("papiez","polak",55);
    auto st2 = myStudent::student("papiez","niemiec",12);

    std::cout<<model::predicates::is_of_legal_age(st)<<"\n";
    std::cout<<model::predicates::is_of_legal_age(st2)<<"\n";


    std::cout<<model::mappers::to_string(st)<<"\n";
    std::cout<<model::mappers::to_string(st2)<<"\n";

    23;





}
