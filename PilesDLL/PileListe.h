#ifndef PILELISTE_H
#define PILELISTE_H
#include <iostream>
#include "export.h"
using namespace std;

template <typename T>
class PileListe {
private:
    struct Noeud {
        T valeur;
        Noeud* suivant;
        Noeud(const T& valeur, Noeud* suivant)
            : valeur(valeur), suivant(suivant) {}
    };
    Noeud* sommet;
    int taille;

public:
    PileListe() : sommet(nullptr), taille(0) {}
    ~PileListe() { while (!estVide()) depiler(); }

    void empiler(const T& valeur) {
        sommet = new Noeud(valeur, sommet);
        taille++;
    }
    T depiler() {
        Noeud* ancien = sommet;
        T valeur = ancien->valeur;
        sommet = sommet->suivant;
        delete ancien;
        taille--;
        return valeur;
    }
    T sommetValeur() { return sommet->valeur; }
    bool estVide() const { return sommet == nullptr; }
    int getTaille() const { return taille; }
    void afficher() const {
        cout << "Pile [sommet -> ";
        Noeud* c = sommet;
        while (c != nullptr) {
            cout << c->valeur;
            if (c->suivant != nullptr) cout << ", ";
            c = c->suivant;
        }
        cout << "]" << endl;
    }
};

extern template class PILE_API PileListe<int>;
extern template class PILE_API PileListe<char>;
#endif
