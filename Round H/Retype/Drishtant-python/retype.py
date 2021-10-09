def solve(i):
    n,k,s = [int(i) for i in input().split(" ")]
    print(f"Case #{i}: {min(n+k,n+2*(k-s))}")
    

if __name__ == "__main__":
    t = int(input())
    for i in range(1,t+1,1):
        solve(i)