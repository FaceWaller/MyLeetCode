#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

char* intToRoman(int num) {
	char arr[16];
	int res = num;
	int top = 0;
	memset(arr,'\0',sizeof(arr));
	
	
	int kilobitNum = num/1000;
	res = num%1000;
	while (kilobitNum>0) {
		arr[top] = 'M';
		++top;
		--kilobitNum;
	}
	
	int nineHundredNum = res/900; //九百
	res = res%900;
	if (nineHundredNum) {
		arr[top] = 'C';
		++top;
		arr[top] = 'M';
		++top;
	}
	
	
	int fiveHundredNum = res/500; //五百
	res = res%500;
	while (fiveHundredNum>0) {
		arr[top] = 'D';
		++top;
		--fiveHundredNum;
	}
	
	
	int fourHundredNum = res/400; //四百
	res = res%400;
	if (fourHundredNum) {
		arr[top] = 'C';
		++top;
		arr[top] = 'D';
		++top;
	}
	
	int hundredNum = res/100; //一百
	res = res%100;
	while (hundredNum>0) {
		arr[top] = 'C';
		++top;
		--hundredNum;
	}
	
	
	int ninetyNum = res/90; //九十
	res = res%90;
	if (ninetyNum) {
		arr[top] = 'X';
		++top;
		arr[top] = 'C';
		++top;
	}
	
	
	int fiftyNum = res/50; //五十
	res = res%50;
	if (fiftyNum) {
		arr[top] = 'L';
		++top;
	}
	
	int fortyNum = res/40; //四十
	res = res%40;
	if (fortyNum) {
		arr[top] = 'X';
		++top;
		arr[top] = 'L';
		++top;
	}
	
	
	int tenNum = res/10; //十
	res = res%10;
	while (tenNum>0 ) {
		arr[top] = 'X';
		++top;
		--tenNum;
	}
	
	
	int nineNum = res/9; //九
	res = res%9;
	if (nineNum) {
		arr[top] = 'I';
		++top;
		arr[top] = 'X';
		++top;
	}
	
	
	int fiveNum = res/5; //五
	res = res%5;
	if (fiveNum) {
		arr[top] = 'V';
		++top;
	}
	
	int fourNum = res/4; //四
	res = res%4;
	if (fourNum) {
		arr[top] = 'I';
		++top;
		arr[top] = 'V';
		++top;
	}
	
	while (res>0) {
		arr[top] = 'I';
		++top;
		--res;
	}
	
	char * resStr = malloc(top+1);
	char * temp = resStr;
	int arrIndex = 0;
	while (top>-1) {
		*(temp+arrIndex) = arr[arrIndex];
		++arrIndex;
		--top;
	}
	
	return resStr;
}


int main(int argc, char *argv[]) {
	char * res = intToRoman(88);
	printf("%s\n",res);
}

