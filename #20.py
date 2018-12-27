class Node:
	def __init__(self, x):
		self.val = x
		self.next = None


def create_linked_list(vals):
	root = Node(vals[0])
	curr = root
	for i in vals[1:]:
		temp = Node(i)
		curr.next = temp
		curr = temp

	return root


def find_intersecting_node(a, b):
	# Find length of linked list a
	len_a = 1
	temp = a
	while temp.next is not None:
		temp = temp.next
		len_a += 1

	# Find length of linked list b
	len_b = 1
	temp = b
	while temp.next is not None:
		temp = temp.next
		len_b += 1

	# Iterates ptr through longer list so that both linked list ptrs are matched up
	for i in range(abs(len_a - len_b)):
		if len_a > len_b:
			a = a.next
		else:
			b = b.next

	# Iterate both linked lists at the same time until match
	while a.val != b.val:
		a = a.next
		b = b.next

	# return value of intersecting node
	return a.val


list_a = [int(x) for x in input().split(',')]
list_b = [int(x) for x in input().split(',')]

a = create_linked_list(list_a)
b = create_linked_list(list_b)

print("Intersecting Node: " + str(find_intersecting_node(a, b)))