#include <iostream>
#include <queue>
using namespace std;

int N, M, temp, X;
int visited[101];
int snake[101];
queue<int> q;

int BFS(){
    for(int i = 2; i <= 7; i++){
        if(snake[i]){
            if(!visited[snake[i]]){
                visited[snake[i]] = 1;
                if(snake[i] == 100) return visited[100];
                q.push(snake[i]);
            }
        }
        else{
            visited[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = 1; i <= 6; i++){
            X = temp + i;
            if(X <= 100 && !visited[X]){
                if(snake[X]){
                    if(!visited[snake[X]]){
                        visited[snake[X]] = visited[temp] + 1;
                        if(snake[X] == 100) return visited[100];
                        q.push(snake[X]);
                    }
                }
                else{
                    visited[X] = visited[temp] + 1;
                    if(X == 100) return visited[100];
                    q.push(X);
                }
            }
        }
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int start, end;
    
    cin >> N >> M;
    for(int i = 0; i < N + M; i++){
        cin >> start >> end;
        snake[start] = end;
    }

    cout << BFS();
    
    return 0;
}