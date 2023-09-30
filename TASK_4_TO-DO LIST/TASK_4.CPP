#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Task structure to represent a task
struct Task
{
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

class TodoList
{
public:
    void addTask(const string &description)
    {
        tasks.push_back(Task(description));
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "No tasks in the to-do list." << endl;
        }
        else
        {
            for (size_t i = 0; i < tasks.size(); i++)
            {
                cout << i + 1 << ". ";
                if (tasks[i].completed)
                {
                    cout << "[Completed] ";
                }
                cout << tasks[i].description << endl;
            }
        }
    }

    bool deleteTask(int taskIndex)
    {
        if (isValidIndex(taskIndex))
        {
            tasks.erase(tasks.begin() + taskIndex - 1);
            return true;
        }
        return false;
    }

    bool markCompleted(int taskIndex)
    {
        if (isValidIndex(taskIndex))
        {
            tasks[taskIndex - 1].completed = true;
            return true;
        }
        return false;
    }

private:
    vector<Task> tasks;

    bool isValidIndex(int taskIndex) const
    {
        return taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size());
    }
};

int main()
{
    TodoList todoList;
    int choice;

    cout << "TO-DO LIST MANAGER" << endl;

    while (true)
    {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please try again: ";
        }

        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            cout << "Enter task description: ";
            string description;
            getline(cin, description);
            todoList.addTask(description);
            break;
        }
        case 2:
        {
            todoList.viewTasks();
            break;
        }
        case 3:
        {
            todoList.viewTasks();
            cout << "Enter the task number to mark as completed: ";
            int taskIndex;
            cin >> taskIndex;
            if (todoList.markCompleted(taskIndex))
            {
                cout << "Task marked as completed." << endl;
            }
            else
            {
                cout << "Invalid task index." << endl;
            }
            break;
        }
        case 4:
        {
            todoList.viewTasks();
            cout << "Enter the task number to delete: ";
            int taskIndex;
            cin >> taskIndex;
            if (todoList.deleteTask(taskIndex))
            {
                cout << "Task deleted." << endl;
            }
            else
            {
                cout << "Invalid task index." << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    }

    return 0;
}
