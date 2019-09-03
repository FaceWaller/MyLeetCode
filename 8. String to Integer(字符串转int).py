#字符串转int数字
class Solution:  
	# @param {string} str  
	# @return {integer}  
	def myAtoi(self, str):  
		INT_MAX=2147483647;INT_MIN=-2147483648  
		index=0  
		while index<len(str) and str[index]==' ': #遍历统计字符串前面的空格数
			index+=1
		flag=1      #标记正负
		if index<len(str) and str[index]=='-':  
			index+=1  
			flag=-1  
		elif index<len(str) and str[index]=='+':  
			index+=1  
		res=0  
		while index<len(str):  
			if str[index]<'0' or str[index]>'9':return flag*res  
			digit=ord(str[index])-ord('0')   #ord函数返回字符对应的ASCII码数值
			if flag==1 and res*10+digit>INT_MAX:return INT_MAX  
			if flag==-1 and res*10+digit>-INT_MIN:return INT_MIN  
			res=res*10+digit  
			index+=1  
		return flag*res  

if __name__ == "__main__":
	res = Solution().myAtoi(" +123 ")
	print(res)