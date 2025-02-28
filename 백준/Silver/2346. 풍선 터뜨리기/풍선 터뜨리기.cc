#include <iostream>
#include <deque>
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, num, val;
    deque<pair<int, int>> D;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        D.push_back(pair<int, int>(num, i));
    }

    while(D.size()){
        
        val = D.front().first;
        cout << D.front().second + 1 << ' ';
        D.pop_front();
        
        if(val > 0){
            for(int i = 1; i < val; i++){
                D.push_back(D.front());
                D.pop_front();
            }
        }
        
        else{
            for(int i = 0; i > val; i--){
                D.push_front(D.back());
                D.pop_back();
            }
        }
    }
    return 0;
}