
t = int(input())

for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split(" ")]
    ans = 0
    for i in range(1, n-1):
        if arr[i-1] < arr[i] > arr[i+1]:
            ans += 1
    print("Case #{}:".format(_+1),ans)