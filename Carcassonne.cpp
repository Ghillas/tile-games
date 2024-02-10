#include "Carcassonne.hpp"


Carcassonne::Carcassonne(vector<Joueur *> j, vector<TuileTrax *> t) : Trax(j,t) {
    for(long unsigned int i = 0; i < j.size(); i++) {
        vector<Partisan *> tmp;
        for(int k = 0; k < 10; k++) {
            Partisan *p = new Partisan(0,0,'R');
            tmp.push_back(p);
        }
        partisan.push_back(tmp);
    }
}

Carcassonne::Carcassonne(Carcassonne &c) : Trax(c), partisan{c.partisan} {}

Carcassonne::~Carcassonne() {}



vector<vector<Partisan *>> Carcassonne::getPartisan() {
    return this -> partisan;
}


/*int Carcassonne::tuile_correspond(TuileTrax *tmp, int i, int j) {
    return tuile_correspond(tmp,i,j);
}*/