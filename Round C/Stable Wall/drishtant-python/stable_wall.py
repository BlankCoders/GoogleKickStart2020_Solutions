def dfs(u, vis, inst, st, edges):
    vis[u] = True
    inst[u] = True
    suc = True
    for v in edges[u]:
        if inst[v]:
            return False
        if vis[v] == False:
            suc &= dfs(v, vis, inst, st, edges)
    st.append(u)
    inst[u] = False
    return suc


def solve(T):
    for tdx in range(T):
        n, m = list(map(int, input().split()))
        tbl = [input() for _ in range(n)]
        
        edges = [set() for _ in range(26)]
        nodes = set([ord(c) - ord('A') for row in tbl for c in row])
        for jdx in range(m):
            for idx in range(1, n)[::-1]:
                if tbl[idx][jdx] != tbl[idx - 1][jdx]:
                    u = ord(tbl[idx][jdx]) - ord('A')
                    v = ord(tbl[idx - 1][jdx]) - ord('A')
                    edges[v].add(u)

        vis = [False for _ in range(26)]
        inst = [False for _ in range(26)]
        st = []

        suc = True
        for kdx in range(26):
            if kdx in nodes and vis[kdx] == False:
                suc &= dfs(kdx, vis, inst, st, edges)
            
        if not suc:
            print('Case #{TDX}: -1'.format(TDX=tdx + 1))
        else:
            res = ''.join([chr(ord('A') + v) for v in st])
            print('Case #{TDX}: {RES}'.format(TDX=tdx + 1, RES=res))


if __name__ == '__main__':
    T = int(input())
    solve(T)
