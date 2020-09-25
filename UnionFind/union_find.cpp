#include <iostream>
#include<vector>
#include <map>

using namespace std;

template <typename T>
class UnionFind
{
    map<T, T> ht;
    map<T, long long> size;

public:
    UnionFind() {}
    UnionFind(initializer_list<T> list)
    {
        for (auto x : list)
        {
            ht[x] = x;
            size[x] = 1;
        }
    }
    // to add a new Data, sets parent of that data to itself
    void add(T data)
    {
        if (ht.find(data) == ht.end())
        {
            ht[data] = data;
            size[data] = 1;
        }
    }

    void print(){
        for(auto x:ht){
            cout<<x.first<<" --> "<<x.second<<"\n";
        }
    }

    T find_root(T data)
    {
        if (ht[data] == data)
        {
            return data;
        }
        else
        {
            return find_root(ht[data]);
        }
    }

    void union_both(T data1, T data2)
    {
        add(data1);
        add(data2);

        T parent1 = find_root(data1);

        T parent2 = find_root(data2);

        if (size[parent1] < size[parent2])
        {
            swap(data1, data2);
            swap(parent1,parent2);
        }

        vector<T> temp;

        for (auto x : ht)
        {
            if (find_root(x.first) == parent2)
            {
                temp.push_back(x.first);
            }
        }

        for(auto x:temp){
            ht[x] = parent1;
        }
        
        size[parent1] += size[parent2];
    }

    bool find(T data1, T data2)
    {
        return find_root(data1) == find_root(data2);
    }
};
