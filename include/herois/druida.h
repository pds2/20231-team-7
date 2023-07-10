#ifndef DRUIDA_H
#define DRUIDA_H

#include "heroi.h"
#include "../personagem.h"

class nao_pode_transformar_para_transformacao_atual_e{};

enum Tranformacao{
    Humano, Urso, Lobo, Falcao
};

class Druida: public Heroi{
    private:
        Tranformacao _trans;
        std::vector<std::string> _ataques;
    public:
         /*
         * @brief Cria um duida.
         */       
        Druida(std::string nome, int vida, int dano);

        /*
        * @brief Destrutor do druida
        */
        ~Druida();

        /*
         * @brief Retorna a classe do personagem.
         */
        Classes get_classe() const override;

        /*
        * @brief retorna o numero de habilidades que o personagem tem
        */
        unsigned get_num_habilidades() override;

        /*
        * @brief retorna a letra que representa o heroi
        */
        std::string get_letra() override;

        /*
        * @brief aumenta o nivel do druida
        */
        void aumenta_nivel() override;

        /*
         * @brief Retorna a transformação atual do druida.
         */
        Tranformacao get_tranformacao();

        /*
         * @brief Altera a transformação atual do druida.
         */
        void transformar(Tranformacao trans);

        /*
         * @brief Retorna o dano de ataque do urso.
         */
        void ataqueUrso(int valor_dado, std::vector<Personagem *> inimigos);

        /*
         * @brief Retorna o dano de ataque do humano.
         */
        void ataqueHumano(int valor_dado, std::vector<Personagem *> inimigos);

        /*
         * @brief Retorna o dano de ataque do falcao.
         */
        void ataqueFalcao(int valor_dado, std::vector<Personagem *> inimigos);

        /*
         * @brief Retorna o dano de ataque do lobo.
         */
        void ataqueLobo(int valor_dado, std::vector<Personagem *> inimigos);

        /*
         * @brief Retorna o dano de ataque do druida baseado na tranformação.
         */
        void ataque(int alvo, int valor_dado, std::vector<Personagem *> inimigos) override;

       /*
        * @brief Retorna as habilidades do druida.
        */
        std::vector<std::string> get_habilidades() override;
};

#endif
