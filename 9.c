#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	
	
	int * arr = malloc(sizeof(int)*10);
	int * arrHead = arr;
	int * tempP = arr;
	int intLen = 0;
	
	while (x>0) {
		*tempP = x%10;
		x = x/10;
		++tempP;
		++intLen;
	}
	--tempP;
	
	
	while (*arrHead == *tempP && intLen>0) {
		++arrHead;
		--tempP;
		--intLen;
	}
	
	return !intLen;

}


int main(int argc, char *argv[]) {
	int a = 1221;
	bool res = isPalindrome(a);
	printf("%d\n",res);
}

