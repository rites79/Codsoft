#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks);
void removeTask(vector<Task> &tasks);

int main() {
    vector<Task> tasks; // Vector to store tasks
    
    char choice;
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                markTaskCompleted(tasks);
                break;
            case '4':
                removeTask(tasks);
                break;
            case '5':
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');
    
    return 0;
}

// Function to display menu options
void displayMenu() {
    cout << "\n===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a task
void addTask(vector<Task> &tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

// Function to view tasks
void viewTasks(const vector<Task> &tasks) {
    if(tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        cout << "Tasks:\n";
        for(size_t i = 0; i < tasks.size(); ++i) {
            cout << i+1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks) {
    viewTasks(tasks);
    if(tasks.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }
    
    int index;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;
    
    if(index < 1 || index > tasks.size()) {
        cout << "Invalid index. Please try again.\n";
        return;
    }
    
    tasks[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

// Function to remove a task
void removeTask(vector<Task> &tasks) {
    viewTasks(tasks);
    if(tasks.empty()) {
        cout << "No tasks available to remove.\n";
        return;
    }
    
    int index;
    cout << "Enter the index of the task to remove: ";
    cin >> index;
    
    if(index < 1 || index > tasks.size()) {
        cout << "Invalid index. Please try again.\n";
        return;
    }
    
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed successfully.\n";
}
