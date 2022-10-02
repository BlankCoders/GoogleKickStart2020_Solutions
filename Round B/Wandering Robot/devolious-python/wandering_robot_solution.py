"""#!/usr/bin/env pypy"""
import collections
import random
import heapq
import bisect
import math
import time


class Solution2:
    def solve(self, A, B):
        pass


def gcd(a, b):
    if not b: return a
    return gcd(b, a%b)
def lcm(a, b):
    return b*a//gcd(b,a)



class Solution:

    def solve(self, A):
        W, H, L, U, R, D = [int(c) for c in A.split()]
        def permutate(n, k):

            if k == 0:
                return 1
            elif n < n - k + 1:
                return n
            else:
                return n * permutate(n - 1, k - 1)
        
        def comb(k, n):
            out = pow(0.5,n)
            c = 1.0
            count = n
            for i in range(1, k+1):
                while c > p and count:
                    c /= 2
                    count -= 1
                c *= float((n+1-i))/float(i)
                if not count:
                    out += c

            return out

        p = pow(0.5, 200)
        #print(p)
        out = 0
        if L > 1 and D < H:
            a = 0
            N = D + L-2
            #for i in range(L-1):
            a += comb(L-2, N)
            out += a
            

        if U > 1 and R < W:
            a = 0
            N = R + U-2
            #for i in range(U-1):
            a += comb(U-2, N)
            out += a
        return out

        
sol = Solution()
sol2 = Solution2()

TT = int(input())
for tc in range(TT):
    out = sol.solve(input())
    print('Case #' + str(tc+1) + ': '+ str(out))
