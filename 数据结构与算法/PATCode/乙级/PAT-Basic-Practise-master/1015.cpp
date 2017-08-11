#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int de;
	int cai;
	int num;
	int zongfen;
	int cl;   //类别 
} stu;

int comp(const void*a, const void*b) {
	stu *pa = (stu*) a;
	stu *pb = (stu*) b;
	if(pa->cl == pb->cl) {
		if(pa->zongfen == pb->zongfen) {
			if(pa->de == pb->de) {
				return pa->num-pb->num;
			} else {
				return pb->de-pa->de;
			}
		} else {
			return pb->zongfen-pa->zongfen;
		}
	} else {
		return (pa->cl)-(pb->cl);
	}
}

int main() {
	int L, H, N, i;
	scanf("%d %d %d", &N, &L, &H);
	stu *list;
	list = (stu*) malloc(sizeof(stu)*N);
	for(i=0; i<N; i++) {
		scanf("%d %d %d", &list[i].num, &list[i].de, &list[i].cai);
		
		if(list[i].cai<L || list[i].de<L) {
			i--;
			N--;
			continue;
		}
		list[i].zongfen = list[i].cai + list[i].de;
		/*德分和才分均不低于H，此类按总分从高到低排序*/
		if(list[i].cai>=H && list[i].de>=H) {
			list[i].cl = 1;
		}
		/*才分不到但德分到线，在第一类考生之后，按总分排序*/
		else if(list[i].cai<H && list[i].de>=H) {
			list[i].cl = 2;
		}
		/*德才分均低于H，但德分不低于才分，排在第二类考生之后*/
		else if(list[i].de < H) {
			if(list[i].de >= list[i].cai) {
				list[i].cl = 3;
			} else if(list[i].de < list[i].cai) {
				list[i].cl = 4;
			}
		}
	}
	/*qsort(要排序的集合数组，元素的个数，一个元素的大小，比较函数)*/
	qsort(list, N, sizeof(stu), comp);
	printf("%d\n", N);
	for(i=0; i<N; i++) {
		printf("%d %d %d\n", list[i].num, list[i].de, list[i].cai);
	}
	free(list);
	return 0;
}
