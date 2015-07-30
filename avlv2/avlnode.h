#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream>


using namespace std;

class AVLNode
{
public:
    AVLNode();
    int dato;
    AVLNode *izq;
    AVLNode *der;
    int altura;
};

#endif // AVLNODE_H
