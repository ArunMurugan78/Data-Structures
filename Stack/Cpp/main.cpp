#include<iostream>
#include "./Stack.cpp"

int main(){
Stack<int> s;
s.push(10);
s.push(20);
s.push(11);
s.pop();
s.print();
return 0;
}
