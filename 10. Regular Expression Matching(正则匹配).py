#动态规划算法 没看懂
#class Solution:
#	# @return a boolean
#	def isMatch(self, s, p):
#		dp=[[False for i in range(len(p)+1)] for j in range(len(s)+1)]
#		dp[0][0]=True
#		for i in range(1,len(p)+1):
#			if p[i-1]=='*':
#				if i>=2:
#					dp[0][i]=dp[0][i-2]
#		for i in range(1,len(s)+1):
#			for j in range(1,len(p)+1):
#				if p[j-1]=='.':
#					dp[i][j]=dp[i-1][j-1]
#				elif p[j-1]=='*':
#					dp[i][j]=dp[i][j-1] or dp[i][j-2] or (dp[i-1][j] and (s[i-1]==p[j-2] or p[j-2]=='.'))
#				else:
#					dp[i][j]=dp[i-1][j-1] and s[i-1]==p[j-1]
#		return dp[len(s)][len(p)]

#递归算法
class Solution:
	# @return a boolean
	def isMatch(self, ss, pstr):
		if len(pstr)==0: return len(ss)==0  
		if len(pstr)==1 or pstr[1]!='*': #不存在*的情况 一个一个的去比较就好了
			if len(ss)==0 or (ss[0]!=pstr[0] and pstr[0]!='.'):
				return False
			return self.isMatch(ss[1:],pstr[1:])
		else: #当len(pstr) >1 且 pstr[1] == * 的时候
			i=-1; length=len(ss)
			while i<length and (i<0 or pstr[0]=='.' or pstr[0]==ss[i]): 
				if self.isMatch(ss[i+1:],pstr[2:]): return True   #不断地比较ss的子区间和pstr[2:], pstr前面两个字符为一个字符加上* 通过pstr[0]=='.' or pstr[0]==ss[i] 判断是否符合 
				i+=1
			return False





if __name__ == "__main__":
	res = Solution().isMatch("12", ".*");
	print(res)