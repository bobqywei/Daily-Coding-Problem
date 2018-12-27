memo = {}

def count_ways (n):
	ret = memo.get(n)
	if ret is not None:
		return ret

	if n == 1:
		ret = 1
	elif n == 2:
		ret = 2
	else:
		ret = count_ways(n - 1) + count_ways(n - 2)

	memo[n] = ret
	return ret

inp = ""

while inp != 'q':
	inp = input()
	print(count_ways(int(inp)))
