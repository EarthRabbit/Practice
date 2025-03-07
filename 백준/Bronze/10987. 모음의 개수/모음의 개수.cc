#include <iostream>
using namespace std;

int main() {

    char c;
    int cnt = 0;

    while(cin >> c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
    }

    cout << cnt;
    return 0;
}