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
    public:
         /*
         * @brief Cria um duida.
         */       
        Druida(std::string nome, int vida, int dano);

        /*
         * @brief Retorna a classe do personagem.
         */
        Classes get_classe() const override;

        char const* get_letra() override;

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
        void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;

        /*
         * @brief Retorna as habilidades do druida.
         */
        void print_habilidades() override;
};

#endif
