#include <iostream>
using namespace std;

unsigned long long int P[101];

unsigned long long int dp(int N){
    
    if(P[N]) return P[N];
    
    else{
        P[N] = dp(N - 5) + dp(N - 1);
        return P[N];
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int T, N;

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;
        cout << dp(N) << '\n';
    }

    return 0;
}