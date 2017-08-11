#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int de;
	int cai;
	int num;
	int zongfen;
	int cl;   //��� 
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
		/*�·ֺͲŷ־�������H�����ఴ�ִܷӸߵ�������*/
		if(list[i].cai>=H && list[i].de>=H) {
			list[i].cl = 1;
		}
		/*�ŷֲ������·ֵ��ߣ��ڵ�һ�࿼��֮�󣬰��ܷ�����*/
		else if(list[i].cai<H && list[i].de>=H) {
			list[i].cl = 2;
		}
		/*�²ŷ־�����H�����·ֲ����ڲŷ֣����ڵڶ��࿼��֮��*/
		else if(list[i].de < H) {
			if(list[i].de >= list[i].cai) {
				list[i].cl = 3;
			} else if(list[i].de < list[i].cai) {
				list[i].cl = 4;
			}
		}
	}
	/*qsort(Ҫ����ļ������飬Ԫ�صĸ�����һ��Ԫ�صĴ�С���ȽϺ���)*/
	qsort(list, N, sizeof(stu), comp);
	printf("%d\n", N);
	for(i=0; i<N; i++) {
		printf("%d %d %d\n", list[i].num, list[i].de, list[i].cai);
	}
	free(list);
	return 0;
}
