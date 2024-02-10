#ifndef VUE_TRAX_H
#define VUE_TRAX_H

#include<SFML/Graphics.hpp>
#include "TuileTrax.hpp"
#include "Trax.hpp"
#include "Joueur.hpp"
using namespace std;
using namespace sf;

class VueTrax {
private:
    Trax jeu;
public:
    VueTrax(Trax t);
    virtual ~VueTrax();
    void partie();
    int getCaseClick(Vector2f mouse, TuileTrax *actuel, char c);
};


#endif
