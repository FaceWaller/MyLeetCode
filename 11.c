#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int maxArea(int* height, int heightSize) {
	
	int maxArea = 0;
	int left = 0;//左值偏移量
	int right = heightSize-1;//右值偏移量
	while (right > left) {
		int leftNum = *(height+left);
		int rightNum = *(height+right);
		int height = leftNum < rightNum?leftNum:rightNum;
		int tempArea = (right-left)*height;
		if (tempArea>maxArea) {
			maxArea = tempArea;
		}
		
		if (leftNum < rightNum) {
			++left;
		} else{
			--right;
		}
		
		
	}
	
	return maxArea;
}

//int maxArea(int* height, int heightSize) {
//
//    int maxArea = 0;
//    for (int i = 0; i<heightSize; i++) {
//        for (int j = i+1; j<heightSize; j++) {
//
//            int leftNum = *(height+i);
//            int rightNum = *(height+j);
//            int height = leftNum<rightNum?leftNum:rightNum;
//
//            int tempArea = height * (j-i);
//
//            if (tempArea > maxArea) {
//                maxArea = tempArea;
//            }
//        }
//    }
//
//    return maxArea;
//}


int main(int argc, char *argv[]) {
	int arr[] = {1,2,4,3};
	int max = maxArea(arr, sizeof(arr)/sizeof(int));
	printf("%d\n",max);
}

