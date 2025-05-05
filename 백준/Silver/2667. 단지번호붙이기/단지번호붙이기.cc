#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, cnt, temp_r, temp_c, temp_cnt;
char c;
int M[25][25];
int A[25][25];
queue<pair<int, int>> q1;
vector<int> v1;

void bfs(int r, int c){
    A[r][c] = ++cnt;
    M[r][c] = 0;
    temp_cnt = 1;
    q1.emplace(r, c);
    while(!q1.empty()){
        temp_r = q1.front().first;
        temp_c = q1.front().second;
        q1.pop();
        if(temp_r != N - 1 && A[temp_r + 1][temp_c] == 0){
            A[temp_r + 1][temp_c] = cnt;
            M[temp_r + 1][temp_c] = 0;
            q1.emplace(temp_r + 1, temp_c);
            temp_cnt++;
        }
        if(temp_r != 0 && A[temp_r - 1][temp_c] == 0){
            A[temp_r - 1][temp_c] = cnt;
            M[temp_r - 1][temp_c] = 0;
            q1.emplace(temp_r - 1, temp_c);
            temp_cnt++;
        }
        if(temp_c != 0 && A[temp_r][temp_c - 1] == 0){
            A[temp_r][temp_c - 1] = cnt;
            M[temp_r][temp_c - 1] = 0;
            q1.emplace(temp_r, temp_c - 1);
            temp_cnt++;
        }
        if(temp_c != N - 1 && A[temp_r][temp_c + 1] == 0){
            A[temp_r][temp_c + 1] = cnt;
            M[temp_r][temp_c + 1] = 0;
            q1.emplace(temp_r, temp_c + 1);
            temp_cnt++;
        }
    }
    v1.push_back(temp_cnt);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    memset(A, -1, sizeof(A));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;
            M[i][j] = c - 48;
            A[i][j] = c - 49;
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(M[i][j] == 1) bfs(i, j);
        }
    }
    sort(v1.begin(), v1.end());
    
    cout << cnt << '\n';
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << '\n';
    }
    
    return 0;
}