#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
int visited[100001];
vector<vector<int>> v1(100001);

void dfs(int start){
    visited[start] = ++cnt;
    for(int i = 0; i < v1[start].size(); i++){
        if(!visited[v1[start][i]]) dfs(v1[start][i]);
    }
}

bool comp(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, R, start, end;
    cin >> N >> M >> R;
    
    for(int i = 0; i < M; i++){
        cin >> start >> end;
        v1[start].push_back(end);
        v1[end].push_back(start);
    }

    for(int i = 1; i <= N; i++){
        sort(v1[i].begin(), v1[i].end());
    }

    dfs(R);

    for(int i = 1; i <= N; i++){
        cout << visited[i] << '\n';
    }

    return 0;
}