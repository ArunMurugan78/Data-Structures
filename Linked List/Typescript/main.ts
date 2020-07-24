import  LinkedList  from './LinkedList'


function main():void {
    let list : LinkedList<number> = new LinkedList<number>();
    list.push_back(11);
    list.push_back(1); 
    list.push_back(112); 
    list.remove(112); 
    list.print();
}



main();