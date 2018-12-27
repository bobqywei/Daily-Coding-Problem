def largest_nonadj_sum(arr):
	sum_incl = arr[0]
	sum_excl = 0

	for i in range(1, len(arr)):
		new_incl = sum_excl + arr[i]
		sum_excl = max(sum_incl, sum_excl)
		sum_incl = new_incl

	return max(sum_incl, sum_excl)


while True:
	arr = [int(x) for x in input().split(',')]
	print(largest_nonadj_sum(arr))
