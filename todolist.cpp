/* To Do List*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Task {
    string description;
    time_t timestamp;
};

// Function to display the menu options
void displayMenu() {
    cout << "\n===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View All Tasks\n";
    cout << "3. View Completed Tasks during a Period\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Quit\n";
    cout << "==============================\n";
}

// Function to convert time_t to string
string timeToString(time_t time) {
    return asctime(localtime(&time));
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Task newTask;
                cout << "Enter task description: ";
                cin.ignore(); // To clear the input buffer
                getline(cin, newTask.description);
                newTask.timestamp = time(nullptr); // Current timestamp
                tasks.push_back(newTask);
                cout << "Task added successfully!\n";
                break;
            }
            case 2:
                if (tasks.empty()) {
                    cout << "No tasks in the list.\n";
                } else {
                    cout << "\n===== All Tasks =====\n";
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        cout << i+1 << ". " << tasks[i].description << " - " << timeToString(tasks[i].timestamp);
                    }
                    cout << "======================\n";
                }
                break;
            case 3: {
                time_t startTime, endTime;
                cout << "Enter start time (in seconds since epoch): ";
                cin >> startTime;
                cout << "Enter end time (in seconds since epoch): ";
                cin >> endTime;

                cout << "\n===== Completed Tasks during the Period =====\n";
                for (const auto& task : tasks) {
                    if (task.timestamp >= startTime && task.timestamp <= endTime) {
                        cout << task.description << " - " << timeToString(task.timestamp);
                    }
                }
                cout << "============================================\n";
                break;
            }
            case 4:
                // Mark task as completed
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
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}
