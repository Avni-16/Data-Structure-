#include <stdio.h>

void insertionSort(int a[], int n) {
int i, key, j;
	for(j=1;j<n;j++){
	key=a[j];
	i=j-1;
		while(i>=0 && a[i]>key){
		a[i+1]=a[i];
	i=i-1;
		}
	a[i+1]=key;

	}
}

int main() {
    int a[20], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
