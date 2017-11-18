#include <bits/stdc++.h>
using namespace std;

struct event{
    int startDate, endDate;
    string contestName;
};

int main(){
    int numOfContests,a,b,p,q;
    cin>>numOfContests;
    struct event contests[numOfContests];
    for(int i=0; i<numOfContests; i++){
        cout<<"enter start date and end date and contest name"<<endl;
        cin>>a>>b>>p>>q>>contests[i].contestName;
        contests[i].startDate = b*100 +a;
        contests[i].endDate = q*100 +p;
    }

    cout<<"Enter the number of queries: ";
    cin>>q;
    while(q--){
        cout<<"enter a date: ";
        cin>>a>>b;
        int date = b*100 + a;

        for(int i=0; i<numOfContests; i++){
            if(contests[i].startDate <= date && contests[i].endDate >= date){
                cout<<contests[i].contestName<<endl;
            }
        }
    }


    return 0;
}
