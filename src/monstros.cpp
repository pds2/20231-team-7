#include "../include/monstros.h"

Monstros::Monstros(std::string nome, int vida, int dano,
int nivel_de_desafio, int classe_de_armadura,
int valor_xp_minimo): Personagem(nome, vida, dano),_nivel_de_desafio
(nivel_de_desafio),_classe_de_armadura(classe_de_armadura),
_valor_xp_minimo(valor_xp_minimo){}

Monstros::~Monstros()
 {
    std::cout << get_nome() << "morreu!" << std::endl;
 }
 
tamanho Monstros::get_tamanho(){ 
    return  tamanho::_MIUDO;
 }

habilidade Monstros::get_habilidade(){
    return habilidade::_INTELIGENCIA;
}   
