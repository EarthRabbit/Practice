#include <iostream>
using namespace std;

int pow1(long long int N, int M){
    for(int i = 0; i < M; i++){
        N = (N * 31) % 1234567891;
    }
    return N;
}

int main() {

    unsigned long long sum = 0;
    int L;
    char arr[50];
    
    cin >> L;
    
    for(int i=0; i<L; i++){
        cin >> arr[i];
        sum += pow1(arr[i] - 96, i);
    }
    cout << sum % 1234567891;
    return 0;
}