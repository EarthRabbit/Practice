#include <iostream>
using namespace std;

int main() {

    int T, sum = 0;
    int timeSet[3] = {300, 60, 10};
    int timeTime[3];
    
    cin >> T;
    
    for(int i = 0; i < 3; i++){
        timeTime[i] = (T / timeSet[i]);
        T = T % timeSet[i];
    }

    if(T == 0){
        for(int i = 0; i < 3; i++){
            cout << timeTime[i] << ' ';
        }
    }
    else cout << -1;
    
    return 0;
}