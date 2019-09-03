#题意:再一个数组中找出两个数字 和为给出的另一个数字 返回这两个数字的位置数

class Solution:
	def twoSum(self, nums, target):
		dict={}
		for i in  range(len(nums)):
			if  target-nums[i] in dict:#  target-nums[i]为key
				return  [dict[target-nums[i]],i]
			dict[nums[i]]=i
		return  []
		
if __name__ == '__main__':
	ansDict = Solution().twoSum([2,7,11], 9)
	print(ansDict)