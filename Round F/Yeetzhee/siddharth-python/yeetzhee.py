def solve(n,m,k,target):
  dp={}
  def dfs(node):
    if sum(node)==n:
      return 0
    if node in dp:
      return dp[node]

    state=list(node)
    cnt,total=0,0 #To calculate probaility to reach next state
    res=0.0
    for i in range(len(state)):
      if i==0 or state[i]!=state[i-1]:
        cnt=1
      else:
        cnt+=1
      # now comes recursion with backtrack
      #Accept only valid states
      if state[i]<target[i] and (i == m - 1 or state[i] != state[i + 1]):       
        state[i]+=1 #try this new state
        total+=cnt 
        res+=dfs(tuple(state))*cnt 
        state[i]-=1 #backtrack

    dp[node] = 1.0 * m/total + res/total #store in cache
    return dp[node]
  
  ret=dfs(tuple([0]*m))
  return ret
  
T = int(input())
for i in range(1, T + 1):
    n, m, k = list(map(int, input().split()))
    target = [0]*(m-k)
    for _ in range(m-k,m):
        target.append(int(input()))
    ans = solve(n, m, k, target)
    print('Case #{}: {}'.format(i, ans))