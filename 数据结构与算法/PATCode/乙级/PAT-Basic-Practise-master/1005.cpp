#include <stdio.h>
#define MAX 101
int main()
{
	int k;
	int a;
	int i, temp;
	int arr[MAX] = { 0 };
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d", &a);
		arr[a]++;
	}
	
	for(i=2; i<=MAX; i++){
		if(arr[i]){
			temp = i;
			while(temp != 1){
				if(temp%2){
					temp = 3*temp+1;
					temp /= 2;
				} else {
					temp /= 2;
				}
				if(temp < 100 && temp > 1){
					arr[temp] = 0;
				}
			}
		}
	}
	temp = 0;
	for(i=0; i<=MAX; i++){
		if(arr[i]){
			temp++;
		}
	}
	int arr2[temp];
	int j=0;
	for(i=0; i<=MAX; i++){
		if(arr[i]){
			arr2[j] = i;
			j++;
		}
	}
	for (i = 0; i < temp; i++)  
        for (j = i + 1; j < temp; j++)  
            if (arr2[i] < arr2[j]) {  
                a = arr2[i];  
                arr2[i] = arr2[j];  
                arr2[j] = a;
            }
    for (i = 0; i < temp-1; i++)  
        printf("%d ", arr2[i]);
    printf("%d", arr2[i]);
    return 0;
}
