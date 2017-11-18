#include <bits/stdc++.h>
#include <string>
using namespace std;

bool delete(int a, int x){


}

int main(){
    int t;
    cin>>t;
    char str[100001];
    int a[100000];
    while(t--){
        cin>>str;
        //size of string
        int l=strlen(str);
        int sum=0;

        //storing into array and calculating sum
        for(int i=0; i<l; i++){
            a[i]=(int)(str[i]-48);
            sum+=a[i];
        }

        //checking if any of last two digits is divisible by 2 or not for
        //the whole number to be div by 2 in order to be able to be div by 6
        if(a[l-1] % 2 == 0 || a[l-2] % 2 == 0)
            flg=1;

        bool done=false;
        //finding number to delete
        for(int i=0; i<10; i++){
            if((sum-i) %3==0){
                if(delete(a, i)){
                    done=true;
                    break;
                }
            }
        }

    }


    return 0;
}
