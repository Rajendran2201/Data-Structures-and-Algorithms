# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, node: Optional[TreeNode]) -> List[int]:
        if node is None : 
             return []
        return ([node.val] +
            self.preorderTraversal(node.left) +
            self.preorderTraversal(node.right))
