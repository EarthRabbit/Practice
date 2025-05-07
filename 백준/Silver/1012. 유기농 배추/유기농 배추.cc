#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int M, N, K, X, Y, row, col, cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vegetable[50][50];
int visited[50][50];
vector<pair<int, int>> v;
queue<pair<int, int>> q;

bool isInside(int X, int Y){
    return ((X >= 0 && X <= M - 1) && (Y >= 0 && Y <= N - 1));
}

void BFS(int X, int Y){
    visited[X][Y] = 1;
    vegetable[X][Y] = 0;
    q.emplace(X, Y);
    while(!q.empty()){
        X = q.front().first;
        Y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            row = X + dx[i];
            col = Y + dy[i];
            if(isInside(row, col) && vegetable[row][col] && !visited[row][col]){
                visited[row][col] = 1;
                vegetable[row][col] = 0;
                q.emplace(row, col);
            }
        }
    }
    cnt++;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cnt = 0;
        cin >> M >> N >> K;
        for(int j = 0; j < K; j++){
            cin >> X >> Y;
            vegetable[X][Y] = 1;
            v.push_back(pair<int, int>(X, Y));
        }
    
        for(auto iter = v.begin(); iter != v.end(); iter++){
            X = iter->first;
            Y = iter->second;
            if(!visited[X][Y]){
                BFS(X, Y);
            }
        }
        cout << cnt << '\n';
        memset(visited, 0, sizeof(visited));
        v.clear();
    }
    
    return 0;
}