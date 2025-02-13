#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(int A, int B){
    if(A == B) return false;
    else return A < B;
}

bool comp2(pair<int, int> A, pair<int, int> B){
    if(A.second == B.second) return A.first < B.first;
    else return A.second > B.second;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, num, ans;
    int numset[8001] = {0, };
    double avg, sum = 0;
    vector<int> v1;
    vector<pair<int, int>> p;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        v1.push_back(num);
        sum += num;
    }

    sort(v1.begin(), v1.end(), comp);

    for(int i = 0; i < N; i++){
        numset[v1[i] + 4000]++;
    }
    
    for(int i = 0; i < 8001; i++){
        if(numset[i] > 0){
            p.push_back(pair<int, int>(i - 4000, numset[i]));
        }
    }

    sort(p.begin(), p.end(), comp2);

    if(p.size() == 1) ans = 0;
    else{
        if(p[0].second > p[1].second) ans = 0;
        else ans = 1;
    }

    avg = round(sum / N);
    if(avg == -0) avg = 0;

    cout << avg << '\n' << v1[N/2] << '\n' << p[ans].first << '\n' << v1[N - 1] - v1[0];
    
    return 0;
}