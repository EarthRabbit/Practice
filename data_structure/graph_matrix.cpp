// 행렬로 만드는 그래프
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    
    cin.tie();
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N;

    bool **arr = new bool*[N+1];
    for(int i = 0; i < N+1; i++){
        arr[i] = new bool[N+1];
    }
    for(int i = 0; i < N + 1; i++){
        for(int j = 0; j < N + 1; j++){
            arr[i][j] = 0;
        }
    }
    while(1){
        cin >> A >> B;
        if(A == 0 && B == 0) break;
        arr[A][B] = 1;
    }
    for(int i = 0; i < N + 1; i++){
        cout << i << ": ";
        for(int j = 0; j < N + 1; j++){
            if(arr[i][j]) cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}