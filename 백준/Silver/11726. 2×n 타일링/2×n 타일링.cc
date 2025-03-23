#include <iostream>
using namespace std;

int how[1001];

int dp(int N){
    if(how[N]) return how[N];
    else{
        int temp;
        for(int i = 3; i <= N; i++){
            how[i] = (how[i - 1] + how[i - 2]) % 10007;
        }
    }
    return how[N];
}

int main() {

    ios::sync_with_stdio(false);
    int N;

    how[1] = 1;
    how[2] = 2;
    
    cin >> N;

    cout << dp(N);
    return 0;
}