#include "Joueur.hpp"
using namespace std;

int Joueur::compteur = 1;

Joueur::Joueur(string s) : name{s}, score{0}, id{compteur} { compteur += 1; };

Joueur::Joueur(Joueur const &j) : name{j.name}, score{j.score}, id{j.compteur} {};

Joueur::~Joueur() {}

string Joueur::getName() {
  return name;
}

int Joueur::getID() {
  return id;
}

int Joueur::getScore() {
  return score;
}

void Joueur::setScore(int i) {
  this -> score = i;
}

void Joueur::addScore(int i) {
  this -> score += i;
}


ostream& operator<<(ostream& os, Joueur &j) {
  os << "Joueur " << j.getName() << " : ID " << j.getID() << " et score " << j.getScore() << endl;
  return os;
}


