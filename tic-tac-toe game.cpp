#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char current_marker;
int current_player;
string n1;
string n2;

void functionone(){
    cout<<"Enter the name of the first player : \n";
    cin>>n1;
    cout<<"Enter the name of the second player : \n";
    cin>>n2;
	cout<<n1<<" Is player First so it's Your Turn' : \n";
}

void functiontwo() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool functionthree(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if (current_player == 1) current_player = 2;
    else current_player = 1;
}

void game() {

    cout << "Player " << n1 << " choose your marker: " << endl;
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    functiontwo();

    int player_won;

    for (int i = 0; i < 9; i++) {
        if (current_player == 1) {
            cout << "It's player " << n1 << "'s turn. Enter your slot: " << endl;
        } else {
            cout << "It's player " << n2 << "'s turn. Enter your slot: " << endl;
        }
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Choose another slot!" << endl;
            i--;
            continue;
        }

        if (!functionthree(slot)) {
            cout << "Slot occupied! Choose another slot!" << endl;
            i--;
            continue;
        }

        functiontwo();

        player_won = winner();

        if (player_won == 1) {
            cout << "Player " << n1 << " wins! Congratulations!" << endl;
            break;
        }
        if (player_won == 2) {
            cout << "Player " << n2 << " wins! Congratulations!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        cout << "It's a tie!" << endl;
    }
}

int main() {
	functionone();
    game();
    return 0;
}
