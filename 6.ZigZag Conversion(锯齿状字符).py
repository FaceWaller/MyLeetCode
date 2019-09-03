#把字符串按照给定行数进行锯齿形排列 再返回
class Solution(object):
	def convert(self, ss, numRows):
		if numRows == 1: #一排的情况直接返回就可以了
			return ss
		str = ''
		for i in range(numRows):#遍历行数 每次拼接每一行的字符串
			start = i 
			type = 1 #type为1时取左间距 type为2时取右间距
			space1 = 2*(numRows-i-1) #锯齿左边间距
			space2 = 2*i  #锯齿右边间距
			if(len(ss) > i ):    
				str = str + ss[i]
			else:
				return str #len(ss)<=i 说明字符数比行数少直接返回就可以了
			while start < len(ss):
				if(type == 1):
					start = start + space1
					if start > (len(ss)-1):
						break
					type = 2
					if(space1 !=0):
						str = str + ss[start]
				else:
					start = start + space2
					if start > (len(ss)-1):
						break
					type = 1
					if(space2 != 0):
						str = str + ss[start]
		return str
	
if __name__ == "__main__":
	str = Solution().convert("abcdefghigklmnopqrst", 3)
	print(str)