#include <iostream>
using namespace std;

int numset[51][51][51];

int w(int a, int b, int c){

    if(a < 0 || b < 0 || c < 0){
        a = 0;
        b = 0;
        c = 0;
    }
    
    if(numset[a][b][c]) return numset[a][b][c];

    else{
        if(a <= 0 || b <= 0 || c <= 0){
            return numset[0][0][0];
        }
        else if(a > 20 || b > 20 || c > 20){
            if(!numset[20][20][20]) numset[20][20][20] = w(20, 20, 20);
            return numset[20][20][20];
        }
        else if(a < b && b < c){
            if(!numset[a][b][c]) numset[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
            return numset[a][b][c];
        }
        else{
            if(!numset[a][b][c]) numset[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
            return numset[a][b][c];
        }
    }
}

int main() {

    int a, b, c;
    numset[0][0][0] = 1;

    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1) break;
        else printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}