#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

bool tBombOn = 0, pcDemoOn = 0;
char blockChar = 'X';
int boardSize = 10, tBombCount = 9;

//Declare function
void blockBoard();
bool exit(char[]);
void credit();
void blockCharC();
void startGame();
void settingsMenu();

class Block
{
public:
	//Construtor to create block for player to pick(block type, index, blockCount) 
	Block(char block[5][5],int x,int b){
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				blockS[i][j] = block[i][j];
		blockIndex = x;
		placeScore = b*10;
	}

	void print(){

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cout << blockS[i][j];
			}
			cout << endl;
		}

	}

private:
	char blockS[5][5];
	int placeScore, blockIndex;
};


int main()
{
	char choice;
	char mainmenuExit[40] = "Do you really wish to exit?";
	/*
	 * Plz copy zero's work to here
	 * Please name h for horizontal block
	 * v for vectical block e.t.c
	 */
	char h1[4][4] = {blockChar};
	char h2[4][4] = {blockChar,blockChar};
	char h3[4][4] = {blockChar,blockChar,blockChar};
	char h4[4][4] = {blockChar, blockChar, blockChar, blockChar};
	char h5[4][4] = {blockChar, blockChar, blockChar, blockChar, blockChar};
	char v2[4][4] = {{blockChar}, {blockChar}};
	char v3[4][4] = {{blockChar}, {blockChar}, {blockChar}};
	char v4[4][4] = {{blockChar}, {blockChar}, {blockChar}, {blockChar}};
	char v5[5][4] = {{blockChar}, {blockChar}, {blockChar}, {blockChar}, {blockChar}};
	char L11[4][4] = {{blockChar}, {blockChar, blockChar}};
	char L12[4][4] = {{' ', blockChar}, {blockChar, blockChar}};
	char L13[4][4] = {{blockChar, blockChar}, {blockChar}};
	char L14[4][4] = {{blockChar, blockChar}, {' ', blockChar}};
	char L21[4][4] = {{blockChar}, {blockChar}, {blockChar, blockChar, blockChar}};
	char L22[4][4] = {{' ', ' ', blockChar}, {' ', ' ', blockChar}, {blockChar, blockChar, blockChar}};
	char L23[4][4] = {{blockChar, blockChar, blockChar}, {blockChar}, {blockChar}};
	char L24[4][4] = {{blockChar, blockChar, blockChar}, {' ', ' ', blockChar}, {' ', ' ', blockChar}};
	char s1[4][4] = {{blockChar, blockChar}, {blockChar, blockChar}};
	char s2[4][4] = {{blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}, {blockChar, blockChar, blockChar}};

	//The main loop of the game, only break out when user want to exit
	while(1){
		cout << endl;
		cout << "Blockblazer - Clear The Blocks!\n" << endl;
		cout << "*** Game Menu ***" << endl;
		cout << "[1] Start Game" << endl;
		cout << "[2] Settings" << endl;
		cout << "[3] Instructions" << endl;
		cout << "[4] Credits" << endl;
		cout << "[5] Exit" << endl;
		cout << "*****************" << endl;
		cout << "Option (1-5): ";
		cin >> choice;

		switch (choice){
		case '1': startGame() ; break;
		case '2': system("cls");settingsMenu(); break;
		case '3': /*P3 here*/ ; break;
		case '4': credit() ; break;
		case '5': if(exit(mainmenuExit) == true)
					return 0;
				else continue;
		default:
			cout << "Please enter choice 1 - 5 only." << endl;
			system("pause");
			break;
		}
		//Clear Screen
		system("cls");
	};
}

//The real chessboard
void blockBoard(){
	char boardSpace[10][10];

	//store empty space into board
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
			boardSpace[i][j] = ' ';
		}
	}

}

//Macro exit function (with y/n) for returning to upper level of the program, terminate the program when execute in main menu
bool exit(char msg[]){
	char isexit;

	while(1){
		//Ask User for input
		cout << msg << endl;
		cout << "(y/n)" << endl;
		cin >> isexit;
		//Check the input
		if(isexit == 'y'|| isexit == 'Y')
			return true;
		else if(isexit == 'n'|| isexit == 'N'){
			system("cls");
			return false;
		}else{
			system("cls");
			cout << "Only y/n is accepted" << endl;
		}
	}

}

//Show the credit page
void credit(){
	//clear the screen first
	system("cls");
	cout << "Leung Ho HIN  16187002A 103A" << endl;
	cout << "Leung Ka MING 16091968A 103A" << endl;
	cout << "MAK HOI KIT   16027276A 103C" << endl;
	cout << "SARKI JOSHAN  1698910AA 103B" << endl;
	
	system("pause");

}

//Change the char of the blocks
void blockCharC(){
	int loopCheck = 0;
	char charChoice;
	
	while(loopCheck == 0){
		cout << "*** Block Character Selection ***" << endl;
		cout << "[1] X" << endl;
		cout << "[2] O" << endl;
		cout << "[3] @" << endl;
		cout << "[4] #" << endl;
		cout << "*****************" << endl;
		cout << "Option (1-4): ";
		cin >> charChoice;
		
		loopCheck = 1;
		switch(charChoice){
			case '1': blockChar = 'X'; break;
			case '2': blockChar = 'O'; break;
			case '3': blockChar = '@'; break;
			case '4': blockChar = '#'; break;
			default: cout << "Please enter choice 1 - 4 only." << endl;
				loopCheck = 0;
		}
		
		if (loopCheck != 0) cout << "Block Character has been changed.";
		
		system("pause");
		system("cls");
	}
}

//Start the Game <-- Will be modified later <--Cosmetics chessboard
void startGame(){
	
	system("cls");
	int gboardSize = boardSize+3;

	//The chessboard with A-J and 0-9
	char greaterboard[gboardSize][gboardSize];

	//Fill the board with ' ' first
	for(int i=0;i<gboardSize;i++){
		for(int j=0;j<gboardSize;j++){
			greaterboard[i][j] = ' ';
		}
	}

	//generate size sensitive top
	for(int i=2;i<gboardSize-1;i++){
		greaterboard[0][i] = 48+i-2;
	}

	//generate size sensitive side
	for(int i=2;i<gboardSize-1;i++){
		greaterboard[i][0] = 65+i-2;
	}

	//Generate the outline of the board
	for(int i=0;i<gboardSize;i++){
		for(int j=0;j<gboardSize;j++){
			if((i==1||i==gboardSize-1) && j>=1)
				greaterboard[i][j] = '|';
			if(i!=0){
				if(j==1 || j== gboardSize-1)
					greaterboard[i][j] = '-';
			}
		}

	}

	//Show the board
	for(int i=0;i<gboardSize;i++){
		for(int j=0;j<gboardSize;j++){
			cout << greaterboard[i][j];
		}
		cout << endl;
	}


	system("pause");
}

//Load Settings configuration
void settingsMenu(){
	bool setExit = 0;
	char choice;
	char settingsMenuExit[40] = "Do you wish to return to main menu?";
	
	while(setExit == 0){
		cout << "\n*** Settings Menu ***" << endl;
		cout << "[1] PC Game Demo" << endl;
		cout << "[2] Timer Bomb Mode" << endl;
		cout << "[3] Change Board Size" << endl;
		cout << "[4] Change Bomb Timer" << endl;
		cout << "[5] Change Block Character" << endl;
		cout << "[6] Return to Game Menu" << endl;
		cout << "*****************" << endl;
		cout << "Option (1-6): ";
		cin >> choice;

		switch (choice){
		case '1': /*PC Demo toggle*/ ; continue;
		case '2': /*Timer Bomb toggle*/ ; continue;
		case '3': /*Board Size option*/ ; continue;
		case '4': /*Bomb Timer option*/ ; continue;
		case '5': blockCharC(); continue;
		case '6': if(exit(settingsMenuExit) == true) setExit = 1;
			continue;
		default:
			cout << "Please enter choice 1 - 6 only." << endl;
			break;

		}
		//Clear Screen
		system("cls");
	};
}
