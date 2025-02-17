#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, A, B, C, sum, s_A, s_B, s_C;
    vector<int> v;

    cin >> A >> B >> C >> N;
    for(int i = 0; i < N; i++){
        sum = 0;
        for(int i = 0; i < 3; i++){
            cin >> s_A >> s_B >> s_C;
            sum += A * s_A + B * s_B + C * s_C;
        }
        v.push_back(sum);
    }

    sort(v.begin(), v.end(), greater<>());

    cout << v[0];
    return 0;
}