#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt, temp;
vector<vector<int>> v1(100001);
int visited[100001];
queue<int> q;

void BFS(int R){
    visited[R] = ++cnt;
    q.push(R);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(auto iter = v1[temp].begin(); iter != v1[temp].end(); iter++){
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
        v1[start].push_back(end);
        v1[end].push_back(start);
    }

    for(int i = 0; i < N; i++){
        sort(v1[i].begin(), v1[i].end());
    }

    BFS(R);
    
    for(int i = 1; i <= N; i++){
        cout << visited[i] << '\n';
    }
    return 0;
}