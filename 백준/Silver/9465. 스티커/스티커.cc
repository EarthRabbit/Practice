#include <bits/stdc++.h>
using namespace std;

int n;

void dp(vector<int> &A, vector<int> &B){
    vector<int> C(n + 1);
    vector<int> D(n + 1);

    C[0] = 0, C[1] = A[1];
    D[0] = 0, D[1] = B[1];

    for(int i = 2; i <= n; i++){
        C[i] = max(max(D[i - 1], C[i - 2]) + A[i], C[i - 1]);
        D[i] = max(max(C[i - 1], D[i - 2]) + B[i], D[i - 1]);
    }

    cout << max(C[n], D[n]) << '\n';
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> n;
        vector<int> A(n + 1);
        vector<int> B(n + 1);
        for(int j = 1; j <= n; j++){
            cin >> A[j];
        }
        for(int j = 1; j <= n; j++){
            cin >> B[j];
        }
        dp(A, B);
    }

    return 0;
}