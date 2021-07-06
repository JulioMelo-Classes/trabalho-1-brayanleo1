#include "Interface.hpp"
#include "KenoGame.hpp"

#include "iostream"

using namespace std;
Interface::Interface(KenoGame kg_) {
    kg = kg_;
}

void Interface::readArchive() {
    std::cout << "Oi" << endl; //Aqui deve lidar com a leitura de arquivo
}

void Interface::welcome(int rounds) {
    std::cout << "Você apostará um total de " << kg.get_bet().get_wage() <<" créditos." << endl;
    std::cout << "Jogará um total de " << rounds <<" rodadas, apostando " << *kg.get_round_wage() <<" créditos por rodada" << endl;
}

void Interface::printPlayerData(std::vector<std::vector<float>> tabela) {
    std::cout << "Sua aposta tem "<< kg.get_bet().size() <<" números, eles são: [ ";
    auto spts = kg.get_bet().get_spots();
    auto it = spts.begin();
    auto out = spts.end();
    while(it != out) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "]" << endl;
    std::cout << "----------+-----------" << endl;
    std::cout << "Hits      | Retorno" << endl;
    auto it2 = tabela[kg.get_bet().get_spots().size()].begin();
    auto out2 = tabela[kg.get_bet().get_spots().size()].end();
    int p = 0;
    while(it2 != out2) {
        std::cout << p << "         | " << *it2 << endl;
        ++it2;
        p = p + 1;
    }
    std::cout << endl << "------------------------------------------------------------" << endl;
}

void Interface::printRound(int rounds, int round, std::vector<std::vector<float>> tabela) {
    std::cout << "Esta é a rodada #" << round << "de " << rounds <<", sua aposta é " << *kg.get_round_wage() << ". Boa sorte!" << endl;
    std::cout << "Os números sorteados são: [ ";
    auto ghits = kg.get_round_hits();
    auto it = ghits.begin();
    auto out = ghits.end();
    while(it != out) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "]" << endl << endl;
    std::cout << "Você acertou os números [ ";
    auto gmatchs = kg.get_bet().get_hits(ghits);
    auto it2 = gmatchs.begin();
    auto out2 = gmatchs.end();
    while(it2 != out2) {
        std::cout << *it2 << " ";
        ++it2;
    }
    std::cout << "], um total de " << gmatchs.size() << "hits de" << kg.get_bet().get_spots().size() << endl;
    auto r = kg.calc_wage(tabela);
    std::cout << "Sua taxa de retorno é " << r.first << ", assim você sai com: " << r.second <<endl;
    std::cout << "Você possui um total de: " << kg.get_total_wage() << " créditos." << endl;
    std::cout << "------------------------------------------------------------" << endl;
}

void Interface::printSumary() {
    std::cout << "======= Sumário =======" << endl;
    std::cout << ">>> Você gastou um total de " << kg.get_bet().get_wage() << " créditos" << endl;
    if(kg.get_total_wage() > kg.get_bet().get_wage()) {
        std::cout << ">>> Hooray! você ganhou " << kg.get_total_wage() - kg.get_bet().get_wage() << " créditos!" << endl;
    } else {
        std::cout << ">>> Ahhh! Que peninha! você perdeu " << kg.get_bet().get_wage() - kg.get_total_wage() << " créditos!" << endl;
    }
    std::cout << ">>> Você está saindo do jogo com um total de " << kg.get_total_wage() <<" créditos." << endl;
}