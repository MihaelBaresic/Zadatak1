#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ime[20];
	char prezime[20];
	int bodovi;
}Student;


int countRows(char* fileName) {
	FILE* Dat;
	Dat = fopen(fileName, "r");
	if (!Dat)
		printf("Krivo otvorena datoteka");
	int n = 0;
	char* buffer = malloc(1024);
	while (1) {
		if (fgets(buffer, 50, Dat) == '\0')
			break;
		n++;
	}
	fclose(Dat);
	return n;
}

void Unos_Ispis(char* fileName, int n) {
	FILE* Dat;
	Dat = fopen(fileName, "r");
	if (!Dat)
		printf("Krivo otvorena datoteka");
	Student* Studenti;
	Studenti = (Student*)malloc(n * sizeof(Student));
	if (!Studenti)
		printf("Krivo alocirana memorija");
	int i;

	int max_bodovi;
	printf("Unesi max bodove: ");
	scanf("%d", &max_bodovi);

	//unos
	for (i = 0; i < n; i++)
		fscanf(Dat, "%s %s %d", Studenti[i].ime, Studenti[i].prezime, &Studenti[i].bodovi);

	//ispis
	printf("Ime:\t\tPrezime:\t\tAps_bodovi:\t\tRel_bodovi:\n");
	for (i = 0; i < n; i++)
		printf("%-20s\t%-20s\t%-10d\t%0.2f Percent \n", Studenti[i].ime, Studenti[i].prezime, Studenti[i].bodovi, ((float)(Studenti[i].bodovi) / max_bodovi) * 100);
	fclose(Dat);
}

int main() {
	char fname[20];
	int n;
	printf("Unesi ime datoteke: ");
	scanf("%s", fname);
	n = countRows(fname);
	Unos_Ispis(fname, n);

	return 0;
}
