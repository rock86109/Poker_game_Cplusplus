#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>
#include <algorithm> 
using namespace std;

class poker{

	private:
		static int length, length_com, first_sta;
		int i, j, k, l, choose, read1, read2;
		int deck[4][13] , suit_r[52], number_r[52], cover_suit[26], cover_number[26];
		int com_suit[26], com_num[26];
		int number, number_i, line, r1, r2, suit;
		string temp;

	public:

        poker(){
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<13;j++)
                    deck[i][j]=0;
            }

    	}//Constructor
	 	~poker(){
		}//Destructor

        ////////////////////////////////////////////////////////
		int read_number(int *a, int *b){
			cout << "The suit of the card" << endl << "1:Spade\n2:Heart\n3:Diamond\n4:Cloud" << endl;
			cin >> r1;
			*a = r1;

            while(cin.fail() || r1 < 1 || r1 > 4 || r1 - int(r1) > 0){
                cout << "Please enter the correct number" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clean the things in the buffer
                cout << endl;
                cin >> r1;
            }

			cout << "The number of the card(From 1 to 13)" << endl;
			cin >> r2;
			*b = r2;

            while(cin.fail() || r2 < 1 || r2 > 13 || r2 - int(r2) > 0){
                cout << "Please enter the correct number" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clean the things in the buffer
                cout << endl;
                cin >> r2;
            }
		}

		///////////////////////////////////////////////////////
		void deal(){
			srand(time(NULL));//Random

			for(i = 0;i < 52;i++){
				suit_r[i] = rand()%4+1;
				number_r[i] = rand()%13+1;
				if(suit_r[i] == 1 && number_r[i] == 7 && i < 26){first_sta = 1;}
				if(deck[suit_r[i]-1][number_r[i]-1] == 1){
				i--;
				}//Pretend to get the same card

				deck[suit_r[i]-1][number_r[i]-1] = 1;//Mark the deck
			}

			for(i = 26;i < 52;i++){
				com_suit[i-26] = suit_r[i];
				com_num[i-26] = number_r[i];
			}//record computer's card
		}
		///////////////////////////////////////////////////////
		void hand(){
			poker P;
        	cout<</*"Start!!"<<*/ endl << "The cards you have : " << endl;
			for(l = 0;l <= 1;l++){
				for(k = 0;k <= 2;k++){
					for(i = 1;i <= 9; i++){
						for(j = 0;j < 10; j++){
							if(j+10*k == length || (length < 10 && k == 1) || (length < 20 && k == 2) ){break;}
							P.set(suit_r[j+10*k], number_r[j+10*k], i);

							if(l == 0){P.show();}
						}//Print the same lines of different cards
						if(l == 0){cout << endl;}
					}//Print the lines seperately
				//	cout << endl<<endl;
				}
			}

		}
		//////////////////////////////////////////////////////
		void com_hand(){
 			poker P;
        	cout<</*"Start!!"<<*/ endl << "The cards computer has : " << endl;
			for(l = 0;l <= 1;l++){
				for(k = 0;k <= 2;k++){
					for(i = 1;i <= 9; i++){
						for(j = 0;j < 10; j++){
							if(j+10*k == length_com || (length_com < 10 && k == 1) || (length_com < 20 && k == 2) ){break;}
							P.set(com_suit[j+10*k], com_num[j+10*k], i);

							if(l == 0){P.show();}
						}//Print the same lines of different cards
						if(l == 0){cout << endl;}
					}//Print the lines seperately
				//	cout << endl<<endl;
				}
			}

		}
		//////////////////////////////////////////////////////
		int whofirst(){
			if(first_sta == 1){cout << "Your turn" << endl;}else{cout << "Computer's turn" << endl;}
            return first_sta;
		}
		//////////////////////////////////////////////////////
		//search the cards that computer can used
		void searchcom(int can_use_suit[], int can_use_number[] , int s1[], int s2[], int n1[], int n2[], int seven_s[], int seven_n[],int *length = 0){
			int j = 0, k =0;
			for(i = 0;i < length_com;i++){
				if(com_num[i] == 7 || (com_suit[i] == 1 && com_num[i] == n1[0]+1 && n1[0] != 0)|| (com_suit[i] == 1 && com_num[i] == n2[0]-1 && n2[0] != 0) || (com_suit[i] == 2 && com_num[i] == n1[1]+1 && n1[1] != 0) || (com_suit[i] == 2 && com_num[i] == n2[1]-1 && n2[1] != 0)
                    || (com_suit[i] == 3 && com_num[i] == n1[2]+1 && n1[2] != 0) || (com_suit[i] == 3 && com_num[i] == n2[2]-1 && n2[2] != 0) || (com_suit[i] == 4 && com_num[i] == n1[3]+1 && n1[3] != 0) || (com_suit[i] == 4 && com_num[i] == n2[3]-1 && n2[3] != 0)
                        || (seven_n[0] == 7 && com_suit[i] == 1 && com_num[i] == 6) || (seven_n[0] == 7 && com_suit[i] == 1 && com_num[i] == 8)
                            || (seven_n[1] == 7 && com_suit[i] == 2 && com_num[i] == 6) || (seven_n[1] == 7 && com_suit[i] == 2 && com_num[i] == 8)
                                || (seven_n[2] == 7 && com_suit[i] == 3 && com_num[i] == 6) || (seven_n[2] == 7 && com_suit[i] == 3 && com_num[i] == 8)
                                    || (seven_n[3] == 7 && com_suit[i] == 4 && com_num[i] == 6) || (seven_n[3] == 7 && com_suit[i] == 4 && com_num[i] == 8)){

					can_use_suit[j++] = com_suit[i];
					can_use_number[k++] = com_num[i];
					*length = *length +1;
					
					
				}
				if(com_suit[i] == 1 && com_num[i] == 7){
					can_use_suit[0] = com_suit[i];
					can_use_number[0] = com_num[i];
					*length = 1;
					break;
				}
			}
//			cout << s1[0] << "  " << s2[0] << "  " << n1[0] << "  " << n2[0] << "  " << seven_s[0] << "  " << seven_n[0] << endl << endl << endl;
		}


		//////////////////////////////////////////////////////


		//////////////////////////////////////////////////////
		//remove the card which I decide to use
		void remove_use(int r1, int r2, int *temp2){
		    *temp2 = -1;
			for(i = 0;i < length;i++){
				if(suit_r[i] == r1 && number_r[i] == r2){
                    *temp2 = i;
					suit_r[i] = suit_r[length-1];
					number_r[i] = number_r[length-1];
				}
			}
			if(*temp2 == -1){
                length++;
                cout << "You don't have this card." << endl;
            }
			length--;
        }



		//////////////////////////////////////////////////////

		//////////////////////////////////////////////////////
		//remove the card which comuter decided to use
		void comremove_use(int r1, int r2, int *temp2){
		    *temp2 = -1;
			for(i = 0;i < length_com;i++){
				if(com_suit[i] == r1 && com_num[i] == r2){
                    *temp2 = i;
					com_suit[i] = com_suit[length_com-1];
					com_num[i] = com_num[length_com-1];
				}
			}
			if(*temp2 == -1){
                length_com++;
                cout << "You don't have this card." << endl;
            }
			length_com--;
		}

		//////////////////////////////////////////////////////
		//remove the card which computer decided to cover
        void comremove_cover(int a, int b){
            for(i = 0;i < length_com;i++){
                if(com_suit[i] == a && com_num[i] == b){
					com_suit[i] = com_suit[length_com-1];
					com_num[i] = com_num[length_com-1];
                }
            }
 			length_com--;
        }

		//////////////////////////////////////////////////////
		//remover the card which I want to cover and record the cover card
        void remove_cover(int r1, int r2, int cover_suit[], int cover_number[], int *temp4, int *playertotal){
            *temp4 = -1;
            int temp3 = 0;
			for(i = 0;i < length;i++){
				if(suit_r[i] == r1 && number_r[i] == r2){
                    *temp4 = i;
					cover_suit[temp3] = r1;
					cover_number[temp3] = r2;
					*playertotal = *playertotal + cover_number[temp3];
					temp3++;					
					suit_r[i] = suit_r[length-1];
					number_r[i] = number_r[length-1];
				}
			}
			if(*temp4 == -1){
                length++;
                cout << "You don't have this card." << endl;
            }
			length--;
        }

		/////////////////////////////////////////////////////
		//decided which card to cover					
		void com_cover(int *c_cover_s, int *c_cover_n){

			int *min = std::min_element(com_num, com_num+length_com);
            for(i = 0;i < length;i++){
                if(com_num[i] == *min){
                    *c_cover_s = com_suit[i];
                    *c_cover_n = com_num[i];
                    break;
                }
            }
		}



		/////////////////////////////////////////////////////
		void court(int s1[], int n1[], int s2[], int n2[], int seven_s[], int seven_n[]){
			poker P;
        	cout << "The cards on the court : " << endl;
			for(i = 0;i <= 9;i++){
				for(j = 0;j < 4;j++){
					P.set(s1[j], n1[j], i);
					P.show();
				}
				cout << endl;
			}
			for(i = 0;i <= 9;i++){
				for(j = 0;j < 4;j++){
					P.set(seven_s[j], seven_n[j], i);
					P.show();
				}
				cout << endl;
			}
			for(i = 0;i <= 9;i++){
				for(j = 0;j < 4;j++){
					P.set(s2[j], n2[j], i);
					P.show();
				}
				cout << endl;
			}
		}
		/////////////////////////////////////////////////////
		void set(int s, int n, int l){
            suit = s;
			number = n;
			number_i = n;
			line = l;

			if(n == 1){
				number = 'A';
			}else if(n == 11){
				number = 'J';
			}else if(n == 12){
				number = 'Q';
			}else if(n == 13){
				number = 'K';
			}
		}

		void show(){
 			if(number == 10){
				temp = "10";
			}else if(number_i == 1 or number_i == 11 or number_i ==12 or number_i ==13){
				temp = char(number);
			}else {
				number = number+48;
				temp = char(number);
			}


			if(suit == 1){
				switch(line){
					case 1:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
					case 2:cout << temp <<"      *      " << setfill(' ') << setw(2) << temp ;
    				break;
					case 3:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
    				break;
					case 4:cout << temp <<"  ** *** **  " << setfill(' ') << setw(2) << temp ;
					break;
					case 5:cout << temp <<" ***** ***** " << setfill(' ') << setw(2) << temp ;
					break;
					case 6:cout << temp <<"  **  *  **  " << setfill(' ') << setw(2) << temp ;
					break;
					case 7:cout << temp <<"      *      " << setfill(' ') << setw(2) << temp ;
					break;
					case 8:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
					break;
					case 9:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
				}

			}
			if (suit == 2){
				switch(line){
					case 1:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
					case 2:cout << temp <<"             " << setfill(' ') << setw(2) << temp ;
					break;
					case 3:cout << temp <<"   **   **   " << setfill(' ') << setw(2) << temp ;
					break;
					case 4:cout << temp <<"  **** ****  " << setfill(' ') << setw(2) << temp ;
					break;
					case 5:cout << temp <<"   *******   " << setfill(' ') << setw(2) << temp ;
					break;
					case 6:cout << temp <<"    *****    " << setfill(' ') << setw(2) << temp ;
					break;
					case 7:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
					break;
					case 8:cout << temp <<"      *      " << setfill(' ') << setw(2) << temp ;
					break;
					case 9:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
				}
			}
			if (suit == 3){
				switch(line){
					case 1:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
					case 2:cout << temp <<"      *      " << setfill(' ') << setw(2) << temp ;
					break;
					case 3:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
					break;
					case 4:cout << temp <<"    *****    " << setfill(' ') << setw(2) << temp ;
					break;
					case 5:cout << temp <<"   *******   " << setfill(' ') << setw(2) << temp ;
					break;
					case 6:cout << temp <<"    *****    " << setfill(' ') << setw(2) << temp ;
					break;
					case 7:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
					break;
					case 8:cout << temp <<"      *      " << setfill(' ') << setw(2) << temp ;
					break;
					case 9:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
				}
			}
			if (suit == 4){
				switch(line){
					case 1:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
					case 2:cout << temp <<"             " << setfill(' ') << setw(2) << temp ;
					break;
					case 3:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
					break;
					case 4:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
					break;
					case 5:cout << temp <<"  **  *  **  " << setfill(' ') << setw(2) << temp ;
					break;
					case 6:cout << temp <<" ***** ***** " << setfill(' ') << setw(2) << temp ;
					break;
					case 7:cout << temp <<"  **  *  **  " << setfill(' ') << setw(2) << temp ;
					break;
					case 8:cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp ;
					break;
					case 9:cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp ;
					break;
				}
			}
		}

};
