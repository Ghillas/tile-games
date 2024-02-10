#include "VueCarcassonne.hpp"


using namespace std;
using namespace sf;


VueCarcassonne::VueCarcassonne(Carcassonne j) : jeu{j} {}

VueCarcassonne::~VueCarcassonne() {}


void VueCarcassonne::partie() {
    RenderWindow app(VideoMode(1400, 1000, 32), "Carcassonne");
    app.setKeyRepeatEnabled(false);

    Texture ville,pres,route,pres_3ville,pres_3villeB,route_3ville,route_3villeB,pres2_2villeB,pres2_2villeB2,pres2_2ville_2,pres2_2ville_3;
    Texture pres_ville_2route,pres_2route_ville;
    ville.loadFromFile("./ressources/carcassonne/ville.png");
    route.loadFromFile("./ressources/carcassonne/route.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres_3ville.loadFromFile("./ressources/carcassonne/1pres_3ville.png");
    pres_3villeB.loadFromFile("./ressources/carcassonne/1pres_3villeB.png");
    route_3ville.loadFromFile("./ressources/carcassonne/1route_3ville.png");
    route_3villeB.loadFromFile("./ressources/carcassonne/1route_3villeB.png");
    pres2_2villeB2.loadFromFile("./ressources/carcassonne/2pres_2villeB2.png");
    pres2_2ville_2.loadFromFile("./ressources/carcassonne/2pres_2ville_2.png");
    pres2_2ville_3.loadFromFile("./ressources/carcassonne/2pres2_2ville_3.png");
    pres2_2villeB.loadFromFile("./ressources/carcassonne/2pres_2villeB.png");
    pres_ville_2route.loadFromFile("./ressources/carcassonne/2route_1pres_1ville.png");
    pres_2route_ville.loadFromFile("./ressources/carcassonne/2route_1ville_1pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");
    pres.loadFromFile("./ressources/carcassonne/pres.png");

}


int VueCarcassonne::getCaseClick(Vector2f mouse, TuileTrax *actuel) {
    int x_click = (int)mouse.x / 139;// 139 = taille d'une tuile
    int y_click = (int)mouse.y / 139;
    bool est_libre = jeu.case_libre(x_click,y_click);
    if(est_libre) {
        int attache = jeu.nb_environ(x_click,y_click);
        if(attache == 0) {
            cout << "La case choisit n'est attaché a aucune case" << endl;
            return -1;
        } else {
            int score = jeu.tuile_correspond(actuel,x_click,y_click, 'O'); //juste pour la compilation
            if(score == -1) {
                cout << "La tuile ne peut pas etre placé ici car il n'y a pas de correspondance avec les tuiles autour" << endl;
            }
            return score;
        }
    } else {
        cout << "La case choisit est deja occupé" << endl;
        return -1;
    }
}
