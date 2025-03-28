#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, num, target;
vector<int> v1;

void binarySearch(int target){

    int start = 0, end = N - 1;
    int mid = 0;

    while(start <= end){
        mid = (start + end) / 2;
        if(v1[mid] == target){
            cout << 1 << '\n';
            return;
        }
        else if(v1[mid] > target){
            end = mid - 1;
        }
        else if(v1[mid] < target){
            start = mid + 1;
        }
    }
    cout << 0 << '\n';
    return;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        v1.push_back(num);
    }
    
    sort(v1.begin(), v1.end());
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> target;
        binarySearch(target);
    }
    return 0;
}