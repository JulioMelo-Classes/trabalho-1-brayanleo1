#ifndef KenoGame_hpp
#define KenoGame_hpp

#include "KenoBet.hpp"

#include "vector"

using set_of_sets = std::vector< set_of_numbers_type >; //Conjunto dos conjuntos do tipo de dado do keno hit
using set_of_wages = std::vector < cash_type >; //Conjunto de apostas do tipo definidas nesse aplicativo

template<class InputIt> //Iterator para a range

class KenoGame {
    private:
        set_of_sets g_hits; //Números sorteados em todos os rounds
        set_of_wages g_wages; //Apostas de todos os rounds
        InputIt g_round; //Iterator indice do round da vez
    public:
        //Cria um KenoGame vazio usando uma objeto da classe KenoBet
        KenoGame(KenoBet kb);

        //Coloca o iteretor indice do primeiro round
        void put_round(InputIt g_round_);

        //Retorna o iterator indice do round atual
        InputIt get_round();

        //Sorteia e preenche os números do round atual usando o iterator
        void make_hits(InputIt g_round_);

        //Retorna os números sorteados do round da vez
        set_of_numbers_type get_hits(InputIt g_round_);

        //Coloca o valor da aposta do round atual
        void put_wage(InputIt g_round_);

        //Retorna o valor da aposta do round atual
        cash_type get_wage(InputIt g_round_);

        //Calcula e adiciona ou remove da wage do round atual dependendo do número de matchs
        void calc_wage(InputIt g_round_, set_of_numbers_type g_hits_, cash_type g_wage_);
};

#endif //KenoGame_hpp