#include <iostream>
#define MAX 1000000000;
using namespace std;

int stairs_cumulative[101][10]; // 횟수, 0~9

void dp(int N){
    for(int i = 1; i < N; i++){
        stairs_cumulative[i][0] = stairs_cumulative[i - 1][1];
        for(int j = 1; j < 9; j++){
            stairs_cumulative[i][j] = (stairs_cumulative[i - 1][j - 1] + stairs_cumulative[i - 1][j + 1]) % MAX;
        }
        stairs_cumulative[i][9] = stairs_cumulative[i - 1][8];
    }    
}

int main() {

    int N, sum = 0;
    cin >> N;

    for(int i = 1; i <= 9; i++){
        stairs_cumulative[0][i] = 1;
    }

    dp(N);
    
    for(int i = 0; i <= 9; i++){
        sum += stairs_cumulative[N - 1][i];
        sum %= MAX;
    }
    cout << sum;
    return 0;
}