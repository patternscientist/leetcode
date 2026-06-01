# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        MIN = -2**31-1
        MAX = 2**31+2
        def isValid(root: Optional[TreeNode],MIN: int,MAX: int) -> bool:
            if not root:
                return True
            if root.val <= MIN or root.val >= MAX:
                return False
            return isValid(root.left,MIN,root.val) and isValid(root.right,root.val,MAX)
        return isValid(root,MIN,MAX)