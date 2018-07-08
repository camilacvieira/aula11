#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int val);
    void imprime();
    void insere(int x);
    float media(int x);
    void remove(int x);


private:
    NoArv* raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);
    NoArv* auxinsere(NoArv *p, int x);
    NoArv* removefolha(NoArv *p);
    NoArv* remove1filho(NoArv *p);
    NoArv* remove2filhos(NoArv *p, int x);
    NoArv* menorsubarvdir(NoArv *p);
    NoArv* auxremove(NoArv *p,int x);
};

#endif // ARVBINBUSCA_H_INCLUDED
