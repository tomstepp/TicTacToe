#include <iostream>
#include <cstdlib>

using namespace std;

int drawboard();
int checkwin();

// the 'o' is just to make the indexing easier (not good for memory)
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
char square1[10] = {'o','1','2','3','4','5','6','7','8','9'};

int p1score = 0;
int p2score = 0;

int main(){
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
	cout << "Player " << player << " - enter your move: ";
	
	// 2. place mark
	cin >> spot;
	if (square[spot] != 'X' && square[spot] != 'O'){
	  square[spot] = mark;
	}
        else{
	  cout << "illegal move!" << endl;
	  player = (player+1) % 2;
	  continue;
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
		return 0;
	  }
	}
  }


  return 0;
}

int drawboard(){
  system("clear");
  cout << "-----------------------" << endl;
  cout << "----- T1c t@c T03 -----" << endl;
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

