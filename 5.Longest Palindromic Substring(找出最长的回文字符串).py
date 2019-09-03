#找出最长的回文子字符串

class Solution:  
	# @param {string} s  
	# @return {string}  
	def longestPalindrome(self, s):  
		Max=1;MaxStart=0;MaxEnd=0  
		for i in range(0,len(s)):  
			end = self.findOdd(s,i)  
			if Max < (end-i)*2+1:  
				Max = (end-i)*2+1  
				MaxStart = i+i-end  
				MaxEnd = end  
			end = self.findEven(s,i)  
			if Max < (end-i)*2:  
				Max = (end-i)*2  
				MaxStart = i+i+1-end  
				MaxEnd = end  
		return s[MaxStart:MaxEnd+1]  
	def findOdd(self,s,center):  #寻找aba 形式的回文
		i=center-1;j=center+1  
		while i>=0 and j<len(s):  
			if s[i]!=s[j]:return j-1  
			i=i-1;j=j+1  
		return j-1  
	def findEven(self,s,center):  #寻找abba形式的回文
		i=center;j=center+1  
		while i>=0 and j<len(s):  
			if s[i]!=s[j]:return j-1  
			i=i-1;j=j+1  
		return j-1 
		 			
#class Solution
		
if __name__ == "__main__":
	str = Solution().longestPalindrome("cadccdac")
	print(str)