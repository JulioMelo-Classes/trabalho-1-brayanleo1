#include <iostream>
#include <vector>

#include "KenoBet.hpp"

using namespace std;

KenoBet::KenoBet() : m_wage(0) {/*empty*/}

bool KenoBet::add_number(number_type spot_) {
    auto it = m_spots.begin();
    auto end_m = m_spots.end();
    bool x = true;
    while(it != end_m && x == true) {
        if(*it == spot_) {
            x = false;
        }
        ++it;
    }
    return x;
}

bool KenoBet::set_wage( cash_type wage_ ) {
    bool az = false;
    if(wage_ > 0) {
        az = true;
    }
    return az;
}

void KenoBet::reset( void ) {
    //std::fill(m_spots.begin(), m_spots.end(), 0);
    m_spots.clear();
}

cash_type KenoBet::get_wage( void ) {
    m_wage = 0;
    return m_wage;
}

size_t KenoBet::size( void ) {
    int x = 0;
    int y = 1;
    auto it = m_spots.begin();
    auto end_m = m_spots.end();
    while(it != end_m && y != 0) {
        y = *it;
        if(y >= 1 && y <= 80) {
            x = x + 1;
        }
        ++it;
    }
    return x;
}

set_of_numbers_type KenoBet::get_hits( const set_of_numbers_type & hits_ ) {
    vector<number_type> v;
    auto it_h = hits_.begin();
    auto end_h = hits_.end();

    auto it_m = m_spots.begin();
    auto end_m = m_spots.end();

    while(it_m != end_m) {
        int c = 0; //para parar o próximo while quando encontrar match
        while(it_h != end_h && c == 0) {
            if(*it_h == *end_h) {
                c = 1;
                v.push_back(*it_h);
            }
            ++it_h;
        }
        c = 0;
        ++it_m;
        it_h = hits_.begin();
    }
    return v;
}

set_of_numbers_type KenoBet::get_spots( void ) {
    return m_spots;
}

