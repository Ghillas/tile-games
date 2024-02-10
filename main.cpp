#include "Joueur.hpp"
#include "Tuile.hpp"
#include "DominoCarre.hpp"
#include "VueDomino.hpp"
#include "TuileTrax.hpp"
#include "Trax.hpp"
#include "VueTrax.hpp"
using namespace std;

bool isNumeric(string str) {
   for (long unsigned int i = 0; i < str.length(); i++) {
      if (isdigit(str[i]) == false) {
         return false; //when one non numeric value is found, return false
      }
   }
   return true;
}

int main(int argc, char *argv[]) { // 2 args
  cout << "Bonjour et bienvenue, à quel jeu voulez-vous jouer ?" << endl;
  cout << "Vous pouvez jouer aux dominos, Trax et Carcassone(non implementé)." << endl;
  string choice;
  string names;
  cin >> choice;
  for_each(choice.begin(), choice.end(), [](char & c){
    c = ::tolower(c);
  });
  vector<Joueur *> players;
  if (choice == "dominos" || choice == "domino") {
    cout << "Combien de joueurs ?" << endl;
    string cb;
    vector<Tuile *> tuiles;
    cin >> cb;
    bool is_good_1 = false;
    bool is_good_2 = false;
    if(isNumeric(cb)) {
      int cb_i = stoi(cb);
      for (int i=0; i<cb_i; i++) {
        cout << "\nJoueur " << i << ", votre nom ?" << endl;
        cin >> names;
        Joueur *tmp = new Joueur(names);
        players.push_back(tmp);
      }
      is_good_1 = true;
    }
    cout << "Combien de tuiles dans le sac?" << endl;
    cin >> cb;
    if(isNumeric(cb)) {
      int cb_i = stoi(cb);
      for (int i=0; i<cb_i; i++) {
        Tuile *tmp = new Tuile();
        tuiles.push_back(tmp);
      }
      is_good_2 = true;
    }
    if(is_good_1 && is_good_2) {
      DominoCarre dom = DominoCarre{players,tuiles};
      VueDomino a = VueDomino{dom};
      a.partie();
    } else {
      cout << "une erreur c'est produite dans la création de la partie" << endl;
    }
  }

  else if (choice == "trax") {
    for (int i=0; i<2; i++) {
      cout << "\nJoueur " << i << ", votre nom ?" << endl;
      cin >> names;
      Joueur *tmp = new Joueur(names);
      players.push_back(tmp);
    }
    Trax tra = Trax{players};
    VueTrax v = VueTrax{tra};
    v.partie();
  }

  else if (choice == "carcassone") {
    cout << "Non implementé" << endl;
  }
    
  else {
    cout << "Nous n'avons pas compris votre demande" << endl;
  }

  return EXIT_SUCCESS;
}
