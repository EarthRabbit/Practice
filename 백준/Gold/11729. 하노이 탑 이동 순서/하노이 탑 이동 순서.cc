#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<pair<int, int>> p;

void hanoi(int N, int start, int mid, int end){

    if(N == 1){
        cnt++;
        p.push_back(pair<int, int>(start, end));
    }
    
    if(N > 1){
        hanoi(N - 1, start, end, mid);
        cnt++;
        p.push_back(pair<int, int>(start, end));
        hanoi(N - 1, mid, start, end);
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    hanoi(N, 1, 2, 3);
    cout << cnt << '\n';

    for(auto iter = p.begin(); iter != p.end(); iter++){
        cout << iter->first << ' ' << iter->second << '\n';
    }
    
    return 0;
}