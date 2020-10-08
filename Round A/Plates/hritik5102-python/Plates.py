# Google Kick Start - Round A - Q2 - Plates 
'''
Author : Hritik Jaiswal
Problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
Date : October 10 2020
'''''

# Inspired or took help from : https://www.youtube.com/watch?v=SDxh1FTgrHA

'''
Sample input : 
                2
                2 4 5
                10 10 100 30
                80 50 10 50
                3 2 3
                80 80
                15 50
                20 10

Sample output : 
            Case #0 : 250
            Case #1 : 180
'''

# Approch to solving the problem is Dynamic programming

def main():
    def recursion(ith_stack,plate_needed):

        # Base case for solving Recursion 
        if(ith_stack>=N or plate_needed<=0):
            return 0
        
        # Memoization
        # if value already present in the table so simply return that value 
        if lookup_table[ith_stack][plate_needed]:
            return lookup_table[ith_stack][plate_needed]

        # Recursive function
        current_max = 0
        
        # if suppose plate needed > k then we have to choose minimum between plate_needed and k
        # Because when we have only 1 stack availble it has k = 5 but if our plate needed greater then k , then we have to choose minimum between the two values. 
        for j in range(0,min(plate_needed,K)+1):
            
            temp = recursion(ith_stack+1,plate_needed-j) 
            if j>0:
                temp += plates_piles[ith_stack][j-1]
            
            current_max = max(current_max, temp)

        lookup_table[ith_stack][plate_needed] = current_max
        return current_max         
    
    # Choose no. of test cases
    T = int(input())

    # input
    # Number of stack = N
    # Number of plates per stack = K
    # Number of required plates = P
    for i in range(1,T+1):
        N,K,P = [int(s) for s in input().split(" ")]

        # N,K,P
        '''
        N = number_of_stack 
        K = number_of_plates_per_stack 
        P = number_req_plates
        '''

        plates_piles = []

        # find the cummulative distribution of each stack
        for j in range(N):
            pile = []
            current = 0
            for s in input().split(" "):
                current+=int(s)
                pile.append(current)     
            plates_piles.append(pile) 

        lookup_table = [[0]*(P + 1) for _ in range(N)]

        result = recursion(0,P)
        print("Case #{}: {}".format(i,result))


if __name__=='__main__':
    main()

