# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def heightOrFail(root):
    if not root: return -1
    lh = heightOrFail(root.left)
    if lh == -2: return -2
    rh = heightOrFail(root.right)
    if rh == -2: return -2
    if abs(lh-rh) > 1: return -2
    return 1 + max(lh,rh)

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return heightOrFail(root) != -2
        