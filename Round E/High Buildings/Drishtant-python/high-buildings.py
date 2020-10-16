testcases=[]
T = int(input())
for i in range (T):
    testcases.append(input().split(" "))

for j in range(1,T+1):
    n,a,b,c = testcases[j-1]
    n = int(n)
    a = int(a)
    b = int(b)
    c = int(c)
    print(f"Case #{j}: ",end="")

    if n==1:
        if a==1 and c==1 and b==1 :
            print(1)
        else:
            print("IMPOSSIBLE")
    elif n==2:
        if c==2 and b==2 and a==2 :
            print(1," ",1)
        elif a==2 and b==1 and c==1 :
            print(1," ",2)
        elif a==1 and b==2 and c==1 :
            print(2," ",1)
        else:
            print('IMPOSSIBLE')
    else:
        overshadowed_buildings = n-((a+b)-c)
        if overshadowed_buildings < 0:
            print("IMPOSSIBLE")

        elif a-c >0:
            for i in range(a-c):
                print(2,end=" ")
                i+=1
            for i in range(overshadowed_buildings):
                print(1,end=" ")
                i+=1
            for i in range(c):
                print(3,end=" ")
                i+=1
            for i in range(b-c):
                print(2,end=" ")
                i+=1
            print()

        elif b-c>0:
            for i in range(a-c):
                print(2,end=" ")
                i+=1
            for i in range(c):
                print(3,end=" ")
                i+=1
            for i in range(overshadowed_buildings):
                print(1,end=" ")
                i+=1
            for i in range(b-c):
                print(2,end=" ")
            print()

        elif c>=2:
            print(3,end=" ")
            for i in range(overshadowed_buildings):
                print(1,end=" ")
                i+=1
            for i in range(c-1):
                print(3,end=" ")
                i+=1
            print()
        else:
            print("IMPOSSIBLE")
