#include <iostream>
#include <vector>

#include "KenoBet.hpp"

using namespace std;

KenoBet::KenoBet() : m_wage(0) {/*empty*/}

bool KenoBet::add_number(number_type spot_) {
    auto it = m_spots.begin();
    auto end_m = m_spots.end();
    bool x = true;
    while(it != end_m) {
        if(*it == spot_) {
            x = false;
        }
        ++it;
    }
    return x;
}