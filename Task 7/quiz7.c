#include<stdio.h>
#include<math.h>

double fact(int n)
{
    double ans = 1;
    while(n>1){
        ans *= n;
        n--;
    }
    return ans;
}

double Exp(double x,int n){
    double ans = 0.0;
    while(n>0){
        ans += pow(x,n)/fact(n);
        n--;
    }
    return ans;
}

int main(){
    double x[] = {0.0,4.1,10.0,-0.05};
    int n[] = {10,100};
    for (int i = 0; i < 2; i++){
        for (int g = 0; g < 4; g++){
            printf("x Value: %f | n Value: %d | Result: %lf\n",x[g],n[i],Exp(x[g],n[i]));
        }
    }
    return 0;
}