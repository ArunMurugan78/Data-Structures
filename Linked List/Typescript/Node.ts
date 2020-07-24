


export class Node <Type> {
     data:Type;
     next:Node<Type> | null;

     constructor(data:Type){
        this.data = data;
        this. next = null;
     }
}