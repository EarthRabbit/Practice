#include <iostream>
#include <vector>
using namespace std;

int checkchess(vector<vector<char>> chessboard, int n, int m){
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j)%2 == 0){
                if(chessboard[n+i][m+j] == 'B') cnt++;
            }
            else if((i+j)%2 == 1){
                if(chessboard[n+i][m+j] == 'W') cnt++;
            }
        }
    }
    if(cnt>32) return 64-cnt;
    else return cnt;
}
int main()
{
    int N, M, cnt = 33, temp;
    char P;
    vector<vector<char>> chessboard;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        chessboard.push_back(vector<char>());
        for(int j=0; j<M; j++){
            scanf(" %c", &P);
            chessboard[i].push_back(P);
        }
    }
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            temp = checkchess(chessboard, i, j);
            if(cnt > temp) cnt = temp;
        }
    }
    printf("%d", cnt);
    return 0;
}