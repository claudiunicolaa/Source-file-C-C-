/*
 * prb6.c
 *
 *  Created on: Feb 25, 2016
 *      Author: claudiu
 *  Problem statement:
 *  6. Tiparste triunghiul lui Pascal, cu toate combinarile C(m,k) de m obiecte
 *  luate cite k, k = 0, 1, ..., m, in linia m, pentru m = 1, 2, ..., n.
 */

#include <stdio.h>

/*
 * Read a integer number.
 * preconditions: -
 * postconditions: return a integer number
 */
int read() {
	int n = 0;

	printf("Enter the N:");
	fflush(stdout);
	scanf("%d", &n);

	return n;
}

/*
 * Compute the factorial of number x
 * preconditions: x > 0
 * postconditions: return a integer number
 */
int factorial(int x) {
	int i;
	int fact = 1;
	for (i = 2; i <= x; i++) {
		fact = fact * i;
	}
	return fact;
}

/*
 * Compute combinations of n taken k, C(n,k)
 * preconditions: k>0, n>0
 * postconditions: return a integer number
 */
int combinations(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

/*
 * Print Pascal's triangle with all C(m,k)
 * where m=1,2,3,...,n and k=0,1,2,...m
 * preconditions: n>0
 * postconditions: -
 */
void triangle(int n) {
	int i, j, c;
	printf("1 \n");
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			c = combinations(i, j);
			if (c == 0) {
				printf("%s", "  ");
			} else {
				printf("%d%s", combinations(i, j), " ");
			}

		}
		printf("\n");
	}
}

int main() {
	int n = read();
	triangle(n);
	return 0;
}
