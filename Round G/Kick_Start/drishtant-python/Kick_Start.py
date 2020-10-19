# Python to solve Kick_Start Problem by drishtantR1508
def solve(string):
    empty_list = []
    for i in range(len(string)-3):
        if string[i:i+4]=="KICK":
            empty_list.append(i)
    kickstart = 0
    for i in empty_list:
        kickstart += string[i:].count("START")
    return kickstart

if __name__ == "__main__":
    t = int(input())
    testcases = [input() for i in range(t)]
    for i in range(len(testcases)):
        print("Case #",end="")
        print(i+1,end="")
        print(":",solve(testcases[i]))
