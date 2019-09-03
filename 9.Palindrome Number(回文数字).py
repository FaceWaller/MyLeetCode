#回文数字
class Solution(object):
	def isPalindrome(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
		return str(x) == str(x)[::-1] #直接转成字符串再翻转

if __name__ == "__main__":
	res = Solution().isPalindrome(-121);
	print(res)