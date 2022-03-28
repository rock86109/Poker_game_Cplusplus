#include <iostream>
#include"Poker.h"
#include <string>
#include <stdlib.h>



/*
#include <cstdlib>
#include <ctime>
srand(time(NULL));
hand=rand()%4+1;


int main()
{
    int a;
    cin>>a;
    cout<<cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    cin.sync();
}
*/


using namespace std;

int main(){
	double number;
	int number_int;
	int suit = 0;
	poker P;



	while(suit != 1 & suit != 2 & suit != 3 & suit != 4){
        cout << "Enter the suit(1--Spade, 2--Heart, 3--Diamond, 4--Cloud)" << endl;
		cin >> suit ;
	}

	while((number > 13 or number < 1 ) or (number - int (number) != 0)){
        cout << "Enter the number(1-13)" << endl;
		cin >> number ;
		number_int = number;
	}



	P.set(suit, number_int);
	P.show();

	return 0;
}

