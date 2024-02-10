#ifndef CARCASSONNE_H
#define CARCASSONNE_H

#include "Trax.hpp"
#include "Partisan.hpp"

class Carcassonne : public Trax {
private:
    vector<vector<Partisan *>> partisan;
public:
    Carcassonne(vector<Joueur *> j, vector<TuileTrax *> t);
    Carcassonne(Carcassonne &c);
    virtual ~Carcassonne();

    vector<vector<Partisan *>> getPartisan();
    //int tuile_correspond(TuileTrax *tmp, int i, int j);
};

#endif
