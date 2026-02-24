# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(root : Optional[TreeNode], exclusiveLow : int, exclusiveHigh : int) -> bool:
            if not root: return True 
            if root.val <= exclusiveLow or root.val >= exclusiveHigh:
                return False
            return dfs(root.left,exclusiveLow,root.val) and dfs(root.right,root.val,exclusiveHigh)
        exclusiveLow  = -2**31-1
        exclusiveHigh = 2**31
        return dfs(root,exclusiveLow,exclusiveHigh)