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
Status InsertList(LNode *p, LNode *q) {
    //p节点不存在，无意义
    if(!p) {
        return ERROR;
    }
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
    if(p->next) {
        LNode *next  = p->next;
        p->next = p->next->next;
        *e = next->data;
        free(p->next);
        return SUCCESS;
    }
    return ERROR;
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
    int flag = 0;
    LNode *newHead  = NULL;
    while((*L)->next) {
        //用于记录是不是第一次，第一次的话就给出新的头节点，后续头节点不变
        if(flag == 0) {
           newHead = (*L)->next;
            flag = 1;
        }
        LNode *temp = (*L)->next;
        (*L)->next = temp->next;
        temp->next = (*L);
        L = (*L)->next;
        return newHead;
    }
    return L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    if(L == NULL) {
        return ERROR;
    }
    LNode *fast = L;
    LNode *slow = L;
    while(fast->next) {
        //快的指针走2步，慢的指针走一步
        if(fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return slow;
}
