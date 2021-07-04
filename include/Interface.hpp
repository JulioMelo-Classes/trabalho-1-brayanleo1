#ifndef Interface_hpp
#define Interface_hp

class Interface {
    public:
        //! Cria uma interface vazia
        Interface();

        //! Imprime a mensagem de leitura de arquivo
        void readArchive();

        //! Imprime a mensagem de início de jogo
        /*Você apostará um total de kb.get_wage créditos.
            Jogará um total de 'rounds' rodadas, apostando kg.get_g_wage[kg.get_round_wage].get_wage créditos por rodada*/
        void welcome(int rounds);

        //! Imprime a aposta atual e a tabela com quantidade de hits e retorno por rodada
        /* Sua aposta tem kb.get_size números, eles são: kb.get_spots;
        ----------+-----------
        Hits      | Retorno
        0         | 0
        1         | 1
        2         | 2
        3         | 16
        ------------------------------------------------------------
        */
       void printPlayerData();

       //! Imprime o estado inicial e final da rodada atual
       /*Esta é a rodada #1 de 'rounds', sua aposta é kg.get_g_wage[kg.get_round_wage].get_wage. Boa sorte!
        Os números sorteados são: kg.get_round_hits
        
        Você acertou os números kb.get_hits(kg.get_round_hits), um total de kb.get_hits(kg.get_round_hits).size hits de kb.size
        Sua taxa de retorno é kg.calc_wage, assim você sai com: kg.get_g_wage[kg.get_round_wage].get_wage
        Você possui um total de: kg.get_total_wage créditos.
        ------------------------------------------------------------
       */
      void printRound(int rounds);

      //! Imprime um resumo de todas as partidas
      /*
        ======= Sumário =======
        >>> Você gastou um total de kb.get_wage créditos
        >>> Hooray! você ganhou kg.get_total_wage - kb.get_wage créditos!
        >>> Você está saindo do jogo com um total de kg.get_total_wage créditos.
        */
       void printSumary();
};

#endif  //Interface_hpp