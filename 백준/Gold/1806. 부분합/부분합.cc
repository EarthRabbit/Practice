#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, S, num, sum = 0, size = 1, temp, temp_size = 100001, isTrue = 0;
    vector<int> numset;

    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> num;
        numset.push_back(num);
        sum += num;
    }

    int start = 0;
    int end = 1;
    
    if(sum < S) cout << 0;
    else{
        sum = numset[0];
        temp = numset[0];
        while(start < end){
            if(sum >= S && size == 1){
                isTrue = 1;
                temp_size = 1;
                break;
            }
            if(sum < S && end < N){
                sum += numset[end++];
                size++;
            }
            else if(sum >= S && end < N){
                isTrue = 1;
                if(sum >= S && temp_size > size) temp_size = size;
                sum -= temp;
                temp = numset[++start];
                size--;
            }
            else if(sum >= S && end == N){
                isTrue = 1;
                if(sum >= S && temp_size > size) temp_size = size;
                size--;
                sum -= temp;
                temp = numset[++start];
            }
            else if(sum < S && end == N) break;
        }
        if(isTrue){
            if(start == end) cout << 1;
            else cout << temp_size;
        }
        
    }
    return 0;
}