#include <iostream>
#include <vector>
using namespace std;

int visited[8];
int N, M;
vector<int> v1;

void backTracking(){
    if(v1.size() == M){
        for(int i = 0; i < M; i++){
            cout << v1[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        v1.push_back(i);
        backTracking();
        visited[i] = 0;
        v1.pop_back();
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;

    backTracking();
    
    return 0;
}