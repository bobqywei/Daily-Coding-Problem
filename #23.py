import sys

def minSteps(board, start, end):

	memo = {}

	def nextStep(curr):
		memo[curr] = -1

		rows = len(board)
		cols = len(board[0])
		minimum = sys.maxsize

		for row, col in [(curr[0]-1, curr[1]), (curr[0]+1, curr[1]), (curr[0], curr[1]-1), (curr[0], curr[1]+1)]:

			# Base Case (1 step to reach end coordinate)
			if row == end[0] and col == end[1]:
				memo[curr] = 1
				return memo[curr]

			# Verifies coordinates are in bounds and are not a wall
			if row >= 0 and row < rows and col >= 0 and col < cols and not board[row][col]:

				# Checks if steps needed was already computed 
				stepsToEnd = memo.get((row, col))
				# -1 means not possible to get to end from current tile
				if stepsToEnd != -1:

					# None means not yet computed
					if stepsToEnd != None:
						if 1 + stepsToEnd < minimum:
							minimum = 1 + stepsToEnd
					else:
						steps = nextStep((row, col))
						if steps != -1 and 1 + steps < minimum:
							minimum = 1 + steps

		if minimum != sys.maxsize:
			memo[curr] = minimum

		# Return value is either -1 (Not Possible) or the least number of steps 
		return memo[curr]

	return nextStep(start)

 
board = [[0, 0, 0, 0],
		 [1, 1, 1, 0],
		 [0, 0, 0, 0],
		 [0, 1, 1, 1],
		 [0, 1, 0, 0],
		 [0, 1, 1, 0],
		 [0, 0, 0, 0]]

start = [int(x) for x in input("Start: ").split(',')]
end = [int(x) for x in input("End: ").split(',')]
steps = minSteps(board, (start[0], start[1]), (end[0], end[1]))

if (steps == -1):
	print("Not Possible")
else:
	print("Minimum Steps Needed: " + str(steps))