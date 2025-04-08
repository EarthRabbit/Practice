#include <iostream>
#include <algorithm>
using namespace std;

int numset[100000];
int sumset[100000];

void dp(int N){
    for(int i = 1; i < N; i++){
        sumset[i] = numset[i] + max(sumset[i - 1], 0);
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> numset[i];
    }
    
    sumset[0] = numset[0];
    
    dp(N);
    sort(sumset, sumset + N);
    
    cout << sumset[N - 1];
    
    return 0;
}