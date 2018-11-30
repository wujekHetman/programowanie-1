#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>



//1. Zmienne, komunikacja z u¿ytkownikiem.Instrukcje warunkowe
//1.1.Zadeklarowaæ zmienne typu int, float, char.Przypisaæ do nich wartoœæ, wyœwietliæ je na ekran.

void zad_1_1() {

	int a = 5;
	float b = 20.5;
	char c = 'c';

	printf("Int: [%d], Float: [%.2f], Char: [%c]", a, b, c);

}

//1.2.Wyœwietliæ zmienn¹ typu int na ekran.Nale¿y u¿yæ metody printf i konstrukcji %d
void zad_1_2() {

	int a = 5;
	printf("Int: [%d]", a);

}

//1.3.Pobraæ od u¿ytkownika liczbê x.Wyœwietliæ kwadrat liczby x.
void zad_1_3() {

	int x;
	puts("Wprowadz liczbê ca³kowit¹.. ");
	scanf("%i", &x);
	printf("square: [%i]", x*x);

}

//1.4.Zapoznaæ siê z instrukcjami warunkowymi(if, else if, else oraz switch).Pobraæ od u¿ywkownika liczbê i wyœwietliæ informacjê, czy jest
//ona : mniejsza, wiêksza, czy równa 0.
void zad_1_4() {

	int x;
	puts("Wprowadz liczbê ca³kowit¹.. ");
	scanf("%i", &x);
	if (x > 0)puts("Liczba jest wiêksza od zera");
	else if (x == 0)puts("Liczba jest równa zero");
	else puts("Liczba jest mniejsza od zera");

}

//	1.5.Pobraæ ud u¿ytkownika 3 liczby(x1, x2, x3).Wyœwietliæ informacjê, która z tych liczb jest najwiêksza.

void zad_1_5() {

	int x1, x2, x3;
	puts("Wprowadz 3 liczby ca³kowite.. ");
	scanf_s("%i%i%i", &x1, &x2, &x3);
	if ((x1 > x2) && (x1 > x3)) printf("Liczba %i jest najwieksza.", x1);
	else if((x2 > x1) && (x2 > x3)) printf("Liczba %i jest najwieksza.", x2);
	else if((x3 > x1) && (x3 > x2)) printf("Liczba %i jest najwieksza.", x3);
	else puts("Brak najwiekszej liczby w zestawieniu.");
	
}

//	1.6.Napisaæ prosty kalkulator.Nale¿y pobraæ od u¿ytkownika 2 liczby oraz operator (jeden z czterech : mno¿enie, dzielenie, dodawanie,
//		odejmowanie).Wymagane jest utworzenie prostego menu u¿ytkownika.Uwaga - nale¿y pamiêtaæ o u³amkach(1 / 3 powinno daæ 0.33, a nie 0)

void zad_1_6() {
	int x, y;
	char znak_operacji = 'c';
	puts("Witaj w prostym kalkulatorze 1.0.0");

	puts("Wprowadz kod operacji[\"+\", \"-\", \"*\" lub \"/\"]");
	scanf("%c", &znak_operacji);

	switch (znak_operacji) {
		case '+':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, znak_operacji, y, x+y);
			break;
		case '-':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, y, znak_operacji, x-y);
			break;
		case '*':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x*(float)y);
			break;
		case '/':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x/(float(y)));
			break;
		default:
			puts("Nieprawid³owy kod operacji.");
			break;
	}
}




//	2. Pêtle
//	2.1.Zapoznaæ siê z pêtl¹ while.Pêtla ta s³u¿y do wielokrotnego wykonania fragmentu kodu przez NIEZNAN¥ Z GÓRY iloœæ razy.Pêtla
//	wykonuje siê zawsze, jeœli warunek jest prawdziwy(ewaluowany do true).Napisaæ pêtlê, w któej u¿ytkownik podaje liczbê x.Nale¿y
//	wyœwietliæ tê liczbê.Je¿eli u¿ytkownik poda 0, nale¿y zakoñczyæ program.

void zad_2_1() {
	int x;
	puts("Podaj liczbê ca³kowit¹.. ");
	scanf("%i", &x);

	while (x != 0)
	{
		printf("Podana liczba: %i\n", x);
		puts("Podaj liczbê ca³kowit¹.. ");
		scanf("%i", &x);
	}

}

//	2.2.Przerobiæ kalkulator z zadania 1.6.Teraz po ka¿dym dzia³aniu program powinien spytaæ u¿ytkownika, czy ten chce powtórzyæ
//	wszystko od pocz¹tku.Jeœli tak - restartujemy kalkulator i zaczynamy od nowa.Jeœli nie - koñczymy program.

void zad_2_2() {
	int x, y;
	char znak_operacji = 'c';
	puts("Witaj w prostym kalkulatorze 1.0.1");

	while (znak_operacji != 'Q') {
		puts("\nWprowadz kod operacji[\"+\", \"-\", \"*\" lub \"/\"], naciœnij 'Q' aby wyjœæ.");
		scanf("%c", &znak_operacji);
		switch (znak_operacji) {

		case '+':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, znak_operacji, y, x + y);
			break;

		case '-':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, y, znak_operacji, x - y);
			break;

		case '*':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x*(float)y);
			break;

		case '/':
			puts("Podaj dwie liczby ca³kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x / (float(y)));
			break;

		case 'Q':
			puts("Do zobaczenia.");
			break;

		default:
			puts("Nieprawid³owy kod operacji.");
			break;
		}

	}

}

//	2.3.Pobraæ od u¿ytkownika liczbê x.Nale¿y wyœwietliæ wszystkie kolejne potêgi liczby x.Zakoñczyæ program, kiedy liczba przekroczy 100000.

void zad_2_3() {

	long x;
	int y;
	puts("Podaj liczbe ca³kowit¹.. ");
	scanf("%d", &x);
	y = x;
	while (x <= 100000) {
		x = x * y;
		printf("x = %d\n", x);
	}
}
//	2.4.Pobraæ od u¿ytkownika liczbê x.Jeœli liczba jest niedodatnia - nale¿y zakoñczyæ program.Nastêpnie nale¿y wyœwietlaæ kolejno(w
//		nowej linii) wszystkie liczby mniejsze od x, a¿ osi¹gniête zostanie 0.

void zad_2_4() {

	int x;
	puts("Podaj liczbe ca³kowit¹.. ");
	scanf("%d", &x);
	while (x > 0) {
		printf("x = %i\n", --x);
	}
}

//	2.5.Zapoznaæ siê z instrukcjami continue; i break; .Pierwsza s³u¿y do zakoñczenia iteracji i przejœcia do nastêpnej, a druga natychmiast
//	koñczy pêtlê.Przerobiæ program z zadania 1.4, aby wyœwietla³ tylko parzyste liczby(u¿yæ if oraz continue).Jeœli liczba wynosi 40, nale¿y
//	wyjœæ z pêtli i zakoñczyæ program.

void zad_2_5() {

	int x;
	puts("Podaj liczbe ca³kowit¹.. ");
	scanf("%d", &x);
	while (x > 0) {

		if (x == 40)
			break;
		else if (x % 2 != 0)
			printf("x = %i\n", --x);
		else
			--x;
			continue;
	}

}


//	2.6.Zapoznaæ siê z pêtl¹ for.Pêtla s³u¿y do wykonania danego fragmentu kodu ZNAN¥ Z GÓRY okreœlon¹ iloœæ razy.Uwaga - ka¿d¹ pêtlê
//	for mo¿na zast¹piæ pêtl¹ while i wzajemnie.Zwyczajowo obowiazuje zasada, ¿e jeœli iloœæ iteracji jest znana - u¿ywamy for, a jeœli nie jest
//		znana(zale¿y od u¿ytkownika lub jakiegoœ stanu zewnêtrznego) - u¿ywamy pêtli while.Pêtla for sk³ada siê z : ZMIENNEJ ITERACYJNEJ,
//		czyli stanu pocz¹tkowego pêtli, np. int i = 0. Nastêpnie WARUNKU ZAKOÑCZENIA PÊTLI, np.i<10. Nastêpnie OPERACJI WYKONYWANEJ
//		PO KA¯DEJ ITERACJI - zazwyczaj jest to zwiêkszenie iteratora o 1, czyli i = i + 1, b¹dŸ w skrócie i++.Napisaæ pêtlê for, która wyœwietli cyfry
//		od 0 do 9.

void zad_2_6() {

	for (int i = 0; i < 10; i++)
		printf("%i\n", i);

}

//		2.7.Pobraæ od u¿ytkownika liczby x i y.Zak³adamy, ¿e y > x(zawsze, nie musimy tego sprawdzaæ).Za pomoc¹ pêtli for wypisaæ liczby
//		miêdzy x a y(do przemyœlenia - co jest stanem pocz¹tkowym, a co warunkiem zakoñczenia pêtli ? )

void zad_2_7() {

	int x, y;
	puts("Podaj 2 liczby ca³kowite najpierw mniejsz¹, nastêpnie wiêksz¹.");
	scanf("%d%d", &x, &y);
	printf("\n\n\n");
	for(x; x<y; x ++)
		printf("%i\n", x);

}

//		2.8.Pobraæ od u¿ytkownika liczbê x.Za pomoc¹ pêtli for wypisaæ wszystkie liczby mniejsze od x, ale wiêksze ni¿ 0.

void zad_2_8() {

	int x;
	puts("Podaj liczbe ca³kowit¹ dodatni¹.. ");
	scanf("%d", &x);
	printf("\n\n\n");
	for(x--; x>0; --x)
		printf("%i\n", x);
}

//		2.9.Pobraæ od u¿ytkownika liczbê x.Za pomoc¹ pêtli for wypisywaæ CO TRZECI¥ liczbê wiêksz¹ od x.Pêtla powinna siê zakoñczyæ, jeœli
//		liczba przekroczy 100. Uwaga - proszê nie u¿ywaæ operacji continue i break, a sterowaæ tylko parametrami pêtli.

void zad_2_9() {

	int x;
	puts("Podaj liczbe ca³kowit¹ dodatni¹.. ");
	scanf("%d", &x);
	printf("\n\n\n");

	for(x; x < 100; x = x + 3)
		printf("%i\n", x);

}


//3. Funkcje, podstawy
//3.1.Napisaæ metodê void NewLine().Powinna ona wypisaæ na ekran pojedyncz¹ pust¹ liniê.U¿yæ tej metodê w main().
void NewLine() {
	printf("\n");
}

//3.2.Napisaæ metodê void NewLines(int count).Powinna ona wypisaæ tyle nowych linii, ile zosta³o podanych W PARAMETRZE count(nale¿y
//	u¿yæ pêtli for).U¿yæ metodê w main()

void NewLines(int count) {
		
	for(count; count > 0; count--)
		printf("\n");

}

//3.3.Napisaæ metodê void WriteBiggerNumber(int x, int y).Metoda powinna pobraæ 2 parametry i zwróciæ wiêkszy z nich.Wykorzystaæ
//funckjê w metodzie main().UWAGA - pobieranie liczb od u¿ytkownika powinno odbyæ siê w funkcji main(), a NIE w WriteBiggerNumber!Do
//funkcji nale¿y jedynie przes³aæ pobrane wczeœniej parametry.

void WriteBiggerNumber(int x, int y) {

	if (x > y) printf("%i jest wieksze od %i", x, y);
	else if (y > x) printf("%i jest wieksze od %i", y, x);
	else puts("Liczby s¹ równe.");

}


//3.4.Napisaæ metodê Multiply(int x, int y).Metoda powinna ZWRÓCIÆ(s³owo kluczowe return) iloczyn dwóch parametrów.Uwaga!Metoda
//NIE POWINNA wypisywaæ wyniku - powinien on byæ wyœwietlony w funkcji main!

int Multiply(int x, int y) {
	return x * y;
}

int main() {
	setlocale(LC_ALL, "polish");
	//zad_1_1();
	//zad_1_2();
	//zad_1_3();
	//zad_1_4();
	//zad_1_5();
	//zad_1_6();
	//zad_2_1();
	//zad_2_2();
	//zad_2_3();
	//zad_2_4();
	//zad_2_5();
	//zad_2_6();
	//zad_2_7();
	//zad_2_8();
	//zad_2_9();
	//NewLines(10);

	// zad 3.3
	//int x, y;
	//puts("Podaj dwie liczby ca³kowite.. \n");
	//scanf("%i%i", &x, &y);
	//WriteBiggerNumber(x, y);

	// zad 3.4
	int x, y;
	puts("Podaj dwie liczby ca³kowite.. \n");
	scanf("%i%i", &x, &y);
	printf("%i * %i = %i\n", x, y, Multiply(x, y));

	getchar();
	getchar();
	return 0;
}