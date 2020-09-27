#include<iostream>
#include "./fenwicktree.cpp"

using namespace std;

int main(){
    FenwickTree ft = { 1 ,2 ,3,4,10,6,7};
    
    ft.update(2,4);
    cout<<ft.rangeQuery(2,5);

    return 0;
}