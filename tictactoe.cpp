#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int drawboard();
int checkwin();
void playVplayer();
void playVcomputer();

// the 'o' is just to make the indexing easier (not good for memory)
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
char square1[10] = {'o','1','2','3','4','5','6','7','8','9'};

int p1score = 0;
int p2score = 0;

int main(){
  system("clear");
    cout << "Welcome to TicTacToe." << endl;

    int decision = 0;
    cout << "Select '1' for 2 player." << endl;
    cout << "Select '2' to play vs computer." << endl;
    cout << "Decision: ";

    while (decision == 0){
	  cin >> decision;

	  if (decision == 1){
	    playVplayer();
	  }
	  else if (decision == 2){
	    playVcomputer();
	  }
          else{
	    cout << "Please choose '1' or '2'" << endl;
	    cout << "Decision: ";
	    decision = 0;
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
    }
    return 0;
}

void playVcomputer(){
  int player = 2;
  char mark = 'X';
  int spot;
  int result;
  char decision;
  
  while (player != -1){

    drawboard();
    	cout << "spot:: " << spot << endl;

	// 1. get player input
	if (player == 2){
	  player = 1;
	  mark = 'X';
	
		// Human
		spot = -1;
		while (spot == -1){
		  
		  cout << "Player " << player << " - enter your move: ";
		  cin >> spot;

		  if ((spot<1)||(spot>9)){
		    cout << "enter number 1 through 9!" << endl;
		    spot = (int) -1;
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  }
		  else if (square[spot] != 'X' && square[spot] != 'O'){
		    square[spot] = mark;
		  }
		  else{
		    cout << "illegal move!" << endl;
		    spot = (int) -1;
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  }
		}
	}
	// computer
	else{
	  player = 2;
	  mark = 'O';
	  bool marked = false;
	  while (!marked){
	    int spot = (rand() % 9) + 1;
	    if (square[spot] != 'X' && square[spot] != 'O'){
		    square[spot] = mark;
		    marked = true;
	    }
	  }
	}

	// 3. draw board
	drawboard();

	// 4. check for win
	result = checkwin();

	if (result == 1){
	  cout << "Player " << player << " wins the game!" << endl;
	  if (player == 1){
	    p1score++;
	  }else{
	    p2score++;
	  }
	}
	else if (result == 0){
	  cout << "Tie game" << endl;
	}
	if (result >= 0){
	  square = {'o','1','2','3','4','5','6','7','8','9'};
	  cout << "Continue? (y/n): " << endl;
	  cin >> decision;
	  if (decision == 'n'){
		return;
	  }
	}
  }
}

void playVplayer(){
  int player = 2;
  char mark = 'X';
  int spot;
  int result;
  char decision;
  while (player != -1){

    drawboard();
	// 1. get player input
	if (player == 2){
	  player = 1;
	  mark = 'X';
	}
	else{
	  player = 2;
	  mark = 'O';
	}
	
	// 2. place mark
	spot = -1;
	while (spot == -1){
	  
	  cout << "Player " << player << " - enter your move: ";
	  cin >> spot;

	  if ((spot<1)||(spot>9)){
	    cout << "enter number 1 through 9!" << endl;
	    spot = (int) -1;
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  }
	  else if (square[spot] != 'X' && square[spot] != 'O'){
	    //cout << "heyyy" << endl;
	    square[spot] = mark;
	  }
          else{
	    cout << "illegal move!" << endl;
	    spot = (int) -1;
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }

	}
	
	// 3. draw board
	drawboard();
	// 4. check for win
	result = checkwin();

	if (result == 1){
	  cout << "Player " << player << " wins the game!" << endl;
	  if (player == 1){
	    p1score++;
	  }else{
	    p2score++;
	  }
	}
	else if (result == 0){
	  cout << "Tie game" << endl;
	}
	if (result >= 0){
	  square = {'o','1','2','3','4','5','6','7','8','9'};
	  cout << "Continue? (y/n): " << endl;
	  cin >> decision;
	  if (decision == 'n'){
		return;
	  }
	}
  }
}

int drawboard(){
  system("clear");
  cout << "-----------------------" << endl;
  cout << "----- T1cTacToe -------" << endl;
  cout << "-----------------------" << endl;
  cout << "Player 1 (X)  -  Player 2 (O) \n\n";

  cout << "Score: " << p1score << "  -  " << p2score << endl;

  cout << "   |   |   " << endl;
  cout << " " << square[1] <<" | "<<square[2]<<" | "<<square[3]  << endl;
  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;
  cout << " " << square[4] <<" | "<<square[5]<<" | "<<square[6]  << endl;
  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;
  cout << " " << square[7] <<" | "<<square[8]<<" | "<<square[9]  << endl;
  cout << "   |   |   " << endl;

  return 0;
}

int checkwin(){
  if (square[1] == square[2] && square[2] == square[3])
    return 1;
  else if (square[4] == square[5] && square[5] == square[6])
	return 1;
  else if (square[7] == square[8] && square[8] == square[9])
	return 1;
  else if (square[1] == square[4] && square[4] == square[7])
	return 1;
  else if (square[2] == square[5] && square[5] == square[8])
	return 1;
  else if (square[3] == square[6] && square[6] == square[9])
	return 1;
  else if (square[1] == square[5] && square[5] == square[9])
	return 1;
  else if (square[3] == square[5] && square[5] == square[7])
	return 1;
  else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')
	return 0;
  else
	return -1;

  return 0;
}

