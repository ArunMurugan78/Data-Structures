#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BST
{
    Node<T> *root;

    void freeUp(Node<T> *root)
    {
        if (!root)
        {
            return;
        }

        freeUp(root->left);
        freeUp(root->right);

        delete root;
    }

    Node<T>* _add(Node<T> *ptr, T data)
    {
        if (!ptr)
        {
            return nullptr;
        }

        if (ptr->data < data)
        {
            if (!ptr->right)
            {
                Node<T> *newNode = new Node<T>(data);
                ptr->right = newNode;
            }
            else
            {
                ptr->right = this->_add(ptr->right,data);
            }
        }
        else
        {
            if (!ptr->left)
            {
                Node<T> *newNode = new Node<T>(data);
                ptr->left = newNode;
            }
            else
            {
                ptr->left = this->_add(ptr->left,data);
            }
        }

        return ptr;
    }

    bool _find(Node<T> *ptr, T data)
    {
        if (!ptr)
        {
            return false;
        }
        else
        {
            if (ptr->data == data)
            {
                return true;
            }
            else
            {
                if (ptr->data < data)
                {
                    return _find(ptr->right, data);
                }
                else
                {
                    return _find(ptr->left, data);
                }
            }
        }
    }

    void _inOrder(Node<T> *ptr)
    {
        if (!ptr)
        {
            return;
        }
        _inOrder(ptr->left);
        cout << ptr->data << "\n";
        _inOrder(ptr->right);
    }
    void _preOrder(Node<T> *ptr)
    {
        if (!ptr)
        {
            return;
        }
        cout << ptr->data << "\n";
        _preOrder(ptr->left);
        _preOrder(ptr->right);
    }
    void _postOrder(Node<T> *ptr)
    {
        if (!ptr)
        {
            return;
        }
        _postOrder(ptr->left);
        _postOrder(ptr->right);
        cout << ptr->data << "\n";
    }

public:
    void in_order()
    {
        this->_inOrder(this->root);
    }
    void pre_order()
    {
        this->_preOrder(this->root);
    }

    void post_order()
    {
        this->_postOrder(this->root);
    }
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        freeUp(this->root);
    }

    void add(T data)
    {
        if(!this->root){
            this->root = new Node<T>(data);
        }
         else this->_add(this->root, data);
    }

    bool find(T data)
    {
        return this->_find(this->root, data);
    }
};