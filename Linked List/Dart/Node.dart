class Node<Type> {
  Type data;
  Node<Type> next;

  Node({this.data, this.next = null});
}
