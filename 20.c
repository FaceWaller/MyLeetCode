#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>


bool isValid(char* s) {
	
	int strLen = 0;
	char * curLenChar = s;
	while ( *curLenChar != '\0' ) {
		++strLen;
		++curLenChar;
	}
	
	int resTop = 0;
	char * resArr = malloc(sizeof(char)*strLen);
	
	char * curChar = s;
	while ( *curChar != '\0' ) {
		if ( *curChar == '(' || *curChar == '{' || *curChar == '[') {
			resArr[resTop] = *curChar;
			++resTop;
		}else if (*curChar == ')') {
			if (resArr[resTop-1] == '(') --resTop;
			else return false;
		}else if (*curChar == '}') {
			if (resArr[resTop-1] == '{') --resTop;
			else return false;
		}else if (*curChar == ']') {
			if (resArr[resTop-1] == '[') --resTop;
			else return false;
		}
		++curChar;
	}
	free(resArr);
	
	return resTop == 0;
}


int main(int argc, char *argv[]) {
 
	char * str = "{[]}";
	bool res = isValid(str);
	printf("%d\n",res);
	
   
}

