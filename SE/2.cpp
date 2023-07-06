#include <iostream>
using namespace std;
int main()
{
    int external_inputs, external_outputs, external_inquiries, internal_logical_files,
        external_interface_files;
    cout << "Enter the number of External Inputs: ";
    cin >> external_inputs;
    cout << "Enter the number of External Ouputs: ";
    cin >> external_outputs;
    cout << "Enter the number of External Inquiries: ";
    cin >> external_inquiries;
    cout << "Enter the number of Internal Logical Files: ";
    cin >> internal_logical_files;
    cout << "Enter the number of External Interface Files: ";
    cin >> external_interface_files;
    int ufp = external_inputs + external_outputs + external_inquiries +
              internal_logical_files + external_interface_files;
    cout << "The Unadjusted Function Point count = " << ufp << endl;
    int complexity_factor;
    cout << "Enter the complexity factor (1 : Low, 2 : Average, 3 : High) : ";
    cin >> complexity_factor;
    double caf;
    if (complexity_factor == 1)
    {
        caf = 0.65;
    }
    else if (complexity_factor == 2)
    {
        caf = 1.00;
    }
    else if (complexity_factor == 3)
    {
        caf = 1.35;
    }
    else
    {
        cout << "Invalid Complexity Factor!" << endl;
        cout << "Enter the value of Complexity Adjustment Factor: ";
        cin >> caf;
    }
    double fp = ufp * caf;
    cout << "The Adjusted Function point count = " << fp << endl;
    return 0;
}