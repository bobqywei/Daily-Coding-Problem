class Node:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None


def eval(root):
	if isinstance(root.val, int):
		return root.val

	if root.val == '+':
		return eval(root.left) + eval(root.right)
	elif root.val == '-':
		return eval(root.left) - eval(root.right)
	elif root.val == '*':
		return eval(root.left) * eval(root.right)
	elif root.val == '/':
		return eval(root.left) / eval(root.right)


root = Node('*')
root.left = Node('+')
root.right = Node('+')
root.left.left = Node(3)
root.left.right = Node(2)
root.right.left = Node(4)
root.right.right = Node(5)

print(eval(root))