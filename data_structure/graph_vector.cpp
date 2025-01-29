// 단방향 그래프
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    cin.tie();
    ios::sync_with_stdio(false);

    int N, A, B, index;
    vector<vector<int>> graph;

    cin >> N;
    // 2차원 벡터 초기화, 1부터 N까지에 해당하는 노드 사용
    for(int i = 0; i < N + 1; i++){
        graph.push_back(vector<int>());
    }

    while(1){
        cin >> A >> B;
        if(A == 0 && B == 0) break;
        graph[A].push_back(B);
        // 양방향 그래프의 경우 graph[B].push_back(A);
    }

    for(int i = 1; i < N + 1; i++){
        sort(graph[i].begin(), graph[i].end());
        index = 0;
        while(index != graph[i].size()){
            cout << i << "->" << graph[i][index++] << ' ';
        }
    }
    return 0;
}