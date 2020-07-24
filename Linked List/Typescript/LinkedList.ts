import { Node } from './Node'; 

class LinkedList<Type>{
    private head : Node<Type>|null;

    constructor(){
        this.head = null
    }

    print():void{
        let ptr : Node<Type>|null = this.head;

        while(ptr!==null){
            console.log(ptr.data);
            ptr = ptr.next;
        }
    }
    push_front(data:Type):void{
        const newNode : Node<Type>|null = new Node<Type>(data);
        let ptr : Node<Type>|null = this.head;
        if(ptr===null){
            this.head = newNode;
        }
        else {
            newNode.next = this.head;
            this.head = newNode;
        }

    }

    find(data:Type):boolean{
        let ptr : Node<Type>|null = this.head;
        while(ptr){
            if(ptr.data===data){
                return true;
            }
            ptr = ptr.next;
        }
        return false;
    }

    pop_front():void{
        if(this.head){
            this.head = this.head.next;
        }
    }
    pop_back():void{
        let ptr:Node<Type>|null = this.head;
        let prev:Node<Type>|null = null;
        if(ptr===null){
            this.head = null;
        }
        while(ptr){
            if(ptr.next===null){
                prev.next = null;
                break;
            }
            prev = ptr;
            ptr =ptr.next;
        }
    }

    remove(data:Type):boolean{
        let ptr : Node<Type>|null = this.head;
        let prev: Node<Type>|null = null;

        while(ptr){
            if(ptr.data===data){
                if(prev===null){
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

    push_back(data:Type):void{
        let ptr : Node<Type>|null = this.head;
        const newNode : Node<Type>|null = new Node<Type>(data);

        if(ptr===null){
            this.head = newNode;
        }

        while(ptr!==null){
            if(ptr.next===null){
                ptr.next = newNode;
                break;
            }
            ptr = ptr.next;
        }
    }

};

export default LinkedList;