#include "Queue.h"
#include "infixToPostfix.h"

int main() {
    Queue Queue;

    // adds given elements to the end of the queue
    Queue.add(10);
    Queue.add(20);
    Queue.add(30);
    Queue.add(40);
    Queue.add(50);

    Queue.display();

    // removes front element of queue
    cout << "Removing front element: " << Queue.remove() << endl;


    // returns the first element of the current queue
    cout << "Front element of current queue: " << Queue.front() << endl;

    Queue.display();

    // checks if queue is empty
    cout << "Is queue empty? " << (Queue.isEmpty() ? "Yes" : "No") << endl;

    // returns total number of elements in queue
    cout << "Size of queue: " << Queue.size() << endl;


    string infixExpression;

    cout << "\nEnter the infix expression: ";
    getline(cin, infixExpression);
    if (balanced(infixExpression)) {
        string postfixExpression = InToPost(infixExpression);
        cout << "Postfix Expression: " << postfixExpression << endl;
    }
    else {
        cout << "The expression is invalid." << endl;
    }
    return 0;
}
