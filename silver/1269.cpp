// https://www.acmicpc.net/problem/1269

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, num;
    
    set<int> s;
    vector<int> v;

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        cin >> num;
        s.insert(num);
    }

    for (int i = 0; i < M; i++){
        cin >> num;
        if(s.find(num) != s.end()) v.push_back(num);
        s.insert(num);
    }

    cout << s.size() - v.size();

    return 0;
}