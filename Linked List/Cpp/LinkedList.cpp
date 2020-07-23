#include<iostream>
#include "./Node.cpp"
using namespace std;

template<typename T>
class LinkedList {

  private :
    Node<T>* head;  // has properties data and next

  public:
  LinkedList(){
    this->head = nullptr;
  }

  void print(){
    //works only if type T has operator Overload for <<
    Node<T>*temp = this -> head;
    while(temp){
      try
      {
       std::cout<<temp->data<<"\n";
      }
      catch(std::exception){
        std::cout<<"Type does not have Overload for << i.e Type not printable";
        break;
      }
      temp = temp->next;
    }
  }


 friend  ostream  &operator<<( ostream &output , LinkedList<T>& l){
    //works only if type T has operator Overload for <<
    Node<T>*temp = l.head;
    while(temp){
      try
      {
       output<<temp->data<<"\n";
      }
      catch(std::exception){
        output<<"Type does not have Overload for << i.e Type not printable";
        break;
      }
      temp = temp->next;
    }
    return output;
 }

  void addElement(T data){
     Node<T>* newNode = new Node<T>(data);

     Node<T>* ptr = this->head;

    if(!ptr){
      this-> head = newNode;
   }
    while(ptr)
    {
      if(!ptr->next){
        ptr->next = newNode;
        break;
      }
      ptr = ptr->next;

    }
  }

  ~LinkedList(){
    // De Allocate the allocated space
    const Node<T>* temp = this->head;
    while(head){
      temp = head;
      head = head->next;
      delete temp;
    }
  }

};
