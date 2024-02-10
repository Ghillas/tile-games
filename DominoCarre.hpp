#ifndef DOMINO_CARRE_H
#define DOMINO_CARRE_H

#include<iostream>
#include<vector>
#include "Joueur.hpp"
#include "Tuile.hpp"

using namespace std;

class DominoCarre {
private :
  vector<Joueur *> joueur;
  vector<Tuile *> sac; 
  vector<Tuile *> plateau;
  Tuile* centre;
public:
  DominoCarre(vector<Joueur *> j, vector<Tuile *> t);
  virtual ~DominoCarre();
  vector<Joueur *> getJoueur();
  vector<Tuile *> getSac();
  vector<Tuile *> getPlateau();
  void addTuile(Tuile &t);
  Tuile* getCentre();
  Tuile* pioche_tuile();
  Tuile* get_tuile_on_case(int i, int j);
  bool case_libre(int i, int j);
  int nb_environ(int i, int j); //retourne le nombre de case avec lesquels elle est en contact
  int tuile_correspond(Tuile *tmp, int i, int j);
  Joueur* getGagnant();
  
  bool joue(Joueur *j); //renvoie true si le joueur a pu jouer et false sinon
  Joueur jeu(); //retourne le joueur gagnant
};

#endif
