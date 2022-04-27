class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        from itertools import combinations
        
        k = list(permutations(nums, len(nums)))
        
        return k
        