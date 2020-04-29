typedef struct{
	char name[20];
	int weight;
	int price;
	int stdprice;
	int rate;
}Product;



// read file name store it in p, return the number of products
int readF(Product *p[],char* filename);
// save products to file
void saveF(Product *p[], int count, char *filename);


// create new prouduct
void createProd(Product *p);
// delete product (NULL p)
void deleteProd(Product *p);
// update proudct
void updateProd(Product *p);
// read(view) single prouduct
void readProd(Product *p);
// list all products
void listProd(Product *p[], int count);


// read user choice, return it
int chooseProd(Product *p[], int count);


// load other search function & search input
void searchProd(Product *p[], int count);
//search by name
void searByName(Product *p[], int count, char *name);
//search by rating
void searByRate(Product *p[], int count, int rating);
//search by price range
void searByPrice(Product *p[], int count, int min_price, int max_price);