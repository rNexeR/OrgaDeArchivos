#ifndef AVLTREE_H
#define AVLTREE_H
#include <avlnode.h>
#include <iostream>


using namespace std;

class AVLTree
{


public:


    AVLTree();
    AVLNode *vacio ();
    AVLNode *hacer (int x, AVLNode * izq, AVLNode * der);
    bool es_vacio (AVLNode * t);
    /*
    Selectores
    */
    AVLNode *izquierdo (AVLNode * t);
    /* devuelve el subárbol izquierdo de t. */
    AVLNode *derecho (AVLNode * t);
    /* devuelve el subárbol derecho de t. */
    int raiz (AVLNode* t);
    int altura (AVLNode * t);
    void actualizar_altura (AVLNode * t);
    void rotar_s (AVLNode ** t, bool izq);
    void rotar_d (AVLNode ** t, bool izq);
    void balancear (AVLNode ** t);
    void insertar (AVLNode** t, int x);

};

#endif // AVLTREE_H
