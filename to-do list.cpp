#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> list;
    int ch;
    string task;

    do {
        cout << "\n1. Add Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> ch;
        cin.ignore(); 

        if (ch == 1) {
            cout << "Enter Task: ";
            getline(cin, task);
            list.push_back(task);
            cout << "Task Added.\n";
        }
        else if (ch == 2) {
            if (list.empty()) {
                cout << "No Tasks.\n";
            } else {
                for (int i = 0; i < list.size(); i++) {
                    cout << i + 1 << ". " << list[i] << "\n";
                }
            }
        }
        else if (ch == 3) {
            int no;
            cout << "Enter Task Number to Delete: ";
            cin >> no;
            if (no >= 1 && no <= list.size()) {
                list.erase(list.begin() + no - 1);
                cout << "Task Deleted.\n";
            } else {
                cout << "Invalid Number.\n";
            }
        }
        else if (ch == 4) {
            cout << "Exiting\n";
        }
        else {
            cout << "Wrong Option.\n";
        }

    } while (ch != 4);

    return 0;
}

