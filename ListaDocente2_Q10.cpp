int Arv::impAsc(Nodo *raiz, int n) {
    if(raiz == nullptr) {
        return 0;
    }
    if(raiz -> info == n) {
        return 1;
    }
    if(impAsc(raiz -> esq, n) || impAsc(raiz -> dir,n) == 1) {
        inserirLD(raiz -> info);
        return 1;
    }
}

void LD::inserirLD(int n) {
    NodoL *novo = new NodoL;
    if(novo == nullptr) exit(1);
    if(inicio == nullptr) {
        novo -> prox = nullptr;
        novo -> ant = nullptr;
        inicio = fim = novo;
        return;
    }
    NodoL *aux = inicio;
    while(aux != nullptr) {
        if(aux -> prox == nullptr) {
            novo -> prox = aux -> prox;
            novo -> ant = aux;
            fim = novo;
            return;
        }
        aux = aux -> prox;
    }
}
