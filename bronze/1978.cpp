#include <iostream>
using namespace std;

int main(){
    
    int N, num, cnt=0;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        scanf("%d", &num);
        if(num<2){
            cnt++;
        }
        else{
            for(int i=2; i<num; i++){
                if(num%i == 0){
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d", N-cnt);
    return 0;
}