#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* nextNode;
    struct node* prevNode;
};

class doublyLinkedList{
    private:
        node* head = new node;
        node* tail = new node;
    public:
        doublyLinkedList(){
            head->prevNode = NULL;
            head->nextNode = tail;
            tail->prevNode = head;
            tail->nextNode = NULL;
        }
        node* findNode(int data){
            
            if(head->nextNode == tail && tail->prevNode == head){
                cout << "empty list\n";
            }
            else{   
                node* targetNode = head->nextNode;
                while(targetNode != tail){
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
        void insert_front(int data);
        void insert_back(int data);
        void insert(node* previous, int data);
        void deleteNode(int data);
        void showAll();
};

void doublyLinkedList::insert_front(int data){
    
    node* newNode = new node;
    newNode->data = data;

    if(head->nextNode == tail && tail->prevNode == head){
        head->nextNode = newNode;
        newNode->prevNode = head;
        tail->prevNode = newNode;
        newNode->nextNode = tail;
    }

    else{
        head->nextNode->prevNode = newNode;
        newNode->prevNode = head;
        newNode->nextNode = head->nextNode;
        head->nextNode = newNode;
    }
}

void doublyLinkedList::insert_back(int data){

    if(head->nextNode == tail && tail->prevNode == head) insert_front(data);

    else{
        node* newNode = new node;
        newNode->data = data;

        node* lastNode = head->nextNode;
        
        while(lastNode->nextNode != tail){
            lastNode = lastNode->nextNode;
        }

        lastNode->nextNode = newNode;
        newNode->prevNode = lastNode;
        newNode->nextNode = tail;
        tail->prevNode = newNode;
    }
}

void doublyLinkedList::insert(node* previous, int data){
    
    if(previous == nullptr){
        cout << "invalid address\n";
        return;
    }

    node* newNode = new node;
    newNode->data = data;

    if(previous->nextNode == tail){
        previous->nextNode = newNode;
        newNode->prevNode = previous;
        newNode->nextNode = tail;
        tail->prevNode = newNode;
        return;
    }

    else{
        previous->nextNode->prevNode = newNode;
        newNode->nextNode = previous->nextNode;
        newNode->prevNode = previous;
        previous->nextNode = newNode;
    }
}

void doublyLinkedList::deleteNode(int data){

    if(head->nextNode == tail && tail->prevNode == head){
        cout << "empty list\n";
        return;
    }

    node* targetNode = new node;

    if(head->nextNode->data == data){
        targetNode = head->nextNode;
        head->nextNode = tail;
        tail->prevNode = head;
        targetNode = nullptr;
        delete targetNode;
        return;
    }


    node* previous = head->nextNode;

    while(previous->nextNode != tail){
        if(previous->nextNode->data == data){
            targetNode = previous->nextNode;
            break;
        }
        previous = previous->nextNode;
    }
    
    if(previous->nextNode == tail){
        cout << "no such data in this list\n";
        return;
    }

    else{
        previous->nextNode = targetNode->nextNode;
        targetNode->nextNode->prevNode = previous;
        targetNode = nullptr;
        delete targetNode;
        return;
    }
}

void doublyLinkedList::showAll(){
    node* curNode = new node;
    curNode = head->nextNode;

    while(curNode != tail){
        cout << curNode->data << '-';
        curNode = curNode->nextNode;
    }

    cout << '\n';
}

int main()
{
    doublyLinkedList doublyLinkedList1 = doublyLinkedList();

    int N, M, A, B, C;
    bool flag = true;
    while(flag){
        cout << " 1: add 2: subtract 3: find 0: out\n function: ";
        cin >> N;
        switch(N){
            case 1:
            {
                cout << "1: addfront 2: addback 3: add \n function: "; 
                cin >> M;
                cout << "number: ";
                if(M == 1){
                    cin >> A;
                    doublyLinkedList1.insert_front(A);
                }
                else if(M == 2){
                    cin >> A;
                    doublyLinkedList1.insert_back(A);
                }
                else{
                    cin >> A >> B;
                    node* curNode = doublyLinkedList1.findNode(A);
                    doublyLinkedList1.insert(curNode, B);
                }
                doublyLinkedList1.showAll();
                break;
            }
            case 2:
            {
                cout << "number: ";
                cin >> A;
                doublyLinkedList1.deleteNode(A);
                doublyLinkedList1.showAll();
                break;
            }
            case 3:
            {
                cout << "number: ";
                cin >> A;
                node* curNode = doublyLinkedList1.findNode(A);
                doublyLinkedList1.showAll();
                break;
            }
            case 0:{
                flag = false;
            }
        }
    }
    return 0;
}