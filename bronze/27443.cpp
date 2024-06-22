#include <iostream>
using namespace std;

unsigned long long int factorial(int n){
    if(n>1) return n*factorial(n-1);
    else return 1;
}

int main(){
    int N;
    unsigned long long A;
    scanf("%d", &N);
    A = factorial(N);
    printf("%lld", A);
}