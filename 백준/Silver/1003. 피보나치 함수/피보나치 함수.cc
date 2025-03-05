#include <iostream>
using namespace std;

int dp[41];

int fibonacci(int T){

    if(dp[T]) return dp[T];
    
    else{
        dp[T] = fibonacci(T - 1) + fibonacci(T - 2);
        return dp[T];
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T, N;
    
    dp[1] = 1;
    dp[2] = 1;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;
        if(N == 0) cout << 1 << ' ' << 0 << '\n';
        else if(N == 1) cout << 0 << ' ' << 1 << '\n';
        else cout << fibonacci(N - 1) << ' ' << fibonacci(N) << '\n';
    }
    
    return 0;
}