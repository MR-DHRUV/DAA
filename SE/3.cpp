#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int kloc, mode;
    cout << "Enter the size of the software in KLOC (thousands of lines of code): ";
    cin >> kloc;

    cout << "Enter the mode (1 : Organic, 2 : Semi-Detached, 3 : Embedded): ";
    cin >> mode;
    double effort, duration;

    if (mode == 1)
    {
        effort = 2.4 * pow(kloc, 1.05);
        duration = 2.5 * pow(effort, 0.38);
    }
    else if (mode == 2)
    {
        effort = 3.0 * pow(kloc, 1.12);
        duration = 2.5 * pow(effort, 0.35);
    }
    else if (mode == 3)
    {
        effort = 3.6 * pow(kloc, 1.20);
        duration = 2.5 * pow(effort, 0.32);
    }
    else
    {
        cout << "Inavlid Mode!" << endl;
        return 1;
    }

    int Avg_staff_size = effort / duration;

    cout << "The Effort required = " << effort << " Person Months." << endl;
    cout << "The Development time required = " << duration << " Months." << endl;
    cout << "Average Staff Size required = " << Avg_staff_size << " Persons." << endl;

    return 0;
}