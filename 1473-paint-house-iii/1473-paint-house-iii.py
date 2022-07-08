class Solution:

    def minCost(self, houses, cost, m, n, target) -> int:

        @lru_cache(None)
        def dfs(i, target_left, k=0):
            if target_left > m-i:
                # optimized: early stop if there is no way to have enough neighborhood
                return -1
            if i == m:
                # stop criteria: not enough neighborhood when searching to the last house
                return 0 if target_left == 0 else -1  

            if houses[i] != 0:  # already painted
                return dfs(i+1, target_left - int(houses[i]!=k), houses[i])
            else:
                ret = []
                for j in range(1, n+1):
                    current_cost = cost[i][j-1]
                    future_cost = dfs(i+1, target_left - int(j!=k), j)
                    if future_cost != -1:
                        ret.append(current_cost + future_cost)

                return min(ret) if ret else -1

        return dfs(0, target)