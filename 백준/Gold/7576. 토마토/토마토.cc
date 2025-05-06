#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int M, N, row, col, cnt, x, y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[1000][1000];
queue<pair<int, int>> q;

bool isInside(int &x, int &y){
    return (x >= 0 && x <= M - 1) && (y >= 0 && y <= N - 1);
}

void BFS(){
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            x = row + dx[i];
            y = col + dy[i];
            if(isInside(x, y) && visited[x][y] == 0){
                q.emplace(x, y);
                visited[x][y] = visited[row][col] + 1;
                if(cnt < visited[x][y]){
                    cnt = visited[x][y] - 1;
                }
            }
        }
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int flag = 0;
    
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++){
            cin >> visited[i][j];
            if(visited[i][j] == 1) q.emplace(i, j);
        }
    }

    BFS();
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 0){
                flag = 1;
                break;
            }
        }
    }
    if(flag) cout << -1;
    else cout << cnt;
    
    return 0;
}