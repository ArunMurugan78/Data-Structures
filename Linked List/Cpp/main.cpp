#include<iostream>

#include "./LinkedList.cpp"



int main () {
  LinkedList<int> s;
  s.push_front(10);
  s.push_front(1);
  s.push_front(112);
  s.pop_back();
  std::cout<<s;

  return 0;
}
