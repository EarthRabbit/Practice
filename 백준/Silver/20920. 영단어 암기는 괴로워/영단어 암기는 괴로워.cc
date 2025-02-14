#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        if((p1.first).length() == (p2.first).length()){
            return p1.first < p2.first;
        }
        return (p1.first).length() > (p2.first).length();
    }
    return p1.second > p2.second;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    string str;
    map<string, int> m;
    
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> str;
        if(str.length() >= M){
            m[str]++;
        }
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), comp);

    for(auto iter = v.begin(); iter != v.end(); iter++){
        cout << iter->first << '\n';
    }
    
    return 0;
}