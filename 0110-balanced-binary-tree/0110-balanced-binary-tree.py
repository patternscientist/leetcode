# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def heightOrFail(root):
            if not root:
                return -1
            if not root.left and not root.right:
                return 0
            lh = heightOrFail(root.left)
            if lh == -2:
                return -2
            rh = heightOrFail(root.right)
            if rh == -2:
                return -2
            if abs(lh-rh) > 1:
                return -2
            return max(lh,rh)+1
        return heightOrFail(root) != -2