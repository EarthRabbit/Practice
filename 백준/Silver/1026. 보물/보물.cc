#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, num, sum = 0;
    vector<int> A, B;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        A.push_back(num);
    }
    
    for(int i = 0; i < N; i++){
        cin >> num;
        B.push_back(num);
    }

    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end());

    for(int i = 0; i < N; i++){
        sum += A[i] * B[i];
    }

    cout << sum;
    return 0;
}