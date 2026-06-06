#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int gamevalue[25];
bool opened[25] = {false};
int score = 0;

void gamebord() {
    cout << "+----+----+----+----+----+\n";
    for (int i = 0; i < 25; i++) {
        if (opened[i])
            cout << "| " << gamevalue[i] << "  ";
        else {
            if (i+1 < 10)
                cout << "| 0" << i+1 << " ";
            else
                cout << "| " << i+1 << " ";
        }

        if ((i+1) % 5 == 0) {
            cout << "|\n+----+----+----+----+----+\n";
        }
    }
}

void clear() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    srand(time(NULL));

    for(int i = 0; i < 25; i++)
        gamevalue[i] = 1 + rand() % 9;  // امتیاز هر خانه

    while (true) {
        gamebord();
        cout << "Score: " << score << endl;
        cout << "Select a box (1-25, 0 to exit): ";

        int choice;
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > 25 || opened[choice-1]) {
            cout << "Invalid choice!\n";
            continue;
        }

        opened[choice-1] = true;
        score += gamevalue[choice-1];

        clear();
    }

    cout << "Final Score: " << score << endl;
    return 0;
}
