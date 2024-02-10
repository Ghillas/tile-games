#include "Tuile.hpp"
#include<cstdlib>
using namespace std;

Tuile::Tuile() {
  x = -1;
  y = -1;
  x_on_screen = 0; //on verra plus tard ou l'image apparait pour que le joueur voit sa tuile avant de décider ou la poser
  y_on_screen = 0;
  //srand(time(NULL));
  for (int j=0; j<3; j++) {
    this->vnord.push_back(rand() % 3);
  }
  for (int j=0; j<3; j++) {
    this->vest.push_back(rand() % 3);
  }
  for (int j=0; j<3; j++) {
    this->vsud.push_back(rand() % 3);
  }
  for (int j=0; j<3; j++) {
    this->vouest.push_back(rand() % 3);
  }

  
}

Tuile::Tuile(int a, int b) {
  x = a;
  y = b;
  x_on_screen = x * 139;//une tuile fait 139 pixels
  y_on_screen = y * 139;
  //srand(time(NULL));
  for (int j=0; j<3; j++) {
    this->vnord.push_back(rand() % 3);
  }
  for (int j=0; j<3; j++) {
    this->vest.push_back(rand() % 3);
  }
  for (int j=0; j<3; j++) {
    this->vsud.push_back(rand() % 3);
  }
  for (int j=0; j<3; j++) {
    this->vouest.push_back(rand() % 3);
  }
  /*cout << "nord : " << vnord[0] << vnord[1] << vnord[2] << endl;
  cout << "sud : " << vsud[0] << vsud[1] << vsud[2] << endl;
  cout << "est : " << vest[0] << vest[1] << vest[2] << endl;
  cout << "ouest : " << vouest[0] << vouest[1] << vouest[2] << endl;*/

}

//Tuile::Tuile(const Tuile& t) : vnord(t.vnord), vsud(t.vsud), vouest(t.vouest), vest(t.vest) {}

Tuile::~Tuile() {}

Tuile::Tuile(const Tuile& t) {
  vnord = t.vnord;
  vsud = t.vsud;
  vouest = t.vouest;
  vest = t.vest;
  x = t.x;
  y = t.y;
}

vector<int> Tuile::getVnord() {
  return vnord;
}

vector<int> Tuile::getVest() {
  return vest;
}

vector<int> Tuile::getVsud() {
  return vsud;
}

vector<int> Tuile::getVouest() {
  return vouest;
}

int Tuile::getX() {
  return this -> x;
}

int Tuile::getY() {
  return this -> y;
}

int Tuile::getXOnScreen() {
  return this -> x_on_screen;
}

int Tuile::getYOnScreen() {
  return this -> y_on_screen;
}

void Tuile::setX(int a) {
  this -> x = a;
  x_on_screen = x * 139;
}

void Tuile::setY(int a) {
  this -> y = a;
  y_on_screen = y * 139;
}


void Tuile::pivoter() {
  reverse(vest.begin(),vest.end());//on retourne le vector car quand on pivote, quand l'est passe au sud le sens du vector change
  reverse(vouest.begin(),vouest.end());//pareil pour l'ouest qui passe au nord
  vector<int> nouv_vest = vnord;
  vector<int> nouv_vsud = vest;
  vector<int> nouv_vouest = vsud;
  vector<int> nouv_vnord = vouest;
  this->vest = nouv_vest;
  this->vsud = nouv_vsud;
  this->vouest = nouv_vouest;
  this->vnord = nouv_vnord;
}

int Tuile::match_haut(Tuile *b) {
  if(!b) {
    return 0;
  } else if(vector_egaux(this -> vnord, b -> vsud)) { //si y a correspondance on renvoie le score du coté haut de la tuile (car on verifie le haut ici)
    return somme_vector(this -> vnord, b -> vsud);
  } else {
    return -1;
  }
}

int Tuile::match_bas(Tuile *h) {
  if(!h) {
    return 0;
  } else if(vector_egaux(this -> vsud, h -> vnord)) {
    return somme_vector(this -> vsud, h -> vnord);
  } else {
    return -1;
  }
}

int Tuile::match_gauche(Tuile *d) {
  if(!d) {
    return 0;
  } else if(vector_egaux(this -> vouest, d -> vest)) {
    return somme_vector(this -> vouest, d -> vest);
  } else {
    return -1;
  }
}

int Tuile::match_droite(Tuile *g) {
  if(!g) {
    return 0;
  } else if(vector_egaux(this -> vest, g -> vouest)) {
    return somme_vector(this -> vest, g -> vouest);
  } else {
    return -1;
  }
}

int Tuile::somme_vector(vector<int> v1, vector<int> v2) {
  int tot = 0;
  for(int i = 0; i < 3; i++) {
    tot += v1[i] + v2[i];
  }
  return tot;
}

bool Tuile::vector_egaux(vector<int> v1, vector<int> v2) {
  for(int i = 0; i < 3; i++) {
    if(v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

ostream& operator<<(ostream& out, Tuile &t) {
  out << "Vnord : \n";
  for (int i=0; i<3; i++) {
    out << t.getVnord().at(i);
  }
  out << "\nVest : \n";
  for (int i=0; i<3; i++) {
    out << t.getVest().at(i);
  }
  out << "\nVsud : \n";
  for (int i=0; i<3; i++) {
    out << t.getVsud().at(i);
  }
  out << "\nVouest : \n";
  for (int i=0; i<3; i++) {
    out << t.getVouest().at(i);
  }
  out << "\n";
  return out;
}



