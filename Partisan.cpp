#include "Partisan.hpp"


Partisan::Partisan(int i, int j,char c) : x{i}, y{j} , color{c} {}

Partisan::Partisan(Partisan &p) : x{p.x}, y{p.y}, color{p.color} {}

Partisan::~Partisan() {}


int Partisan::getX() {
    return this -> x;
}

int Partisan::getY() {
    return this -> y;
}

char Partisan::getColor() {
    return this -> color;
}

void Partisan::setX(int a) {
    this -> x = a;
}

void Partisan::setY(int a) {
    this -> y = a;
} 

void Partisan::setColor(char a) {
    this -> color = a;
}