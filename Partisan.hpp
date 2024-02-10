#ifndef PARTISAN_H
#define PARTISAN_H


class Partisan {
private:
    int x;
    int y;
    char color;
public:
    Partisan(int i, int j, char c);
    Partisan(Partisan &p);
    virtual ~Partisan();
    
    int getX();
    int getY();
    char getColor();
    void setX(int a);
    void setY(int a);
    void setColor(char a);
};


#endif
