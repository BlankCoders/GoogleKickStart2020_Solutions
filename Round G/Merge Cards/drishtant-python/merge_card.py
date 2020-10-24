d={}
d[2]=[1,1]
def fetch(n):
    if n in d:
        return d[n]
    m = max(d.keys())
    for i in range(m+1,n+1):
        mul = 1
        for j in range(1,i-1):
            mul *= j
        s = d[i-1]
        news=[]
        news.append(s[0]*(i-1))
        for j in range(i-2):
            a,b = j+1,i-1-j-1
            news.append(s[j]*a+s[j+1]*b)
        news.append(s[-1]*(i-1))
        for j in range(i-1):
            news[j]+=1
        for j in range(1,i):
            news[j]+=1

        d[i] = [c/(i-1) for c in news]
    return d[n]


T = int(input())
for x in range(1, T + 1):
    n = int(input())
    nums = list(map(int,input().split()))
    l = fetch(n)
    y = sum([l[i]*nums[i] for i in range(len(l))])
    print("Case #{}: {}".format(x, y), flush = True)
