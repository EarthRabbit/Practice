#include <iostream>
#include <cstring>
using namespace std;

int alphabet_count[26][200001];
int alphabet_temp[26];
int alphabet_number[26];

int alphabet_sub(char c, int begin, int end){
    int idx = c - 97;
    return alphabet_count[idx][end + 1] - alphabet_count[idx][begin];
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, idx, begin, end;
    char target;
    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++){
        idx = str[i] - 97;
        for(int j = alphabet_temp[idx]; j < i; j++){
            alphabet_count[idx][j + 1] = alphabet_number[idx];
        }
        alphabet_number[idx]++;
        alphabet_temp[idx] = i;
    }

    for(int i = 0; i < 26; i++){
        for(int j = alphabet_temp[i]; j < str.length(); j++){
            alphabet_count[i][j + 1] = alphabet_number[i];
        }
    }

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> target >> begin >> end;
        idx = target - 97;
        cout << alphabet_sub(target, begin, end) << '\n';
    }

    return 0;
}