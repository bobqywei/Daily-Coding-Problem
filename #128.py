def towers_of_hanoi(n):
	memo = {}

	def move(src, dest):
		global num_moves
		num_moves += 1
		return (src, dest)

	def recursive_move(n, src, dest, spare):
		# use memoized value if possible
		key = (n, src, dest)
		if key in memo:
			return memo[key]

		ret = []
		# Base case: move 1 block
		if n == 1:
			ret.append(move(src, dest))
		else:
			# move all blocks smaller than n to spare
			ret += recursive_move(n-1, src, spare, dest)
			# move n to dest
			ret.append(move(src, dest))
			# move all blocks on spare to dest
			ret += recursive_move(n-1, spare, dest, src)

		memo[key] = ret
		return memo[key]

	return recursive_move(n, 1, 3, 2)

if __name__ == "__main__":
	num_moves = 0
	n = int(input())
	result = towers_of_hanoi(n)
	output = "\n".join(["Move {} to {}".format(src, dest) for src, dest in result]) + "\nTook {} moves".format(num_moves)
	print(output)
