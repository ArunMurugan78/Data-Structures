#include <iostream>
#include "./hashtable.cpp"
using namespace std;

int hash_string(string s)
{
    hash<string> h;

    return h(s);
}

int main()
{
    HashTable<string, int> ht([](string s) {
        return hash_string(s);
    });

    ht.add("One", 1);
    ht.add("Two", 2);
    ht.add("Three", 3);
    ht.add("Four", 4);

  

    cout<<ht.get("One")<<"\n";
    cout<<ht.get("Two")<<"\n";
    cout<<ht.get("Three")<<"\n";
    cout<<ht.get("Four")<<"\n";

    return 0;
}