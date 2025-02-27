#include <iostream>
#include <cstring>
using namespace std;

bool arr[123456 * 2 + 1];

int main() {
    
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    memset(arr, true, sizeof(arr));
    for(int i = 2; i * i < 123456 * 2 + 1; i++){
        for(int j = 2 * i; j <= 123456 * 2 + 1; j += i){
            arr[j] = false;
        }
    }
    
    while(1){
        
        cin >> N;
        if(N == 0) break;
        int sum = 0;
        for(int i = N + 1; i <= 2 * N; i++){
            if(arr[i] == true) sum++;
        }
        cout << sum << '\n';
    }
    return 0;
}