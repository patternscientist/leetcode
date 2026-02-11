# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def ok(self, root: Optional[TreeNode], low: int, high: int) -> bool:
        if not root: return True
        if root.val <= low or root.val >= high:
            return False
        if not root.left and not root.right:
            return True
        return self.ok(root.left,low,root.val) and self.ok(root.right,root.val,high)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        EXCLUSIVE_LOW  = -2**31-1
        EXCLUSIVE_HIGH = 2**31
        return self.ok(root,EXCLUSIVE_LOW,EXCLUSIVE_HIGH)