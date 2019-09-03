#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool isMatch(char* s, char* p) {
	
   
	if(*p == '\0') return *s == '\0';
	
	//next char is not '*'; must match current character
	if(*(p+1) != '*')
	{
		return ((*p == *s) ||(*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
	}
	
	//next char is '*' 继续递归匹配,不能写成*(p+1) == '*' 考虑情况isMatch('ab','.*c')
	while((*p == *s)|| (*p == '.' && *s != '\0'))
	{
		//这里动态规划的思想，不断的减小s中重复的字符，去进行比较，直到找出正确的或者不匹配的
		if (isMatch(s, p+2)) return true;
		s++;
	}
	
	
	//当s中没有对应的字符的时候，a*中a的数量可以为0
	return isMatch(s,p+2);
}



int main(int argc, char *argv[]) {
	char * s = "b";
	char * p = "a*b";
	bool res = isMatch(s, p);
	printf("%d\n",res);
	
}

