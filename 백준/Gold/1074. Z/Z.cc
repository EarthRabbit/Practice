#include <iostream>
#include <cmath>
using namespace std;

int sum, r, c, N, K;

int Z(int n, int m, int num){
    if((n / num) % 2 == 1 && (m / num) % 2 == 1) sum += num * num * 3;
    else if((n / num) % 2 == 1 && (m / num) % 2 == 0) sum += num * num * 2;
    else if((n / num) % 2 == 0 && (m / num) % 2 == 1) sum += num * num;

    if(num == 1) return sum;
    else return Z(n, m, num / 2);
}

int main() {

    cin >> N >> r >> c;
    
    K = pow(2, N - 1);
    
    cout << Z(r, c, K);
    
    return 0;
}