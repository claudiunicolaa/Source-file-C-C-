/*
 * ui.c
 *
 *  Created on: Mar 7, 2016
 *      Author: claudiu
 */

#include <src/controller/controller.h>
#include <stdio.h>
#include <src/util/constants.h>

void printMenu() {
	puts("1.Adauga cheltuiala.");
	puts("2.Afisare cheltuieli.");
	puts("3.Sterge cheltuiala.");
	puts("0.Iesire.\n");
	puts("Dati o comanda: ");
}
int getCommand() {
	int cmd = 0;
	scanf("%d", &cmd);
	return cmd;
}
void addCommand(Controller* ctrl) {
	int day = 1;
	float money = 0;
	char type[20];
	puts("Adauga cheltuiala:");
	puts("Introdu ziua(1-31):");
	scanf("%d", &day);
	puts("Introdu suma:");
	scanf("%f", &money);
	puts("Introdu tipul*:");
	puts("*Tipul poate fi: mancare, transport, "
			"telefon&internet,imbracaminte,altele");
	scanf("%s", type);
	addAction(ctrl, day, money, type);
	puts(SUCCES_MSG);
}

void showCommand(Controller* ctrl) {
	DynamicVector* vector = getAllAction(ctrl);
	printDynamicVector(vector);
}
void deleteCommand(Controller* ctrl) {
	puts(SUCCES_MSG);
}
void destroyAll(Controller* ctrl) {
}

void runUi(Controller* ctrl) {
	puts("Bine ati venit!\n");
	int cmd = 0;
	while (1) {
		printMenu();
		cmd = getCommand();
		switch (cmd) {
		case 1:
			addCommand(ctrl);
			break;
		case 2:
			showCommand(ctrl);
			break;
		case 3:
			deleteCommand(ctrl);
			break;
		case 0:
			puts("\nLa revedere!!!");
			return;
		default:
			puts("Comanda nerecunoscuta.");
			break;
		}
	}
}
