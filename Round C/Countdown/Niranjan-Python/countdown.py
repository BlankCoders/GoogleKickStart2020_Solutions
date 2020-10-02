t = int(input())
for _ in range(t):
    n, k = map(int, input().split(" "))
    arr = [int(x) for x in input().split(" ")]
    ans = 0
    c = 0
    for i in range(1,n):
        if arr[i] == arr[i-1] -1:
            c += 1
        else:
            c = 0
        if arr[i] == 1 and c >= k - 1:
            ans += 1
    print('Case #{}: {}'.format(_+1,ans))