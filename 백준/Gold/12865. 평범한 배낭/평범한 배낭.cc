#include <iostream>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    int val[100] = {0}, weight[100] = {0}, max_val[100001] = {0};
    
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> weight[i] >> val[i];
    }

    for(int j = 0; j < N; j++){
        for(int i = K; i >= weight[j]; i--){
            max_val[i] = max(val[j] + max_val[i - weight[j]], max_val[i]);
        }
    }
    
    cout << max_val[K];
    
    return 0;
}