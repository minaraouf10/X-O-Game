#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;
char  grid[10] = {'0','1','2','3','4','5','6','7','8','9' };

void bord() {
	system("cls");
	cout << "\n\tX/O Game : "
		<< "\n\tPlayer 1 -> (X) & Player 2 -> (O)\n"
		<< "\t ____ ____ ____ \n"
		<< "\t|    |    |    |\n"
		<< "\t|  " << grid[7] << " |  " << grid[8] << " |  " << grid[9] << " |\n"
		<< "\t|____|____|____|\n"
		<< "\t|    |    |    |\n"
		<< "\t|  " << grid[4] << " |  " << grid[5] << " |  " << grid[6] << " |\n"
		<< "\t|____|____|____|\n"
		<< "\t|    |    |    |\n"
		<< "\t|  " << grid[1] << " |  " << grid[2] << " |  " << grid[3] << " |\n"
		<< "\t|____|____|____|\n"
		<< "\n\n";

}
int check_win() {
		 if (grid[7] == grid[8] && grid[8] == grid[9])
		return 1;
	else if (grid[4] == grid[5] && grid[5] == grid[6])
		return 1;
	else if (grid[1] == grid[2] && grid[2] == grid[3])
		return 1;
	else if (grid[7] == grid[4] && grid[4] == grid[1])
		return 1;
	else if (grid[8] == grid[5] && grid[5] == grid[2])
		return 1;
	else if (grid[9] == grid[6] && grid[6] == grid[3])
		return 1;

	else if (grid[7] == grid[5] && grid[5] == grid[3])
		return 1;
	else if (grid[9] == grid[5] && grid[5] == grid[1])
		return 1;
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3'
		&& grid[3] != '4' && grid[4] != '5' && grid[5] != '6'
		&& grid[7] != '7' && grid[8] != '8' && grid[9] != '9')
		return 0;
	else
		return -1;
}
void play(int &player ,int &choice, char &mark) {
	if (choice == 1 && grid[1] == '1')
		grid[1] = mark;
	else if (choice == 2 && grid[2] == '2')
		grid[2] = mark;
	else if (choice == 3 && grid[3] == '3')
		grid[3] = mark;
	else if (choice == 4 && grid[4] == '4')
		grid[4] = mark;
	else if (choice == 5 && grid[5] == '5')
		grid[5] = mark;
	else if (choice == 6 && grid[6] == '6')
		grid[6] = mark;
	else if (choice == 7 && grid[7] == '7')
		grid[7] = mark;
	else if (choice == 8 && grid[8] == '8')
		grid[8] = mark;
	else if (choice == 9 && grid[9] == '9')
		grid[9] = mark;

	else {
			cout << "\t Please Enter a Vaild Move \n";
			player--;
			Sleep(3000);
		}
	
}
int main() {
	int win,player = 1,choice;
	char mark;
	do {
		bord();
		//player = ((player % 2 == 1) ? player = 1 : player = 2);
		//mark = ((player == 1) ? mark = 'X' : mark = 'O');
		if (player % 2 == 1)
			player = 1;
		else
			player = 2;

		if (player == 1)
			mark = 'X';
		else
			mark = 'O';


		cout << "\tplayer " << player << " ,Enter the Number you needed to play in : ";
		cin >> choice;
		play(player,choice,mark);

		win = check_win();
		player++;
	} while (win == -1);
	bord();
	if (win == 1) {
		player--;
		cout << "\t\tplayer " << player << " win " << endl;
	}
	else {
		cout << "\t\tGame Draw ";
	}

}