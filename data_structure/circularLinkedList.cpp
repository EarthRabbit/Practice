#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* nextNode;
};

class circularLinkedList{
    private:
        node* head = new node;
    
    public:
        circularLinkedList(){
            head->nextNode = head;
        }
        node* findNode(int data){
            
            if(head->nextNode == head){
                cout << "empty list\n";
            }

            else{
                node* targetNode = head->nextNode;

                while(targetNode != head){
                    if(targetNode->data == data){
                        cout << targetNode << '\n';
                        return targetNode;
                    }
                    targetNode = targetNode->nextNode;
                }
            }
            cout << nullptr << '\n';
            return nullptr;
        }
        bool isempty();
        void add(int data);
        void insert(node* previous, int data);
        void deleteNode(int data);
        void showAll();
};

bool circularLinkedList::isempty(){
    if(head->nextNode == head){
        return true;
    }
    return false;
}

void circularLinkedList::add(int data){
    
    node* newNode = new node;
    newNode->data = data;

    head->nextNode = newNode;
    newNode->nextNode = head;
}

void circularLinkedList::insert(node* previous, int data){

    node* newNode = new node;
    newNode->data = data;

    if(previous == nullptr){
        if(head->nextNode == head){
            head->nextNode = newNode;
            newNode->nextNode = head;
            return;
        }
        else{
            cout << "invalid address\n";
            return;
        }
    }

    if(previous->nextNode == head){
        newNode->nextNode = head;
        previous->nextNode = newNode;
    }

    else{
        newNode->nextNode = previous->nextNode;
        previous->nextNode = newNode;
    }
}

void circularLinkedList::deleteNode(int data){
    
    if(head->nextNode == head){
        cout << "empty list\n";
        return;
    }

    node* prevNode = head;

    node* curNode = new node;
    curNode->data = data;

    while(prevNode->nextNode != head){
        if(prevNode->nextNode->data == data){
            curNode = prevNode->nextNode;
            break;
        }
        prevNode = prevNode->nextNode;
    }
    
    if(prevNode->nextNode == head){
        cout << "no such data in this list\n";
        return;
    }

    else{
        prevNode->nextNode = curNode->nextNode;
        curNode = nullptr;
        delete curNode;
    }
}

void circularLinkedList::showAll(){
    
    if(head->nextNode == head){
        return;
    }

    node* curNode = head->nextNode;

    while(curNode != head){
        cout << curNode->data << '-';
        curNode = curNode->nextNode;
    }
    cout << '\n';
}

int main()
{
    circularLinkedList circularLinkedList1 = circularLinkedList();

    int N, data, number;
    bool flag = true;
    while(flag){
        cout << " 1: insert 2: delete 3: find 0: out\n function: ";
        cin >> N;
        switch(N){
            case 1:
            {
                if(!circularLinkedList1.isempty()){
                    cout << "previous data and number: ";
                    cin >> data >> number;
                    node* curNode = circularLinkedList1.findNode(data);
                    circularLinkedList1.insert(curNode, number);
                    circularLinkedList1.showAll();
                    break;
                }
                else{
                    cout << "number: ";
                    cin >> number;
                    circularLinkedList1.add(number);
                    circularLinkedList1.showAll();
                    break;
                }
            }
            case 2:
            {
                cout << "number of data: ";
                cin >> data;
                circularLinkedList1.deleteNode(data);
                circularLinkedList1.showAll();
                break;
            }
            case 3:
            {
                cout << "number of data: ";
                cin >> data;
                node* curNode = circularLinkedList1.findNode(data);
                circularLinkedList1.showAll();
                break;
            }
            case 0:{
                flag = false;
            }
        }
    }
    return 0;
}