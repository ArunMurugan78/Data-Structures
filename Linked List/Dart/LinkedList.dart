import "Node.dart";

class LinkedList<Type> {
  Node<Type> head;

  LinkedList() {
    this.head = null;
  }

  void printList() {
    Node<Type> temp = this.head;
    while (temp != null) {
      print(temp.data);
      temp = temp.next;
    }
  }

  void push_front(Type data) {
    Node<Type> newNode = Node<Type>(data: data);
    newNode.next = this.head;
    this.head = newNode;
  }

  bool find(Type data) {
    Node<Type> ptr = this.head;
    while (ptr != null) {
      if (ptr.data == data) {
        return true;
      }
      ptr = ptr.next;
    }
    return false;
  }

  void pop_front() {
    if (this.head != null) {
      this.head = this.head.next;
    }
  }

  void pop_back() {
    Node<Type> ptr = this.head;
    Node<Type> prev = null;

    while (ptr != null) {
      if (ptr.next == null) {
        if (prev != null) {
          prev.next = null;
        } else {
          this.head = null;
        }
        break;
      }
      prev = ptr;
      ptr = ptr.next;
    }
  }

  bool remove(Type data) {
    Node<Type> ptr = this.head;
    Node<Type> prev = null;

    while (ptr != null) {
      if (ptr.data == data) {
        if (prev == null) {
          this.pop_front();
        } else {
          prev.next = ptr.next;
        }
        return true;
      }
      prev = ptr;
      ptr = ptr.next;
    }
    return false;
  }

  void push_back(Type data) {
    Node<Type> newNode = Node<Type>(data: data);
    Node<Type> temp = this.head;

    if (temp == null) {
      this.head = newNode;
    }

    while (temp != null) {
      if (temp.next == null) {
        temp.next = newNode;
        break;
      }
      temp = temp.next;
    }
  }
}
