#include "maze.h"

void showStartMenu();
void showEndMenu();
int main()
{
	showStartMenu();
	Maze m;
	m.showResult();
	system("pause");
	system("cls");
	showEndMenu();
	return 0;
}

void showStartMenu()
{
	cout << " _________________________" << endl;
	cout << "|    |  |     |  _  |   __|\t\tFilename: MazeSolver.exe" << endl;
	cout << "|  | |  |  |  |   __|   __|\t\tAuthor: NOPE" << endl;
	cout << "|__|____|_____|__|  |_____|\t\tCreationDate: Feb 6th, 2021" << endl;
	cout << endl;
	cout << "a simple tool that can help u solve the two-dimensional maze problem. " << endl;
	cout << "Please name the file name of the maze as 'maze.txt'. And save it in the same directory." << endl;
	
}
void showEndMenu()
{
	cout << " _________________________" << endl;
	cout << "|    |  |     |  _  |   __|\t\tFilename: MazeSolver.exe" << endl;
	cout << "|  | |  |  |  |   __|   __|\t\tAuthor: NOPE" << endl;
	cout << "|__|____|_____|__|  |_____|\t\tCreationDate: Feb 25th, 2021" << endl;
	cout << endl;
	cout << "GOODBYE~~" << endl;

}