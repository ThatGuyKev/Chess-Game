		//Chess game made by Ahmed Abdalla
		#include<iostream>
		#include<string>
		#include<fstream>
		#include <stdio.h>
		#include <stdlib.h>
		
		#define pawn 100
		#define bishop 300
		#define knight 200
		#define rook 400
		#define queen 1000
		#define king 2000
		#define Player1 1
		#define Player2 2
		#define a 11
		#define b 12
		#define c 13
		#define d 14
		#define e 15
		#define f 16
		#define g 17
		#define h 18
		
		// Declaring and defining the bard setup
		const int startup[10][10] = { 10,10,a,b,c,d,e,f,g,h,10,10,10,10,10,10,10,10,10,10,1,10,rook, knight, bishop, queen, king, bishop, knight, rook, 2,10,pawn, pawn,pawn,pawn,pawn,pawn,pawn, pawn,3,10, 0, 0, 0, 0, 0, 0, 0, 0,4,10, 0, 0, 0, 0, 0, 0, 0, 0,5,10, 0, 0, 0, 0, 0, 0, 0, 0,6, 10, 0, 0, 0, 0, 0, 0, 0, 0,7,10, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn,8,10, -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};
		int board[10][10];
		
		//Declaring Functions
		void setup(); //Function to reset the game and start from the beginnig
		void printb(); //Function to print the current board
		void undo(); //Function to undo Last game
		void save(); //Function to save the game into a file 
		void load(); //Function to load the game from a file
		void Player1Movement(); // Function to perform a play for a Player1 with validation
		void Player2Movement(); // Function to perform a play for a Player with validation
		
		// Variables to deffrentiate between players and to assist in movements
		int currentPlayer, countPlayer=1,check;
		
		// Variables of the x axies and y axies for the position and destination
		int x1, y1, x2, y2, move;
		
		//**************************************************************************************************************************
		//..............................Begining of the main function...............................................................
		int main (){
		
		using namespace std;
		
		cout << "Please enter your moves in 4 letter algebraic" << endl << "Example b1a3 in lower case only" << endl;
		cout << "Commands: exit = quit, abort = quit, print = displays the board," << endl << "new = new game, undo = undo \nNote!: You can undo only one time." << endl << endl;
		
		string passd;
		setup();
		
		while (1)
		{
		getline (cin, passd );
		 if (passd.substr(0, 4) == "exit" || passd.substr(0, 5) == "abort" || passd.substr(0, 4) == "quit"){
		  break;
		 }
		
		 if (passd.substr(0, 5) == "print"){
		  printb();
		 }
		 if (passd.substr(0, 4) == "undo"){
		  undo();
		}
		if (passd.substr(0, 4) == "load"){
		  load();
		}
		 if (passd.substr(0, 3) == "new"){
		 setup();
		 }
		 if (passd.substr(0, 4) == "save"){
		 save();
		 }
		 if (passd.substr(0, 1) >= "a" && passd.substr(0, 1) <= "h" && passd.substr(1, 1) >= "1" && passd.substr(1, 1) <= "8" && passd.substr(2, 1) >= "a" && passd.substr(2, 1) <= "h" && passd.substr(3, 1) >= "1" && passd.substr(3, 1) <= "8") {
			x1 = passd[0] - 'a' +2;
			y1 = passd[1] - '1' +2;
			x2 = passd[2] - 'a' +2;
			y2 = passd[3] - '1' +2;
			if (countPlayer%2 ==0){
			currentPlayer =Player2;
		}
		else
		{
			currentPlayer = Player1;
		}
			if (currentPlayer == Player1){
				Player1Movement();
				countPlayer++;
			}
			if (currentPlayer == Player2){
				Player2Movement();
				countPlayer++;
			}
		
		
			
				 }
		
		
				}
		
		}
		// .............................End of the main Functoin....................................................................
		
		//**************************************************************************************************************************
		//..............................Start of the setup funcion..................................................................
		void setup (){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				board[i][j] = startup[i][j];
		}
		
			}
			countPlayer =0;
			printb();
		}
		// .............................End of the setup Functoin....................................................................
		
		//***************************************************************************************************************************
		//..............................Start of the printb funcion..................................................................
		void printb(){
		using namespace std;
		string piece;
		for (int i = 9; i > -1; i--){
			for (int j = 0; j < 10; j++){
				switch (board[i][j]){
					case 0:
					piece = "-";
					break;
					case 10:
					piece = " ";
					break;
					case 1:
					piece = "1";
					break;
					case 2:
					piece = "2";
					break;
					case 3:
					piece = "3";
					break;
					case 4:
					piece = "4";
					break;
					case 5:
					piece = "5";
					break;
					case 6:
					piece = "6";
					break;
					case 7:
					piece = "7";
					break;
					case 8:
					piece = "8";
					break;
					case a:
					piece = "a";
					break;
					case b:
					piece = "b";
					break;
					case c:
					piece = "c";
					break;
					case d:
					piece = "d";
					break;
					case e:
					piece = "e";
					break;
					case f:
					piece = "f";
					break;
					case g:
					piece = "g";
					break;
					case h:
					piece = "h";
					break;
					case pawn:
					piece = "P";
					break;
					case knight:
					piece = "N";
					break;
					case bishop:
					piece = "B";
					break;
					case rook:
					piece = "R";
					break;
					case queen:
					piece = "Q";
					break;
					case king:
					piece = "K";
					break;
					case -pawn:
					piece = "p";
					break;
					case -knight:
					piece = "n";
					break;
					case -bishop:
					piece = "b";
					break;
					case -rook:
					piece = "r";
					break;
					case -queen:
					piece = "q";
					break;
					case -king:
					piece = "k";
					break;
		
		 }
		  cout << " " << piece << " ";
		 }
		  cout<< endl ;
		}
		
		
		cout << endl << endl;
		
		}
		// .............................End of the printb Functoin....................................................................
		
		//***************************************************************************************************************************
		//..............................Start of the undo funcion..................................................................
		void undo(){
		
			board[y1][x1] = board[y2][x2];
			board[y2][x2] = move;
			printb();
			countPlayer--;
		
		}
		// .............................End of the undo Functoin....................................................................
		
		//*************************************************************************************************************************
		//..............................Start of the save funcion..................................................................
		void save(){
			using namespace std;
			ofstream chessfile;
			chessfile.open ("chessfile.dat");
			chessfile << countPlayer<<" ";
			for (int i = 0; i < 10; i++){
				for (int j = 0; j < 10; j++){
					chessfile<<board[i][j]<<" ";
				}
		
			}
			chessfile<<endl;
			chessfile.close();
		}
		// .............................End of the save Functoin....................................................................
		
		//*************************************************************************************************************************
		//..............................Start of the load funcion..................................................................
		void load(){
			
			FILE *loadfile;
			int array1[10][10];
			int loadplayer;
			char buf[9999];
			
			loadfile = fopen("chessfile.dat", "r");
			
			
			fgets(buf, sizeof(buf), loadfile);
			sscanf(buf, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ", &loadplayer, &array1[0][0],&array1[0][1],&array1[0][2],&array1[0][3],&array1[0][4],&array1[0][5],&array1[0][6],&array1[0][7],&array1[0][8],&array1[0][9], &array1[1][0],&array1[1][1],&array1[1][2],&array1[1][3],&array1[1][4],&array1[1][5],&array1[1][6],&array1[1][7],&array1[1][8],&array1[1][9], &array1[2][0],&array1[2][1],&array1[2][2],&array1[2][3],&array1[2][4],&array1[2][5],&array1[2][6],&array1[2][7],&array1[2][8],&array1[2][9], &array1[3][0],&array1[3][1],&array1[3][2],&array1[3][3],&array1[3][4],&array1[3][5],&array1[3][6],&array1[3][7],&array1[3][8],&array1[3][9], &array1[4][0],&array1[4][1],&array1[4][2],&array1[4][3],&array1[4][4],&array1[4][5],&array1[4][6],&array1[4][7],&array1[4][8],&array1[4][9],&array1[5][0],&array1[5][1],&array1[5][2],&array1[5][3],&array1[5][4],&array1[5][5],&array1[5][6],&array1[5][7],&array1[5][8],&array1[5][9], &array1[6][0],&array1[6][1],&array1[6][2],&array1[6][3],&array1[6][4],&array1[6][5],&array1[6][6],&array1[6][7],&array1[6][8],&array1[6][9], &array1[7][0],&array1[7][1],&array1[7][2],&array1[7][3],&array1[7][4],&array1[7][5],&array1[7][6],&array1[7][7],&array1[7][8],&array1[7][9], &array1[8][0],&array1[8][1],&array1[8][2],&array1[8][3],&array1[8][4],&array1[8][5],&array1[8][6],&array1[8][7],&array1[8][8],&array1[8][9], &array1[9][0],&array1[9][1],&array1[9][2],&array1[9][3],&array1[9][4],&array1[9][5],&array1[9][6],&array1[9][7],&array1[9][8],&array1[9][9]);
			
			
			fclose(loadfile);
			countPlayer = loadplayer;
			for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				board[i][j] = array1[i][j];
		}
		
			}
			printb();
		}
		// .............................End of the load Functoin....................................................................
		
		//*****************************************************************************************************************************
		//..............................Start of the Player1Movement funcion...........................................................
		void Player1Movement(){
			using namespace std;
			if (board[y2][x2] > 0){
				cout<<"invalid move \n";
				countPlayer--;
			}else{
		
				switch (board[y1][x1]){
					case 0:
					cout<<"Empty space \n";
					countPlayer--;
					break;
					case pawn:
					if (board[y2][x2] <0){
						if((y2 == y1+1 && x2 == x1+1) ||(y2 == y1+1 && x2== x1-1)){
							board[y2][x2] = board[y1][x1];
							board[y1][x1] = 0;
						
							cout<<endl<<countPlayer<<endl;printb();
							break;
						}
					}
					if (board[y2][x2] == 0){
		
						if (y1 == 3){
							if ((y2 == y1+1 && x1 == x2) || (y2  == y1+2 && x1 ==x2)){
								board[y2][x2] = board[y1][x1];
								board[y1][x1] = 0;
								cout<<endl<<countPlayer<<endl;printb();
								break;
							}
						}
						if (y2 == y1+1 && x1 == x2){
							board[y2][x2] = board[y1][x1];
							board[y1][x1] = 0;
							cout<<endl<<countPlayer<<endl;printb();
							break;
						}
					}
					cout<<"invalid move pawn \n";
					countPlayer--;
					break;
					case knight:
					if ((x2 == x1+2) && (y2 == y1+1)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ((x2 == x1+1) && (y2 == y1+2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ((x2 == x1-2) && (y2 == y1-1)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ((x2 == x1+2) && (y2 == y1-1)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ( (x2 == x1-1) && (y2 == y1+2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
						if ( (x2 == x1-1) && (y2 == y1-2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move knight \n";
					countPlayer--;
					break;
					case bishop:
					if (x2+y1 == x1+y2 ){
						check =0;
						for (int i=y2-1;i>y1;i--){
							for(int j=x2-1;j>x1;j--){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						for (int i=y2+1;i<y1;i++){
							for(int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y2-y1 ){
						check =0;
						cout<<"2";
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y1-y2){
						check =0;
						for (int i =y2-1;i>y1;i--){
							for (int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move bishop \n";
					countPlayer--;
					break;
					case rook:
					if (x1 == x2 ){
						if (y2 > y1){
							check = 0;
							for(int i=y2-1;i>y1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
		
						}
						if (y2 < y1)	{
							check=0;
							for(int i=y2+1;i<y1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
		
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
		
					board[y2][x2] = board[y1][x1];
					board[y1][x1] = 0;
					cout<<endl<<countPlayer<<endl;printb();
					break;
					}
					if (y1==y2){
						if (x2 > x1){
							check=0;
							for(int i=x2-1;i>x1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
						}
						if (x2 < x1)	{
							check=0;
							for(int i=x2+1;i<x1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move rook \n";
					countPlayer--;
					break;
					case queen:
					if (x2+y1 == x1+y2 ){
						check =0;
						for (int i=y2-1;i>y1;i--){
							for(int j=x2-1;j>x1;j--){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						for (int i=y2+1;i<y1;i++){
							for(int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y2-y1 ){
						check =0;
						cout<<"2";
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y1-y2){
						check =0;
						for (int i =y2-1;i>y1;i--){
							for (int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x1 == x2 ){
						if (y2 > y1){
							check = 0;
							for(int i=y2-1;i>y1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
		
						}
						if (y2 < y1)	{
							check=0;
							for(int i=y2+1;i<y1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
		
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
		
					board[y2][x2] = board[y1][x1];
					board[y1][x1] = 0;
					cout<<endl<<countPlayer<<endl;printb();
					break;
					}
					if (y1==y2){
						if (x2 > x1){
							check=0;
							for(int i=x2-1;i>x1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
						}
						if (x2 < x1)	{
							check=0;
							for(int i=x2+1;i<x1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move queen \n";
					countPlayer--;
					break;
					case king:
					if ((-2>x2-x1<2)  && (-2>y2-y1<2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move king \n";
					countPlayer--;
					break;
					default:
						cout<<"invalid move \n";
						countPlayer--;
						break;
			}
					}
		}
		// .............................End of the Player1Movement Functoin............................................................
		
		//******************************************************************************************************************************
		//..............................Start of the Player2Movement funcion............................................................
		void Player2Movement(){
			using namespace std;
			if (board[y2][x2] < 0){
				cout<<"invalid move \n";
				countPlayer--;
			}else{
			switch (board[y1][x1]){
		
				case -pawn:
					if (board[y2][x2] >0){
						if((y2 == y1-1 && x2 == x1+1) ||(y2 == y1-1 && x2== x1-1)){
							board[y2][x2] = board[y1][x1];
							board[y1][x1] = 0;
							cout<<endl<<countPlayer<<endl;printb();
							break;
						}
					}
					if (board[y2][x2] == 0){
						if (y1 ==8){
							if ((y2 == y1-1 && x1==x2) || (y2 == y1-2 && x1==x2)){
							board[y2][x2] = board[y1][x1];
							board[y1][x1] = 0;
							cout<<endl<<countPlayer<<endl;printb();
							break;
						}
						}
						if (y2 == y1-1 && x1==x2){
							board[y2][x2] = board[y1][x1];
							board[y1][x1] = 0;
							cout<<endl<<countPlayer<<endl;printb();
							break;
						}
		
					}
			cout<<"invalid move -pawn \n";
			countPlayer--;
					break;
					case -knight:
					if ((x2 == x1+2) && (y2 == y1+1)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ((x2 == x1+1) && (y2 == y1+2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ((x2 == x1-2) && (y2 == y1-1)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ((x2 == x1+2) && (y2 == y1-1)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ( (x2 == x1-1) && (y2 == y1+2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ((x2 == x1-2) && (y2 == y1+1)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if ( (x2 == x1+1) && (y2 == y1-2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
						if ( (x2 == x1-1) && (y2 == y1-2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move -knight \n";
					countPlayer--;
					break;
					case -bishop:
				if (x2+y1 == x1+y2 ){
						check =0;
						for (int i=y2-1;i>y1;i--){
							for(int j=x2-1;j>x1;j--){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						for (int i=y2+1;i<y1;i++){
							for(int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y2-y1 ){
						check =0;
						cout<<"2";
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y1-y2){
						check =0;
						for (int i =y2-1;i>y1;i--){
							for (int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move -bishop \n";
					countPlayer--;
					break;
					case -rook:
					if (x1 == x2 ){
						if (y2 > y1){
							check = 0;
							for(int i=y2-1;i>y1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
		
						}
						if (y2 < y1)	{
							check=0;
							for(int i=y2+1;i<y1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
		
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
		
					board[y2][x2] = board[y1][x1];
					board[y1][x1] = 0;
					cout<<endl<<countPlayer<<endl;printb();
					break;
					}
					if (y1==y2){
						if (x2 > x1){
							check=0;
							for(int i=x2-1;i>x1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
						}
						if (x2 < x1)	{
							check=0;
							for(int i=x2+1;i<x1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move -rook \n";
					countPlayer--;
					break;
					case -queen:
					if (x2+y1 == x1+y2 ){
						check =0;
						for (int i=y2-1;i>y1;i--){
							for(int j=x2-1;j>x1;j--){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						for (int i=y2+1;i<y1;i++){
							for(int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y2-y1 ){
						check =0;
						cout<<"2";
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x2-x1 == y1-y2){
						check =0;
						for (int i =y2-1;i>y1;i--){
							for (int j=x2+1;j<x1;j++){
								if (board[i][j] !=0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					if (x1 == x2 ){
						if (y2 > y1){
							check = 0;
							for(int i=y2-1;i>y1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
		
						}
						if (y2 < y1)	{
							check=0;
							for(int i=y2+1;i<y1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
		
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
		
					board[y2][x2] = board[y1][x1];
					board[y1][x1] = 0;
					cout<<endl<<countPlayer<<endl;printb();
					break;
					}
					if (y1==y2){
						if (x2 > x1){
							check=0;
							for(int i=x2-1;i>x1;i--){
								if (board[i][x2] != 0){
									check++;
								}
		
							}
						}
						if (x2 < x1)	{
							check=0;
							for(int i=x2+1;i<x1;i++){
								if (board[i][x2] != 0){
									check++;
								}
							}
						}
						if (check !=0){
							cout<<"invalid move \n";
							countPlayer--;
							break;
						}
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move -queen \n";
					countPlayer--;
					break;
					case -king:
					if ((-2>x2-x1<2)  && (-2>y2-y1<2)){
						board[y2][x2] = board[y1][x1];
						board[y1][x1] = 0;
						cout<<endl<<countPlayer<<endl;printb();
						break;
					}
					cout<<"invalid move -king \n";
					countPlayer--;
					break;
					default:
						cout<<"invalid move \n";
						countPlayer--;
						break;
		
		}
					}
		}
		// .............................End of the Player2Movement Functoin.............................................................
		

