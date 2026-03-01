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
        s = ""
        q = deque()
        q.append(root)
        while len(q) != 0:
            cur = q.popleft()
            if cur:
                s += str(cur.val) + "#"
                q.append(cur.left)
                q.append(cur.right)
            else:
                s += "n#"
        return s

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == "":
            return None
        vals = data.split("#")[:-1]       
        root = TreeNode(int(vals[0]))
        q = deque()
        q.append(root)
        i = 1
        n = len(vals)
        while len(q) != 0 and i < n:
            cur = q.popleft()
            if i < n and vals[i] != "n":
                cur.left = TreeNode(int(vals[i]))
                q.append(cur.left)
            else:
                cur.left = None
            i += 1
            if i < n and vals[i] != "n":
                cur.right = TreeNode(int(vals[i]))
                q.append(cur.right)
            else:
                cur.right = None
            i += 1
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))