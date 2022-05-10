class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        return list(filter(lambda x: sum(x) == n, list(combinations(list(range(1,10)),k))));
        