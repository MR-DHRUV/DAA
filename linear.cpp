#include <iostream>
#include <cmath>

using namespace std;

double evalPolynomial(double coefficients[], int degree, double x)
{
    double result = 0.0;
    for (int i = 0; i <= degree; i++)
    {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

double findRealZeroLinear(double coefficients[], int degree, double start, double end)
{
    double step = 0.01; // Step size for linear search
    double x = start;
    double y = evalPolynomial(coefficients, degree, x);

    while (x <= end)
    {
        if (y == 0)
        {
            return x; // Found a zero within the tolerance
        }
        x += step;
        y = evalPolynomial(coefficients, degree, x);
    }

    return NAN; // No zero found within the given interval
}

int main()
{
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    double coefficients[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        cout << "Enter the coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    double start, end, epsilon;
    cout << "Enter the start and end points of the interval: ";
    cin >> start >> end;

    double zero = findRealZeroLinear(coefficients, degree, start, end);

    if (!isnan(zero))
    {
        cout << "Real zero found at x = " << zero << endl;
    }
    else
    {
        cout << "No real zero found within the given interval." << endl;
    }

    return 0;
}
