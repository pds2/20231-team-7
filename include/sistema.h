#ifndef SISTEMA_H
#define SISTEMA_H

#include "../include/herois/time_heroi.h"
#include "monstros/monstros.h"

#include <string>
#include <vector>

class invalid_option_e{};
class slot_invalido_e{};

class Sistema{
    private:
        std::string _opcao;
        Time_h _herois;
    public:
        /*
        * @brief Cria um sistema
        */  
        Sistema();

        /*
        * @brief Inicia o menu inicial do jogo
        */ 
        void inicia_menu();

        /*
        * @brief Cria e atribui os personagens ao sistema
        */ 
        void cria_personagens();

        /*
        * @brief Roda o jogo chamando os combates necessarios
        */ 
        void roda_jogo(unsigned fase);

        /*
        * @brief Inicia um novo jogo
        */ 
        void inicia_jogo();

        /*
        * @brief Finaliza o jogo liberando uma mensagem de derrota
        */ 
        void encerra_jogo();

        /*
        * @brief Salva o jogo usando de um file txt
        */ 
        void salva_jogo(int faseatual);

        /*
        * @brief Avança entre fases do jogo e pergunta se o usuiario quer salvar seu progresso
        */ 
        int avança_fase(int fase);

        /*
        * @brief Faz o carregamento de um save e instancia herois
        */ 
        unsigned carrega_save(unsigned int numslot);

        /*
        * @brief Fornece as opçoes de carregamento de jogo para o usuario
        */ 
        void carrega_jogo();

        /*
        * @brief Retorna um vetor de inimigos aleatorios que escala com a fase atual
        */ 
        std::vector<Monstro *> gera_fase(int numfase);
};

#endif
