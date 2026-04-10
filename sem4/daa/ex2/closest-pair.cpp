#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    int x1,y1,x2,y2;

    cout << "Enter number of points: ";
    cin >> n;

    double x[100], y[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter x and y for point " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    double shortest = 999999.0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            double dx = x[i] - x[j];
            double dy = y[i] - y[j];

            double d = sqrt(dx * dx + dy * dy);

            if (d < shortest) {
                shortest = d;
                x1 = x[i];
                y1 = y[i];
                x2 = x[j];
                y2 = y[j];
            }
        }
    }

    cout << "The smallest distance is: " << shortest << endl;
    cout<< "The points are (" << x1 << "," << y1 <<" ) , (" << x2 << "," <<y2 <<" )";
    return 0;
}