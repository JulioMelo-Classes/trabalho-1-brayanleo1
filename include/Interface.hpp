#ifndef Interface_hpp
#define Interface_hp

#include "KenoGame.hpp"

class Interface {
    public:
        //! Cria uma interface vazia usando um objeto da classe KenoGame
        Interface(KenoGame kg_); 

        //! Imprime a mensagem de leitura de arquivo e verifica se o arquivo está correto
        void readArchive();

        //! Imprime a mensagem de início de jogo
        void welcome(int rounds);

        //! Imprime a aposta atual e a tabela com quantidade de hits e retorno por rodada
        void printPlayerData(std::vector<std::vector<float>> tabela);

        //! Imprime o estado inicial e final da rodada atual assim como faz o cálculo da wage da rodada
        void printRound(int rounds, int round, std::vector<std::vector<float>> tabela);

        //! Imprime um resumo de todas as partidas
        void printSumary();

    private:
        KenoGame kg;//<! Objeto do tipo KenoGame
};

#endif  //Interface_hpp