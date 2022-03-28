#include <iostream>
#include"Poker3-2.h"
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;


int poker::length = 26;
int poker::length_com = 26;
int poker::first_sta = 0;
int main(){
	int i, j, k, l, choose, read1, read2, first, mytotal = 0, total = 0, total_times = 0, temp = -1;
	int c_cover_s, c_cover_n;
	int deck[4][13] = {0}, suit_r[52], number_r[52], cover_s[13] = {0}, cover_n[13] = {0}, n1[4] = {0}, n2[4] = {0}, seven_n[13] = {0}, s1[4] = {1, 2, 3, 4}, s2[4] = {1, 2, 3, 4}, seven_s[4] = {1, 2, 3, 4};
	int can_use_suit[26], can_use_number[26];
	bool endi = 1, com_move = 1;
	poker P;


	P.deal();
	P.hand();
	P.court(s1, n1, s2, n2, seven_s, seven_n);
    first = P.whofirst();
	if(first == 1){
		cout << "The first card should be the 7 of Spade" << endl;
	}
	//P.com_hand();
	////////////////////////////////////////////////////////////

	while(endi == 1){
 		if(first == 1){

			cout << "1:I have cards to use" << endl << "2:I don't have any card can be used"  << endl << "3:Show my cards" << endl << "4:Show the cards on court" << endl << "5:End" << endl;
			cin >> choose;
			while(cin.fail() || choose < 1 || choose > 5 || choose - int(choose) > 0){
    			cout << "Please enter the correct number" << endl;
				cin.clear();
	    		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clean the things in the buffer
				cout << endl;
       			cin >> choose;
			}

			switch(choose){
				case 1:
			    	temp = -1;
			    	while(temp == -1){
                    	P.read_number(&read1, &read2);
                	    P.remove_use(read1, read2, &temp);
			    	}
					if(temp != -1){
						switch(read2){
							case 13:
								n1[read1-1] = 13;break;
							case 12:
								n1[read1-1] = 12;break;
							case 11:
								n1[read1-1] = 11;break;
							case 10:
								n1[read1-1] = 10;break;
							case 9:
								n1[read1-1] = 9;break;
							case 8:
								n1[read1-1] = 8;break;
							case 7:
								seven_n[read1-1] = 7;break;
							case 6:
								n2[read1-1] = 6;break;
							case 5:
								n2[read1-1] = 5;break;
							case 4:
								n2[read1-1] = 4;break;
							case 3:
								n2[read1-1] = 3;break;
							case 2:
								n2[read1-1] = 2;break;
							case 1:
								n2[read1-1] = 1;break;
						}
					}
					P.court(s1, n1, s2, n2, seven_s, seven_n);

             	   com_move = 1;
            	    first = 0;
				break;

				case 2:
				    temp = -1;
				    while(temp == -1){
            	        P.read_number(&read1, &read2);
            	        P.remove_cover(read1, read2, cover_s, cover_n, &temp, &mytotal);
				    }
            	    com_move = 1;
            	    first = 0;
				break;

				case 3:
					P.hand();
            	    com_move = 0;
            	    first = 1;
            	    total_times--;
				break;

				case 4:
					P.court(s1, n1, s2, n2, seven_s, seven_n);
            	    com_move = 0;
            	    first = 1;
            	    total_times--;
				break;

				case 5:
					endi = 0;
            	    com_move = 0;
				break;
			}
		}//if

		if(first != 1 && com_move == 1){
    	    int length = 0;
			P.searchcom(can_use_suit, can_use_number, s1, s2, n1, n2, seven_s, seven_n, &length);

			if(length == 0){
	            P.com_cover(&c_cover_s, &c_cover_n);
	            P.comremove_cover(c_cover_s, c_cover_n);
		        total = total + c_cover_n;
			}else{
    	    	int c = rand()%length;
        	    cout  << c << endl << can_use_suit[c] << endl << can_use_number[c] << endl << endl;
				P.comremove_use(can_use_suit[c], can_use_number[c], &temp);

				switch(can_use_number[c]){
					case 13:
						n1[can_use_suit[c]-1] = 13;break;
					case 12:
						n1[can_use_suit[c]-1] = 12;break;
					case 11:
						n1[can_use_suit[c]-1] = 11;break;
					case 10:
						n1[can_use_suit[c]-1] = 10;break;
					case 9:
						n1[can_use_suit[c]-1] = 9;break;
					case 8:
						n1[can_use_suit[c]-1] = 8;break;
					case 7:
						seven_n[can_use_suit[c]-1] = 7;break;
					case 6:
						n2[can_use_suit[c]-1] = 6;break;
					case 5:
						n2[can_use_suit[c]-1] = 5;break;
					case 4:
						n2[can_use_suit[c]-1] = 4;break;
					case 3:
						n2[can_use_suit[c]-1] = 3;break;
					case 2:
						n2[can_use_suit[c]-1] = 2;break;
					case 1:
						n2[can_use_suit[c]-1] = 1;break;
				}
        	}

			P.court(s1, n1, s2, n2, seven_s, seven_n);
            total_times++;
//cout << "-----------------------------------" << total_times << "-----------" <<  endl;

			if(total_times >= 52){
        	    cout << "finished, computer total:" << total << endl;
        	    break;
        	}
			first = 1;
		}

		total_times++;
//cout << "-----------------------------------" << total_times << "-----------" <<  endl;
		if(total_times >= 53){
   			cout << "finished, computer total:" << total << endl;
    		break;
		}

	}//while
   	if(mytotal > total){cout << "You Lose!!" << endl;}
   	if(mytotal < total){cout << "You win!!" << endl;}
   	if(mytotal == total){cout << "Even" << endl;}
	cout << "Finished, your total:" << mytotal << "computer total:" << total << endl << endl;

    system("pause > NULL");
	return 0;
}


