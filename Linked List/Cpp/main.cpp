#include<iostream>

#include "./LinkedList.cpp"



int main () {
  LinkedList<int> s;
  s.addElement(10);
  s.addElement(1);
  s.addElement(112);
  s.print();
  std::cout<<s;

  return 0;
}
