# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root: return ""
        q = deque()
        q.append(root)
        s = str(root.val) + "#"
        while len(q) != 0:
            cur = q.popleft()
            s += (str(cur.left.val) + "#" if cur.left else "n#")
            if cur.left: q.append(cur.left)
            s += (str(cur.right.val) + "#" if cur.right else "n#")
            if cur.right: q.append(cur.right)
        return s

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == "": return None
        data = data.split('#')[:-1]
        root = TreeNode(int(data[0]))
        q = deque()
        q.append(root)
        level = 1
        idx = 0
        while len(q) != 0:
            for i in range(1<<level):
                if len(q) == 0:
                    break
                cur = q.popleft()
                for j in range(2):
                    idx += 1
                    if j % 2 == 0:
                        cur.left = TreeNode(int(data[idx])) if data[idx] != "n" else None
                        if cur.left:
                            q.append(cur.left)
                    else:
                        cur.right = TreeNode(int(data[idx])) if data[idx] != "n" else None
                        if cur.right:
                            q.append(cur.right)
            level += 1
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))