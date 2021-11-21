//
// Created by bruno on 28.04.2021.
//

#ifndef UNTITLED8_CARD_H
#define UNTITLED8_CARD_H
#include <string>
#include <vector>
#include <algorithm>
#include <random>


struct card{
    int cost;
    std::string name;
    int attack;
    int toughness;
    std::string description;

};

std::vector<card> getAllCards(){

    std::vector<card> vec{

        card{1,"Blood Knight",3,1,"adsas"},
        card{3,"Brewmaster",2,6,"czxczq"},
        card{2,"Cenarius",2,1,"sdqwdqwq"},
        card{2,"Dire Wolf Alpha",6,2,"igpop"},
        card{2,"Dust Devil",5,4,"dsaqqqq"},
        card{6,"Emerald Drake",5,6,"zzzzzx"},
        card{5,"Fen Creeper",1,7,"aaaaaaaaaaa"},
        card{1,"Gnoll",1,7,"sfwwwwwwwwwr"},
        card{1,"Imp",2,1,"ggghh"},
        card{3,"Deathwing",3,4,"tttttttttttre"},






    };

    return vec;


}


std::vector<std::vector<card>> getSamplehands(int p ){
        std::vector<card> card_pool = getAllCards();

        std::vector<std::vector<card>> hands;

        for(int i =0;i<p;i++){

            std::vector<card> hand;
            std::sample(card_pool.begin(),card_pool.end(),std::back_inserter(hand),7, std::random_device());


            hands.push_back(hand);

        }


    return hands;


}




#endif //UNTITLED8_CARD_H
