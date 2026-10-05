#ifndef PILETABLEAU_H
#define PILETABLEAU_H
#include <iostream>
#include "export.h"
using namespace std;

template <typename T>
class PileTableau {
private:
    T* tableau;
    int capacite;
    int taille;

public:
    PileTableau() {
        capacite = 4;
        taille = 0;
        tableau = new T[capacite];
    }

    ~PileTableau() {
        delete[] tableau;
    }

    void empiler(const T& valeur) {
        if (taille == capacite) {
            agrandir();
        }
        tableau[taille] = valeur;
        taille++;
    }

    T depiler() {
        taille--;
        return tableau[taille];
    }

    T sommetValeur() {
        return tableau[taille - 1];
    }

    bool estVide() const {
        return taille == 0;
    }

    int getTaille() const {
        return taille;
    }

    void afficher() const {
        cout << "Pile [sommet -> ";
        for (int i = taille - 1; i >= 0; i--) {
            cout << tableau[i];
            if (i > 0) cout << ", ";
        }
        cout << "]" << endl;
    }
private:
    void agrandir() {
        capacite = capacite * 2;
        T* nouveauTableau = new T[capacite];
        for (int i = 0; i < taille; i++) {
            nouveauTableau[i] = tableau[i];
        }
        delete[] tableau;
        tableau = nouveauTableau;
    }

};

extern template class PILE_API PileTableau<int>;
extern template class PILE_API PileTableau<char>;
#endif
