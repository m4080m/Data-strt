#include<stdio.h>
int main() {
	int arr[10], temp;
	for (int i = 0; i < 10; i++)scanf("%d", &arr[i]);
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)printf("%d ", arr[i]);
}
