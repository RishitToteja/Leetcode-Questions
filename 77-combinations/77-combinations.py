class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        from itertools import combinations
        l = [i for i in range(1, n+1)]
        return list(combinations(l, k))