#将int数字翻转过来   要注意溢出问题   也可以将int转换为字符串翻转字符串再转换为int数字 当然也要注意溢出问题
class Solution(object):
	def reverse(self, x):
		type = 0
		if(x<0):#python 正负数求余规则不同
			type=-1
			x=0-x
		res = 0
		while(x>=10):
			res = int(res*10) + int(x%10)
			x = int(x/10)
		res = int(res*10) + int(x%10)
		if(type == -1):
			res = 0-res
		if(res>2147483648 or res<-2147483648):#手动处理溢出问题
			res = 0
		return res


if __name__ == "__main__":
	res = Solution().reverse(1534236469)
	print(res)