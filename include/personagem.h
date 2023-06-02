#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

class dano_negativo_e{};

class Personagem{
    private:
        const std::string _nome;
    protected:
        int _vida;
        int _dano;
        bool _morto;
        unsigned int _nivel;
    public:
        /*
         * @brief Cria um personagem.
         */
        Personagem(std::string nome);

        /*
         * @brief Retorna o nome do personagem.
         */
        std::string get_nome() const;

        /*
         * @brief Retorna a vida do personagem.
         */
        int get_vida();

        /*
         * @brief Retorna o dano do personagem.
         */
        int get_dano();

        /*
         * @brief Retorna o nivel do personagem.
         */
        unsigned int get_nivel();

        /*
         * @brief Diminui a vida do personagem de acordo com o dano.
         */
        void recebe_dano(int dano);

        /*
         * @brief Retorna o estado do personagem (morto / vivo).
         */
        bool morto();

        /*
         * @brief Aumenta o nível do personagem.
         */
        void aumenta_nivel();
};

#endif
