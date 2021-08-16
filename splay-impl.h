//
// Created by msobral on 16/08/2021.
//

#ifndef SPLAY_SPLAY_IMPL_H
#define SPLAY_SPLAY_IMPL_H

#include "splay.h"

namespace splay {
    template <typename T> Splay<T> cria_splay() {
        Splay<T> arv;
        arv.raiz = nullptr;

        return arv;
    }

    template <typename T> bool splay_vazia(Splay<T> & arv) {
        return arv.raiz == nullptr;
    }

    template <typename T> bool splay_adiciona(Splay<T> & arv, const T & algo) {

    }

}
#endif //SPLAY_SPLAY_IMPL_H
