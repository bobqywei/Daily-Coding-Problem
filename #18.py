from collections import deque

def max_of_subarrays(arr, k):
	q = deque()

	for i in range(k):
		while q and arr[q[-1]] <= arr[i]:
			q.pop()

		q.append(i)

	ret = [arr[q[0]]]

	for i in range(k, len(arr)):
		while q and q[0] <= i - k:
			q.popleft()

		while q and arr[q[-1]] <= arr[i]:
			q.pop()

		q.append(i)

		ret.append(arr[q[0]])

	return ret


while True:
	k = int(input())
	arr = [int(x) for x in input().split(',')]
	result = max_of_subarrays(arr, k)
	for i in result:
		print(str(i) + ",", end=" ")
	print("")
