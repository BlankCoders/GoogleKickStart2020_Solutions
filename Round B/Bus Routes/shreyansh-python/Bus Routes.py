for _ in range(int(input())):
	n, d = list(map(int, input().split()))
	x = list(map(int, input().split()))
	d_c = d
        ans = []

	for i in x[::-1]:
		div = int(d_c/i)
		ans.append(i*div)
		d_c = (i*div)
	print("Case #"+str(_+1)+": "+str(ans[-1]))
