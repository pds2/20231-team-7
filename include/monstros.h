#ifndef MONSTROS_H
#define MONSTROS_H

#include "personagem.h"
#include <vector>
#include <string>

 enum tamanho{
    _MIUDO, _PEQUENO, _MEDIO, _GRANDE, _ENORME, _IMENSO
 };

 enum habilidade{
    _FORCA, _DESTREZA, _INTELIGENCIA, _SABEDORIA
 };


 class Monstros : public Personagem{
 private:
    int _nivel_de_desafio;
    int _classe_de_armadura;
    int _valor_nivel_minimo;
    std::vector<std::string> imune;
 public:
    Monstros(std::string nome, int vida, int dano,int nivel_de_desafio, int classe_de_armadura,int valor_nivel_minimo);
    virtual tamanho get_tamanho();
    virtual habilidade get_habilidade();
    ~Monstros();
 };



#endif 