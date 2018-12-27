while True:
	k = int(input())
	s = input()

	char_freq = {s[0]: 1}

	left = 0
	right = 0
	distinct_chars = 1
	maxlen = 0
	start = 0

	while right < len(s)-1:

		if distinct_chars <= k:

			right += 1
			freq = char_freq.get(s[right])
			
			if freq is None or freq == 0:
				distinct_chars += 1
				char_freq[s[right]] = 1
			else:
				char_freq[s[right]] = freq + 1

			if distinct_chars == k and right-left+1 > maxlen:
				maxlen = right - left + 1
				start = left

		else:

			char_freq[s[left]] -= 1

			if char_freq[s[left]] == 0:
				distinct_chars -= 1

			left += 1

	print(s[start: start+maxlen])
