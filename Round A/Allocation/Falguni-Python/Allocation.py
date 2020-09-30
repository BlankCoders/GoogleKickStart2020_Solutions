T=int(input())
A=[]
for t in range(1,T+1):
    N,B=[int(s) for s in input().split(" ")]
    A=list(map(int, input().split()))
    count=0
    A.sort()
    for i in range(len(A)):
        if(B>=A[i]):
            B=B-A[i]
            count+=1
    print("Case #{}: {}".format(t,count))
    A.clear()
