// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> S;

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i < N + 1; i++){
        S.push(i);
    }
    cout << '<';
    while(!S.empty()){
        if(S.size() != N) cout << ", ";
        for(int i = 0; i < K - 1; i++){
            S.push(S.front());
            S.pop();
        }
        cout << S.front();
        S.pop();
    }
    cout << '>';
}