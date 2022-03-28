#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class poker{

	private:
		int number, number_i, line;
		int suit;
		string temp;

	public:
        poker(){
	        number = 0;
    	    number_i = 0;
        	suit = 0;
        	cout<<"Enter How Many Cards Do You Want(From 1 to 52)"<< endl << "The outcome of the cards are random and all are different" << endl;
    	}//Constructor
	 	~poker(){
			cout<<"##########  END  ##########"<< endl<< endl;
		}//Destructor
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

