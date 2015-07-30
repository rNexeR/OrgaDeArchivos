#include <iostream>

using namespace std;

typedef struct AVLNode AVLTree;
struct AVLNode
{
int dato;
AVLTree izq;
AVLTree der;
int altura;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
