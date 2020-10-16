def solve(array):
    diff_array = []
    empty_list = []
    for i in range(1,len(array)):
        diff_array.append(array[i]-array[i-1])
    counter = 0
    for i in range(1,len(diff_array)):
        if diff_array[i]==diff_array[i-1]:
            counter +=1
        else:
            empty_list.append(counter)
            counter = 0
    empty_list.append(counter)
    return max(empty_list)+2

if __name__ == "__main__":
    arrays = []
    t = int(input())
    for i in range(t):
        n = int(input())
        arrays.append([int(i) for i in input().split(" ")])
    for i in range(1,len(arrays)+1):
        print("Case #",end="")
        print(i,end="")
        print(":",solve(arrays[i-1]))
