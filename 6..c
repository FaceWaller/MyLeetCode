#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//先找到规律  从上到下 增值从(numRows-2-i)*2+2和0变化到0和(numRows-2-i)*2+2

char* convert(char* s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	
	int sLen=0;//字符串长度
	char * tempS = s;
	while (*tempS) {
		++tempS;
		++sLen;
	}
	
	
	
	
	char * res = malloc(sLen+1);  //新建一个数组用来存储结果字符串
	memset(res,'\0',sLen+1);  //初始化数组为0
	char * resTemp = res;
	
	
	int curExcNum;//当前偏移值
	
	int oneStep; //第一段偏移量
	int twoStep; //第二段偏移量
	
	
	
	
	for (int i=0; i<numRows; i++) {
		
		oneStep = (numRows-2-i)*2+2;
		twoStep = (i-1)*2+2;
		
		int curStepType=0;//第一段第二段偏移量接连来

		//每次处理一组字符

		curExcNum = i;
		
		
		while (curExcNum < sLen) {
			
			if( (curStepType == 0 && oneStep) || !twoStep){
				
				*resTemp++ = *(s+curExcNum);
				
				
				//改变当前偏移量
				curExcNum += oneStep;
				
				//两种step轮流执行
				curStepType=1;
			}else{
				*resTemp++ = *(s+curExcNum);
				
				
				//改变当前偏移量
				curExcNum += twoStep;
				
				//两种step轮流执行
				curStepType=0;
			}
			
		}
		
		
	}
	
	return res;
}

int main(int argc, char *argv[]) {
	char * str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char * res = convert(str,3);
	printf("%s",res);
}

