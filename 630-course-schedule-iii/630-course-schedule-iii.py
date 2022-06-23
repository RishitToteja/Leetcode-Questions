class Solution(object):
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
        pq = [] 
        total = 0
        for t, end in sorted(courses, key = lambda(t,end):end):
            total += t
            heapq.heappush(pq, -t)
            if total > end:
                total += heapq.heappop(pq) 
        return len(pq)