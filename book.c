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

