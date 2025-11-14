#include <iostream>
#include "string.h"
#include "stack.h"
#include "queue.h"
#include "list.h"
#include "dict.h"

using namespace std;

using PyValue = std::variant<int, double, bool, std::string>;

void printVariant(const PyValue& v) {
    visit([](auto&& arg) {
        cout << arg;
    }, v);
}

int main() {

    // -------------------------------
    cout << "\n--- Test 1: PyString ---\n";
    // -------------------------------
    PyString word;
    for (char c : {'H', 'e', 'l', 'l', 'o'})
        word.add_character(c);

    word.print_word();

    string ws = word.create_word();
    cout << "Result: " << ws << endl;

    if (word.test_string("Hello", ws))
        cout << "✅ PyString passed!\n";
    else
        cout << "❌ PyString failed!\n";


    // -------------------------------
    cout << "\n--- Test 2: PyDict ---\n";
    // -------------------------------
    PyDict d;
    d.Insert(0, 1);

    cout << boolalpha << "Empty? " << d.isEmpty() << endl;
    cout << "Get(0): " << get<int>(d.Get(0)) << endl;

    d.Insert(1, "Hey");
    d.Insert(2, true);

    d.print();

    d.Remove(1);
    cout << "After removal:\n";
    d.print();


    // -------------------------------
    cout << "\n--- Test 3: PyQueue ---\n";
    // -------------------------------
    PyQueue q;

    cout << "Empty? " << boolalpha << q.isEmpty() << endl;

    q.Enqueue(1);
    cout << "Peek: ";
    printVariant(q.Peek());
    cout << endl;

    q.Enqueue("Hello");
    cout << "Size: " << q.Size() << endl;

    cout << "Dequeue: ";
    printVariant(q.Dequeue());
    cout << endl;

    cout << "Size now: " << q.Size() << endl;


    // -------------------------------
    cout << "\n--- Test 4: PyStack ---\n";
    // -------------------------------
    PyStack s;

    cout << "Empty? " << boolalpha << s.isEmpty() << endl;

    s.Push(1);
    cout << "Peek: ";
    printVariant(s.Peek());
    cout << endl;

    s.Push("I am hello"s);

    cout << "Size: " << s.Size() << endl;
    cout << "Peek: ";
    printVariant(s.Peek());
    cout << endl;

    cout << "Pop: ";
    printVariant(s.Pop());
    cout << endl;


    // -------------------------------
    cout << "\n--- Test 5: PyList ---\n";
    // -------------------------------
    PyList arr;
    arr.add_var("Hey");
    arr.add_var(1);
    arr.add_var(true);

    arr.print();


    // -------------------------------
    cout << "\n🎉 All tests executed!\n";
    // -------------------------------
    return 0;
}