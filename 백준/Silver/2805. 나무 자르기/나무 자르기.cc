#include <iostream>
#include <algorithm>
using namespace std;

int N, M, max_val, ans;
int tree[1000000];
long long sum;

void parametric(){
    int left = 0, right = max_val, mid;
    while(left <= right){
        sum = 0;
        mid = (left + right) / 2;
        for(int i = 0; i < N; i++){
            if(tree[i] > mid) sum += (tree[i] - mid);
            if(sum >= M) break;
        }
        if(sum < M) right = mid - 1;
        else{
            ans = max(ans, mid);
            left = mid + 1;
        }
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }

    max_val = *max_element(tree, tree + N);

    parametric();

    cout << ans;
    
    return 0;
}