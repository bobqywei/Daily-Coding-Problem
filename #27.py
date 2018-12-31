from collections import deque

def matchingBrackets(s):
	stack = deque()
	brackets = {
		']':'[', 
		')':'(', 
		'}':'{'
	}

	for c in s:
		if c in brackets.values():
			stack.append(c)
		elif len(stack) > 0:
			if not stack[-1] == brackets[c]:
				return False
			else:
				stack.pop()

	return len(stack) == 0


string = input("String to be checked: ")

if matchingBrackets(string):
	print("Brackets are balanced.")
else:
	print("Brackets are not balanced.")