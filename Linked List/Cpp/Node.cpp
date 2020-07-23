

template<typename T>
struct Node {
  T data;
  Node<T>* next;
  Node(){
    next = nullptr;
  }
  Node(T data){
    next = nullptr;
    this->data = data;
  }
};
