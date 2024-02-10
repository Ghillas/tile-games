CPP=g++ --std=c++11 -Wall 
SF=-lsfml-graphics -lsfml-window -lsfml-system

all : main

main : joueur.o tuile.o dominocarre.o vuedomino.o tuiletrax.o trax.o vuetrax.o carcassonne.o partisan.o vuecarcassonne.o main.o
	$(CPP) -o main Joueur.o Tuile.o DominoCarre.o VueDomino.o TuileTrax.o Trax.o VueTrax.o Carcassonne.o Partisan.o VueCarcassonne.o main.o $(SF)

joueur.o : Joueur.cpp
	$(CPP) -c Joueur.cpp $(SF)

tuile.o : Tuile.cpp
	$(CPP) -c Tuile.cpp $(SF)

dominocarre.o : DominoCarre.cpp
	$(CPP) -c DominoCarre.cpp $(SF)

vuedomino.o : VueDomino.cpp
	$(CPP) -c VueDomino.cpp $(SF)

vuetrax.o : VueTrax.cpp
	$(CPP) -c VueTrax.cpp $(SF)

tuiletrax.o : TuileTrax.cpp
	$(CPP) -c TuileTrax.cpp $(SF)

trax.o : Trax.cpp
	$(CPP) -c Trax.cpp $(SF)

carcassonne.o : Carcassonne.cpp
	$(CPP) -c Carcassonne.cpp $(SF)

partisan.o : Partisan.cpp
	$(CPP) -c Partisan.cpp $(SF)

vuecarcassonne.o : VueCarcassonne.cpp
	$(CPP) -c VueCarcassonne.cpp $(SF)

main.o : main.cpp
	$(CPP) -c main.cpp $(SF)


clean :
	rm *.o
	rm main
