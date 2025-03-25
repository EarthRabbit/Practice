#include <iostream>
#include <algorithm>
using namespace std;

int a[301], b[301];
int ans;

void dp(int N){
    
    for(int i = 3; i <= N; i++){
        ans = max(b[i - 2] + a[i], b[i - 3] + a[i - 1] + a[i]);
        b[i] = ans;
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }

    b[0] = 0;
    b[1] = a[1];
    b[2] = a[2] + b[1];

    if(N >= 3) dp(N);

    cout << b[N];

    return 0;
}