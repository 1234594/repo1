#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
int main(){
    //�ҵ��ڵ�
    LNode *findNode();
    //������Ҫ����Ľڵ�
    LNode *insertNode();
    //��� success����error
    void output();
    //������Ҫɾ�����߲���ĵڼ����ڵ�
    int inputNum();
    LinkedList *head = NULL;
    //���ܵ�ֵ������ɾ��
    int receiveNumber;
    int choose;

    while(1) {
        printf("***********     0.quit the system     ***********\n");
        printf("***********     1.��ʼ��              ***********\n");
        printf("***********     2.��������            ***********\n");
        printf("***********     3.����ڵ�            ***********\n");
        printf("***********     4.ɾ���ڵ�            ***********\n");
        printf("***********     5.��������            ***********\n");
        printf("***********     6.���ҽڵ�            ***********\n");
        printf("***********     7.��ת                ***********\n");
        printf("***********     8.�ж��Ƿ�ɻ�        ***********\n");
        printf("***********     9.������ż˳��        ***********\n");
        printf("***********     10.�����м�ڵ�       ***********\n");
        printf("Please choose:");
        scanf("%d",&choose);

        switch(choose) {
            case 0 : return;
            case 1 : output(InitList(&head)); break;
            case 2 : DestroyList(&head); break;
            case 3 : output(InsertList(findNode(&head),insertNode()));break;
            case 4 : output(DeleteList(findNode(&head),&receiveNumber)); printf("���ܵ���ֵ�ǣ�%d",receiveNumber); break;
            case 5 : TraverseList(head,visit); break;
            case 6 : output(SearchList(head,inputNum())); break;
            case 7 : ReverseList(head); break;
            case 8 : IsLoopList(head); break;
            case 9 : ReverseEvenList(&head); break;
            case 10: FindMidNode(&head); break;
            default  : printf("******input error******\n");
        }
        printf("\n please press any key to continue...\n");
        getch();
    }
}

/**
 *	@description : ����ͷ�ڵ㣬���������number�����ص�number���ڵ�
 *	@param		 : L(the head node)
*/
LNode *findNode(LinkedList *L) {
    int num;
    printf("����������Ҫ��������ǵڼ����ڵ����ɾ���ڼ����ڵ�����Ǹ��ڵ�");
    scanf("%d",&num);
	while(*L){
		if(!(--num)) {
            LNode *returnNode = *L;
            return returnNode;
        }
		else
			(*L) = (*L)->next;
	}
	return NULL;
}


LNode* insertNode() {
    int num;
    printf("����������Ҫ����Ľڵ��ֵ:");
    scanf("%d",&num);
    LNode *returnNode = (LNode *)malloc(sizeof(LNode));
    returnNode->data = num;
    returnNode->next = NULL;
    return returnNode;
}


void output(int num) {
    if(num == 1) {
        printf("SUCCESS\n");
    } else if(num == 0) {
        printf("ERROR\n");
    }

}


int inputNum() {
    int num;
    printf("�������ɾ�����߲��ҵĵڼ����ڵ�");
    scanf("%d",&num);
    return num;
}
