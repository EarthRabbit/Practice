#include <bits/stdc++.h>
#define ll long long
#define p pair<int, int>
using namespace std;

int N;

// 유클리드 거리 - l2 norm
ll l2_norm2(p p1, p p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx*dx + dy*dy;
}

bool comp1(p p1, p p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

bool comp2(p p1, p p2){
    return p1.second < p2.second;
}

// 분할, 정복 과정
ll conquer(vector<p> &A, int left, int right, int size){
    ll dist;
    // 처음에 들어왔을때, 혹은 분할했을 때 점이 3개 이하인 경우 바로 최단거리 계산
    if(size <= 3){
        ll best = LLONG_MAX;
        for(int i = left; i < right; i++){
            for(int j = i + 1; j <= right; j++){
                best = min(best, l2_norm2(A[i], A[j])); 
            }
        }
        return best;
    }
    // 점이 4개 이상인 경우 - 분할 진행 
    int mid = (left + right) / 2;
    // 좌우로 분할하여 최단거리 제곱을 best에 저장
    ll best = min(conquer(A, left, mid, mid - left + 1), conquer(A, mid + 1, right, right - mid));

    // 분할했던 두 집합을 합치며 중앙의 점들 중 최단거리의 가능성이 있는 점 점검
    vector<p> v;
    
    // 중앙으로부터 최단거리 이하로 떨어져 있는 점들만 v에 push
    for(int i = left; i <= right; i++){
        ll dx = A[i].first - A[mid].first;
        if (dx*dx <= best) v.push_back(A[i]);    
    }

    // y값 기준 정렬
    sort(v.begin(), v.end(), comp2);

    // 만약 y값 간의 차가 이전 최단값보다 큰 경우 break, 그렇지 않으면 최단 값을 업데이트
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size() && j <= i + 7; j++) {
            ll dy = v[j].second - v[i].second;
            if (dy*dy > best) break;
            best = min(best, l2_norm2(v[i], v[j]));
        }
    }
    return best;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    int left = 0, right = N - 1, size = N;
    vector<p> A(N);

    for(int i = 0 ; i < N; i++){
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end(), comp1);

    cout << conquer(A, left, right, N);

    return 0;
}