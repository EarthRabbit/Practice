#include <bits/stdc++.h>
using namespace std;

int n;
int d[2][100002];

void dp(){
    for(int i = 2; i <= n; i++){
        d[0][i] = max(max(d[1][i - 1], d[0][i - 2]) + d[0][i], d[0][i - 1]);
        d[1][i] = max(max(d[0][i - 1], d[1][i - 2]) + d[1][i], d[1][i - 1]);
    }

    cout << max(d[0][n], d[1][n]) << '\n';
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> n;
        for(int j = 0; j < 2; j++){
            for(int k = 1; k <= n; k++){
                cin >> d[j][k];
            }
        }
        dp();
    }

    return 0;
}