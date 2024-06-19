#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, sum=0;
    vector <int> d1;
    
    while(1){
        scanf("%d", &N);
        if(N == -1) break;
        for(int i=1; i<N; i++){
            if(N%i == 0){
                sum += i;
                d1.push_back(i);
            }
        }
        
        if(sum == N){
            printf("%d = ", N);
            for(int i=0; i<d1.size(); i++){
                printf("%d ", d1[i]);
                if(i != d1.size()-1) printf("+ ");
            }
            printf("\n");
        }
        else printf("%d is NOT perfect.\n", N);
        
        d1.clear();
        sum = 0;
    }
}