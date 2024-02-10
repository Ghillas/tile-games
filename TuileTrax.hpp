#ifndef TUILE_TRAX_H
#define TUILE_TRAX_H

#include<iostream>
using namespace std;

class TuileTrax {
private:
  // NOIR OU BLANC
  char nord;
  char est;
  char sud;
  char ouest;
  int x; // coordonnees de la tuile sur le plateau
  int y;
  int x_on_screen;
  int y_on_screen;
public:
  TuileTrax(char s1, char s2, char s3, char s4);
  TuileTrax(TuileTrax &tt);
  virtual ~TuileTrax();
  char getNord();
  char getEst();
  char getSud();
  char getOuest();
  int getX();
  int getY();
  int getXOnScreen();
  int getYOnScreen();
  void setX(int x2);
  void setY(int y2);
  void pivoter(); // 90° right
  int match_haut(TuileTrax *b, char c); //renvoie 1 si y a une correspondance, 0 si une tuile est nulle et -1000 si y a pas de correspondance
  int match_bas(TuileTrax *h, char c);
  int match_gauche(TuileTrax *d, char c);
  int match_droite(TuileTrax *g, char c);
};

ostream& operator<<(ostream& os, TuileTrax& tt);


#endif
