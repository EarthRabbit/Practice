#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    char c, temp2 = '+';
    string str;
    vector<int> v;
    vector<char> v2;
    int sum = 0, temp = 0;
    
    while(cin >> c){
        if(c >= 48 && c <= 57) str.push_back(c);
        else if(c == '-' || c == '+'){
            v.push_back(stoi(str));
            v2.push_back(c);
            str = "";
        }
    }
    
    v.push_back(stoi(str));

    sum += v[0];
    
    for(int i = 0; i < v2.size(); i++){
        if(v2[i] == '+'){
            if(temp2 == '+') sum += v[i + 1];
            else if(temp2 == '-') temp += v[i + 1];
        }
        else if(v2[i] == '-'){
            if(temp2 == '-'){
                sum -= temp;
                temp = v[i + 1];
            }
            else if(temp2 == '+'){
                temp2 = v2[i];
                temp += v[i + 1];
            }
        }
    }

    if(temp2 == '+') sum += temp;
    else if(temp2 == '-') sum -= temp;

    cout << sum;
    return 0;
}