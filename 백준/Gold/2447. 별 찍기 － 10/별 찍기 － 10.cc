#include <iostream>
using namespace std;

int K;

void star(int i, int j, int N){

    int num = N / 3;
    
    if(N == 1) cout << '*';    
    else if((i / num) % 3 == 1 && (j / num) % 3 == 1) cout << ' ';
    else star(i, j, num);
}

int main(){

    cin >> K;
    
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            star(i, j, K);
        }
        cout << '\n';
    }

    return 0;
}