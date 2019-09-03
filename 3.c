#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
	if (!strlen(s)) {
		return 0;
	}
	struct ListNode{
		char nodech;
		struct ListNode * next;
	};
	
	
	
	char * chp = s; //字符指针
	
	//  首先创建一个哈希表用来记录已经存在的值，存在记为1，否则记为0
	int map[200];
	memset(map,0,sizeof(map));  //初始化数组为0
	int maxLen=1,curLen=1;
	struct ListNode * startNode = (struct ListNode *)malloc(sizeof(struct ListNode));;
	struct ListNode * curNode = startNode;
	startNode->nodech = *chp;
	startNode->next = NULL;
	map[*chp] = 1;
	
	chp++;
	
	
	while (*chp != '\0') {
		
		curNode->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		curNode=curNode->next;
		curNode->nodech = *chp;
		curNode->next = NULL;
		
		++curLen;
		
		if (map[*chp] == 0) {  //链表中不存在相同字符的时候
			
			map[*chp] = 1;  //哈希表记录该值存在
			if (maxLen < curLen) {
				maxLen = curLen;
			}
			
		} else {  //链表中存在相同字符的时候
			
			while (startNode->nodech != (*chp)) {
					map[startNode->nodech] = 0;
					struct ListNode * freeNode = startNode;
					startNode = startNode->next;
					free(freeNode);
					--curLen;
			}
			
			struct ListNode * freeNode = startNode;
			startNode = startNode->next;
			free(freeNode);
			--curLen;
		}
		chp = chp+1; //字符指向下一个
	}
	
	return maxLen;
}


int main(int argc, char *argv[]) {
	char * str = "12s1";
	int max = lengthOfLongestSubstring(str);
	
	printf("%d\n",max);
	
	return 0;
}
