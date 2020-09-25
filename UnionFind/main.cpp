#include <iostream>
#include "./union_find.cpp"
using namespace std;

int main()
{
    UnionFind<string> uf = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};

    uf.union_both("A", "B");
    uf.union_both("D", "E");
    uf.union_both("B", "D");

    uf.union_both("G","H");
    uf.union_both("I","C");
    uf.union_both("I","G");


    uf.print();

    return 0;
}
