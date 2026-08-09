"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        mp = {node : Node(node.val)}
        q = deque()
        q.append(node)
        while len(q) != 0:
            cur = q.popleft()
            for nb in cur.neighbors:
                if not nb in mp:
                    mp[nb] = Node(nb.val)
                    q.append(nb)
                mp[cur].neighbors.append(mp[nb])
        return mp[node]