#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct Student {
	int Age;
	int Height;
	int Semester;
};


Student *create(int age, int height, int semester) {

	Student *wsk = (Student*)malloc(sizeof(Student));
	wsk->Age = age;
	wsk->Height = height;
	wsk->Semester = semester;

	return wsk;
}

void display(Student *s) {

	printf("Wiek studenta: %i\nWzrost studenta: %i\nSemestr: %i\n", s->Age, s->Height, s->Semester);
}


int areEqual(Student *s1, Student *s2) {
	if (s1->Age == s2->Age && s1->Height == s2->Height && s1->Semester == s2->Semester) return 1;
	else return 0;
}



struct Node {
	int Value;
	Node *next;
};


Node *Create(int value) {
//tworzy listê jednokierunkowa, ktora ma wezel wskazujacy na samego siebie jako nastepnik
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->Value = value;
	new_node->next = NULL;

	return new_node;
}

Node *GetTail(Node *root) {
// metoda musi ustaliæ pozycje ostatniego elementu maj¹c dostêp do korzenia i zwróciæ jego adres
	Node *tail = NULL;
	if (root->next != NULL) {
		while (root->next != NULL) {
			tail = root->next;
			root = root->next;
		}
	}
	else tail = root;	
	return tail;
}

void Add(Node *root, int value) {
// metoda dodaje wêze³ do listy, której korzeñ jest przekazany jako parametr, nale¿y uzyc GetTail()
	Node *cursor = GetTail(root);
	Node *added_node = (Node*)malloc(sizeof(Node));
	
	cursor->next = added_node;
	added_node->next = NULL;
	added_node->Value = value;

}

void PrintList(Node *root) {
// metoda wypisuje liste, nalezy uzyc GetTail()

	if (root != NULL) {
		Node *tail = GetTail(root);
		Node *cursor = root;

		while (cursor != tail) {
			printf("%i -> ", cursor->Value);
			cursor = cursor->next;
		}

		printf("%i \n", cursor->Value);
	}

}

void RemoveNode(Node *root, int value) {
// metoda powinna usun¹æ wezê³ o wartoœci podanej jako parametr
	Node *cursor, *tmp, *next_cursor;
	cursor = root;
	next_cursor = root;
	tmp = NULL;

	if (cursor->Value == value) {
		tmp = cursor->next; // pierwszy el. jest poszukiwany
	}
	while (cursor != NULL) {
		if(cursor->next != NULL) next_cursor = cursor->next;
		else break;
		if (next_cursor->Value == value) {
			tmp = next_cursor;
			break;
		}	
		cursor = next_cursor;
	}

	if (tmp != NULL) {
		cursor->next = tmp->next;
		free(tmp);
	}
}



void FreeList(Node *root) {
//metoda czysci pamiec po liscie, usuwajac wszystkie elementy
	Node *cursor, *tmp;
	cursor = root;
	root = NULL;
	while(cursor != NULL){
		tmp = cursor->next;
		free(cursor);
		cursor = tmp;
	}

}


int Count(Node *root) {
//metoda zwraca rozmiar listy
	int cnt = 0;
	if (root != NULL) {
		cnt++;
		while (root->next != NULL) {
			cnt++;
			root = root->next;
		}
	}
	return cnt;
}


void zad_3_1() {
	FILE *file = fopen("numbers.txt", "w");
	int input;

	while (1) {
		scanf("%i", &input);
		if (input == 0) break;

		fprintf(file, "%i\n", input);

	}
	fclose(file);
}



void SortList(Node *root) {

	Node *next_cursor, *cursor;
	int tmp_v;


	int len_of_list = Count(root);
	for (int i = 0; i < len_of_list; i++) {
		cursor = root;
		next_cursor = cursor->next;
		for (int j = 1; j < len_of_list; j++) {
			if (next_cursor->Value < cursor->Value) {
				tmp_v = cursor->Value;
				cursor->Value = next_cursor->Value;
				next_cursor->Value = tmp_v;
			}
			cursor = cursor->next;
			next_cursor = cursor->next;
		}
	}
}

void SaveList(Node *root) {
	Node *cursor = root;

	FILE *fileOut = fopen("sorted.txt", "w");

	while (cursor != NULL) {
		fprintf(fileOut, "%i\n", cursor->Value);
		cursor = cursor->next;
	}

	fclose(fileOut);
}



void zad_3_2_3_3() {

	FILE *fileIn = fopen("numbers.txt", "r");
	//fpos_t len;

	if (fileIn != NULL) {
		char line[10];
		int tab_from_file[30];
		int i = 0;
		while (fgets(line, sizeof line, fileIn) != NULL) {
			char *start = line;
			int field;
			int n;
			while (sscanf(start, "%d%n", &field, &n) == 1) {
				printf("%d ", field);
				start += n;
				tab_from_file[i] = field;
				i++;
			}
			puts("");
			
		}
		fclose(fileIn);

		int j = 0;
		Node *root = Create(tab_from_file[j]);
		for(j = 1; j<i; j++)Add(root, tab_from_file[j]);


		PrintList(root);
		SortList(root);
		PrintList(root);
		SaveList(root);
		FreeList(root);
	}

	


	//fseek(fileIn, 0, SEEK_END);
	//fgetpos(fileIn, &len);
	//printf("Rozmiar pliku: %d\n", len);
	fclose(fileIn);
}

int main() {
	setlocale(LC_ALL, "polish");


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//zad 1.1 Utworzyæ strukturê Student tak¹ jak powy¿ej.Napisaæ metody :
	//-Student * create(int age, int height, int semester)//alokuje pamiêæ i tworzy studenta o podanych parametrach
	//WA¯NE - pamiêæ nale¿y potem zwolniæ w main!
	//-void PrintStudent(Student *s) // wypisuje wszystkie sk³adowe struktury
	//-bool AreEqual(Student *s1, Student *s2)// zwraca informacjê, czy sk³adowe s¹ takie same
	//-UWAGA - w C int zamiast bool.

	//Student *marian = create(29, 182, 3);
	//Student *jan = create(29, 182, 3);
	//display(marian);
	//printf("%i\n", areEqual(marian, jan));

	//free(marian);
	//free(jan);

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//zad 1.2 Utworzyæ tablicê 3 studentów.Zape³niæ j¹ wartoœciami, wyœwietliæ, zwolniæ pamiêæ.Tablica powinna byæ utworzona za
	//pomoc¹ metody malloc(proszê pilnowaæ odpowiedniej iloœci gwiazdek!)

	//int student_tab_size = 3;

	//Student *student_tab_wsk = (Student*)malloc(student_tab_size * sizeof(Student));
	//for (int i = 0; i < student_tab_size; i++) {

	//	printf("Wprowadz wiek, wzrost, bie¿¹cy semestr studenta nr [%i] \n", i + 1);
	//	scanf("%i %i %i", &student_tab_wsk[i].Age, &student_tab_wsk[i].Height, &student_tab_wsk[i].Semester);
	//}

	//for (int i = 0; i < student_tab_size; i++) display(student_tab_wsk + i);
	//free(student_tab_size);


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//zad 2.

	//Node *root = Create(2);
	//PrintList(root);
	//Add(root, 4);
	//Add(root, 8);
	//Add(root, 16);
	//PrintList(root);

	//Add(root, 20);
	//PrintList(root);

	//printf("%d\n", Count(root));

	//RemoveNode(root, 8);
	//PrintList(root);

	//RemoveNode(root, 10);
	//PrintList(root);

	//RemoveNode(root, 20);
	//PrintList(root);
	//
	//printf("%d\n", Count(root));

	//FreeList(root);
	//root = NULL;

	//PrintList(root);

	//fgetc(stdin);

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//zad 3_1 Wczytywaæ od u¿ytkownika liczby, az nie poda 0. Wszystkie wczytane liczby zapisaæ do pliku "numbers.txt"
	//zad_3_1();

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//zad 3_2 Wczytac z "numbers.txt" liczby. Utworzyc liste jednokierunkowa zawierajaca te liczby.
	//Wypisaæ je na ekran.
	//zad 3_3 Posortowaæ listê z zadania 3_2. Zapisaæ posortowan¹ listê do pliku "sorted.txt".

	//zad_3_2_3_3(); //zadania 3.2 i 3.3 zrealizowano w jednej funkcji.

	fgetc(stdin);
	return 0;
}