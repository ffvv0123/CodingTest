#include <iostream>
using namespace std;

class Queue{
public:
    int front, rear;
    int data[10001];

    Queue(){
        for(int i = 0; i < 10001; i++){
            data[i] = NULL;
        }
        rear = 0;
        front = 0;
    }

    bool is_empty(){
        return front == rear;
    }

    void push(int X){
        data[rear] = X;
        rear++;
    }

    void pop(){
        if(is_empty()){
            cout << -1 << "\n";
        }
        else{
            cout << data[front] << "\n";
            front++;
        }
    }

    void size(){
        cout << (rear - front) << "\n";
    }

    void top(){
        if(is_empty()){
            cout << -1 << "\n";
        }
        else{
            cout << data[front] << "\n";
        }
    }
    void back(){
        if(is_empty()){
            cout << -1 << "\n";
        }
        else{
            cout << data[rear - 1] << "\n";
        }
    }
};

void ans(){
    Queue queue;

    int N;
    cin >> N;

    for(int i=0; i < N; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int element;
            cin >> element;
            queue.push(element);
        }

        else if(command == "pop"){
            queue.pop(); 
        }

        else if(command == "empty") {
            cout << queue.is_empty() << "\n";
        }

        else if(command == "size") {
            queue.size(); 
        }

        else if(command == "front") {
            queue.top();
        }

        else if(command == "back") {
            queue.back();
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0; 
}