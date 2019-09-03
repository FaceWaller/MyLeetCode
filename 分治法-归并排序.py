#归并排序的时间复杂度 还不会计算
class Solution:
	def merge(self,left, right):
		i, j = 0, 0
		result = []
		while i < len(left) and j < len(right):
			if left[i] <= right[j]:
				result.append(left[i])
				i += 1
			else:
				result.append(right[j])
				j += 1
		result += left[i:]
		result += right[j:]
		return result

	def merge_sort(self,lists):
		# 归并排序
		if len(lists) <= 1:
			return lists
		num = len(lists) // 2
		left = self.merge_sort(lists[:num])
		right = self.merge_sort(lists[num:])
		return self.merge(left, right)

if __name__ == "__main__":
	sortList = Solution().merge_sort([1,3,5,7,9,2,4,6,8,10])
	print(sortList)