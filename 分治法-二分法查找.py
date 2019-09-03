
class Solution:	
	def dichotomyFind(self,arr,x):
		low,high=0,len(arr)-1
		while low<=high:
			middle = int((low+high)/2)
			if(arr[middle]>x):
				high = middle-1
			elif(arr[middle]<x):
				low = middle+1
			else:
				return middle
		print('不存在')


if __name__ == "__main__":
	index = Solution().dichotomyFind([1,2,3,4,5,6,7,8,9,10],1)
	print(index)