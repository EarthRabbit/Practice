#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];
int N;

bool binarySearch(int target){
    int start = 0;
    int end = N - 1;
    int l;
    while(start <= end){
        l = (start + end)/2;
        if(arr[l] == target){
            return 1;    
        }
            
        else if(arr[l] > target){
            end = l - 1;
        }
        else if(arr[l] < target){
            start = l + 1;
        }
    }
    return 0;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M, num;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num;
        cout << binarySearch(num) << ' ';
    }
    return 0;
}