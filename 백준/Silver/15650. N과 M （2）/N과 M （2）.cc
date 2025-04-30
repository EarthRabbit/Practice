#include <iostream>
#include <vector>
using namespace std;

int N, M, temp;
vector<int> v1;

void backTracking(int start){
    if(v1.size() == M){
        for(int num : v1){
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = start; i <= N; i++){
        v1.push_back(i);
        backTracking(i + 1);
        v1.pop_back();
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;

    backTracking(1);
    return 0;
}