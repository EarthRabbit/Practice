#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int prime[1000001];

void primeCheck(){
    for(int i = 2; i < 1000000; i++){
        for(int j = i * 2; j < 1000000; j += i){
            prime[j] = 1;
        }
    }
}

void primePrime(int N){
    int cnt = 0;
    for(int i = 2; i <= N / 2; i++){
        if(prime[i] == 0){
            if(prime[N - i] == 0) cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    
    cin.tie(0);
    ios::sync_with_stdio(false);

    primeCheck();
    
    int N, num;
    
    cin >> N;

    for(int i = 0 ; i < N; i++){
        cin >> num;
        primePrime(num);
    }
    
    return 0;
}