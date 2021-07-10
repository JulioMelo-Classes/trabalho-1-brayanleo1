#ifndef Interface_hpp
#define Interface_hp

#include "KenoGame.hpp"

class Interface {
    public:
        /*! Cria uma interface vazia usando um objeto da classe KenoGame
            @param kg Objeto do tipo KenoGame
        */
        Interface(KenoGame *kg_); 

        /*! Imprime a mensagem de leitura de arquivo e verifica se o arquivo está correto
            @param argv[] Vetor de caracteres com o endereço do arquivo
        */void readArchive(char argv[]);

        /*! Imprime a mensagem de início de jogo
            @param rounds Inteiro com a quantidade de rounds que o jogo terá
        */
        void welcome(int rounds);

        /*! Imprime a aposta atual e a tabela com quantidade de hits e retorno por rodada
            @param tabela Vetor de vetores do tipo float com o número de retorno por hits no round
        */
        void printPlayerData(std::vector<std::vector<float>> tabela);

        /*! Imprime o estado inicial e final da rodada atual
            @param rounds Inteiro com a quantidade de rounds que o jogo terá
            @param round Inteiro que representa o round atual
            @param par Par com o primeiro valor tipo float de retorno do jogo atual e o segundo do tipo cash_type sendo o valor de retorno
        */
        void printRound(int rounds, int round, std::pair<float,cash_type> par);

        //! Imprime um resumo de todas as partidas
        void printSumary();

    private:
        KenoGame *kg;//<! Objeto do tipo KenoGame
};

#endif  //Interface_hpp