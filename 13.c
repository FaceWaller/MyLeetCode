#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


int romanToInt(char* s) {
	
	int res = 0;
	
	while ( *s != '\0') {
		if (*s == 'M') {
			res = res + 1000;
			++s;
		} else if (*s == 'C' && *(s+1) == 'M'){
			res = res + 900;
			++s;
			++s;
		} else if (*s == 'D'){
			res = res + 500;
			++s;
		} else if (*s == 'C' && *(s+1) == 'D'){
			res = res + 400;
			++s;
			++s;
		} else if (*s == 'C'){
			res = res + 100;
			++s;
		} else if (*s == 'X' && *(s+1) == 'C'){
			res = res + 90;
			++s;
			++s;
		} else if (*s == 'L'){
			res = res + 50;
			++s;
		} else if (*s == 'X' && *(s+1) == 'L'){
			res = res + 40;
			++s;
			++s;
		} else if (*s == 'X'){
			res = res + 10;
			++s;
		} else if (*s == 'I' && *(s+1) == 'X'){
			res = res + 9;
			++s;
			++s;
		} else if (*s == 'V'){
			res = res + 5;
			++s;
		} else if (*s == 'I' && *(s+1) == 'V'){
			res = res + 4;
			++s;
			++s;
		} else if (*s == 'I'){
			++res;
			++s;
		}
	}
	
	
	return res;
}


int main(int argc, char *argv[]) {
	int res = romanToInt("MCMXCIV");
	printf("%d\n",res);

}

