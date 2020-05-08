#include <stdio.h>
#include <string.h>

typedef struct{
	char name[20];
	char genre[20];
	char author[20];
	int price;
	int star;
}Book;

int addbook(Book *b);
void readbook(Book b);
int updatebook(Book *b);
int deleteproduct(Book *b);
int selectMenu();
void listbook(Book *b, int count);
int selectdatano(Book *b, int count);
void savebook(Book *b, int count);
int loadbook(Book *b);
void searchbyname(Book *b, int count);
void searchbyauthor(Book *b, int count);
void searchbystar(Book *b, int count);
void chooseby(Book *b, int count);
