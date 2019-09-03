#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int threeSumClosest(int* nums, int numsSize, int target) {
	
	int res = *nums + (*(nums+1)) + (*(nums+2));
	int resExc=target-res>0?target-res:res-target;
	
	
	if (numsSize == 3) {
		return res;
	}
	
	
	//找出最大值和最小值
	int maxNum = *nums;
	int minNum = *nums;
	for(int i = 0;i < numsSize;i++){
		if (*(nums+i) > maxNum) {
			maxNum = *(nums+i);
		}
		if (*(nums+i) < minNum) {
			minNum = *(nums+i);
		}
	}
	
   
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
	
	
	
   
	for(int i =0;i<tableSize;i++){
		printf("trueValue=%d,key=%d,valueNum=%d\n",i+minNum,i,table[i]);
	}
	
	//初始化当前值
	int tempIvalue = minNum-1;
	int tempJValue = minNum-1;
	
	
	
	
	for (int i=0; i<tableSize; i++) {
		if (table[i] == 0) continue; //不存在值的情况
		int iValue = i+minNum;
		if(iValue == tempIvalue) continue; //重复的情况
		tempIvalue = iValue; //当前i值
		
		--table[i];//使用了一次当前值
		tempJValue = minNum-1;//重置了i值，j的默认值也要初始化
		
		for (int j=i; j<tableSize; j++) {
			
			
		   
			
			//类似的判断
			if (table[j] == 0) continue; //不存在值的情况
			int jValue = j+minNum;
			if(jValue == tempJValue) continue; //重复的情况
			tempJValue = jValue; //当前i值
			
			
			if (tempIvalue == 9 && tempJValue == 9) {
				
				printf("都是9");
				
			}
			
			
			--table[j];//使用了一次当前值
			
			int tempResValue = target-(tempIvalue+tempJValue);
			int tempResKey = tempResValue - minNum;
			
			if (tempResKey > 0 && tempResKey<tableSize && table[tempResKey] > 0) {
				return target;
			}
			
			//能够取到值的key的范围在[0,tableSize)
			
			int tempExc = 0;//临时偏移量
			if (tempResKey<0) tempExc = -tempResKey;
			while ( tempExc<resExc &&(tempExc+tempResKey)<tableSize ) { //向右偏移时
				if( table[tempExc+tempResKey]>0){
					resExc = tempExc;
					res = target+resExc;
				}
				
				++tempExc;
			}
			
			tempExc=0;//临时偏移量
			if (tempResKey>=tableSize) tempExc = tableSize-tempResKey - 1;
			while ( (-tempExc)<resExc && (tempExc+tempResKey)>0) { //向左偏移时
				if(table[tempExc+tempResKey]>0){
					resExc = -tempExc;
					res = target-resExc;
				}
				--tempExc;
			}
			
			++table[j];//还原

		}
		
		++table[i]; //还原
	}
	
	
	
	
	return res;
}



int main(int argc, char *argv[]) {
	
	
	int nums[] = {0,2,1,-3};
	int res = threeSumClosest(nums,sizeof(nums)/sizeof(int),1);
	printf("结果:%d\n",res);
	
}

