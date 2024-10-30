#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string line;
    int user_num;

    srand(time(0));

    fstream file("nums.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < 200; i++) {
            int nums = rand() % 1000;
            file << nums << endl;
        }
        file.close();
    }
    else {
        cout << "Error opening file for writing." << endl;
        return 1;
    }

    bool found = false;
    while (!found) {
        cout << "Write a num and try to found it in file: ";
        cin >> user_num;

        file.open("nums.txt", ios::in);
        if (file.is_open()) {
            found = false;
            while (getline(file, line)) {
                int current_num = stoi(line);
                if (current_num == user_num) {
                    cout << "Num " << user_num << " find in file." << endl;
                    found = true;
                    break;
                }
            }
            file.close();

            if (!found) {
                cout << "Num " << user_num << " not found.Add in file." << endl;
                file.open("nums.txt", ios::app);  
                if (file.is_open()) {
                    file << user_num << endl;
                    file.close();
                }
                else {
                    cout << "Cant open file" << endl;
                    return 1;
                }
            }
        }
        else {
            cout << "Cant open file." << endl;
            return 1;
        }
    }

    return 0;
}
