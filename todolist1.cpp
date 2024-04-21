/* To Do List*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the menu options
void displayMenu() {
    cout << "\n===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Quit\n";
    cout << "==============================\n";
}

int main() {
    vector<string> tasks;
    int choice;
    string task; // Move the declaration outside the switch statement

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter task: ";
                cin.ignore(); // To clear the input buffer
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task added successfully!\n";
                break;
            case 2:
                if (tasks.empty()) {
                    cout << "No tasks in the list.\n";
                } else {
                    cout << "\n===== Tasks =====\n";
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        cout << i+1 << ". " << tasks[i] << endl;
                    }
                    cout << "=================\n";
                }
                break;
            case 3:
                int index;
                cout << "Enter index of task to mark as completed: ";
                cin >> index;
                if (index >= 1 && index <= tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                    cout << "Task marked as completed!\n";
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
