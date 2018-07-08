#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

void ArvBinBusca::insere(int x){
    raiz=auxinsere(raiz,x);
}

NoArv* ArvBinBusca::auxinsere(NoArv *p, int x){
    if(p!=NULL){
        if(x<p->getInfo()){
            p->setEsq(auxinsere(p->getEsq(),x));
        }
        if(x>p->getInfo()){
            p->setDir(auxinsere(p->getDir(),x));
        }
        return p;
    }
    else{
        p=new NoArv();
        p->setInfo(x);
        p->setDir(NULL);
        p->setEsq(NULL);
        return p;
    }
}


float ArvBinBusca::media(int x){
    NoArv *p=raiz;
    float media=0;
    int n=0;
    while(p!=NULL){
        if(x<p->getInfo()){
                media=media+p->getInfo();
            p=p->getEsq();
            n++;
        }
        if(x>p->getInfo()){
            media=media+p->getInfo();
            p=p->getDir();
            n++;
        }
        if(x==p->getInfo()){
                return media/n;
        }
    }
}
NoArv* ArvBinBusca::removefolha(NoArv *p){
    cout<<"TESTEfo"<<endl;
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1filho(NoArv *p){
    NoArv *aux;
    cout<<"TESTE1f"<<endl;
    if(p->getDir()==NULL){
        aux=p->getEsq();
    }
    if(p->getEsq()==NULL){
        aux=p->getDir();
    }
        delete p;
        return aux;
}

NoArv* ArvBinBusca::menorsubarvdir(NoArv *p){
    cout<<"TESTEmsd"<<endl;
    NoArv *aux=p->getDir();
    while(aux->getEsq()!=NULL){
        aux=aux->getEsq();
    }
    return aux;
}

void ArvBinBusca::remove(int x){
    cout<<"TESTEr"<<endl;
    raiz=auxremove(raiz,x);
}

NoArv* ArvBinBusca::auxremove(NoArv *p, int x){
    if(p==NULL){
        return NULL;
    }
    else if(x<p->getInfo()){
        p->setEsq(auxremove(p->getEsq(),x));
    }
    else if(x>p->getInfo()){
        p->setDir(auxremove(p->getDir(),x));
    }
    else{
        if(p->getDir()==NULL&&p->getEsq()==NULL){
            p=removefolha(p);
        }
        if(p->getDir()==NULL||p->getEsq()==NULL){
            p=remove1filho(p);
        }
        else{
                cout<<"TESTE2f"<<endl;
            NoArv *aux=menorsubarvdir(p);
            int auxint=aux->getInfo();
            p->setInfo(auxint);
        cout<<"TESTE"<<endl;
            aux->setInfo(x);
            cout<<"TESTE"<<endl;
            p->setDir(auxremove(p->getDir(), x));
    }
}
return p;
}
