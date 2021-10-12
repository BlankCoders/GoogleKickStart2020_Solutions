def get_boringcount_of_length (n):
    BR_number = 0
    for a in range (n):
        BR_number = BR_number + 5**(a + 1)
    return BR_number

def boring_no_at_digit (digitvalue, digitpos, n): ## parameters are integers.
    boring_no_at_digit = 0

    if digitpos == 1 and digitpos !=n:
        for i in range (1, digitvalue):
            if i %2 == digitpos %2:
                boring_no_at_digit += 1
        return boring_no_at_digit * 5**(n-digitpos)

    if digitpos == n:
        for i in range (digitvalue + 1):
            if i %2 == digitpos %2:
                boring_no_at_digit += 1
        return boring_no_at_digit * 5**(n-digitpos)

    for i in range (digitvalue):
        if i%2 == digitpos %2:
            boring_no_at_digit+=1
    return boring_no_at_digit * 5** (n-digitpos)

def check_boring_no (number_str):
    n = len(number_str)
    total = 0
    split_number = [int (d) for d in number_str]

    if n > 1:
        confirmed_no = get_boringcount_of_length(n-1)
        total = total + confirmed_no

    for digitpos, digitvalue in enumerate(split_number):
        total = boring_no_at_digit(int(digitvalue), int(digitpos + 1), n) + total
        if int(digitpos)%2 == int(digitvalue)%2:
            break
    return total

def boring_in_range(start, end):
    up_to_start = check_boring_no(str(int(start)-1)) if int(start) > 1 else 0
    up_to_end = check_boring_no(str(end))
    return up_to_end - up_to_start

results = []
for m in range(int(input())):
    L, R = input().split()
    result = boring_in_range (L, R)
    results.append(result)

for m, result in enumerate(results):
    print (f"Case #{m + 1}: {result}")
