#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <ios>
using namespace std;

void rotate(char s[101]){
    int l=strlen(s);
    char temp=s[l-1];
    for(int i=l-1; i>0; i--)
        s[i]=s[i-1];

    s[0]=temp;
}

int main(){
    int t;
    cin>>t;
    char s[101];
    while(t--){
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(s,101);
        int len=strlen(s);

        vector <string> v(len);
        for(int i=0; i<len; i++){
            v[i]=s;
            rotate(s);
        }

        //sort strings in vector v
        sort(v.begin(), v.end());

        for(int i=0; i<len; i++)
            cout<<v[i][len-1];
        cout<<endl;

    }

    return 0;
}
