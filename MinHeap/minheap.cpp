#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MinHeap
{
    vector<T> arr;

public:
    void add(T data)
    {
        arr.push_back(data);
        bubbleUp(arr.size() - 1);
    }

    void bubbleUp(int idx)
    {

        if (idx + 1 > arr.size() || idx<0)
        {
            throw new std::bad_exception();
        }

        while (((idx - 1) % 2 == 0 && (idx - 1) / 2 >= 0) || ((idx - 2) % 2 == 0 && (idx - 2) / 2 >= 0))
        {

            const int idx2 = (idx - 1) % 2 == 0 ? (idx - 1) / 2 : (idx - 2) / 2;

            if (arr[idx] < arr[idx2])
            {
                swap(arr[idx], arr[idx2]);
            }
            idx = idx2;
        }
    }

    void bubbleDown(int idx){
         if (idx + 1 > arr.size() || idx<0)
        {
            throw new std::bad_exception();
        }

        while(2*idx+1<arr.size()){

            int temp = idx;

            if(arr[2*idx+1]<arr[idx]){
                swap(arr[2*idx+1],arr[idx]);
                temp = 2*idx+1;
            }

            if(2*idx+2<arr.size() && arr[2*idx+2]<arr[idx]){
                swap(arr[2*idx+2],arr[idx]);
                temp = 2*idx+2;
            }
            if(idx==temp){
                break;
            } else {
                idx = temp;
            }
        }

    }

    void poll(){
        if(arr.size()<=0){
            return;
        } else if (arr.size()==1){
            arr.clear();
        } else {
            swap(arr[0],arr[arr.size()-1]);
            arr.pop_back();
            bubbleDown(0);
        }
    }

    bool isEmpty(){
        return arr.empty();
    }

    T top() {
        if(arr.size()==0){
            throw new std::bad_exception();
        }
        return arr[0];
    }

    void print(){
        for(auto x:arr){
            cout<<x<<"\n";
        }
    }
};