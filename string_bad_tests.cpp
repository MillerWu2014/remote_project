#include <iostream>
#include "stock/stringbad.h"

using std::cout;

void callme1(StringBad & rsb);
void callme2(StringBad sb);

int main(int argc, char const *argv[])
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks as Midnight!");
        StringBad headline2("Lettrce Prey.");
        StringBad sports("Sprinach Leaves Bowl for Dollars");

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1);
        cout << "headline1: " << headline1 << endl;

        callme2(headline2);
        cout << "headline2: " << headline2 << endl;

        cout << "Initalizing one object to another: \n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;

        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";

    return 0;
}

void callme1(StringBad & rsb){
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb){
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}
