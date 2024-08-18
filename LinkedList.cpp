#include <iostream>
#include <initializer_list>
#include<vector>
using namespace std;

template<typename DataType>
class List
{
private:
    struct Node
    {
        DataType data;
        Node* next;
        explicit Node(DataType data):data(data),next(nullptr){}

    };
    Node *head;
    Node *tail;
    unsigned int size;

public:
    List():head(nullptr),tail(nullptr),size(0){}

    List(initializer_list<DataType> initList):head(nullptr),tail(nullptr),size(0)
    {
        if(initList.size() == 0)
        {
            return;
        }
        const DataType *it  = initList.begin();
        head = new Node(*it);
        tail = head;
        ++it;
        size++;
        while (it != initList.end())
        {
            append(*it,'b');
            ++it;
        }
    }

    void append(DataType data, char postiton = 'i', unsigned int index = 0)
    {

        if(head == nullptr)
        {
            head = new Node(data);
            tail = head;
            size++;
            return;
        }
        else
        {
            if (postiton == 'f')
            {
                Node *temp = new Node(data);
                temp->next = head;
                head = temp;
                size++;

            }
            else if(postiton == 'b') {
                Node *temp = new Node(data);
                tail->next = temp;
                tail = temp;
                size++;
            }
            else if (postiton == 'i' and index <= size)
            {
                vector<Node*> value = getNodeContext(index);
                Node* n_temp = new Node(data);
                if(value[0] != nullptr)
                {
                    value[0]->next = n_temp;
                    n_temp->next = value[1];
                    size++;
                }
                else
                {
                    head = n_temp;
                    n_temp->next = value[1];
                    size++;
                }
            }
            else
            {
                cout<<" ERROR ";
            }
        }
    }
    void traverse()
    {
        Node *temp = head;
        cout<<endl;
        while(temp != nullptr)
        {
            cout<< temp->data << " "<< "--> " ;
            temp = temp->next;
        }
        cout<<"nullptr";
    }

    vector<Node*> getNodeContext(const unsigned int targetNodeIndex)
    {
        if (targetNodeIndex >= size){
            throw runtime_error("out of bound");
        }
        unsigned int count = 0;
        Node *previousNode = nullptr;
        Node *currentNode = head;
        Node *nextNode = nullptr;

        while (count != targetNodeIndex)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
            count++;

        }
        nextNode = currentNode->next;
        return {previousNode,currentNode,nextNode};
    }
    void deleteNode(const unsigned int index)
    {
        if(this->getSize() == 0 or index >= size)
        {
            throw runtime_error("Out of Bound Index");
        }
        vector<Node*>value = getNodeContext(index);

        if(value[0] != nullptr)
        {
            value[0]->next = value[2];
            delete value[1];
            size--;
        }
        else
        {
            head = value[2];
            size--;
        }
    }
    unsigned int  getSize() const
     {
        return size;
    }

    ~List()
    {
        Node* temp = head;
        while(temp!= nullptr)
        {
            head = head ->next;
            delete temp;
            temp = head;
        }


    }

};

int main()
{
    List l = {11,2,3,4,56,7};
    l.deleteNode(3);
    l.traverse();
    return 0;
}

