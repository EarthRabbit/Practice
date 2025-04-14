#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

queue<int> q;
vector<vector<int>> v(100001);
int visited[100001];
int cnt, temp;

void bfs(int start){
    visited[start] = ++cnt;
    q.push(start);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(auto iter = v[temp].begin(); iter != v[temp].end(); iter++){
            if(!visited[*iter]){
                visited[*iter] = ++cnt;
                q.push(*iter);
            }
        }
    }
}

int main() {

    int N, M, R, start, end;
    
    cin >> N >> M >> R;

    for(int i = 0; i < M; i++){
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    
    for(int i = 1; i <= N; i++){
        sort(v[i].begin(), v[i].end(), greater<>());
    }

    bfs(R);
    
    for(int i = 1; i <= N; i++){
        cout << visited[i] << '\n';
    }
    
    return 0;
}