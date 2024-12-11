#include <iostream>
#include <queue>
#include <string>

using namespace std;

class JobQueue {
private:
    queue<string> q;

public:
    void addJob(const string& job) {
        q.push(job);
        cout << "Job \"" << job << "\" added to the queue." << endl;
    }

    void deleteJob() {
        if (!q.empty()) {
            cout << "Job \"" << q.front() << "\" completed and removed from the queue." << endl;
            q.pop();
        } else {
            cout << "The job queue is empty. No job to delete." << endl;
        }
    }

    void displayQueue() {
        if (q.empty()) {
            cout << "The job queue is empty." << endl;
        } else {
            cout << "Jobs in the queue:" << endl;
            queue<string> temp = q;
            while (!temp.empty()) {
                cout << temp.front() << endl;
                temp.pop();
            }
        }
    }
};

int main() {
    JobQueue jq;

    jq.addJob("Job1");
    jq.addJob("Job2");
    jq.addJob("Job3");

    jq.displayQueue();

    jq.deleteJob();
    jq.displayQueue();

    jq.deleteJob();
    jq.deleteJob();
    jq.deleteJob();

    return 0;
}
