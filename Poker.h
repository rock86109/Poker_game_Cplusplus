#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class poker{

	private:

		int number, number_i;
		int suit;
		string temp;

	public:

        poker()
    {
        number=0;
        number_i=0;
        suit='0';
        cout<<number<<number_i<<suit<<endl;
    }



    ~poker(){cout<<"Shit!"<<endl;}
		void set(int s, int n){


            suit = s;
			number = n;
			number_i = n;

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
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
				cout << temp <<"      *      " << setfill(' ') << setw(2) << temp << endl;
    			cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
    			cout << temp <<"  ** *** **  " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<" ***** ***** " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"  **  *  **  " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"      *      " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
			}else if (suit == 2){
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
				cout << temp <<"             " << setfill(' ') << setw(2) << temp << endl;
    			cout << temp <<"   **   **   " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"  **** ****  " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"   *******   " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"    *****    " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"      *      " << setfill(' ') << setw(2) << temp << endl;
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
			}else if (suit == 3){
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
				cout << temp <<"      *      " << setfill(' ') << setw(2) << temp << endl;
    			cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"    *****    " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"   *******   " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"    *****    " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"      *      " << setfill(' ') << setw(2) << temp << endl;
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
			}else if (suit == 4){
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
				cout << temp <<"             " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
    			cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"  **  *  **  " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<" ***** ***** " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"  **  *  **  " << setfill(' ') << setw(2) << temp << endl;
				cout << temp <<"     ***     " << setfill(' ') << setw(2) << temp << endl;
				cout << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3) << temp << setfill(' ') << setw(3)  << temp << setfill(' ') << setw(3) <<  temp << endl;
			}
		}

};

