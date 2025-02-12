#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

unordered_set<string> S;
string str1, str2;
int N;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    S.insert("ChongChong");
    cin >> N;
        
    for(int i = 0; i < N; i++){
        cin >> str1 >> str2;
        if(S.find(str1) != S.end()) S.insert(str2);
        else if(S.find(str2) != S.end()) S.insert(str1);
    }

    cout << S.size();
    
    return 0;
}