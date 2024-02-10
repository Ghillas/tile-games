#ifndef TUILES_H
#define TUILES_H

#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Tuile {
private :
  std::vector<int> vnord;
  std::vector<int> vest;
  std::vector<int> vsud;
  std::vector<int> vouest;
  int x; //les coordonnee de la tuile dans la grille de jeu (x_on_screen / 100 donc peut etre inutile)
  int y;
  int x_on_screen; //les coordonnee de la tuile dans la fenetre de jeu (point en haut a gauche)
  int y_on_screen; //on prendra des image de 100 pixels

public :
  Tuile();
  Tuile(int a,int b);
  Tuile(const Tuile& t);
  virtual ~Tuile();
  std::vector<int> getVnord();
  std::vector<int> getVest();
  std::vector<int> getVsud();
  std::vector<int> getVouest();
  int getX();
  int getY();
  int getXOnScreen();
  int getYOnScreen();
  void setX(int a);
  void setY(int a);

  void pivoter(); // 90° right
  int match_haut(Tuile *b); //renvoie le score si y a une correspondance, 0 si une tuile est nulle et -1 si y a pas de correspondance
  int match_bas(Tuile *h);
  int match_gauche(Tuile *d);
  int match_droite(Tuile *g);
  int somme_vector(vector<int> v1, vector<int> v2);
  bool vector_egaux(vector<int> v1, vector<int> v2);
};

std::ostream& operator<<(std::ostream& out, Tuile &t);

#endif
