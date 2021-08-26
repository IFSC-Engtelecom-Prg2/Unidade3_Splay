//
// Created by msobral on 16/08/2021.
//

#ifndef SPLAY_SPLAY_IMPL_H
#define SPLAY_SPLAY_IMPL_H

#include "splay.h"

namespace splay {
    /*
     * funções privativas
     */

    template <typename T> Nodo<T> * cria_nodo(const T & algo, Nodo<T> * pai) {
        Nodo<T> * p_nodo = new Nodo<T>;

        p_nodo->dado = algo;
        p_nodo->pai = pai;
        // não tem filhos ... ao menos não inicialmente
        p_nodo->esq = nullptr;
        p_nodo->dir = nullptr;

        return p_nodo;
    }

    // atualiza o nodo pai de "atual", que deve agora
    // estar conectado em "novo"
    template <typename T> atualiza_pai(Nodo<T> * novo, Nodo<T> * atual) {
        novo->pai = atual->pai;
        if (atual->pai != nullptr) {
            if (na_esquerda(atual)) atual->pai->esq = novo;
            else atual->pai->dir = novo;
        }
    }

    template <typename T> void zig(Nodo<T> * nodoB) {
        // nodoA é o pai do nodo B
        Nodo<T> * nodoA = nodoB->pai;
        // sub2 está à direita do nodo B
        Nodo<T> * sub2 = nodoB->dir;

        // IMPORTANTE !
        // Deve-se atualizar o nodo pai do nodoB, o qual
        // deve ser o mesmo nodo pai do nodoA
        atualiza_pai(nodoB, nodoA);
//        nodoB->pai = nodoA->pai;
//        if (nodoA->pai != nullptr) {
//            if (na_esquerda(nodoA)) nodoA->pai->esq = nodoB;
//            else nodoA->pai->dir = nodoB;
//        }

        // sub2 deve ir pra esquerda de nodoA
        nodoA->esq = sub2;
        sub2->pai = nodoA;

        // nodoA deve ficar à direita de nodoB
        nodoB->dir = nodoA;
        nodoA->pai = nodoB;
    }

    template <typename T> void zag(Nodo<T> * nodoA) {
        //nodoB é o pai do a
        Nodo<T> *nodoB=nodoA->pai;
        //sub2 esta a esquerda do nodoA
        Nodo<T> *sub2=nodoA->esq;

        // IMPORTANTE !
        // Deve-se atualizar o nodo pai do nodoA, o qual
        // deve ser o mesmo nodo pai do nodoB (se nodoB não for a raiz)
        atualiza_pai(nodoA, nodoB);
//        nodoA->pai = nodoB->pai;
//        if (nodoB->pai != nullptr) {
//            if (na_esquerda(nodoB)) nodoB->pai->esq = nodoA;
//            else nodoB->pai->dir = nodoA;
//        }

        //sub2 deve ir para dir do nodoB
        nodoB->dir=sub2;
        sub2->pai=nodoB;
        //nodo B deve ir para esquerda do nodoA
        nodoA->esq=nodoB;
        nodoB->pai=nodoA;

    }

    // testa se o nodo apontado por "ptr" está à esquerda
    // de seu nodo pai
    template <typename T> bool na_esquerda(Nodo<T> * ptr) {
        Nodo<T> * pai = ptr->pai;

        return pai->esq == ptr;
    }

    // ptr: nodo que se deseja transformar na raiz (ou subi-lo
    // de nível)
    template <typename T> bool testa_zig_zig(Nodo<T> * ptr) {
        return na_esquerda(ptr) && na_esquerda(ptr->pai);
    }

    template <typename T> bool testa_zag_zag(Nodo<T> * ptr) {
        return !na_esquerda(ptr) && !na_esquerda(ptr->pai);
    }

    template <typename T> bool testa_zig_zag(Nodo<T> * ptr) {
        return na_esquerda(ptr) && !na_esquerda(ptr->pai);
    }

    template <typename T> bool testa_zag_zig(Nodo<T> * ptr) {
        return !na_esquerda(ptr) && na_esquerda(ptr->pai);
    }

    template <typename T> void move_para_raiz(Nodo<T> * ptr) {
        // move o nodo apontado por "ptr" para a raiz
        // deve aplicar as transformações necessárias, possivelmente
        // de forma sucessiva !

        // enquanto não for a raiz
        while (ptr->pai != nullptr) {
            // testa qual transformação aplicar, e então
            // a efetua
            // A transformação pode ser simples (zig ou zag)
            // ou uma combinação delas (zig-zig, zag-zag,
            // zig-zag, zag-zig)
        }
    }
    /*
     * fim das funções privativas
     */

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
            arv.raiz = cria_nodo<T>(algo, nullptr);
        } else { // não está vazia
            // aqui tem um algoritmo legal !
            // lembrar que: na árvore, à esquerda de um nodo estão os valores
            //              menores que os dele, e à direita estão os maiores
            Nodo<T> * ptr = arv.raiz;

            while (true) {
                if (ptr->dado == algo) {
                    ptr->dado = algo;
                    move_raiz(ptr);
                    break;
                } else if (algo < ptr->dado) {
                    // dado a adicionar é menor que o dado do
                    // nodo apontado por ptr
                    if (ptr->esq != nullptr) {
                        ptr = ptr->esq;
                    } else {
                        ptr->esq = cria_nodo<T>(algo, ptr);
                        move_raiz(ptr->esq);
                        break;
                    }
                    // ???
                } else {
                    // dado a adicionar é maior que o dado do
                    // nodo apontado por ptr
                    if (ptr->dir != nullptr) {
                        ptr = ptr->dir;
                    } else {
                        ptr->dir = cria_nodo<T>(algo, ptr);
                        move_raiz(ptr->dir);
                        break;
                    }
                }
            }

        }
    }

    template <typename T> T splay_acessa(Splay<T> & arv, const T & algo) {
        // se não encontrar, disparar uma exceção:
        // throw std::exception();
        Nodo<T> * ptr = arv.raiz;

        while (ptr != nullptr) {
            if (ptr->dado == algo) {
                move_raiz(ptr);
                return ptr->dado;
            }
            if (algo < ptr->dado) ptr = ptr->esq;
            else ptr = ptr->dir;
        }

        // não encontrou o dado
        throw std::exception();
    }
}

#endif //SPLAY_SPLAY_IMPL_H
