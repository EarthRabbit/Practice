#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str[50];
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin >> str[i];
    }
    for(int j=1; j<N; j++){
        for(int i=0; i<str[0].length(); i++){
            if(str[0][i] != str[j][i]){
                str[0][i] = '?';
            }
        }
    }
    cout << str[0];
}