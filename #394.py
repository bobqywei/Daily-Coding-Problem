class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def has_path_sum(root, k):
    target = k - root.val
    if root.left is None and root.right is None:
        return target == 0

    if root.left is not None and has_path_sum(root.left, target):
        return True
    elif root.right is not None and has_path_sum(root.right, target):
        return True
    
    return False


if __name__ == "__main__":
    n6 = Node(6)
    n2 = Node(2)
    n4 = Node(4, n2, n6)
    n19 = Node(19)
    n13 = Node(13, right=n19)
    n8 = Node(8, n4, n13)

    print(has_path_sum(n8, 18))
    print(has_path_sum(n8, 15))
    print(has_path_sum(n8, 14))
