# -*- coding: utf-8 -*-
"""
Created on Sun Nov 12 14:46:36 2017
@author: Mohit Yadav
"""

def pwr(a, b):
    if(b==0):
        return 1
    elif(b%2==0):
        return (pwr(a,b/2)*pwr(a,b/2))%1000000007
    else:
        return (a*pwr(a,b-1))%1000000007

t=int(input())
while t:
    p,q,r=map(int, input().split())
    if(q>=0):
        pq=pwr(p,q)
    else:
        pq=pwr(1/p,-q)
    
    x=int(pq/r);
    m,n =(x*r)%1000000007, (r*(x+1))%1000000007
    if(abs(pq-m) < abs(pq-n)):
        print(m)
    else:
        print(n)
    
    t-=1