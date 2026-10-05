#include <iostream>
#include <chrono>
#include "PileListe.h"
#include "PileTableau.h"
using namespace std;
using namespace chrono;

template <typename P>
bool estValide(string expr) {
    P pile;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '(' || c == '{') pile.empiler(c);
        else if (c == ')') {
            if (pile.estVide() || pile.sommetValeur() != '(') return false;
            pile.depiler();
        }
        else if (c == '}') {
            if (pile.estVide() || pile.sommetValeur() != '{') return false;
            pile.depiler();
        }
    }
    return pile.estVide();
}

int main() {
    string expr = "{(x+y+z)*5)";
    cout << "Liste chainee : "
         << (estValide<PileListe<char>>(expr) ? "valide" : "invalide") << endl;
    cout << "Tableau       : "
         << (estValide<PileTableau<char>>(expr) ? "valide" : "invalide") << endl;
    const int N = 1000000;

    auto debut1 = high_resolution_clock::now();
    PileListe<int> pl;
    for (int i = 0; i < N; i++) pl.empiler(i);
    for (int i = 0; i < N; i++) pl.depiler();
    auto fin1 = high_resolution_clock::now();
    cout << "Liste chainee  - " << N << " empiler+depiler : "
         << duration<double, milli>(fin1 - debut1).count() << " ms" << endl;

    auto debut2 = high_resolution_clock::now();
    PileTableau<int> pt;
    for (int i = 0; i < N; i++) pt.empiler(i);
    for (int i = 0; i < N; i++) pt.depiler();
    auto fin2 = high_resolution_clock::now();
    cout << "Tableau dyn.   - " << N << " empiler+depiler : "
         << duration<double, milli>(fin2 - debut2).count() << " ms" << endl;
    return 0;
}
