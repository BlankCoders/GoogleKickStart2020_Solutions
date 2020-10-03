from math import ceil
for i in range(int(input())):
    N,hour = map(int,input().split())
    arr= []
    for _ in range(N):
        arr.append(list(map(int,input().split())))
    arr.sort()
    total = 0
    pip = 0
    for a,b in arr:
        if a>pip:
            pip = a
        while pip<b:
            pp = ceil((b-pip)/hour)
            pip+=(pp*hour)
            total+=pp
    print('Case #'+str(i+1)+": "+str(total))