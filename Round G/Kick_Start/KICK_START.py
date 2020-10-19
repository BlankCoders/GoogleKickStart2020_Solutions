from bisect import bisect_right
def main():
    for _ in range(int(input())):
        a=(input())
        k,s=[],[]
        i=0
        while(i<len(a) and a.find('KICK',i)!=-1):
            k.append(a.find('KICK',i))
            i=a.find('KICK',i)+1
        i=0
        while(i<len(a) and a.find('START',i)!=-1):
            s.append(a.find('START',i))
            i=a.find('START',i)+1
        s1=0
        for i in k:
            s1+=(len(s)-bisect_right(s,i))
        print('Case','#'+str(_+1)+':',s1)
        
main()
