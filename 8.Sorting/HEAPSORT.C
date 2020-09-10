#include<stdio.h>

int main() {
	int data[10], i, j, c, root, temp;
	printf("Enter 10 random number to sort in ascending order:\n");
	for(i = 0; i < 10; i++)
		scanf("%d", &data[i]);

	/* Sorting array in binary tree format */
	for(i = 1; i < 10; i++) {
		c = i;
		do {
			root = (c - 1) / 2;
			if(data[root] < data[c]) {
				temp = data[root];
				data[root] = data[c];
				data[c] = temp;
			}
			c = root;
		}
		while(c != 0);
	}
	printf("After sort array in Binary Tree format\n");
	for(i = 0; i < 10; i++)
		printf("%d\n",data[i]);

	/* Sorting array from binary tree format to ascending order */
	for(j = 9; j > 0; j--) {
		temp = data[0];
		data[0] = data[j];
		data[j] = temp;
		root = 0;
		do {
			c = 2 * root + 1;
			if(data[c] < data[c+1] && c < (j-1))
				c++;
			if(data[root] < data[c] && c < j) {
				temp = data[root];
				data[root] = data[c];
				data[c] = temp;
			}
			root = c;
		}
		while(c < j);
	}
	printf("After sort\n");
	for(i = 0; i < 10; i++)
		printf("%d\n",data[i]);
	return 0;
}
