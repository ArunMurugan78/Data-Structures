#include<iostream>

using namespace std;

template<typename Type>
struct Node {
  Type data;
  Node<Type>* next;
  Node(Type data){
    this->data = data;
  }
};


template<typename Type>
class Stack {
  private :
    Node<Type>* ptr;

  public:
    Stack(){
      ptr = nullptr;
    }

  void push(Type data){
    Node<Type>* newNode = new Node<Type>(data);
    if(!this->ptr){
      this->ptr = newNode;
    } else {
      newNode->next = this->ptr;
      this->ptr = newNode;
    }

  }

  Type front(){
    return this->ptr ? this->ptr->data : NULL;
  }

  void pop(){

    if(this->ptr){
      this->ptr = this->ptr->next;
    }
  }

  void print(){
    Node<Type>* temp = this->ptr;
    while(temp){
      std:cout<<temp->data<<'\n';
      temp = temp->next;
    }
  }

  ~Stack(){
    Node<Type>* temp = this->ptr;
    while(ptr){
      temp = ptr;
      this->ptr = this->ptr->next;
      delete temp;
    }
  }
};
