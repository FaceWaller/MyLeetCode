#题意:找出一个字符串中最长的没有重复字符的子串
#思路:先将数组转换成哈希表 每个位置的值都置为-1 再顺次将值置为所在的位置数后面的重复的数字也会被置为一个非-1的数 遍历一遍判断但值不是-1的时候 说明前面有重复的数字值就是重复数字的位置 从start到这个值的数字所有key的value都置为-1(防止这段字符再与后面重复) 
class Solution:
	# @return an integer
	def lengthOfLongestSubstring(self, s):
		start = 0
		maxlen = 0
		dict = {}
		for i in range(len(s)):
			dict[s[i]] = -1    
		for i in range(len(s)):
			if dict[s[i]] != -1:
				while start <= dict[s[i]]:
					dict[s[start]] = -1
					start += 1
			if i - start + 1 > maxlen: maxlen = i - start + 1
			dict[s[i]] = i      #把当前的字母置为当前位置数 同时后面的重复的字符对应的数字也变了
		return maxlen

			
if __name__ == '__main__':
	maxNum = Solution().lengthOfLongestSubstring("abacadeg")
	print(maxNum)
		
		
		
		
		
		