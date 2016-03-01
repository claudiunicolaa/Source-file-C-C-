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
#include <string.h>

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
 * Print Pascal's triangle, using two arrays.
 * preconditions: n>0
 * postconditions: -
 */
void triangle(int n) {
	int i, j, l = 0;
	int array[50], temp[50];
	temp[0] = 1;
	array[0] = 1;
	for (i = 1; i < n; i++) {
		for (j = 1; j < n; j++) {
			array[j] = temp[j - 1] + temp[j];
		}
		array[i] = 1;
		for (l = 0; l <= i; l++) {
			printf("%3d", array[l]);
			temp[l] = array[l];
		}
		printf("\n");
	}

}

/*
 * Print the menu
 * preconditions: -
 * postconditions: -
 */
void menu() {
	printf("Bine ati venit!\n");
	printf("1. Triunghiul lui Pascal.\n");
	printf("0. Iesire.\n");
	printf("Introduceti optiunea: ");
}

int main() {
//	triangle(5);
	int n = 0;
	int opt = 1;
	while (opt != 0) {
		menu();
		if (scanf("%d", &opt) == 0)
			break;
		if (opt == 1) {
			n = read();
			triangle(n);
		}
	}
	printf("La revedere!");
	return 0;
}
