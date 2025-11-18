#include <bits/stdc++.h>
using namespace std;

int N;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    vector<vector<int>> v(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> v[i][j];
        }
    }

    int full = 1<<N; // 비트마스킹, N자리의 100...00(2)
    vector<vector<int>> dp(full, vector<int>(N, INT32_MAX)); // 2^N * N개의 INT_MAX로 구성된 배열
    
    dp[1<<0][0] = 0; // 초기값 설정

    for(int mask = 0; mask < full; mask++){
        for(int i = 0; i < N; i++){
            if(!mask & (1<<i)) continue; // mask가 현재 비트를 포함하지 않는 경우 스킵
            
            int cur_cost = dp[mask][i];
            if(cur_cost == INT32_MAX) continue; // 초기화된 상태 그대로인 경우 스킵
            
            for(int j = 0; j < N; j++){
                if(mask & (1<<j)) continue; // 이미 방문한 정점인 경우 스킵
                if(!v[i][j]) continue; // 갈 수 없는 길 (혹은 자기 자신)인 경우 스킵

                int nextMask = mask | (1<<j); // nextMask는 현재 방문한 정점 집합에 방금 방문한 정점까지 집어넣은 bit 집합
                dp[nextMask][j] = min(dp[nextMask][j], cur_cost + v[i][j]); // nextMask와 i번째 정점까지의 cost + v[i][j] 비교, 최소 선택
            }
        }
    }

    int ans = INT32_MAX;
    int lastMask = full - 1; // 마지막 bit, 111..11(2)

    for(int i = 0; i < N; i++){
        if(dp[lastMask][i] == INT32_MAX) continue; // 초기화된 이후 바뀐 적 없는 경우 스킵
        if(!v[i][0]) continue; // 갈 수 없는 길 (또는 자기 자신)인 경우 스킵

        int total = dp[lastMask][i] + v[i][0]; // 마지막 정점에서 0번째 정점으로 돌아오고 그 거리 추가
        ans = min(ans, total);
    }

    cout << ans;

    return 0;
}