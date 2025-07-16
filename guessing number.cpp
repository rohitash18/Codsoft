#include<iostream>
using namespace std;

int main()
{
    int answer = 5;
    int guess;
    while(answer != guess){
        cout << "enter your number:";
        cin >> guess;

        if (guess < answer) {
            cout << "Too low!" << endl;
        } else if (guess > answer) {
            cout << "Too high!" << endl;
        }
    }
    cout << "you win";

    return 0;
}

