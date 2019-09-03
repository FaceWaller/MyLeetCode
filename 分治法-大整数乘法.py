#第一种方法,列表法 模仿手写计算乘法 时间复杂度O(n^2)
#class Solution:
#	def multi(self,int1,int2):
#		if(int1 == 0 or int2 == 0):
#			return 0
#		#把负数转换成正数 记录正负号
#		sign = 1
#		if(int1<0):
#			sign=sign*-1
#			int1=0-int1
#		if(int2<0):
#			sign=sign*-1
#			int2=0-int2
#			
#		#倒置字符串 每一位数在数组中的位置就是
#		star1 = str(int1)[::-1]
#		star2 = str(int2)[::-1]
#		res = [0 for i in range(len(star1)+len(star2))]
#		for ii in range(len(star1)):
#			for jj in range(len(star2)):
#				res[ii+jj]=res[ii+jj]+int(star1[ii])*int(star2[jj])
#		for i in range(len(res)-1):
#			aa = int(res[i]/10)
#			bb = int(res[i]%10)
#			res[i] = bb
#			res[i+1] = res[i+1] + aa
#		res = res[::-1]
#		while res[0] == 0:
#			del res[0]
#		if(sign==-1):
#			resStr='-'
#		else:
#			resStr=''
#		for char in res:
#			resStr+=str(char)
#		return resStr
		

import math
#分治法  
class Solution:
	def multi(self,int1,int2):
		if(int1 == 0 or int2 == 0):
			return 0
		sign = 1
		if(int1<0):
			sign=sign*-1
			int1=0-int1
		if(int2<0):
			sign=sign*-1
			int2=0-int2
		len1 = len(str(int1))
		len2 = len(str(int2))
		lenN = max(len1, len2)
		if(lenN==1):
			return sign * int1 * int2
		n = lenN//2*2
		
		
		A = int(int1/math.pow(10, n//2))
		C = int(int2/math.pow(10, n/2))
		B = int(int1 - A * math.pow(10, n//2))
		D = int(int2 - C * math.pow(10, n//2))
		AC = self.multi(A, C)
		BD = self.multi(B, D)
		ABCD = self.multi(A-B, D-C) + AC + BD
		return int(sign*(AC * math.pow(10, n) + ABCD * math.pow(10, n//2) + BD))

		 

if __name__ == '__main__':
	int1 = 1234
	int2 = 5678
	res=Solution().multi(int1,int2)
	print(res)
	