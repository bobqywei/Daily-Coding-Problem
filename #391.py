
def find_longest_common_sequence(seq1, seq2):
    memo = []
    for i in range(len(seq1)+1):
        memo.append([0] * (len(seq2)+1))
    
    for i in range(len(seq1)):
        for j in range(len(seq2)):
            memo[i+1][j+1] = 0 if seq1[i] != seq2[j] else 1 + memo[i][j]

    length = 0
    elements = None
    for i in range(len(seq1)):
        for j in range(len(seq2)):
            if memo[i+1][j+1] > length:
                length = memo[i+1][j+1]
                elements = seq1[i-length+1:i+1]

    return elements

if __name__ == "__main__":
    user1 = ['/home', '/about', '/register', '/login', '/user', '/one', '/two']
    user2 = ['/home', '/red', '/login', '/user', '/one', '/pink']

    longest = find_longest_common_sequence(user1, user2)
    print(longest)
