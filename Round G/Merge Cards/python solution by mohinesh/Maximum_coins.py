from collections import  defaultdict
def main():
    for _ in range(int(input())):
        n=int(input())
        l=[list(map(int,input().split())) for i in range(n)]
        d=defaultdict(lambda : 0)
        for i in range(n):
            for j in range(n):
                d[i-j]+=l[i][j]
        print('Case','#'+str(_+1)+':',(d[max(d.keys(),
                    key=lambda x:(d[x]))]))
        
main()