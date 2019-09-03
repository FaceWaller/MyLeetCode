#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* longestPalindrome(char* s) {
	
	
	int maxPlaLen=1;  //最大回文字符串长度
	int curLen = 0;  //当前遍历到的位置
	int maxCenter = 0; //最大回文字符串的中间字符所在位置
	
	char type = 'a'; //判断aba还是abba类型的回文字符串
	char * chp = s; //用来遍历s的指针
  
	while (*chp) {
		
		int curExcLen = 1; //当前偏移位置
		
		//查找aba形的回文字符串
		while ( curLen >= curExcLen  &&  *(chp-curExcLen) == *(chp+curExcLen) ) {
			if (maxPlaLen < 2*curExcLen+1) {
				maxPlaLen = 2*curExcLen+1;
				maxCenter = curLen;
				type = 'a';
			}
			++curExcLen;
		}
		
		curExcLen = 0; //当前偏移位置
		//查找abba形的回文字符串
		while ( curLen >= curExcLen &&  *(chp) == *(chp+1) && *(chp-curExcLen) == *(chp+1+curExcLen) ) {
			if (maxPlaLen < 2*curExcLen+2) {
				maxPlaLen = 2*curExcLen+2;
				maxCenter = curLen;
				type = 'b';
			}
			++curExcLen;
		}
	  
		++curLen;
		++chp;
	}
	
	
	
	
	if(type == 'a'){
		char * str = malloc(maxPlaLen+1);
		int maxExcLen = (maxPlaLen-1)/2; //字符串相对中心的偏移量
		strncpy(str, s+maxCenter-maxExcLen, maxPlaLen+1);
		*(str + maxPlaLen) = '\0';
		return str;
	  
	}else{
		char * str = malloc(maxPlaLen+1);
		int maxExcLen = (maxPlaLen-2)/2; //字符串相对中心的偏移量
		strncpy(str, s+maxCenter-maxExcLen, maxPlaLen+1);
		*(str + maxPlaLen) = '\0';
		return str;

	}
}

int main(int argc, char *argv[]) {
	char * str = "ccc";
	char * res = longestPalindrome(str);
	printf("%s\n",res);
}

