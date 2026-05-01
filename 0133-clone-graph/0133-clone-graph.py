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
            for neighbor in cur.neighbors:
                if not neighbor in mp:
                    mp[neighbor] = Node(neighbor.val)
                    q.append(neighbor)
                mp[cur].neighbors.append(mp[neighbor])
        return mp[node]