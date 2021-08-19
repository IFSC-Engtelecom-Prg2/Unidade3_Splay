#include <iostream>
#include "splay.h"

using namespace splay;
using namespace std;

int main() {
    Splay<int> arv = cria_splay<int>();

    if (splay_vazia(arv)) {
        cout << "Árvore está vazia" << endl;
    }

    splay_adiciona(arv, 5);
    splay_adiciona(arv, 3);
    splay_adiciona(arv, 9);

    cout << "Árvore tem valor 5: " << splay_acessa(arv, 5) << endl;
    cout << "Árvore tem valor 9: " << splay_acessa(arv, 9) << endl;
    cout << "Árvore tem valor 3: " << splay_acessa(arv, 3) << endl;
    cout << "Árvore tem valor 1: " << splay_acessa(arv, 1) << endl;

    return 0;
}
