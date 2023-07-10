#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "heroi.h"

class furia_ja_ativa_e {};

class Guerreiro : public Heroi {
    private:
        std::vector<std::string> _ataques;
        bool _furia;
    public:
    /*
     * @brief Cria um guerreiro
     */
    Guerreiro(std::string nome, int vida, int dano);
   
    ~Guerreiro();

    /*
     * @brief Retorna o dano de ataque do heroi.
     */
    void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;

    /*
     * @brief ativa a habilidade furia
     */
    void ativa_furia();

    /*
     * @brief Retorna estado da furia
     */
    bool get_furia();

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
     * @brief Retorna as habilidades do guerreiro.
    */
    std::vector<std::string> get_habilidades() override;
};

#endif
