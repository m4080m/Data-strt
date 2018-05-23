#include<stdio.h>
#include<string.h>
typedef struct {
	char name[20];
	int num;
}mystruct;

int comp(char *a, char *b){
	int i=0;
	while(1){
		if(a[i]=='\0')return -1;
		if(b[i]=='\0')return 1;
		if(a[i]==b[i]){
			i++;
			continue;
		}
		char temp_a=a[i], temp_b=b[i];
		if('a'<=temp_a&&temp_a<='z')temp_a-=32;
		if('a'<=temp_b&&temp_b<='z')temp_b-=32;
		if(temp_a==temp_b){
			if(a[i]<b[i]) return -1;
			else return 1;
		}
		else {
			if(temp_a<temp_b) return -1;
			else return 1;
		}
	}
}
int main() {
	mystruct people[10], temp;
	for (int i = 0; i < 10; i++) {
		scanf("%s %d", people[i].name, &people[i].num);
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (comp(people[j-1].name, people[j].name) > 0) {
				temp = people[j - 1];
				people[j - 1] = people[j];
				people[j] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		printf("%s %d\n", people[i].name, people[i].num);
	}
	printf("\n");
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (people[j-1].num > people[j].num) {
				temp = people[j - 1];
				people[j - 1] = people[j];
				people[j] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		printf("%s %d\n", people[i].name, people[i].num);
	}
}

