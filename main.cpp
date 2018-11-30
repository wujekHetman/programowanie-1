#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>



//1. Zmienne, komunikacja z u�ytkownikiem.Instrukcje warunkowe
//1.1.Zadeklarowa� zmienne typu int, float, char.Przypisa� do nich warto��, wy�wietli� je na ekran.

void zad_1_1() {

	int a = 5;
	float b = 20.5;
	char c = 'c';

	printf("Int: [%d], Float: [%.2f], Char: [%c]", a, b, c);

}

//1.2.Wy�wietli� zmienn� typu int na ekran.Nale�y u�y� metody printf i konstrukcji %d
void zad_1_2() {

	int a = 5;
	printf("Int: [%d]", a);

}

//1.3.Pobra� od u�ytkownika liczb� x.Wy�wietli� kwadrat liczby x.
void zad_1_3() {

	int x;
	puts("Wprowadz liczb� ca�kowit�.. ");
	scanf("%i", &x);
	printf("square: [%i]", x*x);

}

//1.4.Zapozna� si� z instrukcjami warunkowymi(if, else if, else oraz switch).Pobra� od u�ywkownika liczb� i wy�wietli� informacj�, czy jest
//ona : mniejsza, wi�ksza, czy r�wna 0.
void zad_1_4() {

	int x;
	puts("Wprowadz liczb� ca�kowit�.. ");
	scanf("%i", &x);
	if (x > 0)puts("Liczba jest wi�ksza od zera");
	else if (x == 0)puts("Liczba jest r�wna zero");
	else puts("Liczba jest mniejsza od zera");

}

//	1.5.Pobra� ud u�ytkownika 3 liczby(x1, x2, x3).Wy�wietli� informacj�, kt�ra z tych liczb jest najwi�ksza.

void zad_1_5() {

	int x1, x2, x3;
	puts("Wprowadz 3 liczby ca�kowite.. ");
	scanf_s("%i%i%i", &x1, &x2, &x3);
	if ((x1 > x2) && (x1 > x3)) printf("Liczba %i jest najwieksza.", x1);
	else if((x2 > x1) && (x2 > x3)) printf("Liczba %i jest najwieksza.", x2);
	else if((x3 > x1) && (x3 > x2)) printf("Liczba %i jest najwieksza.", x3);
	else puts("Brak najwiekszej liczby w zestawieniu.");
	
}

//	1.6.Napisa� prosty kalkulator.Nale�y pobra� od u�ytkownika 2 liczby oraz operator (jeden z czterech : mno�enie, dzielenie, dodawanie,
//		odejmowanie).Wymagane jest utworzenie prostego menu u�ytkownika.Uwaga - nale�y pami�ta� o u�amkach(1 / 3 powinno da� 0.33, a nie 0)

void zad_1_6() {
	int x, y;
	char znak_operacji = 'c';
	puts("Witaj w prostym kalkulatorze 1.0.0");

	puts("Wprowadz kod operacji[\"+\", \"-\", \"*\" lub \"/\"]");
	scanf("%c", &znak_operacji);

	switch (znak_operacji) {
		case '+':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, znak_operacji, y, x+y);
			break;
		case '-':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, y, znak_operacji, x-y);
			break;
		case '*':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x*(float)y);
			break;
		case '/':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%i%i", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x/(float(y)));
			break;
		default:
			puts("Nieprawid�owy kod operacji.");
			break;
	}
}




//	2. P�tle
//	2.1.Zapozna� si� z p�tl� while.P�tla ta s�u�y do wielokrotnego wykonania fragmentu kodu przez NIEZNAN� Z G�RY ilo�� razy.P�tla
//	wykonuje si� zawsze, je�li warunek jest prawdziwy(ewaluowany do true).Napisa� p�tl�, w kt�ej u�ytkownik podaje liczb� x.Nale�y
//	wy�wietli� t� liczb�.Je�eli u�ytkownik poda 0, nale�y zako�czy� program.

void zad_2_1() {
	int x;
	puts("Podaj liczb� ca�kowit�.. ");
	scanf("%i", &x);

	while (x != 0)
	{
		printf("Podana liczba: %i\n", x);
		puts("Podaj liczb� ca�kowit�.. ");
		scanf("%i", &x);
	}

}

//	2.2.Przerobi� kalkulator z zadania 1.6.Teraz po ka�dym dzia�aniu program powinien spyta� u�ytkownika, czy ten chce powt�rzy�
//	wszystko od pocz�tku.Je�li tak - restartujemy kalkulator i zaczynamy od nowa.Je�li nie - ko�czymy program.

void zad_2_2() {
	int x, y;
	char znak_operacji = 'c';
	puts("Witaj w prostym kalkulatorze 1.0.1");

	while (znak_operacji != 'Q') {
		puts("\nWprowadz kod operacji[\"+\", \"-\", \"*\" lub \"/\"], naci�nij 'Q' aby wyj��.");
		scanf("%c", &znak_operacji);
		switch (znak_operacji) {

		case '+':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, znak_operacji, y, x + y);
			break;

		case '-':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %i", x, y, znak_operacji, x - y);
			break;

		case '*':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x*(float)y);
			break;

		case '/':
			puts("Podaj dwie liczby ca�kowite.. ");
			scanf("%d%d", &x, &y);
			printf("Wynik operacji %i %c %i = %.2f", x, znak_operacji, y, (float)x / (float(y)));
			break;

		case 'Q':
			puts("Do zobaczenia.");
			break;

		default:
			puts("Nieprawid�owy kod operacji.");
			break;
		}

	}

}

//	2.3.Pobra� od u�ytkownika liczb� x.Nale�y wy�wietli� wszystkie kolejne pot�gi liczby x.Zako�czy� program, kiedy liczba przekroczy 100000.

void zad_2_3() {

	long x;
	int y;
	puts("Podaj liczbe ca�kowit�.. ");
	scanf("%d", &x);
	y = x;
	while (x <= 100000) {
		x = x * y;
		printf("x = %d\n", x);
	}
}
//	2.4.Pobra� od u�ytkownika liczb� x.Je�li liczba jest niedodatnia - nale�y zako�czy� program.Nast�pnie nale�y wy�wietla� kolejno(w
//		nowej linii) wszystkie liczby mniejsze od x, a� osi�gni�te zostanie 0.

void zad_2_4() {

	int x;
	puts("Podaj liczbe ca�kowit�.. ");
	scanf("%d", &x);
	while (x > 0) {
		printf("x = %i\n", --x);
	}
}

//	2.5.Zapozna� si� z instrukcjami continue; i break; .Pierwsza s�u�y do zako�czenia iteracji i przej�cia do nast�pnej, a druga natychmiast
//	ko�czy p�tl�.Przerobi� program z zadania 1.4, aby wy�wietla� tylko parzyste liczby(u�y� if oraz continue).Je�li liczba wynosi 40, nale�y
//	wyj�� z p�tli i zako�czy� program.

void zad_2_5() {

	int x;
	puts("Podaj liczbe ca�kowit�.. ");
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


//	2.6.Zapozna� si� z p�tl� for.P�tla s�u�y do wykonania danego fragmentu kodu ZNAN� Z G�RY okre�lon� ilo�� razy.Uwaga - ka�d� p�tl�
//	for mo�na zast�pi� p�tl� while i wzajemnie.Zwyczajowo obowiazuje zasada, �e je�li ilo�� iteracji jest znana - u�ywamy for, a je�li nie jest
//		znana(zale�y od u�ytkownika lub jakiego� stanu zewn�trznego) - u�ywamy p�tli while.P�tla for sk�ada si� z : ZMIENNEJ ITERACYJNEJ,
//		czyli stanu pocz�tkowego p�tli, np. int i = 0. Nast�pnie WARUNKU ZAKO�CZENIA P�TLI, np.i<10. Nast�pnie OPERACJI WYKONYWANEJ
//		PO KA�DEJ ITERACJI - zazwyczaj jest to zwi�kszenie iteratora o 1, czyli i = i + 1, b�d� w skr�cie i++.Napisa� p�tl� for, kt�ra wy�wietli cyfry
//		od 0 do 9.

void zad_2_6() {

	for (int i = 0; i < 10; i++)
		printf("%i\n", i);

}

//		2.7.Pobra� od u�ytkownika liczby x i y.Zak�adamy, �e y > x(zawsze, nie musimy tego sprawdza�).Za pomoc� p�tli for wypisa� liczby
//		mi�dzy x a y(do przemy�lenia - co jest stanem pocz�tkowym, a co warunkiem zako�czenia p�tli ? )

void zad_2_7() {

	int x, y;
	puts("Podaj 2 liczby ca�kowite najpierw mniejsz�, nast�pnie wi�ksz�.");
	scanf("%d%d", &x, &y);
	printf("\n\n\n");
	for(x; x<y; x ++)
		printf("%i\n", x);

}

//		2.8.Pobra� od u�ytkownika liczb� x.Za pomoc� p�tli for wypisa� wszystkie liczby mniejsze od x, ale wi�ksze ni� 0.

void zad_2_8() {

	int x;
	puts("Podaj liczbe ca�kowit� dodatni�.. ");
	scanf("%d", &x);
	printf("\n\n\n");
	for(x--; x>0; --x)
		printf("%i\n", x);
}

//		2.9.Pobra� od u�ytkownika liczb� x.Za pomoc� p�tli for wypisywa� CO TRZECI� liczb� wi�ksz� od x.P�tla powinna si� zako�czy�, je�li
//		liczba przekroczy 100. Uwaga - prosz� nie u�ywa� operacji continue i break, a sterowa� tylko parametrami p�tli.

void zad_2_9() {

	int x;
	puts("Podaj liczbe ca�kowit� dodatni�.. ");
	scanf("%d", &x);
	printf("\n\n\n");

	for(x; x < 100; x = x + 3)
		printf("%i\n", x);

}


//3. Funkcje, podstawy
//3.1.Napisa� metod� void NewLine().Powinna ona wypisa� na ekran pojedyncz� pust� lini�.U�y� tej metod� w main().
void NewLine() {
	printf("\n");
}

//3.2.Napisa� metod� void NewLines(int count).Powinna ona wypisa� tyle nowych linii, ile zosta�o podanych W PARAMETRZE count(nale�y
//	u�y� p�tli for).U�y� metod� w main()

void NewLines(int count) {
		
	for(count; count > 0; count--)
		printf("\n");

}

//3.3.Napisa� metod� void WriteBiggerNumber(int x, int y).Metoda powinna pobra� 2 parametry i zwr�ci� wi�kszy z nich.Wykorzysta�
//funckj� w metodzie main().UWAGA - pobieranie liczb od u�ytkownika powinno odby� si� w funkcji main(), a NIE w WriteBiggerNumber!Do
//funkcji nale�y jedynie przes�a� pobrane wcze�niej parametry.

void WriteBiggerNumber(int x, int y) {

	if (x > y) printf("%i jest wieksze od %i", x, y);
	else if (y > x) printf("%i jest wieksze od %i", y, x);
	else puts("Liczby s� r�wne.");

}


//3.4.Napisa� metod� Multiply(int x, int y).Metoda powinna ZWR�CI�(s�owo kluczowe return) iloczyn dw�ch parametr�w.Uwaga!Metoda
//NIE POWINNA wypisywa� wyniku - powinien on by� wy�wietlony w funkcji main!

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
	//puts("Podaj dwie liczby ca�kowite.. \n");
	//scanf("%i%i", &x, &y);
	//WriteBiggerNumber(x, y);

	// zad 3.4
	int x, y;
	puts("Podaj dwie liczby ca�kowite.. \n");
	scanf("%i%i", &x, &y);
	printf("%i * %i = %i\n", x, y, Multiply(x, y));

	getchar();
	getchar();
	return 0;
}