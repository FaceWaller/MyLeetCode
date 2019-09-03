#include <stdio.h>

double findMedianSortedArrays(int* nums1, int n1Size, int* nums2, int n2Size) {
	
	int isSingle = (n1Size + n2Size)%2 == 1?1:0; //奇偶判断

	int * n1 = nums1;
	int * n2 = nums2;
	
	int middleleft = (n1Size + n2Size)/2;
	int middleright = (n1Size + n2Size)/2 + 1;
	
	double curNumLeft;
	double curNumRight;
	
  
	
	while(middleright){
		
		if(middleleft){
			if (!n2 || (n1 && *n1<*n2)) { //n2遍历完 或者 n1遍历到的值小于n2遍历到的值
				curNumLeft= *n1;
				if (--n1Size) {
					n1++;
				}else{
					n1 = NULL;
				}
			}else {     //n1遍历完 或者 n1遍历到的值大于n2遍历到的值
				curNumLeft = *n2;
				if (--n2Size) {
					n2++;
				}else{
					n2 = NULL;
				}
			}
		   
			
		}else{
			
			if (!n2 || (n1 && *n1<*n2)) {
				curNumRight= *n1;
				if (--n1Size) {
					n1++;
				}else{
					n1 = NULL;
				}
			}else {
				curNumRight = *n2;
				if (--n2Size) {
					n2++;
				}else{
					n2 = NULL;
				}
			}
			
		}
		
		--middleleft;
		--middleright;
	}
	
	
	
	
	if ( isSingle ) {
		return curNumRight;
	}else {
		return (curNumLeft + curNumRight)/2;
		
	}
	
}

int main(int argc, char *argv[]) {
	int nums1[] = {1,3};
	int nums2[] = {2};

	double res = findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int));
	printf("%f",res);
}