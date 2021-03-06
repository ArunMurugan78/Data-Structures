#include <iostream>
#include "./Node.cpp"
using namespace std;

template <typename T>
class LinkedList
{

private:
  Node<T> *head; // has properties data and next

public:
  LinkedList()
  {
    this->head = nullptr;
  }

  void print()
  {
    //works only if type T has operator Overload for <<
    Node<T> *temp = this->head;
    while (temp)
    {
      try
      {
        std::cout << temp->data << "\n";
      }
      catch (std::exception)
      {
        std::cout << "Type does not have Overload for << i.e Type not printable";
        break;
      }
      temp = temp->next;
    }
  }

  friend ostream &operator<<(ostream &output, LinkedList<T> &l)
  {
    //works only if type T has operator Overload for <<
    Node<T> *temp = l.head;
    while (temp)
    {
      try
      {
        output << temp->data << "\n";
      }
      catch (std::exception)
      {
        output << "Type does not have Overload for << i.e Type not printable";
        break;
      }
      temp = temp->next;
    }
    return output;
  }

  void push_front(T data)
  { // adds element in constant Time

    Node<T> *newNode = new Node<T>(data);

    if (!this->head)
    {
      this->head = newNode;
    }
    else
    {
      newNode->next = this->head;
      this->head = newNode;
    }
  }

  void pop_front()
  {
    if (this->head)
    {
      Node<T> *temp = this->head;
      this->head = this->head->next;
      delete temp;
    }
  }

  void pop_back()
  {

    if (this->head)
    {
      Node<T> *ptr = this->head;
      Node<T> *prev = nullptr;

      if(!ptr){
        this.head = nullptr;
      }

      while (ptr)
      {
        if (!ptr->next)
        {
          if (prev)
          {
            prev->next = nullptr;
          }
          else
          {
            this->head = nullptr;
          }
          delete ptr;
          break;
        }
        prev = ptr;
        ptr = ptr->next;
      }
    }
  }

  bool find(T data)
  {

    Node<T> *ptr = this->head;

    while (ptr)
    {
      // works only when Type T has Overload for ==
      if (ptr.data == data)
      {
        return true;
      }
      ptr = ptr->next;
    }
    return false;
  }

  bool remove(T data)
  {
    // return true for succes and false for error
    Node<T> *ptr = this->head;
    Node<T> *prev = nullptr;

    while (ptr)
    {
      // works only when Type T has Overload for ==
      if (ptr.data == data)
      {

        if (!prev)
        {
          this->pop_front();
        }
        else
        {
          prev->next = ptr->next;
          delete ptr;
        }

        return true;
      }

      prev = ptr;
      ptr = ptr->next;
    }
    return false;
  }

  void push_back(T data)
  { // runs in O(n)
    Node<T> *newNode = new Node<T>(data);

    Node<T> *ptr = this->head;

    if (!ptr)
    {
      this->head = newNode;
    }
    while (ptr)
    {
      if (!ptr->next)
      {
        ptr->next = newNode;
        break;
      }
      ptr = ptr->next;
    }
  }

  ~LinkedList()
  {
    // De Allocate the allocated space
    Node<T> *temp = this->head;

    while (head)
    {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
};
