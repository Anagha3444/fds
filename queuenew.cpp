#include <iostream>
#include <queue>
#include <string>

using namespace std;

class JobQueue {
private:
    queue<string> q;  // Queue to store job names

public:
    // Function to add job to the queue
    void addJob(const string& job) {
        q.push(job);
        cout << "Job \"" << job << "\" added to the queue." << endl;
    }

    // Function to delete job from the queue
    void deleteJob() {
        if (!q.empty()) {
            cout << "Job \"" << q.front() << "\" completed and removed from the queue." << endl;
            q.pop();
        } else {
            cout << "The job queue is empty. No job to delete." << endl;
        }
    }

    // Function to display jobs in the queue
    void displayQueue() {
        if (q.empty()) {
            cout << "The job queue is empty." << endl;
        } else {
            cout << "Jobs in the queue:" << endl;
            queue<string> temp = q;  // Temporary copy of the queue for display
            while (!temp.empty()) {
                cout << temp.front() << endl;
                temp.pop();
            }
        }
    }
};

int main() {
    JobQueue jq;
    int choice;
    string job;

    do {
        cout << "\n1. Add Job\n2. Delete Job\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character left in the buffer

        switch (choice) {
        case 1:
            cout << "Enter job name: ";
            getline(cin, job);
            jq.addJob(job);
            break;
        case 2:
            jq.deleteJob();
            break;
        case 3:
            jq.displayQueue();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
