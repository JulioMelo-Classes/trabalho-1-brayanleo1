#include "KenoGame.hpp"
#include "KenoBet.hpp"

using namespace std;
KenoGame::KenoGame(KenoBet kb_) {
    kb = kb_;
}

KenoGame::KenoGame() {
    //vazio
}

KenoBet KenoGame::get_bet() {
    return kb;
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

void KenoGame::make_hits(int round) {
    std::vector<number_type> x;
    int count = 0;
    srand(round); //Setar a seed para que o rand gere numeros diferentes, mas possa gerar numeros iguais em rounds diferentes
    while(count != 20) {
        number_type numb = rand() % 80 + 1;
        x.push_back(numb);
        count = count + 1;
    }
    g_hits.push_back(x);
}

set_of_numbers_type KenoGame::get_round_hits() {
    return *g_round;
}

void KenoGame::put_wage(int rounds) {
    auto rw = kb.KenoBet::get_wage();
    rw = rw / rounds;
    g_wages.push_back(rw);
}

set_of_wages KenoGame::get_g_wage() {
    return g_wages;
}

cash_type KenoGame::get_total_wage() {
    auto be = g_wages.begin();
    auto en = g_wages.end();
    cash_type tot = *be;
        while(be != en) {
            ++be;
            if(be != en) {
                tot = tot + *be;
            }
        }
    return tot;
}

pair<int,cash_type> KenoGame::calc_wage(set_of_sets tabela) {
    cash_type valor = *g_wage;
    auto matchs = kb.get_hits(get_round_hits());
    auto msize = matchs.size();
    int retorno = tabela[kb.size() - 1][msize];
    valor = valor * retorno;
    *g_wage = valor;
    std::pair<int,cash_type> pp;
    pp.first = retorno;
    pp.second = valor;
    ++g_round;
    ++g_wage;
    return pp;
}