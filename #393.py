def find_longest_range(l):
    l = sorted(l)
    length = 0
    max_len = 0
    max_rnge = None
    for i in range(len(l)):
        if i > 0 and l[i-1]+1 == l[i]:
            length += 1
        else:
            length = 1

        if length > max_len:
            max_len = length
            max_rnge = (l[i-length+1], l[i])
    
    return max_rnge


if __name__ == "__main__":
    r = find_longest_range([9,6,1,3,8,10,12,11])
    print(r)
