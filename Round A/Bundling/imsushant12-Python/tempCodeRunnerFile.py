from collections import defaultdict
from functools import reduce, partial

def iter_dfs(K, node):
    def divide(node, depth):
        if "_count" not in node:
            node["_count"] = 0
        stk.append(partial(conquer, node, depth))
        stk.extend((partial(divide, child, depth+1) for k, child in node.iteritems() if k != "_count"))

    def conquer(node, depth):
        node["_count"] += sum(child["_count"] for k, child in node.iteritems() if k != "_count")
        q, node["_count"] = divmod(node["_count"], K)
        result[0] += q*depth

    result = [0]
    stk = [partial(divide, node, 0)]
    while stk:
        stk.pop()()
    return result[0]

def bundling():
    N, K = map(int, input().strip().split())

    _trie = lambda: defaultdict(_trie)
    trie = _trie()
    for _ in range(N):
        s = input().strip()
        node = reduce(dict.__getitem__, s, trie)
        if "_count" not in node:
            node["_count"] = 0
        node["_count"] += 1    
    return iter_dfs(K, trie)

for case in range(input()):
    print ("Case #%d: %s" % (case+1, bundling()))