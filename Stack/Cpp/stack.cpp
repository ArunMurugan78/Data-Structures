#include<iostream>


template<typename T>
class LinkedList {
  private :
    T* ptr;

  public:
  LinkedList(){
    this->ptr = nullptr;
  }

  LinkedList(long num){
    this->ptr = new T[num];
  }

  ~LinkedList(){
    delete this->ptr;
  }

};
