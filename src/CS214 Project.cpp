#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class ToDoList {
private:
    struct Task {
        string taskName;// the name of the task
        string date;    // the date of the task
        string status;  // the status of the task (e.g., Pending, In Progress, Completed)
        Task* next;     // pointer to the next task in the list
    } * head;           // pointer to the head of the linked list

public:
    ToDoList();
    ~ToDoList();
    void addTask(const string& taskName, const string& date); // adding a new task
    void displayTasks(); // displaying tasks based on user choice (today or all)
    void changeTaskStatus(const string& taskName, const string& newStatus); // changing the status of a task (e.g.,New, Completed, In Progress)
    void deleteTask(const string& taskName); // deleting a task by name
    string getCurrentDate();  // getting the current date in YYYY-MM-DD format from the system
};

ToDoList::ToDoList() {
    head = nullptr;
}

ToDoList::~ToDoList() { //start deleting from the begganing of the list
    Task* current;  // pointer to traverse the list
    current = head; // start from the head of the list
    while (current != nullptr) { 
        Task* temp; // temporary pointer to hold the current task
        temp = current; 
        current = current->next; // move to the next task
        delete temp; //delete the current task
    }
}

void ToDoList::addTask(const string& taskName, const string& date) {
    Task* newTask; // pointer to the new task
    newTask = new Task; // allocate memory for the new task
    newTask->taskName = taskName; // to set the task name 
    newTask->date = date; // to set the task date
    newTask->status = "New"; // the default status for the new task
    newTask->next = head; // point the new task to the current head of the list
    head = newTask; // update the head to point to the new task
    cout << "Task added: " << taskName << " for " << date << endl; // display a message indicating the task has been added
}

void ToDoList::displayTasks() {
    cout << "Choose an option:" << endl; //it gaves the user the option to choose between displaying all tasks or only today's tasks
    cout << "1. Display tasks for today" << endl;
    cout << "2. Display all tasks" << endl;
    int choice;
    cin >> choice;
    cin.ignore(); // to ignore the newline character after the integer input
    if (choice != 1 && choice != 2) {
        cout << "Invalid choice! Please try again." << endl;
        return;
    }
    string date = ""; // variable to hold the date for filtering tasks

    if (choice == 1) { // if the user chooses to display today's tasks
        cout << "Tasks for today:" << endl;
        date = getCurrentDate(); // to get the current date in YYYY-MM-DD format
    } else if (choice == 2) { // if the user chooses to display all tasks
        cout << "All tasks:" << endl;
    } else {
        cout << "Invalid choice! Please try again." << endl; // if the user enters an invalid choice
        return;
    }
    
    Task* current = head; // pointer to traverse the list
    bool found = false; // flag to check if any tasks are found
    int taskNumber = 1; // variable to number the tasks displayed

    while (current != nullptr) {
        if (date == "" || current->date == date) { // if there is no date specified it will print all tasks.Or if there is a date specified it will print only the tasks that match the date
            cout << taskNumber << ". " << current->taskName << " - " << current->date << " - Status: " << current->status << endl;
            found = true; // set the flag to true if a task is found
            taskNumber++; // increment the task number for the next task
        }
        current = current->next; // move to the next task in the list
    }

    if (!found) { // if no tasks are found
        if (date == "") { // if no date is specified, it means there are no tasks at all for all days
            cout << "No tasks available!" << endl; 
        } else { // if there is no tasks for today
            cout << "No tasks found for today: " << date << endl; 
        }
    }
}

void ToDoList::changeTaskStatus(const string& taskName, const string& newStatus) { // changing the status of a task
    Task* current; // pointer to traverse the list
    current = head; // start from the head of the list
    while (current != nullptr) {
        if (current->taskName == taskName) {
            if (current->status == "New" && (newStatus == "In Progress" || newStatus == "Completed")) { // if the current status is New, it can be changed to In Progress or Completed
                current->status = newStatus;
                cout << "Task \"" << taskName << "\" status changed to " << newStatus << endl;
                return;
            }
            else if (current->status == "In Progress" && newStatus == "Completed") { // if the current status is In Progress, it can be changed to Completed
                current->status = newStatus;
                cout << "Task \"" << taskName << "\" status changed to " << newStatus << endl;
                return;
            }
            else {
                cout << "Task \"" << taskName << "\" cannot change to " << newStatus << " from " << current->status << endl;
                return;
            }
        }
        current = current->next;
    }
    cout << "Task \"" << taskName << "\" not found!" << endl;
}

void ToDoList::deleteTask(const string& taskName) {
    if (head == nullptr) {
        cout << "No tasks to delete!" << endl;
        return;
    }

    if (head->taskName == taskName) { // if the task to be deleted is the head of the list (at the beginning of the list)
        Task* temp; 
        temp = head;
        head = head->next;
        delete temp;
        cout << "Task \"" << taskName << "\" deleted!" << endl;
        return;
    }
    // if the task to be deleted is not the head of the list
    Task* current;
    current = head;
    while (current->next != nullptr) {
        if (current->next->taskName == taskName) {
            Task* temp;
            temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Task \"" << taskName << "\" deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Task \"" << taskName << "\" not found!" << endl;
}

string ToDoList::getCurrentDate() {
    time_t now = time(0);  // get the current time
    tm* ltm = localtime(&now);  // convert it to local time
    // format the date as YYYY-MM-DD
    string currentDate = to_string(1900 + ltm->tm_year) + "-" +
                         to_string(1 + ltm->tm_mon) + "-" +
                         to_string(ltm->tm_mday);
    return currentDate;
}

int main() {
    ToDoList toDoList;
    int choice;
    string taskName, status, date;

    while (true) {
        cout << "\nWelcome to To-Do List!" << endl;
        cout << "1. Add New Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Change Task Status" << endl;
        cout << "4. Delete a Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cin.ignore(); // to ignore the newline character after the integer input

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please try again." << endl;
            continue; // continue to the next iteration of the loop
        }
        
        switch (choice) {
        case 1:
            cout << "Enter task name: ";
            getline(cin, taskName);
            cout << "Enter task date (YYYY-MM-DD): ";
            getline(cin, date);
            toDoList.addTask(taskName, date);
            break;

        case 2:
            toDoList.displayTasks(); 
            break;

        case 3:
            cout << "Enter task name to change status: ";
            getline(cin, taskName);
            cout << "Enter new status (New, In Progress, Completed): ";
            getline(cin, status);
            toDoList.changeTaskStatus(taskName, status);
            break;

        case 4:
            cout << "Enter task name to delete: ";
            getline(cin, taskName);
            toDoList.deleteTask(taskName);
            break;

        case 5:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}