"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-26 
"""
from typing import List
from collections import defaultdict
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        ans = self.greedy(tasks, n)
        return ans

    def greedy(self, tasks: [str], n: int):
        """贪心算法
        以n+1为一轮,按任务数量从多到少,依次安排任务,不满足n+1的用空闲填充
        """
        record = defaultdict(int)
        ans = 0
        rest_tasks = len(tasks)
        for task in tasks:
            record[task] += 1
        record = [[key, value] for key, value in record.items()]
        priority_list = sorted(record, key=lambda x: -x[1])
        while rest_tasks:
            for j in range(n+1):
                if j < len(priority_list) and priority_list[j][1]>0:
                    priority_list[j][1] -= 1
                    rest_tasks -= 1
                ans += 1
                if not rest_tasks:
                    break
            priority_list = sorted(priority_list, key=lambda x: -x[1])
        return ans

    def priorityQueue(self, tasks: [str], n: int) -> int:
        """优先队列
        """
        pass

solve = Solution()
solve.leastInterval(["A","A","A","A","A","A","B","C","D","E","F","G"]
,2)