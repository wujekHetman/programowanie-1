#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void display_tab(int tab[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%i\t", tab[i]);
		if ((i + 1) % 5 == 0) puts("");
	}
	puts("");
}

void display_array(int *tab, int len) {

	for (int i = 0; i < len; i++)
		printf("Tab[%i] = %i\t", i, *(tab + i));
	puts("");
}

void print_backwards(int *tab, int len) {
	for (int i = len - 1; i >= 0; i--)
		printf("Tab[%i] = %i\t", i, *(tab + i));
	puts("");
}

bool is_sorted(int *tab, int len) {

	for (int i = 0; i < len - 1; i++) {
		if (tab[i] > tab[i + 1])
			return 0;
	}
	return 1;
}

void print_dots(int *tab, int len) {

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < tab[i]; j++) {
			printf("*");
		}
		puts("");
	}
}

void sum(int *tab, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum = sum + tab[i];

	printf("Suma elementów w tablicy: %i", sum);


}

void bubble_sort(int *tab, int len) {

	int bufor;

	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1; j++) {
			if (tab[j] > tab[j + 1]) {
				bufor = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = bufor;
			}
		}

	puts("\nTablica po sotrowaniu:\n\n");
	display_tab(tab, len);


}

int getLenght(char *znaki) {

	int len = 0;

	while (znaki[len] != '\n') len++;

	return len;
}

void reverse(char *znaki) {

	int i = 0;
	char x;
	char str2[30];
	strcpy(str2, znaki);
	while (i < getLenght(str2) / 2)
	{
		x = str2[i];
		str2[i] = str2[getLenght(str2) - i - 1];
		str2[getLenght(str2) - i - 1] = x;
		i++;
	}
	printf("String od koñca: %s", str2);
}

bool containsDigits(char *znaki) {
	
	for (int i = 0; i < getLenght(znaki); i++)
	{
		if (znaki[i] >= 48 &&  znaki[i] <= 57)
		{
			return 1;
		}
	}
	return 0;


}

bool AreArraysIdentical(int *a1, int s1, int *a2, int s2) {

	if (s1 != s2) return  0;

	for (int i = 0; i < s1; i++) {
		if (a1[i] != a2[i]) return 0;
	}

	return 1;

}

char * reverseString(char*s) {

	char *s2;
	int len = getLenght(s);
	int i = 0;
	char x;

	s2 = (char*)calloc(getLenght(s), sizeof(char) * (len + 1));
	strcpy(s2, s);

	while(i < len/2)
	{
		x = s2[i];
		s2[i] = s2[getLenght(s2) - i - 1];
		s2[getLenght(s2) - i - 1] = x;
		i++;
	}


	return s2;
}

void zad_1_1_i_1_2_i_1_3() {
	int tab[5];
	int tab_lenght = sizeof(tab) / sizeof(tab[0]);

	puts("Podaj piêæ elementów tablicy ");

	for (int i = 0; i < 5; i++)
		scanf("%i", &tab[i]);

	for (int i = 0; i < tab_lenght; i++)
		printf("Tab[%i] = %i\t", i, *(tab + i));
	puts("");

	for (int i = tab_lenght - 1; i >= 0; i--)
		printf("Tab[%i] = %i\t", i, *(tab + i));
	

	int max_value = tab[0];
	for (int i = 1; i < 5; i++) {
		if (tab[i] > max_value) max_value = tab[i];
	}
	printf("Wartoœæ maksymalna = %i\n", max_value);
	puts("");

	bool flag = false;
	for (int i = 0; i < tab_lenght - 1; i++)
		if (tab[i] > tab[i + 1]) {
			flag = true;
			break;
		}
	if(flag) puts("Tablica nie jest uporzadkowana niemalejaco.");
	else puts("Tablica jest uporzadkowna niemalej¹co.");

}


void zad_2_1_2_2() {
	int tab[5];
	int tab_lenght = sizeof(tab) / sizeof(tab[0]);

	puts("Podaj piêæ elementów tablicy ");

	for (int i = 0; i < 5; i++)
		scanf("%i", &tab[i]);

	if (is_sorted(tab, tab_lenght)) puts("Tablica jest uporzadkowana niemalejaco.");
	else puts("Tablica nie jest uporzadkowna niemalej¹co.");

	puts("");
	print_backwards(tab, tab_lenght);

}

void zad_2_3_2_4() {

	int tab[] = { 3,2,5,4 };
	print_dots(tab, sizeof(tab) / sizeof(tab[0]));
	sum(tab, sizeof(tab) / sizeof(tab[0]));

}

void zad_2_5() {

	puts("Podaj iloœæ elementów losowej tablicy do posortowania:");
	srand(time(NULL));

	int tab[100];

	int tab_len = sizeof(tab) / sizeof(tab[0]);


	for (int i = 0; i < tab_len; i++) {

	tab[i] = rand() % (100);
	}

	puts("Tablica przed sotrowaniem:\n");
	display_tab(tab, tab_len);

	bubble_sort(tab, tab_len);
}

void zad_3_1() {
	char znaki[31];
	puts("Wprowadz ³añcuch znaków nie d³u¿szy ni¿ 30 znaków: ");

	fgets(znaki, 30, stdin);
	puts("");
	printf("%s", znaki);

	printf("D³ugoœæ wprowadzonego ³ancucha: %i", getLenght(znaki));
}

void zad_3_2() {

	char znaki[31];
	puts("Wprowadz ³añcuch znaków nie d³u¿szy ni¿ 30 znaków: ");

	fgets(znaki, 30, stdin);
	char *wsk = znaki;

	reverse(wsk);
	   	 
}

void zad_3_3() {

	char znaki[31];
	puts("Wprowadz ³añcuch znaków nie d³u¿szy ni¿ 30 znaków: ");

	fgets(znaki, 30, stdin);
	char *wsk = znaki;

	if (containsDigits(znaki))puts("£añcuch zawiera znaki.");
	else puts("£añcuch nie zawiera znaków");


}


void zad_3_4() {

	char znaki[31];
	puts("Wprowadz ³añcuch znaków nie d³u¿szy ni¿ 30 znaków: ");

	fgets(znaki, 30, stdin);
	char *wsk = znaki;

	if (containsDigits(znaki))puts("£añcuch zawiera znaki.");
	else puts("£añcuch nie zawiera znaków");
}


void zad_4_1() {
	int n;
	puts("Podaj rozmiar tablicy: ");

	scanf("%i", &n);
	int *tab = (int *)malloc(sizeof(int) * n);

	printf("Podaj %i, elementow typuy int: \n", n);
	for (int i = 0; i < n; i++) {

		scanf("%i", tab + i);
	}

	print_backwards(tab, n);
	free(tab);

}


void zad_4_2() {
	int n;
	int i = 0;
	int j = 0;
	int negative_values_num = 0;
	puts("Podaj rozmiar tablicy: ");

	scanf("%i", &n);
	int *tab;
	tab = (int *)malloc(sizeof(int) * n);
	

	printf("Podaj %i, elementow typu int: \n", n);
	for (i = 0; i < n; i++) {

		scanf("%i", tab + i);
		if (tab[i] < 0) negative_values_num++;
	}
	printf("Iloœæ wartoœci ujemnych: %i\n", negative_values_num);
	int *negative_values_tab;
	negative_values_tab = (int *)malloc(sizeof(int) * negative_values_num);

	for (i = 0, j = 0; i < n; i++) {
		if (tab[i] < 0) {
			negative_values_tab[j] = tab[i];
			j++;
		}

	}

	display_tab(negative_values_tab, negative_values_num);

	free(tab);
	free(negative_values_tab);

}


void zad_4_3() {
	int size1;
	int size2;
	puts("Podaj rozmiar tablicy pierwszej i drugiej.");

	scanf("%i", &size1);
	scanf("%i", &size2);

	int *tab1;
	int *tab2;

	tab1 = (int *)malloc(sizeof(int) * size1);
	tab2 = (int *)malloc(sizeof(int) * size2);

	printf("Podaj %i elementow pierwszej tablicy: ", size1);
	for(int i = 0; i < size1; i++)
		scanf("%i", tab1 + i);

	printf("Podaj %i elementow drugiej tablicy: ", size2);
	for (int i = 0; i < size2; i++)
		scanf("%i", tab2 + i);

	if (AreArraysIdentical(tab1, size1, tab2, size2)) puts("Tablice sa identyczne.");
	else puts("Tablice s¹ ró¿ne.");


	free(tab1);
	free(tab2);

}

void zad_4_4() {
	char znaki[31];
	puts("Wprowadz ³añcuch znaków nie d³u¿szy ni¿ 30 znaków: ");
	fgets(znaki, 30, stdin);

	char *reverse;
	reverse = reverseString(znaki);
	printf("%s", reverse);


	free(reverse);

}

int main() {
	setlocale(LC_ALL, "polish");
	//1.1.Utworzyæ 5 - cio elementow¹ tablicê typu int.Pobraæ od u¿ytkownika 5 elementów
	//i dodaæ je do tablicy.Nastêpnie wyœwietliæ najwiêksz¹ liczbê z tablicy
	//(algorytm do samodzielnej implementacji).
	//1.2.Wyœwietliæ w pêtli tablice z zadania 1.1 od pocz¹tku i od koñca(dwie pêtle)
	//1.3 Napisaæ algorytm sprawdzaj¹cy, czy tablica jest posortowana w kolejnoœci niemalej¹cej

	//zad_1_1_i_1_2_i_1_3();

	//2.1.Utworzyæ osobn¹ metodê bool IsSorted(int *, int)
	//realizuj¹c¹ zadanie 1.3 (UWAGA - w jêzyku C niedostêpny jest typ bool z wartoœciami true i false,
	//zamiast niego nale¿y u¿yæ int i wartoœci 1 i 0)
	//2.2. Utworzyæ metodê void printBackwards(int *a, int s) s³u¿¹c¹ do wypisania tablicy OD KOÑCA

	//zad_2_1_2_2();

	//2.3 Utworzyæ metodê printDots(int *a, int s) wyœwietlaj¹c¹ w nowych liniach tyle kropek,
	//ile znajduje siê w danym elemencie tablicy.

	//2.4.Utworzyæ metodê int Sum(int *a, int s) licz¹c¹ sumê elementów tablicy.

	//zad_2_3_2_4();

	//2.5.Zaimplementowaæ algorytm sortowania b¹belkowego(w funkcji main(), nie ma potrzeby tworzenia dodatkowej funkcji).
	//Algorytm powinien posortowaæ dowolnie du¿¹ tablicê w kolejnoœci niemalej¹cej.

	//zad_2_5();

	//3.1.Napisaæ metodê int getLength(char *str),
	//w której W£ASNORECZNIE(nie wolno korzystaæ z metody strlen())
	//przeliczony zostanie rozmiar ³añcucha(bez null - terminatora).
	//Dla przyk³adu dla „Hello!" wynik powinien wynosiæ 6.

	//zad_3_1();

	//3.2.Napisaæ metodê void Reverse(char *str),
	//która wypisze ³añcuch znaków od koñca
	//(zakaz u¿ywania strlen, mo¿na uzyæ metodê z zadania 3.1.)

	//zad_3_2();

	//3.3.Napisaæ metodê bool containsDigits(char * str),
	//która zwróci informacjê, czy w danym stringu znajduje siê jakakolwiek cyfra.
	//Dla przyk³adu : „asdfgzxcv" -> false, „asdf5asdf" -> true

	//zad_3_3();

	//3.4.Pobraæ od u¿ytkownika ³añcuch znaków(dowolna metoda).
	//Przekazaæ go do ka¿dej z metod z 3. czêœci zadañ.

	//zad_3_4();

	//4.1.Pobraæ od u¿ytkownika liczbê n.
	//Zaalokowaæ pamiêæ na n elementów int i pobraæ je od u¿ytkownika.
	//Wykonaæ na niej metodê printBackwards z 2.2.

	//zad_4_1();

	//4.2.Pobraæ od u¿ytkownika liczbê n.
	//Zaalokowaæ pamiêæ na n elementów int i pobraæ je od u¿ytkownika.
	//Nastêpnie zaalokowaæ pamiêæ i utworzyæ tablicê,
	//w której bêd¹ tylko UJEMNE wartoœci z pierwszej tablicy.
	//na koniec zwolniæ pamiêæ na obie tablice.

	//zad_4_2();

	//4.3.Napisaæ metodê bool AreArraysIdentical(int * a1, int s1, int * a2, int s2)
	//zwracaj¹c¹ informacjê, czy dwie tablice podane jako parametr s¹ identyczne, tj.
	//czy maj¹ tak¹ sam¹ d³ugoœæ i czy na ka¿dym indeksie wystêpuje taki sam element.

	//zad_4_3();

	//4.4.Napisaæ metodê char * reverseString(char*s), która ZWRÓCI(a nie wypisze!) string,
	//który jest odwróconym stringiem przekazanym jako pierwszy parametr.
	//Funkcja zaalokuje pamiêæ na nowy ³añcuch i go zwróci.
	//(ca³y algorytm nale¿y zaimplementowaæ samodzielnie).

	zad_4_4();


	getchar();
	getchar();
	return 0;
}