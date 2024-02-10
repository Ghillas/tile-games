#ifndef VUE_DOMINO_H
#define VUE_DOMINO_H


#include<SFML/Graphics.hpp>
#include "Tuile.hpp"
#include "DominoCarre.hpp"
#include "Joueur.hpp"
using namespace std;
using namespace sf;

class VueDomino {
private:
    DominoCarre jeu;
public:
    VueDomino(DominoCarre d);
    virtual ~VueDomino();
    void partie();
    int getCaseClick(Vector2f mouse, Tuile *actuel);
};

#endif
