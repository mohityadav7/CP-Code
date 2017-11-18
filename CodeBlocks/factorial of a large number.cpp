#include <iostream>
using namespace std;
#define MAX 100000

int multiply(int *a, int x, int n){
    int carry=0, temp,i;
    for(i=MAX-1; i>=n; i--){
        temp = a[i]*x + carry;
        a[i] = temp % 10;
        carry = temp / 10;
    }
    while(carry){
        a[i] = carry % 10;
        carry /= 10;
        i--;
    }
    return i+1;
}

int factorial(int n, int *a){
    a[MAX]={0};
    a[MAX-1]=1;
    int index = MAX-1;

    for(int i=2; i<=n; i++)
        index=multiply(a, i, index);

    return index;
}


int main(){
    int n;
    cin>>n;
    int a[MAX];

    int index = factorial(n, a);

    //Output
    for(int i=index; i<MAX; i++)
        cout<<a[i];

    return 0;
}
