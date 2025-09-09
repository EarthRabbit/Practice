#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, cnt, sum_cnt, flag;
int visited[15];
vector<pair<int, int>> v1;

void nQueen(int K){
    if(K == N){
        sum_cnt++;
        return;
    }
    for(int i = 0; i < N; i++){
        visited[K] = i;
        flag = 1;
        for(int j = 0; j < K; j++){
            if(visited[K] == visited[j] || abs(K - j) == abs(visited[K] - visited[j])){
                flag = -1;
                break;
            }
        }
        if(flag > 0) nQueen(K + 1);
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    nQueen(0);

    cout << sum_cnt;

    return 0;
}