//
// Created by msobral on 16/08/2021.
//

#ifndef SPLAY_SPLAY_H
#define SPLAY_SPLAY_H

namespace splay {

    template <typename T> struct Nodo {
        Nodo<T> *esq, *dir, *pai;
        T dado;
    };

    template <typename T> struct Splay {
        Nodo<T> * raiz;
    };

    // cria uma árvore splay vazia
    template <typename T> Splay<T> cria_splay();

    // retorna true se se árvore estiver vazia
    template <typename T> bool splay_vazia(Splay<T> & arv);

    // adiciona "algo" à árvore.
    // ao final, esse novo valor se tornará a nova raiz da árvore
    template <typename T> bool splay_adiciona(Splay<T> & arv, const T & algo);

}
#endif //SPLAY_SPLAY_H

#include "splay-impl.h"

