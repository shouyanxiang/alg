from typing import List
import pandas as pd
import heapq
from sortedcontainers import SortedList
from abc import ABCMeta, abstractmethod


class Dataframe29():
    __metaclass__ = ABCMeta

    def __init__(self):
        pass

    @abstractmethod
    def addNum(self, num: int) -> None:
        pass

    @abstractmethod
    def findMedian(self) -> float:
        pass

    def test(self):
        self.addNum(1)
        self.addNum(2)
        ans1 = self.findMedian()
        print('expected:{} actual:{}'.format(1.5, ans1))
        self.addNum(3)
        ans2 = self.findMedian()
        print('expected:{} actual:{}'.format(2.0, ans2))


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

class Dataframe29PriorityQueue(Dataframe29):

    def __init__(self):
        Dataframe29.__init__(self)
        self.queMin = list()
        self.queMax = list()

    def addNum(self, num: int) -> None:
        queMin_ = self.queMin
        queMax_ = self.queMax

        if not queMin_ or num <= -queMin_[0]:
            heapq.heappush(queMin_, -num)
            if len(queMax_) + 1 < len(queMin_):
                heapq.heappush(queMax_, -heapq.heappop(queMin_))
        else:
            heapq.heappush(queMax_, num)
            if len(queMax_) > len(queMin_):
                heapq.heappush(queMin_, -heapq.heappop(queMax_))

    def findMedian(self) -> float:
        queMin_ = self.queMin
        queMax_ = self.queMax

        if len(queMin_) > len(queMax_):
            return -queMin_[0]
        return (-queMin_[0] + queMax_[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()


class Dataframe29OrderedSetsAndDoublePointers(Dataframe29):

    def __init__(self):
        Dataframe29.__init__(self)
        self.nums = SortedList()
        self.left = self.right = None
        self.left_value = self.right_value = None

    def addNum(self, num: int) -> None:
        nums_ = self.nums

        n = len(nums_)
        nums_.add(num)

        if n == 0:
            self.left = self.right = 0
        else:
            # 模拟双指针，当 num 小于 self.left 或 self.right 指向的元素时, num 的加入会导致对应指针向右移动一个位置
            if num < self.left_value:
                self.left += 1
            if num < self.right_value:
                self.right += 1

            if n & 1:
                if num < self.left_value:
                    self.left -= 1
                else:
                    self.right += 1
            else:
                if self.left_value < num < self.right_value:
                    self.left += 1
                    self.right -= 1
                elif num >= self.right_value:
                    self.left += 1
                else:
                    self.right -= 1
                    self.left = self.right

        self.left_value = nums_[self.left]
        self.right_value = nums_[self.right]

    def findMedian(self) -> float:
        return (self.left_value + self.right_value) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()


class Dataframe30:
    __metaclass__ = ABCMeta

    @abstractmethod
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        pass

    def test_case1(self):
        matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]]
        k = 8
        ans = self.kthSmallest(matrix, k)
        print('expected:{} actual:{}'.format(13, ans))

    def test_case2(self):
        matrix = [[-5]]
        k = 1
        ans = self.kthSmallest(matrix, k)
        print('expected:{} actual:{}'.format(-5, ans))

    def test(self):
        self.test_case1()
        self.test_case2()


class Dataframe30DichotomousSearch(Dataframe30):
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)

        def check(mid):
            i, j = n - 1, 0
            num = 0
            while i >= 0 and j < n:
                if matrix[i][j] <= mid:
                    num += i + 1
                    j += 1
                else:
                    i -= 1
            return num >= k

        left, right = matrix[0][0], matrix[-1][-1]
        while left < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid + 1

        return left


class Dataframe33:
    __metaclass__ = ABCMeta

    @abstractmethod
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pass

    def test_case1(self):
        nums = [2, 7, 11, 15]
        target = 9
        out = [0, 1]
        ans = self.twoSum(nums, target)
        print('expected :{} , actual :{}'.format(out, ans))

    def test_case2(self):
        nums = [3, 2, 4]
        target = 6
        out = [1, 2]
        ans = self.twoSum(nums, target)
        print('expected :{} , actual :{}'.format(out, ans))

    def test_case3(self):
        nums = [3, 3]
        target = 6
        out = [0, 1]
        ans = self.twoSum(nums, target)
        print('expected :{} , actual :{}'.format(out, ans))

    def test(self):
        self.test_case1()
        self.test_case2()
        self.test_case3()


class Dataframe33ViolentEnumeration(Dataframe33):
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return []


class Dataframe33HashTable(Dataframe33):
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = dict()
        for i, num in enumerate(nums):
            if target - num in hashtable:
                return [hashtable[target - num], i]
            hashtable[nums[i]] = i
        return []


class Dataframe46():
    __metaclass__ = ABCMeta

    def __init__(self):
        # self.input_s = None
        # self.ans = None
        # self.ref_ans = None
        self.input_s = []
        self.ans = []
        self.ref_ans = []

    @abstractmethod
    def longestValidParentheses(self, s: str) -> int:
        pass

    def test(self):
        self.input_s.append("(()")
        self.input_s.append(")()())")
        self.input_s.append("")
        self.ref_ans.append(2)
        self.ref_ans.append(4)
        self.ref_ans.append(0)
        for s in self.input_s:
            self.ans.append(self.longestValidParentheses(s))

        print('Dataframe46 test end')


class Dataframe46N1(Dataframe46):
    def longestValidParentheses(self, s: str) -> int:
        maxans = 0
        n = len(s)
        dp = [0] * n
        for i in range(1, n):
            if s[i] == ')':
                if s[i - 1] == '(':
                    dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
                elif i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '(':
                    dp[i] = dp[i - 1] + (dp[i - dp[i - 1] - 2] if (i - dp[i - 1]) >= 2 else 0) + 2

                maxans = max(maxans, dp[i])

        return maxans


def test():
    Dataframe46N1().test()
    print('test end')


if __name__ == '__main__':
    test()