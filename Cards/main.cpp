#include <iostream>
#include "card.h"
#include "operations.h"

std::vector<card> sorted(std::vector<card> cards, comparing_by cond){


    switch (cond) {

        case comparing_by::Name:
            std::sort(cards.begin(),cards.end(),get_nameComparator());
            break;
        case comparing_by::Cost:
            std::sort(cards.begin(),cards.end(),get_costComparator());
            break;
        case comparing_by::Attack:
            std::sort(cards.begin(),cards.end(),get_attackComparator());
            break;
        case comparing_by::Toughness:
            std::sort(cards.begin(),cards.end(),get_toughnessComparator());
            break;
        case comparing_by::Description:
            std::sort(cards.begin(),cards.end(),get_descriptionComparator());
            break;
        
    }

    return cards;
}


card get_min(std::vector<card> cards, comparing_by cond){
    card c;

    switch (cond) {

        case comparing_by::Name:
            c = *std::min_element(cards.begin(),cards.end(),get_nameComparator());
            break;
        case comparing_by::Cost:
            c = *std::min_element(cards.begin(),cards.end(),get_costComparator());
            break;
        case comparing_by::Attack:
            c = *std::min_element(cards.begin(),cards.end(),get_attackComparator());
            break;
        case comparing_by::Toughness:
            c = *std::min_element(cards.begin(),cards.end(),get_toughnessComparator());
            break;
        case comparing_by::Description:
            c = *std::min_element(cards.begin(),cards.end(),get_descriptionComparator());
            break;

    }

    return c;
}

card get_max(std::vector<card> cards, comparing_by cond){
    card c;

    switch (cond) {

        case comparing_by::Name:
            c = *std::max_element(cards.begin(),cards.end(),get_nameComparator());
            break;
        case comparing_by::Cost:
            c = *std::max_element(cards.begin(),cards.end(),get_costComparator());
            break;
        case comparing_by::Attack:
            c = *std::max_element(cards.begin(),cards.end(),get_attackComparator());
            break;
        case comparing_by::Toughness:
            c = *std::max_element(cards.begin(),cards.end(),get_toughnessComparator());
            break;
        case comparing_by::Description:
            c = *std::min_element(cards.begin(),cards.end(),get_descriptionComparator());
            break;

    }

    return c;
}

int main() {






}
