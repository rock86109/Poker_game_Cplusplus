#include <iostream>
#include"Poker2.h"
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main(){
	double choose, Num_of_Card = 0.0;
	bool end = 1;
	int count_of_cards = 0;
	int  suit2[52] = {1}, number2[52] = {0}, i, j, k;
	int deck[4][13]={0};
	poker P;

	cout << endl;



	while(end == 1){
		cout << "1:show the cards" << endl << "2:new deck" << endl << "3:end" << endl;
		cin >> choose;
		while(cin.fail() || choose < 1 || choose > 3 || choose - int(choose) > 0){
    		cout << "Please enter the correct number" << endl;
			cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clean the things in the buffer
			cout << endl;
       		cin >> choose;
		}



	switch(int (choose)){
		case 1:

			cout << "enter how many cards you want" << endl;
			cin >> Num_of_Card;
			count_of_cards = count_of_cards + Num_of_Card;

			while(cin.fail() || Num_of_Card <= 0 || Num_of_Card >= 53 || Num_of_Card - int(Num_of_Card)){
    	    cout << "Please enter the correct number" << endl;
			cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clean the things in the buffer
			cout << endl;
        	cin >> Num_of_Card;
			}



			if(count_of_cards > 52){
				cout << "There is no enough card, please ask for a smaller number or end the game or redeck it. " << endl;
				count_of_cards = count_of_cards - Num_of_Card;
				break;
			}

			srand(time(NULL));//Random

			for(i = 0;i < Num_of_Card;i++){
				suit2[i] = rand()%4+1;
				number2[i] = rand()%13+1;

				if(deck[suit2[i]-1][number2[i]-1] == 1){
				i--;
				}//Pretend to get the same card

				deck[suit2[i]-1][number2[i]-1] = 1;//Mark the deck
			}

			for(k = 0;k <= Num_of_Card/10;k++){
				for(i = 1;i <= 9; i++){
					for(j = 0;j < 10; j++){
						if(j+10*k == 52){break;}
						P.set(suit2[j+10*k], number2[j+10*k], i);
						P.show();
					}//Print the same lines of different cards
					cout << endl;
				}//Print the lines seperately
				cout << endl<<endl;
			}//Arrange every ten cards in a row
			Num_of_Card = 0;

			break;

		case 2:
			for(i = 0;i <= 3;i++){
				for(j = 0;j <= 12;j++){
					deck[i][j] = 0;
				}
			}
			count_of_cards = 0;

			break;
		case 3:
			end = 0;
			break;

	}
}

    system("pause > NULL");
	return 0;
}
