/*
 * Outputs two random integers before and after swapping them, and then
 * outputs two random strings before and after swapping them.
 *
 * Points of discussion: function templates, template functions, strings.
 *
 * Execution snapshot:
 *
 *      Before: 574 927
 *       After: 927 574
 *      Before: XSXPJ QSNRL
 *       After: QSNRL XSXPJ
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// returns a string of five random uppercase letters
std::string get_letters();

// custom version of swap function defined in <utility>
namespace my_swap {
    template <typename T>
    void swap(T& x, T& y) {
       T temp = x;
       x = y;
       y = temp;
    }
}

int main() {
    srand(time(0));
    int a = rand() % 1000;
    int b = rand() % 1000;
    cout << "Before: " << a << " " << b << endl;
    my_swap::swap(a, b);
    cout << " After: " << a << " " << b << endl;

    string s = get_letters();
    string t = get_letters();
    cout << "Before: " << s << " " << t << endl;
    my_swap::swap(s, t);
    cout << " After: " << s << " " << t << endl;
    return 0;
}

string get_letters() {
    string s;
    for (int i = 0; i < 5; i++) {
        char c = 'A' + rand() % 26;
        s += c;
    }
    return s;
}