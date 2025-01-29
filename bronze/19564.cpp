// https://www.acmicpc.net/problem/19564

#include <iostream>
#include <cstring>
using namespace std;
int main() {

    string str;
    int temp = 0, cnt = 1;

    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(temp >= str[i]){
            cnt++;
        }
        temp = str[i];
    }
    cout << cnt;
    return 0;
}