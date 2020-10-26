#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    long height;
    int balance_factor;
    Node<T> *left;
    Node<T> *right;
    Node(T data) : data(data), height(0), balance_factor(0), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVL
{
    Node<T> *root;

protected:
    void reclaim_memory(Node<T> *ptr)
    {
        if(!ptr){
            return;
        }
        reclaim_memory(ptr->left);
        reclaim_memory(ptr->right);
        delete ptr;

    }
    bool _contains(Node<T> *ptr, T data)
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
            else if (ptr->data > data)
            {
                return _contains(ptr->left, data);
            }
            else
            {
                return _contains(ptr->right, data);
            }
        }
    }
    Node<T> *balance(Node<T> *node)
    {
        if (node->balance_factor == -2)
        {
            if (node->left->balance_factor <= 0)
            {
                return left_left_case(node);
            }
            else
            {
                return left_right_case(node);
            }
        }
        else if (node->balance_factor == 2)
        {
            if (node->right->balance_factor >= 0)
            {
                return right_right_case(node);
            }
            else
            {
                return right_left_case(node);
            }
        }
        return node;
    }

    Node<T> *_insert(Node<T> *ptr, T data)
    {
        if (!ptr)
        {
            return new Node<T>(data);
        }
        else if (ptr->data == data)
        {
            return ptr;
        }

        if (ptr->data > data)
        {
            ptr->left = _insert(ptr->left, data);
        }
        {
            ptr->right = _insert(ptr->right, data);
        }
        update(ptr);
        return balance(ptr);
    }
    void update(Node<T> *node)
    {
        if (!node)
        {
            return;
        }
        const int lh = !node->left ? -1 : node->left->height;
        const int rh = !node->right ? -1 : node->right->height;

        node->height = 1 + max(lh, rh);
        node->balance_factor = rh - lh;
    }

    Node<T> *right_rotate(Node<T> *ptr)
    {
        Node<T> *left_child = ptr->left;
        if (!left_child)
        {
            return ptr;
        }

        ptr->left = left_child->right;
        left_child->right = ptr;
        update(left_child);
        update(ptr);
        return left_child;
    }

    Node<T> *left_rotate(Node<T> *ptr)
    {
        Node<T> *right_child = ptr->right;
        if (!right_child)
        {
            return ptr;
        }
        ptr->right = right_child->left;
        right_child->left = ptr;
        update(right_child);
        update(ptr);
        return right_child;
    }

    Node<T> *left_left_case(Node<T> *ptr)
    {
        return this->right_rotate(ptr);
    }
    Node<T> *left_right_case(Node<T> *ptr)
    {
        if (!ptr)
            return ptr;

        ptr->left = left_rotate(ptr);

        return left_left_case(ptr);
    }

    Node<T> *right_right_case(Node<T> *ptr)
    {
        return left_rotate(ptr);
    }

    Node<T> *right_left_case(Node<T> *ptr)
    {
        ptr->right = right_right_case(ptr->right);
        return right_right_case(ptr);
    }

public:
    AVL() : root(nullptr) {}
    void insert(T data)
    {
        this->root = _insert(this->root, data);
    }

    bool contains(T data)
    {
        return _contains(this->root, data);
    }

    ~AVL()
    {
        reclaim_memory(this->root);
    }
};