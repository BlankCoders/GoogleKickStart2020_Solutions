T = int(input())
for i in range(T):
    N = int(input())
    Vs = [int(v) for v in input().split(" ")]
    max_number = -1
    record_breaks = 0
    for j in range(N):
        first_condition = Vs[j] > max_number
        if j+1 < N:
            second_condition = Vs[j] > Vs[j+1]
        else:
            second_condition = True
        if first_condition and second_condition:
            record_breaks +=1
        if first_condition:
            max_number = Vs[j]
    print("Case #{}: {}".format(str(i+1), str(record_breaks)))