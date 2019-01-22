def insert_spaces(s):
	out = ""
	for c in s:
		out += '*'
		out += c
	out += '*'
	return out


def longest_palindrome(s):
	s = insert_spaces(s)
	longest = -1
	center = -1

	for i in range(len(s)):
		left = i - 1
		right = i + 1

		while left >= 0 and right < len(s) and s[left] == s[right]:
			left -= 1
			right += 1

		if right-left-1 > longest:
			longest = right-left-1
			center = i

	ret = "" if s[center] == '*' else s[center]
	for i in range(1, longest // 2):
		if not s[center - i] == '*':
			ret = s[center - i] + ret + s[center - i]

	return ret


while True:
	inp = input("Enter Input: ")
	print("Longest Palindrome: {0}".format(longest_palindrome(inp)))

