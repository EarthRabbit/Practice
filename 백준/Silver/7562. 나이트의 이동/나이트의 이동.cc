#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, l, row, col, X, Y, cnt;
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int visited[300][300];
queue<pair<int, int>> q;
vector<int> v1;

int isInside(int A, int B){
    return (A >= 0 && A < l) && (B >= 0 && B < l);
}

int BFS(int A, int B, int target_row, int target_col){
    visited[A][B] = 0;
    if(A == target_row && B == target_col) return visited[A][B];
    q.emplace(A, B);
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            X = row + dx[i];
            Y = col + dy[i];
            if(isInside(X, Y) && !visited[X][Y]){
                visited[X][Y] = visited[row][col] + 1;
                if(X == target_row && Y == target_col) return visited[X][Y];
                q.emplace(X, Y);
            }
        }
    }
}

int main() {
    int start_row, start_col, target_row, target_col;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> l >> start_row >> start_col >> target_row >> target_col;
        v1.push_back(BFS(start_row, start_col, target_row, target_col));
        memset(visited, 0, sizeof(visited));
        q = queue<pair<int, int>>();
    }

    for(auto num : v1){
        cout << num << '\n';
    }
    return 0;
}