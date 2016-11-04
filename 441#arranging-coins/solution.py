import math
class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int(math.floor(math.sqrt(1 + 8 * n) * 0.5 - 0.5))