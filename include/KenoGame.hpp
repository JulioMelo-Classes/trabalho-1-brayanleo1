#ifndef KenoGame_hpp
#define KenoGame_hpp

#include "KenoBet.hpp"

#include "vector"
#include <utility>

using set_of_sets = std::vector< set_of_numbers_type >; //<! Conjunto dos conjuntos do tipo de dado do keno hit
using set_of_wages = std::vector< cash_type >; //<! Conjunto de apostas do tipo definidas nesse aplicativo
using indR = std::vector<set_of_numbers_type>::iterator;//<! Iterator para round da vez
using indW = std::vector<cash_type>::iterator;//<! Iterator para wage do round da vez


class KenoGame {
    private:
        set_of_sets g_hits; //<! Números sorteados em todos os rounds
        set_of_wages g_wages; //<! Apostas de todos os rounds
        indR g_round; //<! Iterator indice do round da vez
        indW g_wage; //<! Iterator indice da wage do round da vez
        KenoBet kb; //<! Objeto da classe KenoBet
    public:
        /*! Cria um KenoGame vazio usando um objeto da classe KenoBet
            @param kb_ Um objeto do tipo KenoBet
        */
        KenoGame(KenoBet kb_);

        //! Cria um KenoGame vazio
        KenoGame();

        //! Retorna o objeto KenoBet associado ao objeto Kenogame
        KenoBet get_bet();

        //! Cria o g_hits
        void set_g_hits(set_of_sets g_hits_);

        //! Cria o g_wages
        void set_g_wages(set_of_wages g_wages_);

        /*! Coloca o iteretor indice para o começo de g_hits
            @param g_round_ O indice do começo de g_hits
        */
        void put_round(indR g_round_);

        /*! Retorna o iterator do round atual 
            @return O iterator do round atual
        */
        indR get_round();

        /*! Coloca o iteretor para o começo de g_wages
            @param g_round_wage_ O iterator do começo de g_wages
        */
        void put_round_wage(indW g_round_wage_);

        /*! Retorna o iterator da wage do round atual 
            @return O iterator apontando para a wage do round atual
        */
        indW get_round_wage();

        //! Sorteia e preenche os números do round atual
        void make_hits(int round);

        /*! Retorna o vetor com os números sorteados do round atual
            @return Vetor com os números sorteados do round atual
        */
        set_of_numbers_type get_round_hits();

        /*! Coloca o valor da aposta do round atual
            @param rounds Quantidade de rounds
        */
        void put_wage(int rounds);

        /*! Retorna o vetor de valores de apostas 
            @return Vetor de valores das apostas
        */
        set_of_wages get_g_wage();

        /*! Retorna a soma dos valores de todas as apostas do vetor g_wages
            @return Um valor do tipo cash_type contendo todas as wages atuais no vetor g_wages
        */
        cash_type get_total_wage();

        /*! Calcula e adiciona ou remove da wage do round atual dependendo do número de matchs
            @return Um pair contendo o número de quantas vezes o jogador ganhará a wage naquele round e o valor ganho no final
        */
        std::pair<float,cash_type> calc_wage(std::vector<std::vector<float>> tabela);
};

#endif //KenoGame_hpp