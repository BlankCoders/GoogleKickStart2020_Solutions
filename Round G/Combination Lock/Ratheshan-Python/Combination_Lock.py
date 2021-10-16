def get_grid(combos, N):
    grid = []
    for i in range(len(combos)):
        num = 0
        for j in range(len(combos)):
            diff = combos[j] - combos[i]
            diff = (diff%N+N)%N
            dist = min(diff, N-diff)
            num += dist
        grid.append(num)
    return grid

def get_min(combos, N):
    grid = get_grid(combos, N)
    return min(grid)

T = int(input())

for i in range(T):
    w, n = (int(x) for x in input().split())

    locks = [int(x) for x in input().split()]
    
    print ('Case #'+str(i+1)+': '+str(get_min(locks, n)))
