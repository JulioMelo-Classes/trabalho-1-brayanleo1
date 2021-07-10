#include "KenoGame.hpp"
#include "KenoBet.hpp"

#include "iostream"

using namespace std;
KenoGame::KenoGame(KenoBet *kb_) {
    kb = kb_;
}

KenoGame::KenoGame() {
    //vazio
}

KenoBet KenoGame::get_bet() {
    return *kb;
}

void KenoGame::set_g_hits(set_of_sets g_hits_) {
    g_hits = g_hits_;
}

void KenoGame::set_g_wages(set_of_wages g_wages_) {
    g_wages = g_wages_;
}

void KenoGame::put_round_wage(){
    g_wage = g_wages.begin();
}

indW KenoGame::get_round_wage() {
    return g_wage;
}

void KenoGame::adv_round_wage(){
    ++g_wage;
}

void KenoGame::make_hits(int round) {
    std::vector<number_type> x;
    int count = 0;
    auto ale = rand() % kb->get_spots().size();
    auto el = kb->get_spots()[ale];
    auto nr = kb->get_wage() * el * round;
    srand(nr); //Setar a seed para que o rand gere numeros diferentes, mas possa gerar numeros iguais em rounds diferentes
    while(count != 20) {
        number_type numb = rand() % 80 + 1;
        x.push_back(numb);
        count = count + 1;
    }
    g_hits.push_back(x);
}

set_of_numbers_type KenoGame::get_round_hits() {
    return g_hits.back();
}

void KenoGame::put_wage(int rounds) {
    auto rw = (*kb).get_wage() / rounds;
    int count = 0;
    while(count < rounds) {
        g_wages.push_back(rw);
        count = count + 1;
    }
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

pair<float,cash_type> KenoGame::calc_wage(std::vector<std::vector<float>> tabela) {
    cash_type valor = *g_wage;
    auto matchs = (*kb).get_hits(get_round_hits());
    auto msize = matchs.size();
    float retorno = tabela[(*kb).size() - 1][msize];
    valor = valor * retorno;
    *g_wage = valor;
    std::pair<float,cash_type> pp;
    pp.first = retorno;
    pp.second = valor;
    return pp;
}