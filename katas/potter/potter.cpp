#include <iostream>
using namespace std;

#define ORIGINAL_PRICE_OF_ONE_BOOK 8

double getDiscountedPrice(int differentBooks);
void findBiggestDiscountedPrice(int book1Count, int book2Count, int book3Count, int book4Count, int book5Count);
int findMinOfSameTypeBooks(int book1Count, int book2Count, int book3Count, int book4Count, int book5Count);
int minAboveZero(int a, int b);
int countTypesOfBooksStillPresent(int book1Count, int book2Count, int book3Count, int book4Count, int book5Count);
void decrementBooksByCount(int decrementCount, int &book1Count, int &book2Count, int &book3Count, int &book4Count, int &book5Count);

int main()
{
	int book1Count = 0, book2Count = 0, book3Count = 0, book4Count= 0, book5Count = 0;
	
	cout << "Enter the number of copies of first book in the cart" << endl;
	cin >> book1Count;
	
	cout << "Enter the number of copies of second book in the cart" << endl;
	cin >> book2Count;
	
	cout << "Enter the number of copies of third book in the cart" << endl;
	cin >> book3Count;
	
	cout << "Enter the number of copies of fourth book in the cart" << endl;
	cin >> book4Count;
	
	cout << "Enter the number of copies of fifth book in the cart" << endl;
	cin >> book5Count;
	
	findBiggestDiscountedPrice(book1Count, book2Count, book3Count, book4Count, book5Count);	
}

double getDiscountedPrice(int differentBooks)
{
	double discountedPrice = ORIGINAL_PRICE_OF_ONE_BOOK;
	switch(differentBooks)
	{
		case 1: discountedPrice = ORIGINAL_PRICE_OF_ONE_BOOK;
				break;
				
		case 2: discountedPrice = ORIGINAL_PRICE_OF_ONE_BOOK * 2 * .95; //5 %discount
				break;
				
		case 3: discountedPrice = ORIGINAL_PRICE_OF_ONE_BOOK * 3 * .90; //10 %discount
				break; 
		
		case 4: discountedPrice = ORIGINAL_PRICE_OF_ONE_BOOK * 4 * .80; //10 %discount
				break; 
				
		case 5: discountedPrice = ORIGINAL_PRICE_OF_ONE_BOOK * 5 * .75; //10 %discount
				break; 	
				
		default:
				discountedPrice = ORIGINAL_PRICE_OF_ONE_BOOK; 								
	}	
	return discountedPrice;
}

void findBiggestDiscountedPrice(int book1Count, int book2Count, int book3Count, int book4Count, int book5Count)
{
	int setsOfFive = 0;
	int setsOfFour = 0;
	int setsOfThree = 0;
	int setsOfTwo = 0;
	int setsOfOne = 0;
	int sets = 0;
	double price = 0;
	int count = 0;	
	
	int typesOfBooksPresent = countTypesOfBooksStillPresent(book1Count, book2Count, book3Count, book4Count, book5Count);
	
	while(typesOfBooksPresent > 0)
	{
		count = findMinOfSameTypeBooks(book1Count, book2Count, book3Count, book4Count, book5Count);
		switch(typesOfBooksPresent)
		{
		case 5: setsOfFive += count;				
				break;
					
		case 4: setsOfFour += count;				
				break;
				
		case 3: setsOfThree += count;				
				break;
				
		case 2: setsOfTwo += count;				
				break;
		
		case 1: setsOfOne += count;				
				break;
		}	
		decrementBooksByCount(count, book1Count, book2Count, book3Count, book4Count, book5Count);			
		typesOfBooksPresent = countTypesOfBooksStillPresent(book1Count, book2Count, book3Count, book4Count, book5Count);
	}	
	
	//special condition of set of 4 & 4 being better than 5 &3
	if(setsOfFive>0 && setsOfThree>0)
	{
		//turn 5&3 to 4&4
		setsOfFive--;
		setsOfThree--;
		setsOfFour+= 2;	
		
	}
	
	//Total price
	price = setsOfFive * getDiscountedPrice(5) + 
			setsOfFour * getDiscountedPrice(4) +
			setsOfThree * getDiscountedPrice(3) +
			setsOfTwo * getDiscountedPrice(2)+
			setsOfOne * getDiscountedPrice(1);
			
	cout << "Price after biggest discount: " << price << endl;
	cout << "Grouping of books for biggest discount: " << endl;
	
	cout << "Sets of fives: " << setsOfFive << endl;
	cout << "Sets of four: " << setsOfFour << endl;
	cout << "Sets of three: " << setsOfThree << endl;
	cout << "Sets of two: " << setsOfTwo << endl;
	cout << "Sets of one: " << setsOfOne << endl;
}


int findMinOfSameTypeBooks(int book1Count, int book2Count, int book3Count, int book4Count, int book5Count)
{
	//Compare only non-zero elements.	
	return minAboveZero(book1Count, 
						minAboveZero(book2Count, 
							minAboveZero(book3Count, 
								minAboveZero(book4Count, book5Count))));
}

int minAboveZero(int a, int b)
{
	if(a ==0 && b==0)
		return INT_MAX;
	else if(a == 0)
		return b;
	else if(b == 0)
		return a;
	else		
		return min(a,b); //normal min	
}

int countTypesOfBooksStillPresent(int book1Count, int book2Count, int book3Count, int book4Count, int book5Count)
{
	int types = 0;
	if(book1Count > 0)
	{
		types++;
	}
	if(book2Count > 0)
	{
		types++;
	}
	if(book3Count > 0)
	{
		types++;
	}
	if(book4Count > 0)
	{
		types++;
	}
	if(book5Count > 0)
	{
		types++;
	}
	return types;
}


void decrementBooksByCount(int decrementCount, int &book1Count, int &book2Count, int &book3Count, int &book4Count, int &book5Count)
{
	if(book1Count > 0)
		book1Count -= decrementCount;
	if(book2Count > 0)
		book2Count -= decrementCount;
	if(book3Count > 0)
		book3Count -= decrementCount;
	if(book4Count > 0)
		book4Count -= decrementCount;
	if(book5Count > 0)
		book5Count -= decrementCount;		
}