#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> A, pair<int, int> B){
    if(A.second != B.second) return A.second < B.second;
    else return A.first < B.first;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B, temp = -1, idx = 0, cnt = 0;
    vector<pair<int, int>> p;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A >> B;
        p.push_back(pair<int, int>(A, B));
    }

    sort(p.begin(), p.end(), comp);

    while(idx < p.size()){
        if(p[idx].first < temp){
            idx++;
            continue;
        }
        cnt++;
        temp = p[idx++].second;
    }

    cout << cnt;
    return 0;
}