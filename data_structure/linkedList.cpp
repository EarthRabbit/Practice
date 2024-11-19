// reference : https://velog.io/@c-jeongyyun/%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EC%A0%95%EB%B3%B5%ED%95%98%EA%B8%B0-2-%EA%B5%AC%ED%98%84-C

#include <iostream>
using namespace std;

struct node{ // 노드 생성
    int data; // 데이터
    struct node* nextNode; // 다음 노드의 포인터
};

class linkedList{ // 연결 리스트
    private:
        node* head = new node; // head 노드
        node* tail = new node; // tail 노드
    
    public:
        linkedList(){ // 연결 리스트 생성(자)
            head->nextNode = tail; // head - tail의  구조
            tail->nextNode = NULL; // tail 다음 노드는 없음
        }
        void addFront(int data); // addFront 선언
        void addBack(int data); // addBack 선언
        void add(node* previous, int data); // add 선언
        void subtract(int data); // delete 선언
        node* findNode(int data){ // data가 들어있는 node 찾기
            node* targetNode = new node; // targetNode 생성
            targetNode = head->nextNode; // targetNode는 head의 nextNode
            
            while(targetNode->nextNode != NULL){ // 마지막 노드까지
                if(targetNode->data == data){ // data로 targetNode 찾기
                    cout << targetNode << '\n';
                    return targetNode;
                }
                targetNode = targetNode->nextNode;
            }
            cout << nullptr << '\n';
            return nullptr; // 못 찾은 경우 nullptr 반환
        }
        void showAll();
};

void linkedList::addFront(int data){ // 리스트 앞에 node 삽입
    
    node* newNode = new node; // newNode 생성
    newNode->data = data; // newNode에 data 삽입
    
    if(head->nextNode == tail){ // 리스트가 빈 경우
        head->nextNode = newNode; // head 바로 뒤에 newNode 삽입
        newNode->nextNode = tail; // newNode의 nextNode는 tail
    }
    
    else{ // 빈 리스트가 아닌 경우
        newNode->nextNode = head->nextNode; // newNode의 nextNode는 원래 head의 nextNode 
        head->nextNode = newNode; // head의 nextNode는 newNode
    }
}

void linkedList::addBack(int data){ // 리스트 뒤에 data 삽입
    if(head->nextNode == tail){ // 빈 리스트의 경우 addFront 재활용
        addFront(data);
    }
    else{ // 빈 리스트가 아닌 경우
        node* newNode = new node; // newNode 생성
        newNode->data = data; // newNode에 data 삽입
        
        node* curNode = head->nextNode; // head의 nextNode로 curNode 생성
        while(curNode->nextNode != tail){ // tail 바로 앞, 마지막 데이터를 가진 노드 찾기
            curNode = curNode->nextNode; // curNode를 head 다음 노드부터 하나씩 찾아보기 O(N)
        }
        
        curNode->nextNode = newNode; // curNode의 다음 노드가 newNode로 변경
        newNode->nextNode = tail; // newNode의 다음은 tail
    }
}

void linkedList::add(node* previous, int data){ // 리스트 중간에 삽입
    
    if(previous == nullptr){ // 이상한 node 들고 온 경우
        cout << "Invalid node address" << '\n';
        return;
    }
    
    node* newNode = new node; // newNode 생성
    newNode->data = data; // newNode에 data 삽입
    
    if(previous->nextNode == tail){ // 마지막 node의 경우
        newNode->nextNode = tail; // newNode가 마지막 node
        previous->nextNode = newNode; // previous의 nextNode가 newNode
        return;
    }
    
    newNode->nextNode = previous->nextNode; // 중간에 있는 노드는 한 칸씩 밀기
    previous->nextNode = newNode;
}

void linkedList::subtract(int data){ // 리스트의 특정 data를 제거
    
    node* targetNode = new node; // targetNode 생성
    
    if(head->nextNode == tail){ // 리스트가 빈 경우
        cout << "Empty list" << '\n';
        return;
    }
    
    if(head->nextNode->data == data){ // 첫 node의 data가 특정 data인 경우
        targetNode = head->nextNode; // head의 nextNode가 targetNode
        head->nextNode = targetNode->nextNode; // head - tail로 연결
        targetNode = nullptr; // 메모리 해제
        delete targetNode;
        return;
    }
    
    node* previous = new node; // targetNode 이전 node 찾기
    previous = head->nextNode;
    
    while(previous->nextNode != tail){
        if(previous->nextNode->data == data){ // previous의 nextNode의 data가 주어진 data인 경우
            targetNode = previous->nextNode;
            break;
        }
        previous = previous->nextNode;
    }
    
    if(previous->nextNode == tail){ // 리스트에서 해당 data를 못 찾은 경우
        cout << "cannot find data" << '\n';
        targetNode = nullptr;
        return;
    }
    else{
        previous->nextNode = targetNode->nextNode; // previous의 nextNode는 targetNode의 nextNode
        targetNode = nullptr; // 메모리 해제
        delete targetNode;
    }
}

void linkedList::showAll(){
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
    linkedList linkedList1 = linkedList();

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
                    linkedList1.addFront(A);
                }
                else if(M == 2){
                    cin >> A;
                    linkedList1.addBack(A);
                }
                else{
                    cin >> A >> B;
                    node* curNode = linkedList1.findNode(A);
                    linkedList1.add(curNode, B);
                }
                linkedList1.showAll();
                break;
            }
            case 2:
            {
                cout << "number: ";
                cin >> A;
                linkedList1.subtract(A);
                linkedList1.showAll();
                break;
            }
            case 3:
            {
                cout << "number: ";
                cin >> A;
                node* curNode = linkedList1.findNode(A);
                linkedList1.showAll();
                break;
            }
            case 0:{
                flag = false;
            }
        }
    }
    return 0;
}