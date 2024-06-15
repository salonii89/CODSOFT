#include <iostream>
using namespace std;

const int MAX_TASKS = 100;

struct Task {
    string task_name;
    bool completed;
};

void print_tasks(const Task tasks[], int task_count) {
    cout << "Tasks:" << endl;
    cout << "\n-----------------------------------\n" << endl;
    for (int i = 0; i < task_count; i++) {
        cout << "Task " << i + 1 << ": " << tasks[i].task_name;
        if (tasks[i].completed) {
            cout << " (Completed)" << endl;
        } else {
            cout << " (Pending)" << endl;
        }
    }
    cout << "\n-----------------------------------\n" << endl;
}

void mark_task_complete(Task tasks[], int& task_count) {
    print_tasks(tasks, task_count);
    int complete_task;
    cout << "Enter the task number to mark as complete: ";
    cin >> complete_task;
    if (complete_task < 1 || complete_task > task_count) {
        cout << "Invalid Task Number" << endl;
        return;
    }
    tasks[complete_task - 1].completed = true;
    cout << "Task '" << tasks[complete_task - 1].task_name << "' marked as complete." << endl;
}

void remove_task(Task tasks[], int& task_count) {
    print_tasks(tasks, task_count);
    int remove_task;
    cout << "Enter the task number to remove: ";
    cin >> remove_task;
    if (remove_task < 1 || remove_task > task_count) {
        cout << "Invalid Task Number" << endl;
        return;
    }
    cout << "Task '" << tasks[remove_task - 1].task_name << "' removed." << endl;
    for (int i = remove_task - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
}

void view_tasks(const Task tasks[], int task_count) {
    print_tasks(tasks, task_count);
}

int main() {
    Task tasks[MAX_TASKS];
    int task_count = 0;
    int option = -1;

    while (option != 0) {
        cout << "\n\n------TO DO LIST-------\n" << endl;
        cout << "1. Add a New Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Complete" << endl;
        cout << "4. Remove Task" << endl;
        cout << "0. Quit\n" << endl;
        cout << "Enter an option: ";
        cin >> option;

        switch (option) {
            case 1: {
                if (task_count >= MAX_TASKS) {
                    cout << "TASK LIST IS FULL" <<endl;
                } else {
                    cout << "\nEnter a New Task: ";
                    cin.ignore();
                    getline(cin, tasks[task_count].task_name);
                    tasks[task_count].completed = false;
                    task_count++;
                    cout << "Task added successfully!" << endl;
                }
                break;
            }
            case 2: {
                view_tasks(tasks, task_count);
                break;
            }
            case 3: {
                mark_task_complete(tasks, task_count);
                break;
            }
            case 4: {
                remove_task(tasks, task_count);
                break;
            }
            case 0: {
                cout << "Exiting program. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid Choice. Please enter a valid option." << endl;
                break;
            }
        }
    }
    return 0;
}
