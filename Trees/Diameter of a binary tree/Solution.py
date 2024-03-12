# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def diameter(node,ans):
            # Base case 
            if not node : 
                return 0

            # Recursively calculate the diamter of left and right subtrees 

            left = diameter(node.left, ans)
            right = diameter(node.right, ans)

            # update the maximum diameter encountered so far 
            ans[0] = max(ans[0], left+right)

            return 1 + max(left, right)

        # Initialise a list to hold the maximum diamter encountered 
        ans = [0]

        diameter(root, ans)
        
        return ans[0]


        
