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
            Nodo<T> * ptr = arv.raiz;

            while (true) {
                if (ptr->dado == algo) {
                    ptr->dado = algo;
                    break;
                } else if (algo < ptr->dado) {
                    // dado a adicionar é menor que o dado do
                    // nodo apontado por ptr
                    if (ptr->esq != nullptr) {
                        ptr = ptr->esq;
                    } else {
                        ptr->esq = cria_nodo(algo, ptr);
                        break;
                    }
                    // ???
                } else {
                    // dado a adicionar é maior que o dado do
                    // nodo apontado por ptr
                    if (ptr->dir != nullptr) {
                        ptr = ptr->dir;
                    } else {
                        ptr->dir = cria_nodo(algo, ptr);
                        break;
                    }
                }
            }

        }
    }

    template <typename T> T splay_acessa(Splay<T> & arv, const T & algo) {
        // se não encontrar, disparar uma exceção:
        // throw std::exception();
    }
}
#endif //SPLAY_SPLAY_IMPL_H
