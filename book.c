#include "book.h"
int selectMenu(){
int menu;
printf("\n메뉴를 선택하세요\n");
printf("1. 도서조회\n");
printf("2. 도서추가\n");
printf("3. 도서수정\n");
printf("4. 도서삭제\n");
printf("5. 파일저장\n");
printf("6. 도서검색\n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는? ");
scanf("%d",&menu);
    return menu;
}

int addbook(Book *b){
printf("제목: ");
scanf("\n %[^\n]",b->name);
getchar();
printf("장르: ");
scanf("%s",b->genre);
getchar();
printf("작가: ");
scanf("%s",b->author);
printf("가격: ");
scanf("%d",&b->price);
printf("별점: ");
scanf("%d",&b->star);
printf("=> 추가됨!\n");
return 1;
}

void readbook(Book b){
printf("\n%s\n", b.name);
printf("%s\n",b.genre);
printf("%s\n",b.author);
printf("%d원\n",b.price);
for(int i=1;i<=b.star;i++){
printf("★");
}
printf("\n");
}


int updatebook(Book *b){
printf("제목: ");
scanf("\n %[^\n]",b->name);
getchar();
printf("장르: ");
scanf("%s",b->genre);
getchar();
printf("작가: ");
scanf("%s",b->author);
printf("가격 : ");
scanf("%d",&b->price);
printf("별점: ");
scanf("%d",&b->star);
printf("=> 추가됨!\n");
return 1;
}

int deletebook(Book *b){
b -> price = -1;
b -> star = -1;
printf("=>삭제됨!!\n");
}

int selectdatano(Book *b, int count){
int num ;
listbook(b, count);
printf ("번호는 (취소:0)?");
scanf("%d" ,&num);
return num;
}

void listbook(Book *b, int count){
for (int i = 0 ; i<count ; i++){
        if(b[i].price == -1) continue;
        printf("%d번 상품 ", i+1);
        readbook(b[i]);
	printf("-----------------");
        printf("\n");
}
printf ("\n");
}

