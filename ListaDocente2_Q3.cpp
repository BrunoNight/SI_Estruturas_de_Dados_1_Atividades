#include <iostream>
#include <string>

using namespace std;

class NodoP { public:
    int infoP;
    NodoP *prox;
};

class Nodo { public:
    int info;
    Nodo *e, *d;
    Nodo(int n) {
        info = n;
        e = nullptr;
        d = nullptr;
    }
};

class Arv {
    private:
        Nodo *raiz;
    public:
        Arv(Nodo *raiz) {
            raiz = nullptr;
        }
        void impAscendentesPilha(Nodo *raiz, int n, bool encontrou, Pilha &P);
};

class Pilha {
    private:
        NodoP *topo;
    public:
        Pilha(NodoP *topo) {
            topo = nullptr;
        }
        void inserirPilha(int nP);
}

void Arv::impAscendentesPilha(Nodo *raiz, int n, bool encontrou, Pilha &P) {
    if(raiz == nullptr) {
        return;
    }
    
    if(raiz -> info == n) {
        encontrou = true;
        return;
    }
    
    impAscendentesPilha(raiz -> e, n, encontrou, &P);
    if(encontrou) {
        inserirPilha(raiz -> info);
        cout << raiz -> info;
        return;
    }
    impAscendentesPilha(raiz -> d, n, encontrou, &P);
    if(encontrou) {
        inserirPilha(raiz -> info);
        cout << raiz -> info;
        return;
    }
}

void Pilha::inserirPilha(int nP) {
    NodoP *novo = new NodoP;
    if(novo == nullptr) exit(1);
    novo -> infoP = nP;
    if(topo == nullptr) {
        novo -> prox = topo
        topo = novo;
        return;
    }
    if(novo -> infoP > topo -> info) {
        novo -> prox = topo;
        topo = novo;
        return;
    }
    NodoP *aux = topo;
    while(aux != nullptr) {
        if(aux -> prox -> infoP < novo -> infoP) {
            novo -> prox = aux -> prox;
            aux -> prox = novo;
            return;
        }
        aux = aux -> prox;
    }
}
