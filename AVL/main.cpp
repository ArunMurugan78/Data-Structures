#include<iostream>
#include "./avl.cpp"
using namespace std;



int main(){
    AVL<int> tree;
    tree.insert(10);
    tree.insert(11);
    cout<<tree.contains(11);
    return 0;
}