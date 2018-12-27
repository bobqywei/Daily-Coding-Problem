
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None


def get_unival_trees(t):
	if t.left == None and t.right == None:
		return (True, 1)

	elif t.left == None:
		(is_unival, num) = get_unival_trees(t.right)

		if is_unival and t.val == t.right.val:
			return (True, num + 1)
		else:
			return (False, num)

	elif t.right == None:
		(is_unival, num) = get_unival_trees(t.left)

		if is_unival and t.val == t.left.val:
			return (True, num + 1)
		else:
			return (False, num)

	else:
		(is_unival_left, num_left) = get_unival_trees(t.left)
		(is_unival_right, num_right) = get_unival_trees(t.right)

		if is_unival_right and is_unival_left and t.val == t.left.val and t.val == t.right.val:
			return (True, num_right + num_left + 1)
		else:
			return (False, num_left + num_right)


root = TreeNode(0)
root.left = TreeNode(1)
root.right = TreeNode(0)
root.right.left = TreeNode(1)
root.right.left.left = TreeNode(1)
root.right.left.right = TreeNode(1)
root.right.right = TreeNode(0)

print(get_unival_trees(root)[1])
