#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define INT_MAX 2147483647 //for vim

typedef struct{
	char name[20];
	int weight;
	int price;
	int stdprice;
	int rate;
}Product;

// get a specific integer
int getIntLim(char* text, int min, int max){
	int sel;
	while(1){
		printf("%s",text);
		scanf("%d",&sel);
		if(sel>=min&&sel<=max)
			break;
		else
			printf("[Wrong input!]\n");
	}
	return sel;
}

// read file name store it in p, return the number of products
int readF(Product *p[],char* filename){
	FILE *fp = NULL;
	fp = fopen(filename,"r");
	int i = 0;

	if(fp==NULL){
		printf("\t[FILE NOT FOUND]");
		return 0;
	}
	while(!feof(fp)){
		p[i] = (Product*)malloc(sizeof(Product));
		fscanf(fp,"%s %d %d %d %d\n",p[i]->name,&p[i]->weight,&p[i]->price,&p[i]->stdprice,&p[i]->rate);
		i++;
	}
	printf("\t[FILE LOADED]");
	fclose(fp);
	return i-1;
};
// save products to file
void saveF(Product *p[], int count, char *filename){
	FILE *fp = NULL;
	fp = fopen(filename,"w");

	for(int i = 0; i<count; i++){
		if(p[i]!=NULL)
			fprintf(fp,"%s %d %d %d %d\n",p[i]->name,p[i]->weight,p[i]->price,p[i]->stdprice,p[i]->rate);
	}
	
	printf("\t[FILE SAVED]");
	fclose(fp);
};


// create new prouduct
void createProd(Product *p){
	printf("Product Name: ");
    scanf("%s",p->name);

    printf("Product Weight: ");
    scanf("%d",&p->weight);
    
    printf("Product Price: ");
    scanf("%d",&p->price);
    
    printf("Product Standard Price: ");
    scanf("%d",&p->stdprice);

	printf("Product Rating: ");
    scanf("%d",&p->rate);
    printf("\t<Product Added>\n");
};
// delete product (NULL p)
void deleteProd(Product *p){
	printf("\t<Product {%s} Deleted>\n",p->name);
	p = NULL;
};
// update proudct
void updateProd(Product *p){
	printf("New Product Name: ");
    scanf("%s",p->name);

    printf("New Product Weight: ");
    scanf("%d",&p->weight);
    
    printf("New Product Price: ");
    scanf("%d",&p->price);
    
    printf("New Product Standard Price: ");
    scanf("%d",&p->stdprice);

	printf("New Product Rating: ");
    scanf("%d",&p->rate);
    printf("\t<Product Updated>\n");
};
// read(view) single prouduct
void readProd(Product *p){
	printf("%s \t%4d %5d %d %d\n",p->name,p->weight,p->price,p->stdprice,p->rate);
};
// list all products
void listProd(Product *p[], int count){
	printf("No. Name \tWeight Price Stdprice Rating\n");
	for(int i = 0; i<count; i++){
		if(p[i]!=NULL){
			printf("%2d  ",i+1);
			readProd(p[i]);
		}
	}
};


// read user choice, return it
int chooseProd(Product *p[], int count){
	
	listProd(p,count);

	int choice = getIntLim("Enter a number: ",0,count);
	
	int conf = getIntLim("Confirm? (0:No 1:Yes): ",0,1);
	if(conf == 0)
		choice = 0;
	
	return choice;
};

//search by name
void searByName(Product *p[], int count, char *name){
	printf("No. Name \tWeight Price Stdprice Rating\n");
	for(int i = 0; i<count; i++){
		if(strstr(name,p[i]->name)){
			printf("%2d  ",i+1);
			readProd(p[i]);
		}
	}
};

//search by rating
void searByRate(Product *p[], int count, int rating){
	printf("No. Name \tWeight Price Stdprice Rating\n");
	for(int i = 0; i<count; i++){
		if(p[i]->rate==rating){
			printf("%2d  ",i+1);
			readProd(p[i]);
		}
	}
};
//search by price range
void searByPrice(Product *p[], int count, int min_price, int max_price){
	printf("No. Name \tWeight Price Stdprice Rating\n");
	for(int i = 0; i<count; i++){
		if(p[i]->price>=min_price&&p[i]->price<=max_price){			
			printf("%2d  ",i+1);
			readProd(p[i]);
		}
	}
};
// load other search function & search input
void searchProd(Product *p[], int count){
	int sel = getIntLim("Choose a search method \n(0:quit 1:by Name 2:by Rating 3:by price): ",0,3);
	
	switch (sel){
	
	case 1:{
		char keyw[20];
		printf("Enter a keyword: ");
		scanf("%s",keyw);

		searByName(p,count,keyw);

		break;
	}

	case 2:{
		int r = getIntLim("Enter rating (1~5): ",1,5);

		searByRate(p,count,r);

		break;
	}

	case 3:{
		int min = getIntLim("Enter minimum price: ",0,INT_MAX);
		int max = getIntLim("Enter maximum price: ",min,INT_MAX);

		searByPrice(p,count,min,max);

		break;
	}
	default:
		break;
	}

};

int mainMenu(){
	printf("\n\n==================\n");
	printf("\tMENU\n");
	printf("==================\n");
	printf(" 1. List product\n");
	printf(" 2. Add product\n");
	printf(" 3. Update product\n");
	printf(" 4. Delete product\n");
	printf(" 5. Search product\n");
	printf(" 6. Save\n");
	printf(" 0. Quit\n");
	printf("==================\n");
	int men = getIntLim("\tEnter a number: ",0,6);
	return men;
}

#if 1
int main(){
	Product *p[1];
	int c = readF(p,"products.txt");
	int sel = -1;
	
	while (1){
		sel = mainMenu();

		switch (sel){
		
		case 1:
			if(c>0)
				listProd(p,c);
			break;
		
		case 2:
			p[0] = (Product*)malloc(sizeof(Product));
			createProd(p[0]);
			c++;
			break;
		
		case 3:
			if(c>0){
				int s = chooseProd(p,c);
				if(s>0)
					updateProd(p[s-1]);
			}
			break;

		case 4:{
			if(c>0){
				int s = chooseProd(p,c);
				if (s>0)
					deleteProd(p[s-1]);
			}
			break;
		}
		case 5:
			if(c>0){
				searchProd(p,c);
			}
			break;
		
		case 6:
			if(c>0)
				saveF(p,c,"products.txt");
			break;

		default:
			break;
		}

		if(sel==0)
			break;
	}
	printf("\t[Program Shut Down]");
	for(int i =0 ; i<c ; i++)
		free(p[i]);
}
#endif