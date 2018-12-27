class Node:
	def __init__(self, c):
		self.c = c
		self.children = {}

	def get_char(self):
		return self.c

	def contains(self, c):
		return c in self.children

	def get_node_for_char(self, c):
		return self.children[c]

	def add_child(self, n):
		self.children[n.get_char] = n

	def get_strings_with_prefix(self, prefix):
		matches = []

		for char, node in self.children:
			if char == '*':
				matches.append(prefix);
			else:
				matches = matches + node.get_strings_with_prefix(prefix + char)

		return matches


class Trie:
	def __init__(self, words):
		self.roots = {}

		for word in words:

			curr = None
			if word[0] in self.roots:
				curr = self.roots[word[0]]
			else:
				curr = Node(word[0])
				self.roots[word[0]] = curr

			for c in word[1:]:
				if curr.contains(c):
					curr = curr.get_node_for_char(c)
				else:
					temp = Node(c)
					curr.add_child(temp)
					curr = temp

			curr.add_child(Node('*'))

	def query_prefix(self, prefix):
		if prefix[0] in self.roots:
			curr = self.roots[prefix[0]]

			for c in prefix[1:]:
				if curr.contains(c):
					curr = curr.get_node_for_char(c)
				else:
					return None

			return curr.get_strings_with_prefix(prefix)

		else:
			return None 



words = input("Enter words: ").split(',')
dictionary = Trie(words)
while(True):
	query = input("Enter query: ")
	output = ""
	result = dictionary.query_prefix(query)
	if result == None:
		print("No matches found.")
	else:
		for s in dictionary.query_prefix(query):
			output = output + s + ", "
