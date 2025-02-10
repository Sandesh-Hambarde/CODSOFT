#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string description;
    bool completed;
};


vector<Task> tasks;


void addTask(const string& desc) {
    tasks.push_back({desc, false});
    cout << "Task added successfully!\n";
}


void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nTask List:\n";
    for ( int  i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "->" : "->") << "] " << tasks[i].description << "\n";
    }
}


void markCompleted(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed successfully.\n";
}

int main() {
    int choice, taskIndex;
    string taskDesc;

    while (true) {
        cout << "Task Manager"<< endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                addTask(taskDesc);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                markCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                removeTask(taskIndex);
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

