def units_water_trapped(arr):
	curr_max = 0

	max_height_left = []
	for i in arr:
		max_height_left.append(curr_max)
		curr_max = max(curr_max, i)

	curr_max = 0
	max_height_right = [None]*len(arr)
	for i in range(len(arr)-1, -1, -1):
		max_height_right[i] = curr_max
		curr_max = max(curr_max, arr[i])

	total = 0
	for i in range(len(arr)):
		diff = min(max_height_right[i], max_height_left[i]) - arr[i]
		
		if diff > 0:
			total += diff

	return total


while True:
	arr = [int(x) for x in input("Elevation Map: ").split(" ")]
	print("Units of Water Trapped: " + str(units_water_trapped(arr)))