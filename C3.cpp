#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

void addTask(std::vector<Task>& tasks) {
    std::cout << "Enter task description: ";
    std::string desc;
    std::getline(std::cin, desc);
    tasks.push_back(Task(desc));
    std::cout << "Task added successfully.\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "\nTo-Do List:\n";
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    std::cout << "Enter task number to mark as completed: ";
    size_t taskNumber;
    std::cin >> taskNumber;
    std::cin.ignore();  // Ignore the newline character left in the buffer
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    std::cout << "Enter task number to remove: ";
    size_t taskNumber;
    std::cin >> taskNumber;
    std::cin.ignore();  // Ignore the newline character left in the buffer
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // Ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the To-Do List Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
