def move_neg_to_front(arr):
	start = 0
	for i in range(len(arr)):
		if arr[i] <= 0:
			temp = arr[i]
			arr[i] = arr[start]
			arr[start] = temp
			start += 1

	return (start, arr)


def lowest_missing_num(arr):
	(start, arr) = move_neg_to_front(arr)

	for i in range(start, len(arr)):
		index = abs(arr[i]) - 1 + start
		if index < len(arr) and arr[index] > 0:
			arr[index] *= -1

	for i in range(start, len(arr)):
		if arr[i] > 0:
			return i + 1 - start

	return len(arr) - start + 1


while True:
	nums = [int(x) for x in input().split(',')]
	print(lowest_missing_num(nums))
