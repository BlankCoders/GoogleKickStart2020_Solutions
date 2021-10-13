import heapq

T = int(input())

for cas in range(T):
    N, M, S, R = map(int, input().split(' '))
    neighbors = [[] for i in range(N)]
    for i in range(M):
        U, V = map(int, input().split(' '))
        neighbors[U - 1].append(V - 1)
        neighbors[V - 1].append(U - 1)
    heap = []
    heap_size = 0
    stones = [list(map(int, input().split(' '))) for i in range(N)]
    finished = [[False for j in range(S + 1)] for i in range(N)]
    cost = [[None for j in range(S + 1)] for i in range(N)]
    for i in range(N):
        for j in range(stones[i][0]):
            heapq.heappush(heap, (0, i, stones[i][j + 1]))
            heap_size = heap_size + 1
            cost[i][stones[i][j + 1]] = 0
            
    recipes = [list(map(int, input().split(' '))) for i in range(R)]
    recipes_stone = [set({}) for i in range(S + 1)]
    for i in range(R):
        count = recipes[i][0]
        for j in range(count):
            needs = recipes[i][j + 1]
            recipes_stone[needs].add(i)
    ans = -1
    while heap_size > 0:
        top = heap[0]
        cur_cost = top[0]
        if cur_cost >= 10**12:
            break
        junction = top[1]
        stone_type = top[2]
        if stone_type is 1:
            ans = cur_cost
            break
        heapq.heappop(heap)
        heap_size = heap_size - 1
        if finished[junction][stone_type]:
            continue
        finished[junction][stone_type] = True
        for neighbor in neighbors[junction]:
            if cost[neighbor][stone_type] is None or cost[neighbor][stone_type] > cur_cost + 1:
                cost[neighbor][stone_type] = cur_cost + 1
                heapq.heappush(heap, (cur_cost + 1, neighbor, stone_type))
                heap_size = heap_size + 1

        for r in recipes_stone[stone_type]:
            re = recipes[r]
            good = True
            total_cost = 0
            final_stone = re[re[0] + 1]
            if finished[junction][final_stone] is True:
                continue
            for i in range(re[0]):
                if finished[junction][re[i + 1]] is False:
                    good = False
                else:
                    total_cost = total_cost + cost[junction][re[i + 1]]
            if not good:
                continue
            if cost[junction][final_stone] is None or cost[junction][final_stone] > total_cost:
                cost[junction][final_stone] = total_cost
                heapq.heappush(heap, (total_cost, junction, final_stone))
                heap_size = heap_size + 1

    print ("Case #{0}: {1}".format(cas + 1, ans))
