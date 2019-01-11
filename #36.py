class Node:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None

class Tree:
	def __init__(self, arr):
		self.root = Node(arr[0])
		for i in arr[1:]:
			self.insert(i)

	def insert(self, i):
		new_node = Node(i)
		nxt = self.root
		
		while True:
			if i > nxt.val:
				if nxt.right is None:
					nxt.right = new_node
					break
				else:
					nxt = nxt.right

			elif i < nxt.val:
				if nxt.left is None:
					nxt.left = new_node
					break
				else:
					nxt = nxt.left


def bst_print(root):
	if root is not None:
		bst_print(root.left)
		print(root.val)
		bst_print(root.right)


def find_largest(root):
	while root.right is not None:
		root = root.right

	return root


def find_second_largest(root):
	curr = root
	prev = None

	while curr.right is not None:
		prev = curr
		curr = curr.right

	if curr.left is not None:
		left_tree_largest = find_largest(curr.left)
		return max(prev.val, left_tree_largest.val)
	else:
		return prev.val


while True:
	arr = [int(x) for x in input("Enter array of integers: ").split(' ')]
	tree = Tree(arr)
	print("Second largest number {0}".format(find_second_largest(tree.root)))
