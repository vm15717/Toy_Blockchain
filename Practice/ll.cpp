#include <iostream>

class Node{
    public:
        int value;
        Node* next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
    LinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    };
    void printlist()
    {
        Node* temp = head;
        while (temp)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }
    void getHead()
    {
        std::cout << "Head: " << this->head->value << std::endl;
    }
    void getTail()
    {
        std::cout << "Tail: " << this->tail->value << std::endl;
    }
    void getLength()
    {
        std::cout << "Length: " << this->length << std::endl;
    }
    void append(int value)
    {
        Node* newNode = new Node(value);
        if (length == 0)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail =newNode;
        }
        this->length = this->length + 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};


int main(){
    LinkedList* LL1 = new LinkedList(4);
    LL1->append(5);
    LL1->append(6);
    LL1->printlist();
    LL1->getHead();
    LL1->getTail();
    LL1->getLength();
    delete LL1;
}