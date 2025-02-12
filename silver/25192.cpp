// tip : unordered_set의 find : O(1), set의 find : O(logN) / erase()는 O(1)이나 clear()의 경우 O(N). 

#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

unordered_set<string> S;
string str;
int cnt;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cnt = 0;

    cin >> N;
    
    for (int i = 0; i < N; i++){
        cin >> str;
        if(str != "ENTER"){
            if(S.find(str) == S.end()){
                S.insert(str);
                cnt++;
            }
        }
        else S.erase(S.begin(), S.end());
    }
    cout << cnt;
    return 0;
}