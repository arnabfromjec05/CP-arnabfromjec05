import math

def findMaxTwo(ts):
    ct=0
    while ts%2==0:
        ts//=2
        ct+=1
    return ct


t=int(input())
while t>0:
    ts=int(input())
    if ts%2==1:
        print((ts-1)//2)
    else:
        n=findMaxTwo(ts)
        res=ts//int(math.pow(2,n+1))
        print(res)
    t-=1


