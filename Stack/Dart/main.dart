import "./Stack.dart";


void main(){
  Stack<int> s = Stack<int>();
  s.push(10);
  s.push(111);
  s.push(2);
  s.pop();
  s.printStack();
}
