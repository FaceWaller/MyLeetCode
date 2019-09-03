#include <stdio.h>

int reverse(int x) {
	 int type = 1;
	if (x<0) {
		if (x == -2147483648) {
			return 0;
		}
		type=-1;
		x = -x;
		
	}
	if (x<-pow(2,31) || x>pow(2,31)-1) {
		return 0;
	}
	int res=0;
	while (x>0) {
		if(res > 214748364){
			return 0;
		}else if(res == 214748364){
			if (x%10>7 && type==1) {
				return 0;
			}
		}
		res = res*10 + x%10;
		x = x/10;
	}
	return res*type;
}

int main(int argc, char *argv[]) {
	int a = 123;
	int res = reverse(a);
	printf("%d",res);
}