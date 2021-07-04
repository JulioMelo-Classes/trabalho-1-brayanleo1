#ifndef KenoGame_hpp
#define KenoGame_hpp

#include "KenoBet.hpp"

#include "vector"

using set_of_sets = std::vector< set_of_numbers_type >; //Conjunto dos conjuntos do tipo de dado do keno hit
using set_of_wages = std::vector < cash_type >; //Conjunto de apostas do tipo definidas nesse aplicativo
using indR = vector<number_type>::iterator;//Iterator para round da vez
using indW = vector<cash_type>::iterator;//Iterator para wage do round da vez


class KenoGame {
    private:
        set_of_sets g_hits; //Números sorteados em todos os rounds
        set_of_wages g_wages; //Apostas de todos os rounds
        indR g_round; //Iterator indice do round da vez
        indW g_wage;
    public:
        //Cria um KenoGame vazio usando uma objeto da classe KenoBet
        KenoGame(KenoBet kb);

        //Coloca o iteretor indice do primeiro round
        void put_round(indR g_round_);

        //Retorna o iterator indice do round atual
        indR get_round();

        //Coloca o iteretor indice da wage do primeiro round
        void put_round_wage(indW g_round_wage_);

        //Retorna o iterator indice do round atual
        indW get_round_wage();

        //Sorteia e preenche os números do round atual usando o iterator
        void make_hits(indR g_round_);

        //Retorna os números sorteados do round da vez
        set_of_numbers_type get_hits(indR g_round_);

        //Coloca o valor da aposta do round atual
        void put_wage(indW g_round_wage_);

        //Retorna o valor da aposta do round atual
        cash_type get_wage(indW g_round_wage);

        //Calcula e adiciona ou remove da wage do round atual dependendo do número de matchs
        void calc_wage(indR g_round_, indW g_round_wage_, set_of_numbers_type g_hits_, cash_type g_wage_);
};

#endif //KenoGame_hpp