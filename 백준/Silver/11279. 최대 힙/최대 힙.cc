#include <iostream>
#include <queue>
using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, x;
    priority_queue<int> pq;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }

    return 0;
}