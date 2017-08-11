//Usuage of function pointer and qsort_lib function.
//Background:
// 	qsort can sort arbitrary arrays types 
// 	void qsort(void *base, int nelem, unsigned int width, 
//		int(* pfCompare)(const void*,const void *));
//	where:
//	if e1 lie before e2, pfCompare(e1,e2) return Negative  Integer
//	elseif the order or e1 and e2 doesn't matter, pfCompare(e1,e2) return Zero;
//	else pfCompare(e1,e2) return Positive  Integer
//Example:
//	The following programe can sort unsigned int arrays from small to large by comparing their unit digit.
//	For example, qsort(8,23,15) => 23,15,8

#include<stdio.h>
#include<stdlib.h>
#define NUM 5

int MyCompare(const void * elem1, const void * elem2) {
	unsigned int *p1, *p2;
	p1 = (unsigned int *)elem1;
	p2 = (unsigned int*)elem2;
	return (*p1%10) - (*p2%10);

}

int main() {
	unsigned int a[NUM] = {8,123,11,10,4};
	qsort(a,NUM,sizeof(unsigned int),MyCompare);
	for(int i=0;i<NUM;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return  0;
}


