#include "VueTrax.hpp"
#include<SFML/Graphics.hpp>
#include<vector>

using namespace std;
using namespace sf;


VueTrax::VueTrax(Trax t) : jeu{t} {}

VueTrax::~VueTrax() {}


void VueTrax::partie() {
  RenderWindow app(VideoMode(1400, 1000, 32), "Trax");
  app.setKeyRepeatEnabled(false);

  Texture tex1;
  Texture tex1bis;
  Texture tex2;
  Texture tex2_2;
  Texture tex2_3;
  Texture tex2_4;
  tex1.loadFromFile("./ressources/trax_croix1.png");
  tex1bis.loadFromFile("./ressources/trax_croix2.png");
  tex2.loadFromFile("./ressources/trax_courbes1.png");
  tex2_2.loadFromFile("./ressources/trax_courbes2.png");
  tex2_3.loadFromFile("./ressources/trax_courbes3.png");
  tex2_4.loadFromFile("./ressources/trax_courbes4.png");
  Font font;
  font.loadFromFile("./ressources/ma_police.ttf");


  vector<Sprite> all_sprite;
  vector<TuileTrax *> mon_sac = jeu.getSac();
  TuileTrax *tuile_actuelle = nullptr;
  Sprite sprite_actuelle;

  Joueur *tour = jeu.getJoueurs().at(0);
  int id_tour = 0;
  bool isFirst = true;
  bool gagnant = false;

  while (app.isOpen()) {
    Event event;
    while (app.pollEvent(event)) {
      switch (event.type) {
      case Event::Closed :
	app.close();
	break;
      case Event::KeyPressed :
	if (event.key.code == Keyboard::R) {
	  if (tuile_actuelle != nullptr) {
	    tuile_actuelle->pivoter();
	    //on recupere la bonne des textures en fonction des valeur de la tuile
	    if (tuile_actuelle->getNord() == 'N' && tuile_actuelle->getSud() == 'N') {
	      all_sprite[all_sprite.size()-1].setTexture(tex1);
	    }
	    else if (tuile_actuelle->getNord() == 'B' && tuile_actuelle->getSud() == 'B') {
	      all_sprite[all_sprite.size()-1].setTexture(tex1bis);
	    }
	    else if (tuile_actuelle->getNord() == 'B' && tuile_actuelle->getEst() == 'B') {
	      all_sprite[all_sprite.size()-1].setTexture(tex2);
	    }
	    else if (tuile_actuelle->getNord() == 'N' && tuile_actuelle->getEst() == 'B') {
	      all_sprite[all_sprite.size()-1].setTexture(tex2_2);
	    }
	    else if (tuile_actuelle->getNord() == 'N' && tuile_actuelle->getEst() == 'N') {
	      all_sprite[all_sprite.size()-1].setTexture(tex2_3);
	    }
	    else if (tuile_actuelle->getNord() == 'B' && tuile_actuelle->getEst() == 'N') {
	      all_sprite[all_sprite.size()-1].setTexture(tex2_4);
	    }
	  }

	} break;
      case Event::MouseButtonPressed :
	if (event.mouseButton.button == Mouse::Left) {
	  if (tuile_actuelle != nullptr) {
	    Vector2f mouse = app.mapPixelToCoords(Mouse::getPosition(app));
	    int score_case = 0;
	    if(id_tour % 2 == 0) {
	      score_case = getCaseClick(mouse, tuile_actuelle,'B');
	    } else { 
	      score_case = getCaseClick(mouse, tuile_actuelle, 'N');
	    }
	    if (score_case >= 0 || isFirst) {
	      isFirst = false;
	      tuile_actuelle->setX((int)mouse.x/63);
	      tuile_actuelle->setY((int)mouse.y/63);
	      all_sprite[all_sprite.size() - 1].move(tuile_actuelle->getXOnScreen(), tuile_actuelle->getYOnScreen());
	      jeu.addTuile(*tuile_actuelle);

			if(id_tour % 2 == 0) {
				if(jeu.boucle_gagnante(tuile_actuelle,nullptr,tuile_actuelle,'B') || jeu.chemin_gagnant()) {
					cout << tour -> getName() << " a gagné" << endl;
					gagnant = true;
				}
			} else {
				if(jeu.boucle_gagnante(tuile_actuelle,nullptr,tuile_actuelle,'N') || jeu.chemin_gagnant()) {
					cout << tour -> getName() << " a gagné" << endl;
					gagnant = true;
				}
			}

	      tuile_actuelle = nullptr;
	      // tour->setScore(...)
	      id_tour = (id_tour+1)%2;
	      tour = jeu.getJoueurs().at(id_tour);
	    }
	  }
	}
      default : break;
      }
    }

    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
      if (tuile_actuelle == nullptr) {
			if (mon_sac.empty() || gagnant) { // verifier s'il y a un chemin gagnant et retourner le vainqueur
				app.close();
				cout << "la partie est terminée" << endl;
			}
			else {
				srand(time(NULL));
				int i = rand() % mon_sac.size();
				tuile_actuelle = mon_sac.at(i);
				mon_sac.erase(mon_sac.begin() + i);
				if (id_tour % 2 == 0) {
					cout << "Au tour de " << tour -> getName() << " (Blanc)" << endl;
				} else {
					cout << "Au tour de " << tour -> getName() << " (Noir)" << endl;

				}
				//on recupere la bonne texture en fonction des valeur de la tuile
				if (tuile_actuelle->getNord() == 'N' && tuile_actuelle->getSud() == 'N') {
					sprite_actuelle.setTexture(tex1);
				}
				else if (tuile_actuelle->getNord() == 'B' && tuile_actuelle->getSud() == 'B') {
					sprite_actuelle.setTexture(tex1bis);
				}
				else if (tuile_actuelle->getNord() == 'B' && tuile_actuelle->getEst() == 'B') {
					sprite_actuelle.setTexture(tex2);
				}
				else if (tuile_actuelle->getNord() == 'N' && tuile_actuelle->getEst() == 'B') {
					sprite_actuelle.setTexture(tex2_2);
				}
				else if (tuile_actuelle->getNord() == 'N' && tuile_actuelle->getEst() == 'N') {
					sprite_actuelle.setTexture(tex2_3);
				}
				else if (tuile_actuelle->getNord() == 'B' && tuile_actuelle->getEst() == 'N') {
					sprite_actuelle.setTexture(tex2_4);
				}
				sprite_actuelle.setScale(Vector2f(0.1,0.1));
				all_sprite.push_back(sprite_actuelle);
			}
	  	}
	}
      
    app.clear();
    for (Sprite s : all_sprite) {
      app.draw(s);
    }
    app.display();
  }
}


int VueTrax::getCaseClick(Vector2f mouse, TuileTrax* tuile_actuelle, char c) {
  int x_click = (int)mouse.x / 63;
  int y_click = (int)mouse.y / 63;
  bool est_libre = jeu.case_libre(x_click,y_click);
  if(est_libre) {
    int attache = jeu.nb_environ(x_click,y_click);
    if(attache == 0) {
      cout << "La case choisit n'est attaché a aucune case" << endl;
      return -1;
    } else {
		if(!jeu.estDansJeu(x_click,y_click)) {
			cout << "La limite du plateau de 8x8 a été dépasser" << endl;
			return -1;
		} else {
			int score = jeu.tuile_correspond(tuile_actuelle,x_click,y_click, c);
			if(score == -1) {
			cout << "La tuile ne peut pas etre placé ici car il n'y a pas de correspondance avec les tuiles autour" << endl;
			}
			return score;
		}
    }
  } else {
    cout << "La case choisit est deja occupé" << endl;
    return -1;
  }
}
