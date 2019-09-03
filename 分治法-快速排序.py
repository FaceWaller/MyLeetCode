#分治法的一种体现
class Solution:
	def sort(self, arr):
		self.quickSort(arr, 0, len(arr)-1)
		return arr
	def quickSort(self,L,ii,jj): #直接操作L 将他排好序
		low = ii
		high = jj
		if low >= high:    #当头尾相同时 不作处理
			return
		key = L[low]  #找一个标志位 一般是low所在的位置
		while low < high:  #循环操作 目的:把数组按照标志位操作 比标志位小的放在左边 大的放在右边 直到low和high相等(碰头) 完成一次一趟快速排序
			while low < high and L[high] >= key: #从右往左循环直到找到一个比标志位小的数字 
				high = high-1       
			L[low] = L[high]  #把标志位的数字和high所在的数字做替换 使得标志位左边的数字都比标志位小 交换后high的数是不准确的应该为key
			while low < high and L[low] <= key: #同理 从做往右循环  low的数是不准确的应该为key
				low = low+1
			L[high] = L[low]
		L[low] = key #low和high相等时 把数组中不准确的那个值置为key 此处也可以写做L[high] = key
		self.quickSort(L, ii, low-1) #递归 从头到标志位前一个
		self.quickSort(L, low+1, jj)  #递归 从标志位后一个到尾
				
if __name__ == "__main__":
	res = Solution().sort([1,4,2,7,45,5,346,46,234,234,45])
	print(res)