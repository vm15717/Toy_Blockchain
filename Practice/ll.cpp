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
        if (length == 0)
        {
            std::cout << "The list is empty!!" << std::endl;
        }
        else
        {
            Node* temp = head;
            while (temp)
            {
                std::cout << temp->value << std::endl;
                temp = temp->next;
            }
        }
    }
    void getHead()
    {
        if (head)
        {
            std::cout << "Head: " << this->head->value << std::endl;
        }
        else
        {
            std::cout << "The list is empty!!" << std::endl;
        }
    }
    void getTail()
    {
        if (tail)
        {
            std::cout << "Tail: " << this->tail->value << std::endl;
        }
        else
        {
            std::cout << "The list is empty!!" << std::endl; 
        }
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
    void deleteLast()
    {
        Node* temp = head;
        if (length == 0)
        {
            std::cout << "The list is empty!!" << std::endl;
        }
        else if (length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = length - 1;
        }
        else
        {
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
            this->length = this->length - 1;
        }
    }
    ~LinkedList()
    {
        Node* temp = head;
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
    LL1->deleteLast();
    LL1->deleteLast();
    LL1->deleteLast();
    LL1->printlist();
    LL1->getHead();
    LL1->getTail();
    LL1->getLength();
    delete LL1;
}