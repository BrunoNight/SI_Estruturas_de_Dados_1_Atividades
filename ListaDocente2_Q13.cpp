void Arv::deletarArvore(Nodo *raiz) {
    if(raiz == nullptr) {
        return;
    }
    deletarArvore(raiz -> esq);
    deletarArvore(raiz -> dir);
    if(raiz -> esq == nullptr && raiz -> dir == nullptr) {
        delete raiz;
        return;
    }
}
