#include "DominoCarre.hpp"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;

// on génère 30 dominos au hasard
//DominoCarre::DominoCarre(vector<Joueur *> j, vector<Tuile *> t) : joueur{j}, centre{new Tuile()}, sac{t}, plateau{plateau.push_back(centre)} {}//modifier car erreur

DominoCarre::DominoCarre(vector<Joueur *> j, vector<Tuile *> t) {
    joueur = j;
    centre = new Tuile(5,3);
    sac = t;
    plateau.push_back(centre);
}

DominoCarre::~DominoCarre() {}

vector<Joueur *> DominoCarre::getJoueur() {
    return this -> joueur;
}

vector<Tuile *> DominoCarre::getSac() {
    return this -> sac;
}

vector<Tuile *> DominoCarre::getPlateau() {
    return this -> plateau;
}

void DominoCarre::addTuile(Tuile &t) {
    plateau.push_back(&t);
}

Tuile* DominoCarre::getCentre() {
    return this -> centre;
}

Tuile* DominoCarre::get_tuile_on_case(int i, int j) {
    for(Tuile *tmp: plateau) {
        if(tmp -> getX() == i && tmp -> getY() == j) return tmp;
    }
    return nullptr;
}

Tuile* DominoCarre::pioche_tuile() {
    srand(time(NULL));
    Tuile *tmp = sac.at(rand() % sac.size());
    remove(sac.begin(),sac.end(),tmp);
    return tmp;
}

bool DominoCarre::case_libre(int i, int j) {
    for(Tuile *tmp: plateau) {
        if(tmp -> getX() == i && tmp -> getY() == j) return false;
    }
    return true;
}

int DominoCarre::nb_environ(int i, int j) {//renvoie le nombre de tuile presente au environ de la case (i,j)
    int res = 0;
    for(Tuile *tmp: plateau) {
        if(tmp -> getX() == i - 1 && tmp -> getY() == j) res++;
        if(tmp -> getX() == i + 1 && tmp -> getY() == j) res++;
        if(tmp -> getX() == i && tmp -> getY() == j - 1) res++;
        if(tmp -> getX() == i && tmp -> getY() == j + 1) res++;
    }
    return res;
}

int DominoCarre::tuile_correspond(Tuile *tmp, int i, int j) { //renvoie -1 si la tuile ne peut pas etre ajouter la ou le joueur a voulu la mettre et renvoie le score de cette case si ell peut rentrer
    bool gauche = false;
    bool droit = false;
    bool haut = false;
    bool bas = false;
    int score = 0;
    int score_gauche = tmp -> match_gauche(get_tuile_on_case(i - 1, j));
    int score_droit = tmp -> match_droite(get_tuile_on_case(i + 1, j));
    int score_haut = tmp -> match_haut(get_tuile_on_case(i, j - 1));
    int score_bas = tmp -> match_bas(get_tuile_on_case(i, j + 1));
    if(score_gauche >= 0) {
        gauche = true;
        score += score_gauche;
    }
    if(score_droit >= 0) {
        droit = true;
        score += score_droit;
    }
    if(score_haut >= 0) {
        haut = true;
        score += score_haut;
    }
    if(score_bas >= 0) {
        bas = true;
        score += score_bas;
    }
    //une correspondance partout signifie soit que les vectors sont egaux soit que la case est vide (mais on sait qu'au moins une ne l'est pas quand on entre dans cette fonction)
    if(gauche && droit && haut && bas) return score;
    else return -1;
}

Joueur* DominoCarre::getGagnant() {
    Joueur *gagnant = joueur.at(0);
    for(Joueur *j: joueur) {
        if(j -> getScore() > gagnant -> getScore()) {
            gagnant = j;
        }
    }
    return gagnant;
}


