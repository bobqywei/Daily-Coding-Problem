accepting = set(["first_num", "second_num"])

transitions = {
	"start" : [set(["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]), set(["-"])],
	"first_num" : [set(["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]), set(["e"]), set(["."])],
	"neg" : [set(["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"])],
	"exp" : [set(["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]), set(["-"])],
	"second_neg" : [set(["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"])],
	"second_num" : [set(["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"])]
}

next_states = {
	"start" : ["first_num", "neg"],
	"first_num" : ["first_num", "exp", "second_neg"],
	"neg" : ["first_num"],
	"exp" : ["second_num", "second_neg"],
	"second_neg" : ["second_num"],
	"second_num" : ["second_num"]
}

def is_number(s, state="start"):
	if len(s) == 0:
		return state in accepting

	for i in range(len(transitions[state])):
		if s[0] in transitions[state][i]:
			return is_number(s[1:], state=next_states[state][i])

	return False

if __name__ == "__main__":
	while True:
		s = input("Enter string: ")
		print("Is a number." if is_number(s) else "Not a number.")