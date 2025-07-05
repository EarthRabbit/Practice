#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, temp = 0;
    unsigned long long int sum = 0, cnt = 0;
    int num[1000001];
    unsigned long long int remainder[1001];
    remainder[0]++;
  
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> num[i];
        temp = (temp + num[i]) % M;
        remainder[temp]++;
    }

    for(int i = 0; i <= M; i++){
        sum += (remainder[i] * (remainder[i] - 1)) / 2;
    }
    
    cout << sum;
    
    return 0;
}