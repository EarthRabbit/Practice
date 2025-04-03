#include <iostream>
using namespace std;

int sum_temp[1000];

void dp(int N){
    for(int i = 2; i < N; i++){  
        sum_temp[i] = (sum_temp[i - 2] * 2 + sum_temp[i - 1]) % 10007;
    }
}

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    sum_temp[0] = 1;
    sum_temp[1] = 3;

    dp(N);
    
    cout << sum_temp[N - 1];
    
    return 0;
}