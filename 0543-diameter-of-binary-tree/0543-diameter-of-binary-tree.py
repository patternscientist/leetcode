# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root,best):
            if not root:
                return (-1,best)
            if not root.left and not root.right:
                return (0,best)
            lh,leftBest = dfs(root.left,best)
            rh,subTreesBest = dfs(root.right,leftBest)
            best = max(subTreesBest,lh+rh+2)
            return (max(lh,rh)+1,best)
        _,best = dfs(root,0)
        return best