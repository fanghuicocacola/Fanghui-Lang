#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct LNode {
	int a;
	LNode* next;
};
LNode* init_List(int n) {           
	LNode* L;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* p;
	LNode* r = L;
	if (n != 0) {
		int x;
		while (n--) {
			scanf_s("%d", &x);
			p = (LNode*)malloc(sizeof(LNode));
			p->a = x;
			p->next = NULL;
			r->next = p;  
			r = p;
		}
	}
	return L;
}
void print_List(LNode* L) {            
	LNode* p = L->next;
	if (L->next == NULL) {
		printf("-1\n");
		return;
	}
	while (p->next != NULL) {
		printf("%d ", p->a); p = p->next;
	}
	printf("%d\n", p->a);
}

LNode* delete2(LNode* L, int min, int max) {
	LNode* p = L->next, * q = L, * r;
	if (L->next == NULL) {
		return L;
	}
	while (p != NULL) {
		if (p->a > min && p->a < max) {
			r = p;
			q->next = p->next;
			p = q->next;
			free(r);                           
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
	return L;
}
int main() {
	int T, len, q, type, min, max;
	LNode* L;
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d", &len);
		L = init_List(len);
		scanf_s("%d", &q);
		while (q--) {
			scanf_s("%d", &type);
			if (type == 1) {
				print_List(L);
			}
			else if (type == 2) {
				scanf_s("%d%d", &min, &max);
				L = delete2(L, min, max);
			}
		}
	}
	return 0;
}


