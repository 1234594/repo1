#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){
    //找到节点
    LNode *findNode();
    //生成想要插入的节点
    LNode *insertNode();
    //输出 success或者error
    void output();
    //输入想要删除或者插入的第几个节点
    int inputNum();
    LinkedList head = NULL;
    //接受的值，用于删除
    int receiveNumber;
    void printf_Node(LNode* node);
    int choose;

    while(1) {
        printf("***********     0.quit the system     ***********\n");
        printf("***********     1.初始化              ***********\n");
        printf("***********     2.销毁链表            ***********\n");
        printf("***********     3.插入节点            ***********\n");
        printf("***********     4.删除节点            ***********\n");
        printf("***********     5.遍历链表            ***********\n");
        printf("***********     6.查找节点            ***********\n");
        printf("***********     7.反转                ***********\n");
        printf("***********     8.判断是否成环        ***********\n");
        printf("***********     9.调换奇偶顺序        ***********\n");
        printf("***********     10.查找中间节点       ***********\n");
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose) {
            case 0 : return;
            case 1 : output(InitList(&head)); break;
            case 2 : DestroyList(&head); break;
            case 3 : output(InsertList(findNode(head),insertNode() ));break;
            case 4 : output(DeleteList(findNode(head),&receiveNumber));
                     printf("接受到的值是：%d",receiveNumber);
                     break;
            case 5 : TraverseList(head,visit); break;
            case 6 : output(SearchList(head,inputNum())); break;
            case 7 : printf("反转前：");
                     TraverseList(head,visit);
                     output(ReverseList(&head));
                     printf("反转后：");
                     TraverseList(head,visit);
                     break;
            case 8 : output(IsLoopList(head));
                     printf("成环为success，不成环为error");
                     break;
            case 9 : printf("置换前：");
                     TraverseList(head,visit);
                     ReverseEvenList(&head);
                      printf("置换后：");
                     TraverseList(head,visit);
                     break;
            case 10: printf_Node(FindMidNode(&head)); break;
            default: printf("******input error******\n");
        }
        printf("\n please press any key to continue...\n");
        getch();
    }
}

/**
 *	@description : 传入头节点，根据输入的number，返回第number个节点
 *	@param		 : L(the head node)
*/
LNode *findNode(LinkedList L) {
    int num;
    printf("请输入您想要被插入的是第几个节点或者删除第几个节点后面那个节点");
    scanf("%d",&num);
    if(num == 0) {
        return L;
    }
	while(L){
		if(!(--num)) {
            LNode *returnNode = L;
            return returnNode;
        }
		else
			L = L->next;
	}
}


LNode* insertNode() {
    int num;
    printf("请输入您想要插入的节点的值:");
    scanf("%d",&num);
    LNode *returnNode = (LNode *)malloc(sizeof(LNode));
    returnNode->data = num;
    returnNode->next = NULL;
    return returnNode;
}


void output(int num) {
    if(num == 1) {
        printf("\n***SUCCESS***\n");
    } else if(num == 0) {
        printf("\n***ERROR***\n");
    }

}


int inputNum() {
    int num;
    printf("输出您想删除的第几个节点\\\\根据Element的值查找节点");
    scanf("%d",&num);
    return num;
}


 void printf_Node(LNode *node) {
    printf("%d",(*node).data);
 }
