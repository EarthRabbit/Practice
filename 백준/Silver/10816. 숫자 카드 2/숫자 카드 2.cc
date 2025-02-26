// https://www.acmicpc.net/problem/10816

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> P1;
vector<int> P2;
int val, cnt, target;

bool comp(int A, int B){
    if(A == B) return false;
    else return A < B;
}

int binarysearch(int target){
    int start = 0, end = P1.size() - 1, mid;
    while(start <= end){
        mid = (start + end)/2;
        if(P1[mid].first == target){
            return P1[mid].second;
        }
        else if(P1[mid].first > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return 0;
}

int main() {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, temp = 10000001;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> val;
        P2.push_back(val);
    }

    sort(P2.begin(), P2.end(), comp);
    
    for(int i = 0; i < P2.size(); i++){
        if(temp < 10000001){
            if(temp != P2[i]){
                P1.push_back(pair<int, int>(temp, cnt));
                temp = P2[i];
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        else{
            temp = P2[i];
            cnt++;
        }
        if(i == P2.size() - 1) P1.push_back(pair<int, int>(temp, cnt));
    }

    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> target;
        cout << binarysearch(target) << ' ';
    }

    return 0;
}