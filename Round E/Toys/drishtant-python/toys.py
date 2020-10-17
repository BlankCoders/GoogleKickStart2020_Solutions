#toys problem python code by @drishtantR1508
from heapq import heappush as hsh
from heapq import heappop as hp

testcases = int(input())

for j in range(testcases):

    N = int(input())#No of toys

    entertainment_time = [0 for i in range(N)]
    remember_time = [0 for i in range(N)]
    total = 0


    for i in range(N):
        entertainment_time[i], remember_time[i] = map(int, input().split(' '))
        total += entertainment_time[i]

    removed = 0
    current = total
    best_ans = total
    best_removed = 0
    heap = []
    heap_size = 0
    for i in range(N):
        hsh(heap, (-entertainment_time[i] - remember_time[i], entertainment_time[i]))
        current += entertainment_time[i]
        heap_size += 1


        while heap_size > 0:

            top = heap[0]
            if -top[0] > total:
                removed += 1
                heap_size -= 1
                total -= top[1]
                current -= (top[1] * 2)
                hp(heap)


            else:
                break
        if current > best_ans:
            best_ans = current
            best_removed = removed

    if heap_size > 0:
        print("Case #{0}: {1} INDEFINITELY".format((j + 1), removed))
    else:
        print("Case #{0}: {1} {2}".format((j + 1), best_removed, best_ans))
