#include "VueDomino.hpp"
#include<SFML/Graphics.hpp>
#include<vector>

using namespace std;
using namespace sf;


VueDomino::VueDomino(DominoCarre d) : jeu{d} {}

VueDomino::~VueDomino() {}


void VueDomino::partie() {
    RenderWindow app(VideoMode(1400, 1000, 32), "Domino Carre");
    app.setKeyRepeatEnabled(false);

    Texture tex;
    tex.loadFromFile("./ressources/tuile_domino.png");
    Font font;
    font.loadFromFile("./ressources/ma_police.ttf");


    vector<Sprite> all_sprite;
    Sprite centre = Sprite(tex);
    //centre.setScale(Vector2f(0.72,0.72));
    centre.move(jeu.getCentre()->getXOnScreen(), jeu.getCentre()->getYOnScreen());
    all_sprite.push_back(centre);

    vector<vector<Text>> all_text;//chaque vector correspond aux Text d'une seul tuile
    //all_text.push_back(createText(jeu.getCentre()));
    vector<Text> text_tuile;
    for(int i = 0; i < 12; i++) { //on crée 12 Text qui corresponde au chiffres de la tuile du centre
        Text tmp;
        tmp.setFont(font);
        tmp.setFillColor(Color::Black);
        tmp.setCharacterSize(20);
        text_tuile.push_back(tmp);
    }

    //on recupere les chiffres de chaque domino et on les move a la bonne place pour la tuile du centre

    text_tuile[0].setString(to_string(jeu.getCentre()->getVnord().at(0)));
    text_tuile[0].move(jeu.getCentre()->getXOnScreen() + 40, jeu.getCentre()->getYOnScreen() + 5);
    text_tuile[1].setString(to_string(jeu.getCentre()->getVnord().at(1)));
    text_tuile[1].move(jeu.getCentre()->getXOnScreen() + 65, jeu.getCentre()->getYOnScreen() + 5);
    text_tuile[2].setString(to_string(jeu.getCentre()->getVnord().at(2)));
    text_tuile[2].move(jeu.getCentre()->getXOnScreen() + 90, jeu.getCentre()->getYOnScreen() + 5);

    text_tuile[3].setString(to_string(jeu.getCentre()->getVsud().at(0)));
    text_tuile[3].move(jeu.getCentre()->getXOnScreen() + 40, jeu.getCentre()->getYOnScreen() + 108);
    text_tuile[4].setString(to_string(jeu.getCentre()->getVsud().at(1)));
    text_tuile[4].move(jeu.getCentre()->getXOnScreen() + 65, jeu.getCentre()->getYOnScreen() + 108);
    text_tuile[5].setString(to_string(jeu.getCentre()->getVsud().at(2)));
    text_tuile[5].move(jeu.getCentre()->getXOnScreen() + 90, jeu.getCentre()->getYOnScreen() + 108);

    text_tuile[6].setString(to_string(jeu.getCentre()->getVest().at(0)));
    text_tuile[6].move(jeu.getCentre()->getXOnScreen() + 115, jeu.getCentre()->getYOnScreen() + 30);
    text_tuile[7].setString(to_string(jeu.getCentre()->getVest().at(1)));
    text_tuile[7].move(jeu.getCentre()->getXOnScreen() + 115, jeu.getCentre()->getYOnScreen() + 55);
    text_tuile[8].setString(to_string(jeu.getCentre()->getVest().at(2)));
    text_tuile[8].move(jeu.getCentre()->getXOnScreen() + 115, jeu.getCentre()->getYOnScreen() + 80);
    
    text_tuile[9].setString(to_string(jeu.getCentre()->getVouest().at(0)));
    text_tuile[9].move(jeu.getCentre()->getXOnScreen() + 15, jeu.getCentre()->getYOnScreen() + 30);
    text_tuile[10].setString(to_string(jeu.getCentre()->getVouest().at(1)));
    text_tuile[10].move(jeu.getCentre()->getXOnScreen() + 15, jeu.getCentre()->getYOnScreen() + 55);
    text_tuile[11].setString(to_string(jeu.getCentre()->getVouest().at(2)));
    text_tuile[11].move(jeu.getCentre()->getXOnScreen() + 15, jeu.getCentre()->getYOnScreen() + 80);

    all_text.push_back(text_tuile);

    vector<Tuile *> mon_sac = jeu.getSac();
    Tuile * tuile_actuel = nullptr;
    Sprite sprite_actuel = Sprite(tex);

    Joueur *tour = jeu.getJoueur().at(0);
    int id_tour = 0;
    int tot_joueur = jeu.getJoueur().size();

    while (app.isOpen()){
        Event event;
        while (app.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    app.close(); break;
                case Event::KeyPressed:
                    if(event.key.code == Keyboard::R) {
                        if(tuile_actuel != nullptr) {
                            tuile_actuel->pivoter();
                            //on bouge les text de place pour suivre la rotation de la tuile
                            all_text[all_text.size()-1][0].setString(to_string(tuile_actuel->getVnord().at(0)));
                            all_text[all_text.size()-1][1].setString(to_string(tuile_actuel->getVnord().at(1)));
                            all_text[all_text.size()-1][2].setString(to_string(tuile_actuel->getVnord().at(2)));

                            all_text[all_text.size()-1][3].setString(to_string(tuile_actuel->getVsud().at(0)));
                            all_text[all_text.size()-1][4].setString(to_string(tuile_actuel->getVsud().at(1)));
                            all_text[all_text.size()-1][5].setString(to_string(tuile_actuel->getVsud().at(2)));

                            all_text[all_text.size()-1][6].setString(to_string(tuile_actuel->getVest().at(0)));
                            all_text[all_text.size()-1][7].setString(to_string(tuile_actuel->getVest().at(1)));
                            all_text[all_text.size()-1][8].setString(to_string(tuile_actuel->getVest().at(2)));

                            all_text[all_text.size()-1][9].setString(to_string(tuile_actuel->getVouest().at(0)));
                            all_text[all_text.size()-1][10].setString(to_string(tuile_actuel->getVouest().at(1)));
                            all_text[all_text.size()-1][11].setString(to_string(tuile_actuel->getVouest().at(2)));
                        }
                    } break;
                case Event::MouseButtonPressed:
                    if(event.mouseButton.button == Mouse::Left) {
                        if(tuile_actuel != nullptr) {
                            Vector2f mouse = app.mapPixelToCoords(Mouse::getPosition(app));
                            int score_case = getCaseClick(mouse,tuile_actuel); //on recupere les coordonnee du click avec la souris et on regarde si la tuile peut etre placer ici
                            if(score_case >= 0) {
                                tuile_actuel->setX((int)mouse.x / 139);
                                tuile_actuel->setY((int)mouse.y / 139);
                                all_sprite[all_sprite.size()-1].move(tuile_actuel->getXOnScreen(), tuile_actuel->getYOnScreen());
                                for(long unsigned int i = 0; i < all_text[all_text.size()-1].size(); i++) {
                                    all_text[all_text.size()-1][i].move(tuile_actuel->getXOnScreen(), tuile_actuel->getYOnScreen());
                                    //on le deplace seulement de x et y_on_screen car il ne parte pas de 0 mais de leur position precedente
                                }
                                jeu.addTuile(*tuile_actuel);
                                tuile_actuel = nullptr;
                                tour -> setScore(tour -> getScore() + score_case);
                                cout << "le score de " << tour -> getName() << " est de : " << tour -> getScore() << endl;
                                id_tour = (id_tour + 1) % tot_joueur;
                                tour = jeu.getJoueur().at(id_tour);
                                
                            }
                        }
                    }
                default: break;
            }
        }

        

        if(Keyboard::isKeyPressed(Keyboard::Enter)) {

            if(tuile_actuel == nullptr) {
                if(mon_sac.empty()) {
                    app.close();
                    cout << "la partie est terminé" << endl;
                    Joueur *gagnant = jeu.getGagnant();
                    cout << gagnant -> getName() << " a gagné avec un score de : " << gagnant -> getScore() << endl;
                } else {
                    cout << "Au tour de " << tour -> getName() << " de jouer." << endl;
                    tuile_actuel = mon_sac.back();
                    mon_sac.pop_back();
                    all_sprite.push_back(sprite_actuel);
                    
                    vector<Text> text_tuile;
                    for(int i = 0; i < 12; i++) { //on crée 12 Text qui corresponde au chiffres de la tuile du centre
                        Text tmp;
                        tmp.setFont(font);
                        tmp.setFillColor(Color::Black);
                        tmp.setCharacterSize(20);
                        text_tuile.push_back(tmp);
                    }

			//on recupere les chiffres de chaque domino et on les move a la bonne place pour la tuile piocher qui apparaitra en haut a gauche
                    text_tuile[0].setString(to_string(tuile_actuel->getVnord().at(0)));
                    text_tuile[0].move(tuile_actuel->getXOnScreen() + 40, tuile_actuel->getYOnScreen() + 5);
                    text_tuile[1].setString(to_string(tuile_actuel->getVnord().at(1)));
                    text_tuile[1].move(tuile_actuel->getXOnScreen() + 65, tuile_actuel->getYOnScreen() + 5);
                    text_tuile[2].setString(to_string(tuile_actuel->getVnord().at(2)));
                    text_tuile[2].move(tuile_actuel->getXOnScreen() + 90, tuile_actuel->getYOnScreen() + 5);

                    text_tuile[3].setString(to_string(tuile_actuel->getVsud().at(0)));
                    text_tuile[3].move(tuile_actuel->getXOnScreen() + 40, tuile_actuel->getYOnScreen() + 108);
                    text_tuile[4].setString(to_string(tuile_actuel->getVsud().at(1)));
                    text_tuile[4].move(tuile_actuel->getXOnScreen() + 65, tuile_actuel->getYOnScreen() + 108);
                    text_tuile[5].setString(to_string(tuile_actuel->getVsud().at(2)));
                    text_tuile[5].move(tuile_actuel->getXOnScreen() + 90, tuile_actuel->getYOnScreen() + 108);

                    text_tuile[6].setString(to_string(tuile_actuel->getVest().at(0)));
                    text_tuile[6].move(tuile_actuel->getXOnScreen() + 115, tuile_actuel->getYOnScreen() + 30);
                    text_tuile[7].setString(to_string(tuile_actuel->getVest().at(1)));
                    text_tuile[7].move(tuile_actuel->getXOnScreen() + 115, tuile_actuel->getYOnScreen() + 55);
                    text_tuile[8].setString(to_string(tuile_actuel->getVest().at(2)));
                    text_tuile[8].move(tuile_actuel->getXOnScreen() + 115, tuile_actuel->getYOnScreen() + 80);
                    
                    text_tuile[9].setString(to_string(tuile_actuel->getVouest().at(0)));
                    text_tuile[9].move(tuile_actuel->getXOnScreen() + 15, tuile_actuel->getYOnScreen() + 30);
                    text_tuile[10].setString(to_string(tuile_actuel->getVouest().at(1)));
                    text_tuile[10].move(tuile_actuel->getXOnScreen() + 15, tuile_actuel->getYOnScreen() + 55);
                    text_tuile[11].setString(to_string(tuile_actuel->getVouest().at(2)));
                    text_tuile[11].move(tuile_actuel->getXOnScreen() + 15, tuile_actuel->getYOnScreen() + 80);

                    all_text.push_back(text_tuile);
                }
            }
        }


        if(Keyboard::isKeyPressed(Keyboard::D)) {
            if(tuile_actuel != nullptr) {
                tuile_actuel = nullptr;
                all_sprite.pop_back();
                all_text.pop_back();
                cout << "le score de " << tour -> getName() << " est de : " << tour -> getScore() << endl;
                id_tour = (id_tour + 1) % tot_joueur;
                tour = jeu.getJoueur().at(id_tour);
                                
            }
        }

            
        app.clear();

        

        for(Sprite s : all_sprite) {
            app.draw(s);
        }

        for(vector<Text> v : all_text) {
            for(Text t : v) {
                app.draw(t);
            }
        }


        app.display(); // Affichage effectif    
    } // fermeture de la fenêtre

}



int VueDomino::getCaseClick(Vector2f mouse, Tuile *actuel) {
    int x_click = (int)mouse.x / 139;// 139 = taille d'une tuile
    int y_click = (int)mouse.y / 139;
    bool est_libre = jeu.case_libre(x_click,y_click);
    if(est_libre) {
        int attache = jeu.nb_environ(x_click,y_click);
        if(attache == 0) {
            cout << "La case choisit n'est attaché a aucune case" << endl;
            return -1;
        } else {
            int score = jeu.tuile_correspond(actuel,x_click,y_click);
            if(score == -1) {
                cout << "La tuile ne peut pas etre placé ici car il n'y a pas de correspondance avec les tuiles autour" << endl;
            }
            return score;
        }
    } else {
        cout << "La case choisit est deja occupé" << endl;
        return -1;
    }
}
