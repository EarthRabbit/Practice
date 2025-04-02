#include <iostream>
#include <algorithm>
using namespace std;

int wine_sum[10001];
int wine[10001];

void dp(int N){
    for(int i = 3; i < N; i++){
        wine_sum[i] = max(max(wine_sum[i - 3] + wine[i - 1] + wine[i], wine_sum[i - 2] + wine[i]), wine_sum[i - 1]);
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> wine[i];
    }

    wine_sum[0] = wine[0];
    wine_sum[1] = wine[0] + wine[1];
    wine_sum[2] = max(max(wine_sum[0] + wine[2], wine_sum[1]), wine[1] + wine[2]);
    
    dp(N);

    cout << wine_sum[N - 1];
    
    return 0;
}