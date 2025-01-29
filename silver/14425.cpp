#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> S;
int N, M;
string str;

bool compare(string str1, string str2){
    int index = 0;
    while(1){
        if(str1[index] == str2[index]){
            index++;
            continue;
        }
        else if(str1[index] < str2[index]) return true;
        else return false;
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        S.push_back(str);
    }

    sort(S.begin(), S.end(), compare);

    int cnt = 0;

    for(int i = 0; i < M; i++){
        cin >> str;
        if(binary_search(S.begin(), S.end(), str)) cnt++;
    }
    cout << cnt;
    return 0;
}