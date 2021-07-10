#include <iostream>   // cout, endl
#include <sstream>

#include "Arquivo.hpp"
#include "KenoBet.hpp"
#include "KenoGame.hpp"
#include "Interface.hpp"

using namespace std;

int main(int argc, char *argv[]){
  
  //Criando a tabela de apostas
  std::vector<float> s1 = {0,3};
  std::vector<float> s2 = {0,1,9};
  std::vector<float> s3 = {0,1,2,16};
  std::vector<float> s4 = {0,0.5,2,6,12};
  std::vector<float> s5 = {0,0.5,1,3,15,50};
  std::vector<float> s6 = {0,0.5,1,2,3,30,75};
  std::vector<float> s7 = {0,0.5,0.5,1,6,12,36,100};
  std::vector<float> s8 = {0,0.5,0.5,1,3,6,19,90,720};
  std::vector<float> s9 = {0,0.5,0.5,1,2,4,8,20,80,1200};
  std::vector<float> s10 = {0,0,0.5,1,2,3,5,10,30,600,1800};
  std::vector<float> s11 = {0,0,0.5,1,1,2,6,15,25,180,1000,3000};
  std::vector<float> s12 = {0,0,0,0.5,1,2,4,24,72,250,500,2000,4000};
  std::vector<float> s13 = {0,0,0,0.5,0.5,3,4,5,20,60,240,500,3000,6000};
  std::vector<float> s14 = {0,0,0,0.5,0.5,2,3,5,12,50,150,500,1000,2000,7500};
  std::vector<float> s15 = {0,0,0,0.5,0.5,1,2,5,15,50,150,300,600,1200,2500,10000};
  std::vector<std::vector <float>> tabela;
  tabela.push_back(s1);
  tabela.push_back(s2);
  tabela.push_back(s3);
  tabela.push_back(s4);
  tabela.push_back(s5);
  tabela.push_back(s6);
  tabela.push_back(s7);
  tabela.push_back(s8);
  tabela.push_back(s9);
  tabela.push_back(s10);
  tabela.push_back(s11);
  tabela.push_back(s12);
  tabela.push_back(s13);
  tabela.push_back(s14);
  tabela.push_back(s15);

  KenoBet kb;
  KenoGame kg(&kb);
  Interface itfc(&kg);

  std::string campoUm;
  std::string campoDois;
  std::string campoTres;

  itfc.readArchive(*argv);

  Arquivo aq(argv[1]);
  
  auto r = aq.lerLinhas();
  auto i = r.begin();
  campoUm = *i;
  ++i;
  campoDois = *i;
  ++i;
  campoTres = *i;

  stringstream ss1;
  stringstream ss2;
  stringstream ss3;

  ss1<<campoUm;
  cash_type wage;
  ss1 >> wage;

  bool az = kb.set_wage(wage);
  if(az == false) {
    cout << "Arquivo inexistente ou aposta inválida, encerrando o jogo" << endl;
    exit(0);
  }

  ss2<<campoDois;
  int rounds;
  ss2 >> rounds;

  ss3<<campoTres;
  int spot;
  while(ss3 >> spot) { //Enquanto houver números
    bool rep = kb.add_number(spot);
    if(rep == false) {
      cout << "Número repetido detectado, encerrando o jogo" << endl;
      exit(0);
    }
  }

  if(kb.size() > 15) {
    cout << "Quantidade de números maior que o esperado, encerrando o jogo" << endl;
    exit(0);
  }

  cout << ">>> Aposta lida com sucesso!" << endl;

  set_of_sets g_hits;
  kg.set_g_hits(g_hits);

  set_of_wages g_wages;
  kg.set_g_wages(g_wages);
  kg.put_wage(rounds);
  kg.put_round_wage();

  itfc.welcome(rounds);

  itfc.printPlayerData(tabela);

  int round = 1;
  kg.make_hits(round);
  auto par = kg.calc_wage(tabela);
  while(round <= rounds) {
    cout << *kg.get_round_wage() << endl;
    itfc.printRound(rounds, round, par);
    round++;
    if(round <= rounds) {
      kg.make_hits(round);
      kg.adv_round_wage();
      par = kg.calc_wage(tabela);
    }
  }
  
  itfc.printSumary();

  return 0;
}
