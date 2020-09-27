#include <iostream>
#include <vector>

using namespace std;

class FenwickTree
{
    vector<long long> arr;
    vector<long long> sums;



public:

    long long getLSB(long long n)
    {
        long  long bit = 0;

        while (!(n & bit))
        {
            bit++;
        }
        return bit;
    }
    FenwickTree() {}

    void add(long long data){
        arr.push_back(data);
        long long total = 0;
        long lsb = this->getLSB(arr.size());
        for(long i=lsb;i>=0;i--){
            total += arr[arr.size()-i];
        }
        sums.push_back(total);
    }

    void print(){
        for(auto x:sums){
            cout<<"x: "<<x<<"\n";
        }
    }

    void update(long idx,long long newValue){

        if(idx>=arr.size()){
            throw new exception();
        }
        const long long oldValue = arr[idx];

        for(long i=idx;i<arr.size();i++){
          if(getLSB(i) >=(i-idx)){
              sums[i] += newValue - oldValue;
          }
        }

    }

    long long rangeQuery(long idx1,long idx2){
        if(idx1>=arr.size() || idx2>=arr.size()){
            throw new exception();
        } else {
            if(idx2<idx1){
                swap(idx1,idx2);
            }
            long long total1 = 0,total2 = 0;

            for(long i=idx2;i>=0;){
                total1 += sums[i];
                i -= getLSB(i+1);
             
               
            }


            for(long i=idx1-1;i>=0;){
                total2 += sums[i];
                i -= getLSB(i+1);
             
               
            }

            return total1-total2;
        }
    }

    FenwickTree(vector<long long> v)
    {
        for(auto x:v){
            this->add(x);
        }
    }
    FenwickTree(initializer_list<long long> v)
    {
        for(auto x:v){
            this->add(x);
        }
    }

};