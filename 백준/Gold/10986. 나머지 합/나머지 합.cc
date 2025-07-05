#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, temp = 0;
    unsigned long long int sum = 0, cnt = 0;
    int num[1000001];
    vector<int> remainder;
    remainder.push_back(0);
    
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> num[i];
        remainder.push_back((remainder[i - 1] + num[i]) % M);
    }

    sort(remainder.begin(), remainder.end());

    for(int i = 0; i <= N; i++){
        if(temp == remainder[i]) cnt++;
        else{
            sum += (cnt * (cnt - 1)) / 2;
            cnt = 1;
            temp = remainder[i];
        }
    }

    sum += (cnt * (cnt - 1)) / 2;

    cout << sum;
    
    return 0;
}