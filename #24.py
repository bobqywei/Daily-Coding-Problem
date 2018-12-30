def match_regex(regex, s):

	for i in range(len(regex)):

		# Asterisk, zero or more occurences
		if not i+1 == len(regex) and regex[i+1] == '*' :
			match_char = regex[i]
			# Remove the previous char and the asterisk characters from regex
			regex = regex[i+2:]

			# Try all possible number of occurences
			while len(s) > 0 and match_char == '.' or len(s) > 0 and s[0] == match_char:
				s = s[1:]
				# Return true if any occurence results in true
				if match_regex(regex, s):
					return True

			return False

		# Other characters
		else:
			# Input string is empty
			if len(s) == 0:
				return False
			# Mismatch characters
			if not regex[i] == '.' and not s[0] == regex[i]:
				return False

			# Remove the first character
			s = s[1:]

	if len(s) == 0:
		return True
	else:
		return False


while True:
	regex = input("Regex: ")
	s = input("Input: ")

	if match_regex(regex, s):
		print("Matches.")
	else:
		print("Does not match.")				