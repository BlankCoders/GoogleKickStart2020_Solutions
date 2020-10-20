# Python solution for workout problem Round A by drishtantR1508
testcases = int(input())

import collections as cl

for m in range(testcases):
    N,K = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    difference = [0]*(N-1)
    for i in range(N-1):
        difference[i] = arr[i + 1] - arr[i]
    c = cl.Counter(difference)
    def func1(mid):
        result = 0
        for i, j in c.items():
            if i % mid == 0:
                result += (i//mid - 1) * j
            else:
                result += (i//mid) * j
        return result
    left, right = 1, max(difference)
    while left < right:
        mid = (left + right) // 2
        if func1(mid) <= K:
            right = mid
        else:
            left = 1+mid
    print("Case #",end="")
    print(str(m+1),end="")
    print(": " + str(left))
