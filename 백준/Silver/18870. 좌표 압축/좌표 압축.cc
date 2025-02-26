#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, v2;

int binarysearch(int target){
    int start = 0, end = v.size() - 1, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(v[mid] == target) return mid;
        else if(v[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return 0;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, num;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
        v2.push_back(num);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < N; i++){
        cout << binarysearch(v2[i]) << ' ';
    }
        
    return 0;
}