/*
 * Prompts user for a line of text and displays it backwards. To demonstrate
 * a second template instantiation, the program also outputs three sentences
 * and then outputs them again in reverse order.
 *
 * Points of discussion: class templates, template classes, the impossibility 
 * of separate compilation with template classes.
 *
 * Execution snapshot:
 *
 *      Enter a line of text.
 *      > The circle is now complete.
 *      > .etelpmoc won si elcric ehT
 *
 *      Your powers are weak, old man.
 *      You weren't on any mercy mission this time.
 *      An elegant weapon, for a more civilized age.
 *      An elegant weapon, for a more civilized age.
 *      You weren't on any mercy mission this time.
 *      Your powers are weak, old man.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cstring>
#include "stack4.cpp" // Note this!
using namespace std;

int main() {
    const int MAX_INPUT_LEN = 100;
    Stack<char> stack_of_chars(MAX_INPUT_LEN);

    cout << "Enter a line of text.\n> ";
    char c;
    cin.get(c);

    // Push input characters onto the stack.
    while (c != '\n') {
        stack_of_chars.push(c);
        cin.get(c);
    }

    // Pop off and print.
    cout << "> ";
    while (!stack_of_chars.is_empty())
        cout << stack_of_chars.pop();
    cout << "\n\n";

    char lines[3][100];
    strcpy(lines[0], "Your powers are weak, old man.");
    strcpy(lines[1], "You weren't on any mercy mission this time.");
    strcpy(lines[2], "An elegant weapon, for a more civilized age.");

    // Push strings onto the stack.
    Stack<const char*> stack_of_strings;
    for (int i = 0; i < 3; i++) {
        stack_of_strings.push(lines[i]);
        cout << lines[i] << endl;
    }

    // Pop off and print.
    while (!stack_of_strings.is_empty())
        cout << stack_of_strings.pop() << endl;
    return 0;
}