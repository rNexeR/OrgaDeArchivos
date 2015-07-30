#include <QCoreApplication>
#include <avltree.h>
#include <avlnode.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AVLTree * tree = new AVLTree();
    AVLNode * raiz = tree->vacio();
    tree->insertar(&raiz,20);
    tree->insertar(&raiz,23);
    tree->insertar(&raiz,21);


    return a.exec();
}
