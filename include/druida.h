#ifndef DRUIDA_H
#define DRUIDA_H

#include "heroi.h"
#include "personagem.h"

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
        Druida(std::string nome, int vida, int dano, std::string classe);

        /*
         * @brief Retorna a classe do personagem.
         */
        Classes get_classe() const override;

        /*
         * @brief Retorna a transformação atual do druida.
         */
        Tranformacao get_tranformacao();

        /*
         * @brief Altera a transformação atual do druida.
         */
        void transformar(Tranformacao trans);

        /*
         * @brief Retorna o dano de ataque do druida baseado na tranformação.
         */
        void ataque(Personagem &inimigo1, Personagem &inimigo2, Personagem &inimigo3, int valor_dado);

};

#endif