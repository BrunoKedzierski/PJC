//
// Created by bruno on 28.04.2021.
//

#ifndef UNTITLED8_OPERATIONS_H
#define UNTITLED8_OPERATIONS_H
#include "card.h"
#include <string>
#include <vector>
#include <algorithm>
#include <random>


enum class comparing_by{Cost,Name,Description,Attack,Toughness};



auto get_nameComparator(){


    return [](card c1, card c2){

        return c1.name < c2.name;


    };


}


auto get_descriptionComparator(){


    return [](card c1, card c2){

        return c1.name < c2.name;


    };


}

auto get_attackComparator(){


    return [](card c1, card c2){

        return c1.attack < c2.attack;


    };


}


auto get_costComparator(){


    return [](card c1, card c2){

        return c1.attack < c2.attack;



    };


}

auto get_toughnessComparator(){


    return [](card c1, card c2){

        return c1.toughness < c2.toughness;


    };


}


#endif //UNTITLED8_OPERATIONS_H
