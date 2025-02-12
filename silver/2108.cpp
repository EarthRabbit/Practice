#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

float num1, num2;
int num, num3, num4, cnt;

bool comp(int A, int B){
    if(A == B) return false;
    else return A < B;
}

bool comp2(pair<int, int> A, pair<int, int> B){
    if(A.second == B.second) return A.first > B.first;
    else return A.second > B.second;
}

int main() {

    int N, temp = 4001, ans, temp2 = 1, idx = -1;
    vector<int> v1;
    vector<pair<int, int>> p;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        v1.push_back(num);
        num1 += num;
    }

    sort(v1.begin(), v1.end(), comp);

    for(int i = 0; i < N; i++){ 
        if(temp < 4001){
            if(temp != v1[i]){
                p.push_back(pair<int, int>(temp, cnt));
                temp = v1[i];
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        else{
            temp = v1[i];
            cnt++;
        }
        if(i == N - 1) p.push_back(pair<int, int>(temp, cnt));
    }

    sort(p.begin(), p.end(), comp2);

    while(1){
        idx++;
        if(temp == p[idx].second){
            continue;
        }
        else if(temp < p[idx].second){
            temp = p[idx].second;
            continue;
        }
        else{
            if(idx == 0) ans = 0;
            else ans = idx - 2;
            break;
        }
    }

    for(int i = 0; i < p.size(); i++){
        cout << p[i].first << ' ';
    }

    num1 /= N;
    
    cout << floor(num1 + 0.5) << '\n';

    if(N % 2 == 0) num2 = (v1[(N/2) - 1] + v1[N/2]) / 2;
    else num2 = v1[(N - 1) / 2];

    cout << num2 << '\n';
    
    cout << p[ans].first << '\n';
    
    return 0;
}