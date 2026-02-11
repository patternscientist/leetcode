# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def ok(self,root,low,high):
        if root == None: return True
        if not ((low < root.val) and (root.val < high)):
            return False
        return (self.ok(root.left,low,root.val) and 
                self.ok(root.right,root.val,high))

    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        EXCLUSIVE_MIN = -2**31-1
        EXCLUSIVE_MAX = 2**31
        return self.ok(root,EXCLUSIVE_MIN,EXCLUSIVE_MAX)
        