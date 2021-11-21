#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#include <math.h>
#include <set>


enum action {
    move_left =1 , move_right=-1, idle=0
};




bool effectively_idle(std::vector<std::array<action, 3>> moves){

    int counter = 0;


    for( auto &ar : moves){


            for (auto &move : ar) {

                counter+= static_cast<int>(move);

            }
        }


    if(counter ==0){
        return true;
    }
    else
        return false;


}

std::vector<std::array<action, 3>> chunk(std::vector<action> v) {
    int n = std::ceil(v.size()/3.0);
    auto res = std::vector<std::array<action,3>>(n);

    std::fill(res.begin(),res.end(),
              std::array<action,3>{action(idle),action(idle),action(idle)});






    int vector_count=0;
    int array_count = 0;

    for(auto i = v.begin(); i != v.end();++i){


        res[vector_count][array_count] = *i;

        if(array_count == 2){
            array_count =0;
            vector_count++;

        }
        else
            array_count++;



    }

    return res;
}

void show_ordered_character_occurences(std::string str){

  std::vector<std::pair<int,char>> vector;


  for(int i = 0; i < str.length();i++){



      char c = str[i];



      int number  = std::count(str.begin(), str.end(), c);

      vector.push_back(std::make_pair(number, c));

  }



  std::sort(vector.rbegin(),vector.rend());


    vector.erase( unique( vector.begin(), vector.end() ), vector.end() );



  for( auto &p : vector){

      std::cout<< "Character: " << p.second << " Occurence: " << p.first<<"\n";



  }








}


bool has_balanced_brackets(std::string str, const std::map<char,char>& open_close,std::map<char,char>& close_open ) {
    std::stack<char> st;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];



    if (open_close.count(c) > 0) {
        st.push(c);

    }

     if (close_open.count(c) > 0) {

        if (close_open[c] == st.top()) {
            st.pop();
        } else

            return false;

    }
}

    if(st.empty())
        return true;
    else
        return false;



}




int main() {
   std::map<char,char> open_close;
   open_close.insert({'(',')'});
   open_close.insert({'{','}'});
   open_close.insert({'[',']'});
   open_close.insert({'<','>'});

    std::map<char,char> close_open;
    close_open.insert({')','('});
    close_open.insert({'}','{'});
    close_open.insert({']','['});
    close_open.insert({'>','<'});












}
