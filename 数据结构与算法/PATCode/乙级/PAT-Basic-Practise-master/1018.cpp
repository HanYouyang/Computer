#include <stdio.h>
char max(int cc, int jj, int bb){
	if(bb>=cc && bb>=jj)
		return 'B';
	if(cc>=jj && cc>bb)
		return 'C';
	else
		return 'J';
}
int main()
{
	int i, n;
	char j, y;
	int jw=0, pp=0, yw=0;
	int jc=0, jj=0, jb=0, yc=0, yj=0, yb=0;
	scanf("%d", &n);
	getchar();  //清除回车符的影响 
	for(i=0; i<n; i++){
		scanf("%c %c", &j, &y);
		getchar();  //清除回车符的影响 
		if(j == y){
			pp++;
		} else {
			if(j == 'C'){
				if(y == 'J'){
					jw++;
					jc++;
				} else {
					yw++;
					yb++;
				}
			} else if(j == 'J'){
				if(y == 'B'){
					jw++;
					jj++;
				} else {
					yw++;
					yc++;
				}
			}else if(j == 'B'){
				if(y == 'C'){
					jw++;
					jb++;
				} else {
					yw++;
					yj++;
				}
			}
		}
	}
	printf("%d %d %d\n%d %d %d\n%c %c\n", jw, pp, yw, yw, pp, jw, max(jc,jj,jb), max(yc,yj,yb));
	return 0;
}
