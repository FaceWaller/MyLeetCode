#include <stdio.h>


int* twoSum(int* nums, int numsSize, int target) {
	int maxNum = 0;
	int minNum = 0;
	for(int i = 0;i < numsSize;i++){  
		if (nums[i] > maxNum) {
			maxNum = nums[i];
		}
		if (nums[i] < minNum) {
			minNum = nums[i];
		}
	}  
	int tableSize = maxNum-minNum +1;
	int *table = (int*)malloc( tableSize*sizeof(int)); 
	int *a = (int*)malloc(2*sizeof(int));  
 
	for(int i = 0;i < tableSize;i++){
		table[i]=-1;
	}
	for(int i = 0;i<numsSize;i++){
		if ((target-minNum) < nums[i]) {
			continue;
		}
		int differenceIndex = target - nums[i] - minNum;
		if (table[differenceIndex] != -1) {
			a[0] = i;
			a[1] = table[differenceIndex];
			break;
		}
		
		int currentIndex = nums[i] - minNum;
		table[currentIndex] = i;
	}

	free(table);
	
	
	return a;  
}

int main(int argc, char *argv[]) {
	int nums[] = {-3,4,3,90};
	int target = 0;
	int numsSize = sizeof(nums)/sizeof(int);
	int * a = twoSum(nums, numsSize, target);
	printf("%d %d",a[0],a[1]);
//	free(a);
}