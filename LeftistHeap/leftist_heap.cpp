#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct Node
{
    T data;
    long npl;
    Node<T> *left;
    Node<T> *right;

    Node(T data) : data(data), npl(0), left(nullptr), right(nullptr){};
};

std::string toBinary(long n)
{
    std::string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

template <typename T>
class LeftistHeap
{
    long total;
    Node<T> *root;

    void update_npl(Node<T> *ptr)
    {
        if(!ptr){
            return;
        }

        long right_npl = (!ptr->right->npl ? ptr->right->npl : -1);
        long left_npl = (!ptr->left ? ptr->left->npl : -1);


        ptr->npl =  (right_npl > left_npl ? left_npl : right_npl) + 1;

        if(right_npl > left_npl){
            swap(ptr->left,ptr->right);
        }

        update_npl(ptr->left);
        update_npl(ptr->right);

    }


    void heapify(Node<T>* ptr,T data,std::string binary){
        if(binary.length() >1){
            for(int i=0;i<binary.length();i++){
                
            }
        }
    }
public:
    LeftistHeap() : root(nullptr), total(0){};

    T extractMin(){
        return root->data;
    }

    bool isEmpty(){
        return !root;
    }

    void add(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (!root)
        {
            root = newNode;
        }
        else
        {
            std::string binary = toBinary(this->total);
            Node<T> *ptr = this->root;
            if (binary.length() > 1)
            {
                for (int i = 1; i < binary.length(); i++)
                {
                    if (binary[i] == '1')
                    {
                        if (!ptr->right)
                        {
                            ptr->right = newNode;
                            update_npl(root);
                            break;
                        }
                        else
                        {
                            ptr = ptr->right;
                        }
                    }
                    else
                    {
                        if (!ptr->left)
                        {
                            ptr->left = newNode;
                            update_npl(root);
                            break;
                        }
                        else
                        {
                            ptr = ptr->left;
                        }
                    }
                }
            }
            else
            {
                ptr->left = newNode;
            }
        }
        this->total++;
    }
};
