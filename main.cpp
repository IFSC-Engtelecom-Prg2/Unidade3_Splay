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

    return 0;
}
