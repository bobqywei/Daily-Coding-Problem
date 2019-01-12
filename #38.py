def is_valid(row, col, active_queens):
	for r, c in active_queens:
		if abs(row - r) == abs(col - c):
			return False
	return True


def print_board(n, active_queens):
	for row in range(n):
		output = ""
		for col in range(n):
			if (row, col) in active_queens:
				output += "1 "
			else:
				output += "0 "
		print(output)


def recursive_step(active_queens, open_rows, open_cols, solutions):

	if len(open_rows) == 0:
		for solution in solutions:
			if solution == active_queens:
				return solutions
		solutions.append(active_queens)
		return solutions

	sum_ways = 0
	for row in open_rows:
		for col in open_cols:
			if is_valid(row, col, active_queens):
				new_active_q = active_queens.copy()
				new_active_q.add((row, col))

				new_open_c = open_cols.copy()
				new_open_c.remove(col)

				new_open_r = open_rows.copy()
				new_open_r.remove(row)

				solutions = recursive_step(new_active_q, new_open_r, new_open_c, solutions)

	return solutions


def n_queens(n):
	active_queens = set()
	open_cols = set()
	open_rows = set()
	for i in range(n):
		open_rows.add(i)
		open_cols.add(i)

	solutions = []
	solutions = recursive_step(active_queens, open_rows, open_cols, solutions)

	for solution in solutions:
		print_board(n, solution)
		print()

	return len(solutions)


while True:
	n = int(input("Enter N: "))
	print("There are {0} possible ways for {1} queens.".format(n_queens(n), n))
