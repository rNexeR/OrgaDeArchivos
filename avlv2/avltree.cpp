#include "avltree.h"

AVLTree::AVLTree()
{

}

AVLNode *AVLTree::vacio()
{

    return NULL;
}

AVLNode *AVLTree::hacer(int x, AVLNode *izq, AVLNode *der)
{
  AVLNode *temp = new AVLNode();
  temp->dato = x;
  temp->der = der;
  temp->izq = izq;
  temp->altura =0;
  return temp;
}

bool AVLTree::es_vacio(AVLNode *t)
{
    if(t==NULL){
        return true;
    }else{
        return false;
    }
}

AVLNode *AVLTree::izquierdo(AVLNode *t)
{
    return t->izq;
}

AVLNode *AVLTree::derecho(AVLNode *t)
{
    return t->der;
}

int AVLTree::raiz(AVLNode *t)
{
    if(!es_vacio(t)){
        return t->dato;
    }else{
        return -1;
    }
}

int AVLTree::altura(AVLNode *t)
{
    if(es_vacio(t)){
        return -1;
    }else{
        return t->altura;
    }
}

void AVLTree::actualizar_altura(AVLNode *t)
{
    if(!es_vacio(t))
        t->altura = max (altura ((t)->izq), altura ((t)->der)) + 1;
}

void AVLTree::rotar_s(AVLNode **t, bool izq)
{
    AVLNode *t1;
    if (izq) /* rotación izquierda */
    {
    t1 = izquierdo (*t);
    (*t)->izq = derecho (t1);
    t1->der = *t;
    }
    else /* rotación derecha */
    {
    t1 = derecho (*t);
    (*t)->der = izquierdo (t1);
    t1->izq = *t;
    }
    /* actualizamos las alturas de ambos nodos modificados */
    actualizar_altura (*t);
    actualizar_altura (t1);
    /* asignamos nueva raíz */
    *t = t1;

}

void AVLTree::rotar_d(AVLNode **t, bool izq)
{
    if (izq)
    /* rotación izquierda */
    {
    rotar_s (&(*t)->izq, false);
    rotar_s (t, true);
    }
    else
    /* rotación derecha */
    {
    rotar_s (&(*t)->der, true);
    rotar_s (t, false);
    }
    /* la actualización de las alturas se realiza en las rotaciones
    simples */

}

void AVLTree::balancear(AVLNode **t)
{
    if(!es_vacio(*t)){
        if (altura (izquierdo (*t)) - altura (derecho (*t)) == 2)
        {
        /* desequilibrio hacia la izquierda! */
        if (altura ((*t)->izq->izq) >= altura ((*t)->izq->der))
        /* desequilibrio simple hacia la izquierda */
        rotar_s (t, true);
        else
        /* desequilibrio doble hacia la izquierda */
        rotar_d (t, true);
        }
        else if (altura (derecho (*t)) - altura (izquierdo (*t)) == 2)
        {
        /* desequilibrio hacia la derecha! */
        if (altura ((*t)->der->der) >= altura ((*t)->der->izq))
        /* desequilibrio simple hacia la izquierda */
        rotar_s (t, false);
        else
        /* desequilibrio doble hacia la izquierda */
        rotar_d (t, false);
        }
        }


}

void AVLTree::insertar(AVLNode **t, int x)
{
    if (es_vacio (*t))
    *t = hacer (x, vacio (), vacio ()); /* altura actualizada
    automáticamente */
    else
    {
    if (x < raiz (*t))
    insertar (&(*t)->izq, x);
    else
    insertar (&(*t)->der, x);
    balancear (t);
    actualizar_altura (*t);
    }

}





