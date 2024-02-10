#ifndef TRAX_H
#define TRAX_H

#include<iostream>
#include<vector>
#include "TuileTrax.hpp"
#include "Joueur.hpp"

using namespace std;

class Trax {
protected:
  vector<Joueur *> joueurs;
  vector<TuileTrax *> sac;
  vector<TuileTrax *> plateau;
public:
  Trax(vector<Joueur *> players);
  Trax(vector<Joueur *> players, vector<TuileTrax *> s);
  virtual ~Trax();
  vector<Joueur *> getJoueurs();
  vector<TuileTrax *> getSac();
  vector<TuileTrax *> getPlateau();
  void addTuile(TuileTrax &t);
  TuileTrax* pioche_tuile();
  TuileTrax* get_tuile_on_case(int i, int j);
  bool estDansJeu(int i, int j); // renvoie true si la i et j sont dans le plateau (8x8)
  vector<int> getPlateauBorne();
  bool case_libre(int i, int j);
  int nb_environ(int i, int j);
  int tuile_correspond(TuileTrax *tmp, int i, int j, char c);
  bool boucle_gagnante(TuileTrax *target, TuileTrax *prec, TuileTrax *acc, char c);
  //target == la tuile qu'on veut atteindre pour faire une boucle, donc on part de cette tuile a la base
  //cote == la tuile d'ou on vient pour pas revenir en arriere
  //acc == la tuile actuel 
  bool chemin_gagnant();
  bool suivre_chemin(TuileTrax *prec, TuileTrax *acc,vector<int> borne, char to_follow, char dir); //on met les borne pour eviter un nouvel appel de fonction
};

ostream& operator<<(ostream& os, Trax& t);


#endif
