#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    bool isCompleted = false;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, newTask.name);
    tasks.push_back(newTask);
    cout << "Task added!\n";
}

void viewTasks() {
    cout << "\nTo-Do List:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].name << " - "
             << (tasks[i].isCompleted ? "Completed" : "Pending") << endl;
    }
}

void markTaskCompleted() {
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void removeTask() {
    int taskNumber;
    cout << "Enter task number to remove: ";
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
