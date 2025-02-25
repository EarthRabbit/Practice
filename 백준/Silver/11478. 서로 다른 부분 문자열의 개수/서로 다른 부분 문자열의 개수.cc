#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string S, sub;
    unordered_set<string> set1;

    cin >> S;
    
    int size = S.length();
    for(int i = 0; i < size; i++){
        for(int j = 1; j <= size - i; j++){
            sub = S.substr(i, j);
            set1.insert(sub);
        }
    }
    cout << set1.size();
    return 0;
}