#include <iostream>
#include <math.h>

using namespace std;

double evalEquation(int a[], int d, double x)
{
    double res = a[0];
    double powerX = 1.0;
    for (int i = 1; i <= d; i++)
    {
        powerX *= x;
        res += a[i] * powerX;
    }
    return res;
}

void findRoots(double a, double b, double epsilon, int arr[], int d)
{
    double c = (a + b) / 2;
    double fc = evalEquation(arr, d, c);
    if (fc == 0 || (b-a) <= epsilon)
    {
        cout << "roots found at x = " << c << endl;
        return;
    }
    else
    {
        double fa = evalEquation(arr, d, a);
        double fb = evalEquation(arr, d, b);
        if (fa * fc < 0)
            findRoots(a, c, epsilon, arr, d);
        if (fc * fb < 0)
            findRoots(c, b, epsilon, arr, d);
    }
}

int main()
{
    int d;
    cout << "Enter degree of equation: ";
    cin >> d;
    int arr[d + 1];

    for (int i = 0; i < d + 1; i++)
    {
        cout << "Enter Coefficient of x^" << i << ": ";
        cin >> arr[i];
    }

    double a, b, epsilon;

    cout << "Left interval, Right interval and tolerance:  ";
    cin >> a >> b >> epsilon;

    findRoots(a, b, epsilon, arr, d);
    return 0;
}
