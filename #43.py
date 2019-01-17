from collections import deque

class MaxStack:
	def __init__(self):
		self.normal_stack = deque()
		self.max_stack = deque()
		self.max = None

	def push(self, val):
		self.normal_stack.append(val)

		if self.max is None:
			self.max = val
			self.max_stack.append(val)
		elif val >= self.max:
			self.max_stack.append(val - self.max)
			self.max = val

	def pop(self):
		assert len(self.normal_stack) > 0

		val = self.normal_stack[-1]
		self.normal_stack.pop()

		if len(self.normal_stack) == 0:
			self.max_stack.pop()
			self.max = None
		elif self.max == val:
			diff = self.max_stack[-1]
			self.max_stack.pop()
			self.max = self.max - diff

		return val

	def get_max(self):
		return self.max


max_stack = MaxStack()

while True:
	args = input().split()

	if len(args) == 1:
		if args[0] == 'pop':
			print("Pop returned: {0}".format(max_stack.pop()))
		elif args[0] == 'max':
			print("Current max: {0}".format(max_stack.get_max()))

	elif args[0] == 'push':
		print("Pushed {0} onto stack".format(args[1]))
		max_stack.push(int(args[1]))

	print()
