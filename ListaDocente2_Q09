void Arv::retirarFolhas(Nodo *raiz) {
    if(raiz == nullptr) {
        return;
    }
    if(raiz -> esq == nullptr && raiz -> dir == nullptr) {
        inserirLD(raiz -> info);
    }
    retirarFolhas(raiz -> esq);
    retirarFolhas(raiz -> dir);
}

void LD::inserirLD(int n) {
    NodoL *novo = new NodoL;
    if(novo == nullptr) exit(1);
    novo -> info = n;
    if(inicio == nullptr) {
        novo -> prox = nullptr;
        novo -> ant = nullptr;
        inicio = fim = novo;
        return;
    } else if(inicio > n) {
        novo -> prox = inicio;
        novo -> ant = nullptr;
        inicio -> ant = novo;
        return;
    }
    NodoL *aux = inicio;
    while(aux != nullptr) {
        if(aux -> prox -> info > n) {
            novo -> prox = aux -> prox;
            novo -> ant = aux;
            aux -> prox = novo;
            return;
        }
        aux = aux -> prox;
    }
    
    novo -> prox = nullptr;
    novo -> ant = fim;
    fim = novo;
    return;
}
