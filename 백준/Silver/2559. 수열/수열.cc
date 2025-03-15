#include <iostream>
using namespace std;

int T[100000];

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, sum = 0, idx_1 = 0, idx_2, temp;
    
    cin >> N >> M;
    
    idx_2 = M;
    
    for(int i = 0; i < N; i++){
        cin >> T[i];
    }

    for(int i = 0; i < M; i++){
        sum += T[i];
    }

    temp = sum;
    
    while(idx_2 < N){
        sum -= T[idx_1++];
        sum += T[idx_2++];
        if(temp < sum) temp = sum;
    }

    cout << temp;
    
    return 0;
}