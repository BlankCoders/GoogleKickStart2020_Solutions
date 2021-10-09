def minimum(z):
    temp_min = 0
    ind = (len(z)-1)//2
    for x in z:
        temp_min += abs(z[ind]-x)
    return temp_min

def solve(i):
    temp = 0
    N = int(input())
    x = []
    y = []
    for _ in range(N):
        a,b = [int(j) for j in input().split(" ")]
        x.append(a)
        y.append(b)
    y.sort()
    temp += minimum(y)
    x.sort()
    x = [x[i]-i for i in range(N)]
    x.sort() 
    temp += minimum(x)  
    print(f"Case #{i}: {temp}")

if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1,1):
        solve(i)
    