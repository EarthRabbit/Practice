#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare{
    bool operator()(int A, int B){
        if(abs(A) == abs(B)) return A > B;
        else return abs(A) > abs(B);
    }
};

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, num;
    priority_queue<int, vector<int>, compare> pq;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(num == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(num);
    }
    
    return 0;
}