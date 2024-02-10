#include "TuileTrax.hpp"
using namespace std;

TuileTrax::TuileTrax(char s1, char s2, char s3, char s4) : nord{s1}, est{s2}, sud{s3}, ouest{s4}, x{-1}, y{-1} {}

TuileTrax::TuileTrax(TuileTrax &tt) {
    nord = tt.nord;
    est = tt.est;
    sud = tt.sud;
    ouest = tt.ouest;
    x = -1;
    y = -1;
}

TuileTrax::~TuileTrax() {}

char TuileTrax::getNord() {
    return nord;
}

char TuileTrax::getEst() {
    return est;
}

char TuileTrax::getSud() {
    return sud;
}

char TuileTrax::getOuest() {
    return ouest;
}

int TuileTrax::getX() { // x == -1 : tuile pas encore placée
    return x;
}

int TuileTrax::getY() { // idem
    return y;
}

int TuileTrax::getXOnScreen() { // x == -1 : tuile pas encore placée
    return x_on_screen;
}

int TuileTrax::getYOnScreen() { // idem
    return y_on_screen;
}

void TuileTrax::setX(int x2) {
  this -> x = x2;
  x_on_screen = x*63;
}

void TuileTrax::setY(int y2) {
  this -> y = y2;
  y_on_screen = y*63;
}

void TuileTrax::pivoter() {
  char tmpn = nord;
  char tmpe = est;
  char tmps = sud;
  char tmpo = ouest;
  nord = tmpo;
  est = tmpn;
  sud = tmpe;
  ouest = tmps;
}

int TuileTrax::match_haut(TuileTrax *b, char c) {
    if(!b) {
        return 0;
    }
    else if (this->getNord() == c && b->getSud() == c) {
        return 1;
    }
    else {
        return -1000;
    }
}

int TuileTrax::match_bas(TuileTrax *h, char c) {
    if(!h) {
        return 0;
    }
    else if (this->getSud() == c && h->getNord() == c) {
        return 1;
    }
    else {
        return -1000;
    }
}

int TuileTrax::match_gauche(TuileTrax *d, char c) {
    if(!d) {
        return 0;
    }
    else if (this->getOuest() == c && d->getEst() == c) {
        return 1;
    }
    else {
        return -1000;
    }
}

int TuileTrax::match_droite(TuileTrax *g, char c) {
    if(!g) {
        return 0;
    }
    else if (this->getEst() == c && g->getOuest() == c) {
        return 1;
    }
    else {
        return -1000;
    }
}

ostream& operator<<(ostream& out, TuileTrax &tt) {
  out << " " << tt.getNord() << " \n";
  out << tt.getOuest() << " " << tt.getEst() << "\n";
  out << " " << tt.getSud() << " \n";
  return out;
}
