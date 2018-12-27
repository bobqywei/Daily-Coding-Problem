def longest_path_at_level(level, lines):
	longest = ""

	for i in range(len(lines)):
		line = lines[i]

		if "\t" * (level+1) in line:
			name = "/" + line[level+1:]
			subpath_name = name + longest_path_at_level(level+1, lines[i+1:])

			if len(subpath_name) > len(longest):
				longest = subpath_name
		else:
			break

	return longest


def longest_path(s):
	lines = s.split('\n')
	print(lines)
	return lines[0] + longest_path_at_level(0, lines[1:])


dir_string = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" # "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
longest = longest_path(dir_string)
print("Longest Path: " + longest)
print("Length: " + str(len(longest)))
