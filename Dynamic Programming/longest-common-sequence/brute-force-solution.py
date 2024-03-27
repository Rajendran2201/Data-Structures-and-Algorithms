class Solution:
    def longestCommonSubsequence(self, seq1: str, seq2: str, idx1=0, idx2=0) -> int:
        if idx1 == len(seq1) or idx2 == len(seq2):
            return 0
        elif seq1[idx1] == seq2[idx2]:
            return 1 + self.longestCommonSubsequence(seq1, seq2, idx1+1, idx2+1)
        else:
            option1 = self.longestCommonSubsequence(seq1, seq2, idx1+1, idx2)
            option2 = self.longestCommonSubsequence(seq1, seq2, idx1, idx2+1)
            return max(option1, option2)
                
