#include "Trax.hpp"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
using namespace std;

Trax::Trax(vector<Joueur *> j) {
    joueurs = j;
    for (int i=0; i<32; i++) {
        TuileTrax *t1 = new TuileTrax('N', 'B', 'N', 'B'); // croix
        //TuileTrax *t2 = new TuileTrax('B', 'B', 'N', 'N'); // courbes
        sac.push_back(t1);
        //sac.push_back(t2);
    }
}

Trax::Trax(vector<Joueur *> players, vector<TuileTrax *> s) : joueurs{players}, sac{s} {}

Trax::~Trax() {}

vector<Joueur *> Trax::getJoueurs() {
    return this -> joueurs;
}

vector<TuileTrax *> Trax::getSac() {
  return this -> sac;
}

vector<TuileTrax *> Trax::getPlateau() {
  return this -> plateau;
}

void Trax::addTuile(TuileTrax &t) {
  plateau.push_back(&t);
}

TuileTrax* Trax::get_tuile_on_case(int i, int j) {
    for(TuileTrax *tmp: plateau) {
        if(tmp -> getX() == i && tmp -> getY() == j) return tmp;
    }
    return nullptr;
}

TuileTrax* Trax::pioche_tuile() {
    srand(time(NULL));
    TuileTrax *tmp = sac.at(rand() % sac.size());
    remove(sac.begin(),sac.end(),tmp);
    return tmp;
}

bool Trax::case_libre(int i, int j) {
    for(TuileTrax *tmp: plateau) {
        if(tmp -> getX() == i && tmp -> getY() == j) return false;
    }
    return true;
}

int Trax::nb_environ(int i, int j) {//renvoie le nombre de tuile presente au environ de la case (i,j)
    int res = 0;
    for(TuileTrax *tmp: plateau) {
        if(tmp -> getX() == i - 1 && tmp -> getY() == j) res++;
        if(tmp -> getX() == i + 1 && tmp -> getY() == j) res++;
        if(tmp -> getX() == i && tmp -> getY() == j - 1) res++;
        if(tmp -> getX() == i && tmp -> getY() == j + 1) res++;
    }
    return res;
}

int Trax::tuile_correspond(TuileTrax *tmp, int i, int j, char c) { //renvoie -1 si la tuile ne peut pas etre ajouter la ou le joueur a voulu la mettre et renvoie le score de cette case si ell peut rentrer
    bool gauche = false;
    bool droit = false;
    bool haut = false;
    bool bas = false;
    int score = 0;

    int score_gauche = tmp -> match_gauche(get_tuile_on_case(i - 1,  j), c);
    int score_droit = tmp -> match_droite(get_tuile_on_case(i + 1, j), c);
    int score_haut = tmp -> match_haut(get_tuile_on_case(i, j - 1), c);
    int score_bas = tmp -> match_bas(get_tuile_on_case(i , j + 1), c);
    
    if(score_gauche > 0) {
        gauche = true;
        score += score_gauche;
    }
    if(score_droit > 0) {
        droit = true;
        score += score_droit;
    }
    if(score_haut > 0) {
        haut = true;
        score += score_haut;
    }
    if(score_bas > 0) {
        bas = true;
        score += score_bas;
    }
    //une correspondance partout signifie soit que les vectors sont egaux soit que la case est vide (mais on sait qu'au moins une ne l'est pas quand on entre dans cette fonction)
    if(gauche || droit || haut || bas) return score;
    else return -1;
}

bool Trax::estDansJeu(int i, int j) { // renvoie true les i et j n'ont pas depasser la limite de (8x8) du plateau
    vector<int> borne = getPlateauBorne();

    if(borne[0] <= i && i <= borne[1] && borne[2] <= j && j <= borne[3]) return true;//i et j sont deja dans les limite du plateau actuel
    if(i < borne[0]) { // i n'est pas dans les limite du plateau actuel donc on regarde s'il depasse la limite de 8
        if(i <= borne[1] - 8) return false;
    } else if(i > borne[1]) {
        if(i >= borne[0] + 8) return false;
    }
    if(j < borne[2]) { // pareil pour j
        if(j <= borne[3] - 8) return false;
    } else if(j > borne[3]) {
        if(j >= borne[2] + 8) return false;
    }
    return true;
}

vector<int> Trax::getPlateauBorne() {
    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = 0;
    int maxY = 0;
    for(TuileTrax *t : plateau) {
        if(t -> getX() < minX) minX = t -> getX();
        else if(t -> getX() > maxX) maxX = t -> getX();

        if(t -> getY() < minY) minY = t -> getY();
        else if(t -> getY() > maxY) maxY = t -> getY();
    }
    vector<int> res{minX,maxX,minY,maxY};
    return res;
    //retourne les coordonnes des bords haut,bas,droit,gauche du plateau;
}



//on part de la tuile acc pour voir si on peut former une boucle
//on a la tuile prec pour enregistrer d'ou on vient pour eviter de revenir en arriere
//et target pour enregistrer notre tuile objectif, cad la 1ere tuile acc quand on fait le 1er appel de la fonction
bool Trax::boucle_gagnante(TuileTrax *target, TuileTrax *prec, TuileTrax *acc, char c) {
    bool haut = false;
    bool bas = false;
    bool gauche = false;
    bool droite = false;
    
    
    TuileTrax *next = nullptr;

    if(acc == nullptr) return false;
    if(acc == target && prec != nullptr) return true; // on regarde si prec est null car au 1er appel de la fonction prec est null et acc == target
                                            // donc on evite que sa renvoie vrai dés le 1er appel


    if(acc -> getNord() == c) {
        next = get_tuile_on_case(acc -> getX(), acc -> getY()-1);
        if(next != prec)
            haut = boucle_gagnante(target,acc,next, c);
    } 
    if(acc -> getEst() == c) {
        next = get_tuile_on_case(acc -> getX()+1, acc -> getY());
        if(next != prec)
            gauche = boucle_gagnante(target,acc,next, c);
    }
    if(acc -> getSud() == c) {
        next = get_tuile_on_case(acc -> getX(), acc -> getY()+1);
        if(next != prec)
            bas = boucle_gagnante(target,acc,next, c);
    }
    if(acc -> getOuest() == c) {
        next = get_tuile_on_case(acc -> getX()-1, acc -> getY());
        if(next != prec)
            droite = boucle_gagnante(target,acc,next, c);
    } 

    if(haut || bas || gauche || droite) return true;
    else return false;


}


//on parcours les tuile sur la bord le plus a gauche pour voir si un chemin va jusqu'au bord le plus a droite avec la fonction suivre_chemin juste en dessous
// et puis on fait pareil de haut en bas
bool Trax::chemin_gagnant() {
    vector<int> borne = this -> getPlateauBorne();
    
    bool arriver = false;

    if(borne[1] - borne[0] == 7) {
        for(int i = borne[2]; i <= borne[3]; i++) {//on verifie les chemin de haut en bas
            TuileTrax *depart = get_tuile_on_case(borne[0],i);
            if(depart) {
                char to_follow = depart -> getOuest();
                if(depart -> getNord() == to_follow) {
                    arriver = suivre_chemin(depart,get_tuile_on_case(borne[0],i-1),borne, to_follow, 'D');
                } else if(depart -> getEst() == to_follow) {
                    arriver = suivre_chemin(depart,get_tuile_on_case(borne[0]+1,i),borne, to_follow, 'D');
                } else { //else car exactement 1 des 3 sera verifié
                    arriver = suivre_chemin(depart,get_tuile_on_case(borne[0],i+1),borne, to_follow, 'D');//sud
                }
                if(arriver) return arriver;
            }
        }
    }

    if(borne[3] - borne[2] == 7) {
        for(int i = borne[0]; i <= borne[1]; i++) {//on verifie les chemin de haut en bas
            TuileTrax *depart = get_tuile_on_case(i,borne[2]);
            if(depart) {
                char to_follow = depart -> getSud();
                if(depart -> getOuest() == to_follow) {
                    arriver = suivre_chemin(depart,get_tuile_on_case(i-1,borne[2]),borne, to_follow, 'B');
                } else if(depart -> getEst() == to_follow) {
                    arriver = suivre_chemin(depart,get_tuile_on_case(i+1,borne[2]),borne, to_follow, 'B');
                } else { //else car exactement 1 des 3 sera verifié
                    arriver = suivre_chemin(depart,get_tuile_on_case(i,borne[2]+1),borne, to_follow, 'B');//sud
                }
                if(arriver) return arriver;
            }
        }
    }
    return false;
}


//on suit le chemin pour voir si un chemin relie 2 bords opposé
bool Trax::suivre_chemin(TuileTrax *prec, TuileTrax *acc,vector<int> borne, char to_follow, char dir) {
    if(!acc) return false;
    else if((acc -> getEst() == to_follow && dir == 'D' && acc -> getX() == borne[1]) || (acc -> getSud() == to_follow && dir == 'B' && acc -> getY() == borne[3])) {
        return true;
    }
    else {
        bool haut = false;
        bool bas = false;
        bool gauche = false;
        bool droite = false;
        TuileTrax *next = nullptr;
        if(acc -> getNord() == to_follow) {
            next = get_tuile_on_case(acc -> getX(), acc -> getY()-1);
            if(next != prec)
                haut = suivre_chemin(acc,next,borne,to_follow,dir);
        } 
        if(acc -> getEst() == to_follow) {
            next = get_tuile_on_case(acc -> getX()+1, acc -> getY());
            if(next != prec)
                gauche = suivre_chemin(acc,next,borne,to_follow,dir);
        }
        if(acc -> getSud() == to_follow) {
            next = get_tuile_on_case(acc -> getX(), acc -> getY()+1);
            if(next != prec)
                bas = suivre_chemin(acc,next,borne,to_follow,dir);
        }
        if(acc -> getOuest() == to_follow) {
            next = get_tuile_on_case(acc -> getX()-1, acc -> getY());
            if(next != prec)
                droite = suivre_chemin(acc,next,borne,to_follow,dir);
        } 

        if(haut || bas || gauche || droite) return true;
        else return false;


    }

}


ostream& operator<<(ostream& out, Trax &t) {
  for (TuileTrax *tui : t.getPlateau()) {
    out << *tui << " de coordonnee " << tui -> getX() << " : " << tui -> getY() << endl;
  }
  return out;
}
