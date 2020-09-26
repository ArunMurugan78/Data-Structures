#include <iostream>
#include <vector>
using namespace std;

template <typename Key, typename Value>
struct HashNode
{
    Key key;
    Value value;

    HashNode(Key key, Value val) : key(key), value(val) {}
};

template <typename Key, typename Value>
class HashTable
{
    vector<HashNode<Key, Value> *> arr;
    float load_factor;
    long long total;
    long long max_capacity;
    int (*hash_func)(Key);
    int (*probing_func)(int);

public:
    HashTable(
        int (*func)(Key), int (*probing_func)(int) = [](int idx) { return idx + 1; }, float load_factor = 0.5)
    {
        this->hash_func = func;
        this->probing_func = probing_func;
        this->load_factor = load_factor;
        total = 0;
        max_capacity = 100;
        arr = vector<HashNode<Key, Value> *>(max_capacity, nullptr);
    }

    bool contains(Key key)
    {
        long long idx = this->hash_func(key) % max_capacity;

        while (1)
        {

            if (!arr[idx])
            {
                return false;
            }
            else if (arr[idx]->key == key)
            {
                return true;
            }

            else
            {
                idx = this->probing_func(idx);
            }
        }
    }

    Value get(Key key)
    {

        long long idx = this->hash_func(key) % max_capacity;

        while (1)
        {

            if (!arr[idx])
            {
                throw new std::bad_exception();
            }
            else if (arr[idx]->key == key)
            {
                return arr[idx]->value;
            }

            else
            {
                idx = this->probing_func(idx);
            }
        }
    }

    void add(Key key, Value val)
    {
        long long idx = this->hash_func(key) % max_capacity;

        while (1)
        {
            if (!arr[idx])
            {
                arr[idx] = new HashNode<Key, Value>(key, val);

                break;
            }
            else
            {
                idx = this->probing_func(idx);
            }
        }

        if (arr.size() != 0 && total / arr.size() > 0.5)
        {
            arr.resize(2 * total);
            max_capacity = 2 * total;

            for(long long i=0;i<arr.size()/2;i++){
                if(arr[i]){
                    if(this->hash_func(arr[i]->key)%max_capacity!=i){
                        arr[this->hash_func(arr[i]->key)%max_capacity] = arr[i];
                        arr[i] = nullptr;
                    }
                }
            }
        }
    }

    ~HashTable()
    {
        for (auto x : arr)
        {
            if (x)
            {
                delete x;
            }
        }
    }
};