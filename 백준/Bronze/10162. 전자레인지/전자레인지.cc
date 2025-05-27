#include <iostream>
using namespace std;

int main() {

    int T, temp = 0, sum = 0;
    int timeSet[3] = {300, 60, 10};
    int timeTime[3];
    
    cin >> T;
    
    while(T > 9){
        timeTime[temp] = (T / timeSet[temp]);
        T = T % timeSet[temp];
        temp++;
    }

    if(T == 0){
        for(int i = 0; i < 3; i++){
            cout << timeTime[i] << ' ';
        }
    }
    else cout << -1;
    
    return 0;
}