#include <iostream>
#include <algorithm>
using namespace std;

int numset[100000];
int N, M;

int binarySearch_upper(int target){
    
    if(target <= numset[0]) return 0;
    else if(target >= numset[N - 1]) return N;

    int start = 0, end = N - 1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        if(numset[mid] == target){
            return mid + 1;
        }
        if(numset[mid] > target){
            end = mid - 1;
        }
        else if(numset[mid] < target){
            if(numset[mid + 1] > target){
                return mid + 1;
            }
            start = mid + 1;
        }
    }
}

int binarySearch_lower(int target){
    
    if(target <= numset[0]) return 0;
    else if(target >= numset[N - 1]) return N;

    int start = 0, end = N - 1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        if(numset[mid] == target){
            return mid;
        }
        if(numset[mid] > target){
            if(numset[mid - 1] < target){
                return mid;
            }
            else end = mid - 1;
        }   
        else if(numset[mid] < target){
            start = mid + 1;
        }
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int s, e;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> numset[i];
    }

    sort(numset, numset + N);

    for(int i = 0; i < M; i++){
        cin >> s >> e;
        cout << binarySearch_upper(e) - binarySearch_lower(s) << '\n';
    }
    return 0;
}