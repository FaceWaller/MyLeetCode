//三数之和
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int** threeSum(int* nums, int numsSize, int* returnSize) {
	
	if (nums == NULL || numsSize < 3) {
		return NULL;
	}
	
	
	//找出最大值和最小值
	int maxNum = 0;
	int minNum = 0;
	for(int i = 0;i < numsSize;i++){
		if (*(nums+i) > maxNum) {
			maxNum = *(nums+i);
		}
		if (*(nums+i) < minNum) {
			minNum = *(nums+i);
		}
	}
   
	
	int nn=(numsSize)*(numsSize-1)*(numsSize-2)/6;//最多的可能种数
	int **result=(int **)malloc((nn)*sizeof(int *));//用来存放结果的二维数组
	
	
	
	int tableSize = maxNum-minNum +1; //哈希表大小
	int *table = (int*)malloc( tableSize*sizeof(int));
	for(int i = 0; i<tableSize;i++){//初始化数组为0
		table[i] = 0;
	}
	//生成哈希表
	for(int i = 0;i < numsSize;i++){
		int currentValue = *(nums+i);
		int currentKey = currentValue-minNum;
		++table[currentKey];
	}
	
	
//    for(int i =0;i<tableSize;i++){
//        printf("trueValue=%d,key=%d,valueNum=%d\n",i+minNum,i,table[i]);
//    }
	
	//初始化当前值
	int tempIvalue = minNum-1;
	int tempJValue = minNum-1;
	
	
	
	int resTop = 0;
	
	for (int i=0; i<tableSize; i++) {
		if (table[i] == 0) continue; //不存在值的情况
		int iValue = i+minNum;
		if(iValue == tempIvalue) continue; //重复的情况
		tempIvalue = iValue; //当前i值
		
		--table[i];//使用了一次当前值
	
		for (int j=i; j<tableSize; j++) {
			//类似的判断
			if (table[j] == 0) continue; //不存在值的情况
			int jValue = j+minNum;
			if(jValue == tempJValue) continue; //重复的情况
			tempJValue = jValue; //当前j值
			
			
			int tempResValue = -(tempIvalue+tempJValue);
			if (tempResValue<tempJValue) continue;//所求的值要大于tempIvalue和tempJValue
			
			int tempResKey = tempResValue - minNum;
			
			--table[j];//使用了一次当前值
			if (tempResKey>(tableSize-1)|| table[tempResKey] == 0){
				++table[j];//还原
				continue; //不存在符合的值
			}
			
			
			++table[j];//还原
			
			
			//找到一种符合条件的无重复结果
			int * arr = malloc(sizeof(int)*3);
			*arr = tempIvalue;
			*(arr+1) = tempJValue;
			*(arr+2) = tempResValue;
			result[resTop] = arr;
			++resTop;
		}
		
		
		++table[i];//复原
	}
	
 
	
	free(table);
	
	*returnSize = resTop;
	
   
	return result;
}


int main(int argc, char *argv[]) {
	int returnSize;
	int nums[] = {0,0,0};
	int **res = threeSum(nums, sizeof(nums)/sizeof(int), &returnSize);
	
	for(int i = 0; i<returnSize;i++){
		int * tempArr = res[i];
		printf("%d %d %d\n",tempArr[0],tempArr[1],tempArr[2]);
	}
	
}

