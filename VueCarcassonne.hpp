#ifndef VUE_CARCASSONNE_H
#define VUE_CARCASSONNE_H


#include<SFML/Graphics.hpp>
#include "TuileTrax.hpp"
#include "Trax.hpp"
#include "Carcassonne.hpp"
#include "Joueur.hpp"
using namespace std;
using namespace sf;

class VueCarcassonne {
private:
    Carcassonne jeu;
public:
    VueCarcassonne(Carcassonne d);
    virtual ~VueCarcassonne();
    void partie();
    int getCaseClick(Vector2f mouse, TuileTrax *actuel);
};

#endif
