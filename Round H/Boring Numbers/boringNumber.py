#boringNumbers

def boringnum(start,end) :
    total = 0
    for n in range(start,end+1):
        num = str(n)
        pos = 1
        prev = 0
        for i in num :
            if(pos == 1 and pos%2 != 0 and int(i)%2 != 0) :
                prev = 1
                pos += 1
            elif(prev==1 and pos%2 != 0 and int(i)%2 != 0) :
                prev = 1
                pos += 1
            elif(prev==1 and pos%2 == 0 and int(i)%2 == 0) :
                prev = 1
                pos += 1
            else :
                prev = 0
                break
        if(prev == 1) :
            total += 1

    return total


count = int(input())
res = []
for i in range(count) :
    s = input()
    ls = s.split()
    res.append(boringnum(int(ls[0]), int(ls[1])))

for r in range(len(res)) :
    print("Case #"+str(r+1)+": "+str(res[r]))
