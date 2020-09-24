#include<iostream>
#include<vector>
#include "./minheap.cpp"
using namespace std;


int main(){

    MinHeap<int> h;

    vector<int> v = {1,8,1,9,3,0,2,34,7,21};

    for(auto x:v){
        h.add(x);
    }
 
    while(!h.isEmpty()){
        cout<<h.top()<<"\n";
        h.poll();
    }
    

    return 0;
}