#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class TicToeGame {
    private:
        char XOBoard[3][3];
        char previous;  // Initialize previous as null character
        int row, column;
        char choice;
    public:
        TicToeGame()=default;
        TicToeGame(): previous('\0'), { 
            XOBoard[3][3] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}};
        }

        void drawBoard() {
            for(int i=0; i < 3; i++) {

                for(int j=0; j < 3; j++) 
                    cout << XOBoard[i][j] << " ";
                
                cout << endl;
            }
        }
        
        void StartGame() {
            cout << "Enter Your Character(X-O)  ";  
            cin >> choice;
            
            // Convert to uppercase to handle both 'x' and 'X'
            choice = toupper(choice);
            
            // Validate input is either X or O
            while(choice != 'X' && choice != 'O') {
                cout << "Invalid choice! Please enter X or O: ";
                cin >> choice;
                choice = toupper(choice);
            }
            
            // Check if same character as previous move
            while(choice == previous) {
                cout << "Cannot use the same character as previous move! Choose " 
                    << (previous == 'X' ? 'O' : 'X') << ": ";
                cin >> choice;
                choice = toupper(choice);
            }
            
            cout << "Enter Your Location  [i][j]" << endl;
            cout << "Row: ";                        
            cin >> row;
            cout << "Col: ";                        
            cin >> column;
            
            // Validate row and column are within bounds
            while(row < 0 || row > 2 || column < 0 || column > 2) {
                cout << "Invalid position! Please enter row and column between 0-2: " << endl;
                cout << "Row: "; cin >> row;
                cout << "Col: "; cin >> column;
            }
            
            // Check if position is already taken
            while(XOBoard[row][column] != '\0') {
                cout << "Position already taken! Choose another position: " << endl;
                cout << "Row: "; cin >> row;
                cout << "Col: "; cin >> column;
            }
            
            XOBoard[row][column] = choice;
            previous = choice;  // Store current choice for next move
            cout << "Board[" << row << "][" << column << "] = " << choice << endl;
        }
        
        // Function to check if there's a winner
        char checkWinner() {
            // Check rows
            for(int i = 0; i < 3; i++) {
                if(XOBoard[i][0] != '\0' && XOBoard[i][0] == XOBoard[i][1] && XOBoard[i][1] == XOBoard[i][2]) {
                    return XOBoard[i][0];
                }
            }
            
            // Check columns
            for(int i = 0; i < 3; i++) {
                if(XOBoard[0][i] != '\0' && XOBoard[0][i] == XOBoard[1][i] && XOBoard[1][i] == XOBoard[2][i]) {
                    return XOBoard[0][i];
                }
            }
            
            // Check diagonals
            if(XOBoard[0][0] != '\0' && XOBoard[0][0] == XOBoard[1][1] && XOBoard[1][1] == XOBoard[2][2]) {
                return XOBoard[0][0];
            }
            if(XOBoard[0][2] != '\0' && XOBoard[0][2] == XOBoard[1][1] && XOBoard[1][1] == XOBoard[2][0]) {
                return XOBoard[0][2];
            }
            
            // Check for draw
            bool isDraw = true;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == '\0') {
                        isDraw = false;
                        break;
                    }
                }
            }
            if(isDraw) return 'D'; // D for Draw
            
            return '\0'; // No winner yet
        }
}





int main() {
    cout << "Welcome to XO Game";
    bool complete = true;
    TicToeGame Game;

    while(complete) {
        Game.StartGame(XOBoard);
        system("cls");
        Game.drawBoard(XOBoard);
        
        char winner = checkWinner(XOBoard);
        if(winner != '\0') {
            if(winner == 'D') {
                cout << "Game Over! It's a Draw!" << endl;
            } else {
                cout << "Game Over! Player " << winner << " wins!" << endl;
            }
            complete = false;
        }
    }

    return 0;
}
