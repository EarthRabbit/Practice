// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> m;
vector<string> v, ans;
string str;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, cnt = 0;

    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> str;
        m.insert(pair<string, int>(str, 1));
    }

    for(int i = 0; i < M; i++){
        cin >> str;
        v.push_back(str);
    }
    
    sort(v.begin(), v.end());

    for(int i = 0; i < M; i++){
        if(m.find(v[i]) != m.end()){
            cnt++;
            ans.push_back(v[i]);
        }
    }
    
    cout << cnt << '\n';
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}