//
// Created by msobral on 16/08/2021.
//

#ifndef SPLAY_SPLAY_IMPL_H
#define SPLAY_SPLAY_IMPL_H

#include "splay.h"

namespace splay {
    // funções privativas
    template <typename T> Nodo<T> * cria_nodo(const T & algo, Nodo<T> * pai) {
        Nodo<T> * p_nodo = new Nodo<T>;

        p_nodo->dado = algo;
        p_nodo->pai = pai;
        // não tem filhos ... ao menos não inicialmente
        p_nodo->esq = nullptr;
        p_nodo->dir = nullptr;

        return p_nodo;
    }

    template <typename T> Splay<T> cria_splay() {
        Splay<T> arv;
        arv.raiz = nullptr;

        return arv;
    }

    template <typename T> bool splay_vazia(Splay<T> & arv) {
        return arv.raiz == nullptr;
    }

    template <typename T> void splay_adiciona(Splay<T> & arv, const T & algo) {
        // o que fazer primeiro ?
        if (arv.raiz == nullptr) { // está vazia
            arv.raiz = cria_nodo(algo, nullptr);
        } else { // não está vazia
            // aqui tem um algoritmo legal !
            // lembrar que: na árvore, à esquerda de um nodo estão os valores
            //              menores que os dele, e à direita estão os maiores

        }
    }

}
#endif //SPLAY_SPLAY_IMPL_H
