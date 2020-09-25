#include <iostream>
#include "./bst.cpp"
using namespace std;

int main()
{

    BST<int> bst;

    bst.add(1);
    bst.add(56);
    bst.add(7);
    bst.add(8);
    bst.add(9);
    bst.add(3);
    bst.add(8);
    bst.add(4);
    

    bst.in_order();
    return 0;
}
