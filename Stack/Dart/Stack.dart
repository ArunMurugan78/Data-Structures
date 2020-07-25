
class Node<Type> {
  Type data;
  Node<Type> next;
  Node(Type data){
    this.data = data;
  }
}

class Stack<Type> {
  Node<Type> ptr;
  Stack(){
    this.ptr = null;
  }

  void push(Type data){
    Node<Type> newNode = Node<Type>(data);
    if(this.ptr==null){
      this.ptr = newNode;
    } else {
      newNode.next =  this.ptr;
      this.ptr = newNode;
    }
  }

  void printStack(){
    Node<Type> temp = this.ptr;
    while(temp != null){
      print(temp.data);
      temp = temp.next;
    }
  }

  Type pop(){
    if(this.ptr != null){
      this.ptr = this.ptr.next;
    }
  }
}
