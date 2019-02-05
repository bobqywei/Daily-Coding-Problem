def num_ways_across(rows, cols):
	memo = {}

	def recursive_step(x, y):
		if x == rows-1 and y == cols-1:
			return 1

		if not (x, y) in memo:
			memo[(x, y)] = 0

			if x + 1 < rows:
				memo[(x, y)] += recursive_step(x+1, y)
			if y + 1 < cols:
				memo[(x, y)] += recursive_step(x, y+1)

		return memo[(x, y)]

	return recursive_step(0, 0)


while True:
	rows = int(input('Rows: '))
	columns = int(input('Columns: '))
	print('Number of ways from top-left to bottom-right => {0}\n'.format(num_ways_across(rows, columns)))