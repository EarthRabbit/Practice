#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void cantor(int N){
    
    int temp = pow(3, N-1);
    
    if(N == 0){
        cout << '-';
    }
    else{
        cantor(N-1);
        for(int i = 0; i < temp; i++){
            cout << ' ';
        }
        cantor(N-1);
    }
    
}

int main() {

    int N;
    
    while(cin >> N){
        cantor(N);
        cout << '\n';
    }
    
    return 0;
}