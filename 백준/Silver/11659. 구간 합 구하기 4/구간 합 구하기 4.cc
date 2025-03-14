#include <iostream>
using namespace std;

int sum[100001];
int num[100001];

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, s, e;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }

    sum[1] = num[1];
    
    for(int i = 2; i <= N; i++){
        sum[i] = sum[i - 1] + num[i];
    }

    for(int i = 0; i < M; i++){
        cin >> s >> e;
        cout << sum[e] - sum[s - 1] << '\n';
    }
    
    return 0;
}