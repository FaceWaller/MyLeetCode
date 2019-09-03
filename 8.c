#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myAtoi(char* str) {
	
	char * tempP = str;
	char type = NULL;
	int numLen=0;
	int res = 0;
	int hasNum=0;
	while ((*tempP) != '\0') {
		if ( (*tempP) > 47 && (*tempP) < 58) {
			if (numLen == 9) {//将要进行第十位数字的计算
				if(res > 214748364){
					if (type == '-') { //负数
						return -2147483648;
					}else{ //正数
						return 2147483647;
					}
				}else if(res == 214748364){
					if (type == '-') { //负数
						if((*tempP) - 48 > 8){
							return -2147483648;
						}
					}else{ //正数
						if ((*tempP) - 48 > 7) {
							return 2147483647;
						}
					}
				}
			}else if (numLen == 10){
				if (type == '-') {//负数
					return -2147483648;
				}else{ //正数
					return 2147483647;
				}
			}
			
			if (numLen == 0 && (*tempP) == '0'){
				
			}else{
				//字符转数字
				res = 10*res + (*tempP) - 48;
				++numLen;
			}
			hasNum = 1;
		}else if (numLen == 0 && !type && !hasNum){
			if ((*tempP) == '-') {
				type = '-';
			}else if((*tempP) == '+'){
				type = '+';
			}else if ((*tempP) == ' '){
				
			}else if ((*tempP) < 47 || (*tempP) > 58){
				return 0;
			}
		}else{
			if (type == '-') {
				res = -res;
			}
			return res;
		}
		++tempP;
	}
	
	if (type == '-') {
		res = -res;
	}
	
	return res;
}


int main(int argc, char *argv[]) {
	char * str = "      -11919730356x";
	int res = myAtoi(str);
	printf("%d\n",res);
}

