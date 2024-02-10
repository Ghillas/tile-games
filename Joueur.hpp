#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>

class Joueur {
private :
  std::string name;
  int score;
  int id;
  static int compteur;
public :
  Joueur(std::string s);
  Joueur(Joueur const &j);
  virtual ~Joueur();
  std::string getName();
  int getScore();
  void setScore(int i);
  void addScore(int i);
  int getID();
};

std::ostream& operator<<(std::ostream& os, Joueur &j);

#endif
