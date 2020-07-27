
template <typename Type>
struct Node
{
    Type Data;
    Node<Type> *next;
    Node(data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename Type>
class Queue
{
    Node<Type> *head;
    Node<Type> *rear;

public:
    Queue()
    {
        this->head = nullptr;
        this->rear = nullptr;
    }

    void push_front(Type data)
    {
        Node<Type> *newNode = new Node(data);
        if (!this->head)
        {
            this->head = newNode;
            this->rear = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
    }

    void push_back(Type data)
    {
        Node<Type> *newNode = new Node(data);
        if (!this->head)
        {
            this->head = newNode;
            this->rear = newNode;
        }
        else
        {
            this->rear->next = newNode;
            this->rear = newNode;
        }
    }

    Type top()
    {
        return this->head ? this->head->data : NULL;
    }

    Type back()
    {
        return this->rear ? this->rear->data : NULL;
    }

    bool remove(Type data)
    {
        Node<Type> *ptr = this->head;
        Node<Type> *prev = nullptr;

        while (ptr)
        {
            if (ptr->data == data)
            {
                if(ptr ==this->head && ptr==this->rear){

                    delete this->head;
                    this->head = nullptr;
                    this->rear = nullptr;

                } else if (ptr==this->head) {

                    delete this->head;
                    this->head = this->head->next;


                } else if (ptr==this->rear) {

                    delete this->rear;
                    this->rear = nullptr;

                } else {

                    
                    prev->next = ptr->next;
                    delete ptr;

                }
                return true;
            }
            prev = ptr;
            this->ptr = this->ptr.next;
        }

        return false;
    }

    bool find(Type data)
    {

        Node<Type> *temp = this->head;
        while (temp)
        {
            if (temp->data == data)
            {
                return true;
            }
            this->temp = this->temp.next;
        }

        return false;
    }

    ~Queue()
    {
        Node<Type> *temp = this->head;
        while (temp)
        {
            delete temp;
            temp = this->head;
            this->head = this->head.next;
        }
    }
};