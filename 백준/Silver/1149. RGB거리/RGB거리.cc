#include <iostream>
#include <algorithm>
using namespace std;

int rgb[1001][3];
int sum[3];
int temp_0, temp_1, temp_2;

int dp(int N){
    for(int i = 1; i < N; i++){
        temp_0 = min(sum[1], sum[2]);
        temp_1 = min(sum[0], sum[2]);
        temp_2 = min(sum[0], sum[1]);
        sum[0] = temp_0 + rgb[i][0];
        sum[1] = temp_1 + rgb[i][1];
        sum[2] = temp_2 + rgb[i][2];
    }
    return min(min(sum[1], sum[2]), sum[0]);
}

int main() {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    
    for(int i = 0; i < 3; i++){
        sum[i] = rgb[0][i];
    }

    cout << dp(N);
    
    return 0;
}