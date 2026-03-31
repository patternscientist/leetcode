# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], best: int) -> (int,int):
            if not root:
                return (-1,best)
            lh,bestLeft = dfs(root.left,best)
            rh,bestRight = dfs(root.right,bestLeft)
            best = max(bestRight,lh+rh+2)
            return (max(lh,rh)+1,best)
        _,best = dfs(root,0)
        return best