class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return list(map(list, itertools.zip_longest(*matrix, fillvalue=None)))