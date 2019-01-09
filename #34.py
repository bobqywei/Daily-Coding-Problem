def is_palindrome(s):
	for i in range(len(s) // 2):
		if s[i] != s[len(s) - 1 - i]:
			return False

	return True


def shortest_possible_palindrome(s):
	temp = s[0]
	left_palindrome = temp

	# Find the longest palindrome starting from left of string
	for i in range(1, len(s)):
		temp = temp + s[i]
		if is_palindrome(temp):
			left_palindrome = temp

	temp = s[-1]
	right_palindrome = temp

	# Find the longest palindrome ending at right of string
	for i in range(len(s)-2, -1, -1):
		temp = s[i] + temp
		if is_palindrome(temp):
			right_palindrome = temp

	# Input string is a palindrome
	if len(left_palindrome) == len(s):
		return s

	# Two possible shortest palindromes
	if len(left_palindrome) == len(right_palindrome):

		# Returns the lexicographically smaller palindrome
		if ord(s[-1]) < ord(s[0]):
			to_flip = s[len(left_palindrome):]
			return to_flip[::-1] + s
		else:
			to_flip = s[:-len(right_palindrome)]
			return s + to_flip[::-1]

	else:
		# returns the shorter palindrome
		if len(left_palindrome) > len(right_palindrome):
			to_flip = s[len(left_palindrome):]
			return to_flip[::-1] + s
		else:
			to_flip = s[:-len(right_palindrome)]
			return s + to_flip[::-1]


while True:
	inp = input("Enter a string: ")
	ret = shortest_possible_palindrome(inp)
	assert is_palindrome(ret)
	print("Shortest palindrome that can be made: " + ret)

