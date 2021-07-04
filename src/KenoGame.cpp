#include "KenoGame.hpp"
#include "KenoBet.hpp"

using namespace std;
KenoGame::KenoGame(KenoBet kb_) {
    kb_ = kb;
}

void KenoGame::put_round(indR g_round_){
    g_round = g_round_;
}

indR KenoGame::get_round() {
    return g_round;
}

void KenoGame::put_round_wage(indW g_round_wage_){
    g_wage = g_round_wage_;
}

indW KenoGame::get_round_wage() {
    return g_wage;
}

void KenoGame::make_hits() {
    std::vector<number_type> x;
    int count = 0;
    srand(g_round); //Setar a seed para que o rand gere numeros diferentes, mas possa gerar numeros iguais em rounds diferentes
    while(count != 20) {
        number_type numb = rand() % 80 + 1;
        x.push_back(numb);
        count = count + 1;
    }
    g_hits.push_back(x);
}

set_of_numbers_type KenoGame::get_round_hits() {
    return g_hits[g_round];
}

void KenoGame::put_wage(int rounds) {
    auto rw = kb.KenoBet::get_wage();
    rw = rw / rounds;
    g_wages.push_back(rw);
}

set_of_wages KenoGame::get_g_wage() {
    return g_wages;
}

//! Deixado para depois, quando receber resposta
void KenoGame::calc_wage() {
    ++g_round;
    ++g_wage;
}