#include <iostream>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, num, temp, comp1 = 0, c = 0;

    cin >> N;
    cin >> temp;
    
    for(int i = 1; i < N; i++){
        cin >> num;
        if(temp > num){
            if(comp1 == 0){
                comp1 = -1;
            }
            else if(comp1 == 1){
                c++;
                comp1 = -1;
            }
        }
        else if(temp == num){
            c = 999;
        }
        else if(temp < num){
            if(comp1 == 0){
                comp1 = 1;
            }
            else if(comp1 == -1){
                c++;
                comp1 = 1;
            }
        }
        temp = num;
    }

    if(c == 0){
        cout << "YES";
    }
    else if(c == 1){
        if(comp1 == -1) cout << "YES";
        else cout << "NO"; 
    }
    else cout << "NO";
    
    return 0;
}