#求两个有顺序的数组的中位数 要求时间复杂度为 O(log (m+n)).
class Solution(object):
	def findMedianSortedArrays(self, nums1, nums2):
		lenA = len(nums1)
		lenB = len(nums2)
		if( (lenA + lenB)%2 == 1):
			k = int((lenA + lenB)/2 + 1)
			value = self.findMinWithKey(nums1, nums2, k)
			return value
		else:
			k = int((lenA + lenB)/2)
			value = (self.findMinWithKey(nums1, nums2, k) + self.findMinWithKey(nums1, nums2, k+1))/2
			return value
		
#该方法用于找到第k小的数字 根据k的大小变相的解决了中位数的求值
	def findMinWithKey(self, nums1, nums2, k):
		if(len(nums1)>len(nums2)): #为了理顺后面的逻辑 把较小的数组放在前面处理
			return self.findMinWithKey(nums2, nums1, k)
		if(len(nums1) == 0):  #当前面的数组为空时 直接从第二个有序数组取第k个最小值即可
			return nums2[k-1]
		if(k ==1):
			return min(nums1[0], nums2[0])
		startA = min(int(k/2), len(nums1))  
		startB = k - startA
		if(nums1[startA-1]<nums2[startB-1]):
			return self.findMinWithKey(nums1[startA:], nums2, startB)
		else:
			return self.findMinWithKey(nums1, nums2[startB:], startA) 

if __name__ == "__main__":
	A = [1,2]
	B = [3,4]
	C =	Solution().findMedianSortedArrays(A, B)
	print(C)