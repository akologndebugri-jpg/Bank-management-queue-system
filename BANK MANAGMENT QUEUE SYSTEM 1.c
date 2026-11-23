#include <iostream>
#include <queue>
#include <string>

using namespace std;

void displayQueue(queue<string> q) {
    if (q.empty()) {
        cout << "The queue is currently empty.\n";
        return;
    }

    cout << "\n--- Current Queue (Front to Back) ---\n";
    int position = 1;
    while (!q.empty()) {
        cout << position++ << ". " << q.front() << "\n";
        q.pop();
    }
}

int main() {
    queue<string> bankQueue;
    int choice;
    string customerName;

    do {
        cout << "\n=== Bank Customer Queue Management System ===\n";
        cout << "1. Join queue\n";
        cout << "2. Serve customer\n";
        cout << "3. Display queue\n";
        cout << "4. Show number of customers\n";
        cout << "5. Show next customer\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, customerName);
                bankQueue.push(customerName);
                cout << customerName << " has joined the queue.\n";
                break;

            case 2:
                if (bankQueue.empty()) {
                    cout << "No customers in the queue to serve.\n";
                } else {
                    cout << "Serving customer: " << bankQueue.front() << "\n";
                    bankQueue.pop();
                }
                break;

            case 3:
                displayQueue(bankQueue);
                break;

            case 4:
                cout << "Number of customers in queue: " << bankQueue.size() << "\n";
                break;

            case 5:
                if (bankQueue.empty()) {
                    cout << "The queue is empty. No next customer.\n";
                } else {
                    cout << "Next customer to be served: " << bankQueue.front() << "\n";
                }
                break;

            case 6:
                cout << "Exiting system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
