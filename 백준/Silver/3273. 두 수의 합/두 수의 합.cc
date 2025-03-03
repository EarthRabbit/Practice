#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, target, max, cnt = 0, start, end;
    int num[100001];

    cin >> N;

    start = 0;
    end = N - 1;
    
    for(int i = 0 ; i < N; i++){
        cin >> num[i];
    }

    cin >> target;

    sort(num, num + N);
    
    while(start < end){
        if(num[start] + num[end] == target){
            cnt++;
            start++;
        }
        else if(num[start] + num[end] > target) end--;
        else start++;
    }
    
    cout << cnt;
    
    return 0;
}