#include <stdio.h>
#include <stdlib.h>
#include <linkedList.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList *)malloc(sizeof(LinkedList));
    if(!(*L)) {
        return ERROR;
    }
    (*L)->next = NULL;
    (*L)->data = 0;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList p;
    while(*L){
		p = (*L)->next;
		free(*L);
		*L = p;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)
{   //如果p结点不存在，返回错误
	if(!p)
		return ERROR;
    q->next = p->next;
    p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(!p && !p->next)
		return ERROR;
	LNode *q;
	q = p->next;
	*e = q->data;		//记得调用前检查e是否有指向一个已知的内存空间
	p->next = q->next;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LNode *p = L;
	while(p){
		visit(p->data);
		p = p->next;
	}
}

/**
 *  @name       : void visit(ElemType e)
 *	@description : print e
 *	@param		 : e
 *	@return		 : None
 *  @notice     : None
 */
void visit(ElemType e) {
	printf("%d ",e);
}




/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    while(L->next) {
        if(L->next->data == e) {
            return SUCCESS;
        }
        L = L->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if((*L) == NULL || (*L)->next == NULL) {
        return ERROR;
    }
    LNode *pre = (*L);
    LNode *cur = (*L)->next;
    (*L)->next = NULL;
    while(cur) {
        LNode *p = cur->next;
        cur->next = pre;
        pre = cur;
        cur = p;
    }
    *L = pre;
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if(L == NULL) {
        return ERROR;
    }
    LNode *fast = L;
    LNode *slow = L;

    while(fast->next) {
        if(fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return SUCCESS;
            }
        } else {
            return ERROR;
        }
    }
    return ERROR;
}




/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LNode *pre, *cur, *Next;
	pre = *L;
	*L = pre->next;
	while(pre && pre->next){
		cur = pre->next;
		Next = cur->next;
		if(cur->next && cur->next->next){			//如果cur->next不存在，结点个数为偶数
			pre->next = cur->next->next;			//如果cur->next->next不存在，结点个数为奇数
		}else{										//如果都存在，遍历未结束
			pre->next = cur->next;
		}
		cur->next = pre;							//将偶数结点反转
		pre = Next;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

    LNode *mid = *L;
	int cnt;
	//记录链表总长度
	for(cnt=0; mid; cnt++)
		mid = mid->next;
	mid = *L;
	//总长度的一半
	for(int i=0; i<cnt/2; i++)
		mid = mid->next;
	return mid;

}
