#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

char** letterCombinations(char* digits, int* returnSize) {
	
	int digitsSize = 0;//传进来的字符串长度
	int sevenNum = 0;//7的数量
	int nineNum = 0;//9的数量
	char * temp = digits;
	while (*temp != '\0') {
		if(*temp == '7') ++sevenNum;
		if(*temp == '9') ++nineNum;
		++temp;
		++digitsSize;
	}
	
	
	
	
	int strSize = digitsSize+1; //每个字符串的长度,后面要加'\0'
	int resSize = (int)pow(3.0, digitsSize-sevenNum-nineNum)*pow(4.0, sevenNum+nineNum); //结果的总数量
	*returnSize = resSize;
	
	
	if (digitsSize == 0) {
		int resSize = 0; //结果的总数量
		*returnSize = resSize;
	}
   
	//为res申请一块内存
	char ** res = malloc(resSize*sizeof(char *));
	
	
	
	int resTop = 0;//以入栈的形式存储结果
	for (int i = 0; i<resSize; i++) {
		char *str = malloc(sizeof(strSize));
		memset(str, '\0', strSize);
//        *(str+strSize-1)='\0';
		res[resTop] = str;
		++resTop;
	}
	
	
	int sevenOrNineNum = 0;
	//一竖排一竖排的插入数据
	for (int j = 0; j<strSize-1; j++) {
		
		int currentChar = *(digits+j);
		
		
		if(currentChar == '7' || currentChar == '9'){
			++sevenOrNineNum;
		}
		
		//第j排字符的变化规律是，每隔resSize/pow(3,j+1)变化一次 7和9需要特殊处理
		int changeLen = resSize/(pow(3, j+1-sevenOrNineNum)*pow(4, sevenOrNineNum));
		
	  
		
		
		
		printf("变化规律：第%d排字符 ==== %d\n",j,changeLen);
		
		resTop = 0;
		for (int i = 0; i<resSize; i++) {
			char *str = res[resTop];
			
			
			
			//找规律得出currentChar与currentResChar的关系
			char currentResChar;
			if(currentChar == '7' || currentChar == '9'){
				currentResChar = (i/changeLen)%4 + currentChar + 47 + 2*(currentChar-'2') + (currentChar == '9');
			}else{
				currentResChar = (i/changeLen)%3 + currentChar + 47 + 2*(currentChar-'2') + (currentChar == '8');
			}
			
			
			*(str+j) = currentResChar;
			
//            printf("当前字符：%c:%s\n",currentChar,str);
			
			++resTop;
		}
		
	}
	
	
	return res;
}



int main(int argc, char *argv[]) {
	
	
	char * digits = "999";
	int returnSize;
	char ** res = letterCombinations(digits, &returnSize);
	
	
	for (int i = 0; i<returnSize; i++) {
		printf("%s\n",res[i]);
	}
	
}

