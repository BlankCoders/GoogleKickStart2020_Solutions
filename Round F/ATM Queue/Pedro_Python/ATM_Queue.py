import operator
import math
T = int(input())

for i in range(T):
    N, X = input().split(" ")
    X = int(X)
    As = input().split(" ")
    
    list_of_people = [(a, math.ceil(int(As[a-1])/X)) for a in range(1, int(N) + 1)]
    
    sorted_list = sorted(list_of_people, key=operator.itemgetter(1,0))
    
    result_list = [str(item[0]) for item in sorted_list]

    result_string = " ".join(result_list)
    print("Case #{}: {}".format(str(i+1), result_string))
    
