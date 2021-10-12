# Took help from https://www.wikiwand.com/en/Floyd%E2%80%93Warshall_algorithm

class Graph:
    def __init__(self):
        self.translate = {}
        self.g = [[100 for i in range(26)] for j in range(26)]
        alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        for i in range(26): 
            self.translate.update({alphabet[i]: i})

    def addWord(self, word):
        for i in set(word):
            for j in set(word):
                if i == j: continue
                a = self.translate[i]
                b = self.translate[j]
                self.g[a][b] = 1
                self.g[b][a] = 1
        
    def fillBlanks(self):
        for k3 in range(26):
            self.g[k3][k3] = 0
            for k1 in range(26):
                for k2 in range(26):
                    varSum = self.g[k1][k3] + self.g[k3][k2]
                    if self.g[k1][k2] > varSum:
                        self.g[k1][k2] = varSum
                        self.g[k2][k1] = varSum
                        
    def ansQuery(self, nameA, nameB):
        minDist = 100
        for i in set(nameA):
            for j in set(nameB):
                if i == j: return 2
                numA = self.translate[i]
                numB = self.translate[j]
                if self.g[numA][numB] < minDist:
                    minDist = self.g[numA][numB]
                    
        if minDist == 100:
            minDist = -1
        else:
            minDist = minDist + 2
            
        return minDist
        
for t in range(1, int(input())+1):
    N, Q = [int(s) for s in input().split(" ")]
    varG = Graph()
    names = input().split(" ")
    for name in names:
        varG.addWord(name)
    varG.fillBlanks()
    result = []
    for q in range (1, Q+1):
        num1, num2 = [int(s) for s in input().split(" ")]
        result.append(varG.ansQuery(names[num1-1], names[num2-1]))
    print("Case #" + str(t) + ":", *result)