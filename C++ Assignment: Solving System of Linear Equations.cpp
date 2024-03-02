#include <iostream>
#include <vector>
#include <iomanip>  

using namespace std;

int main() {
    int number_of_systems;
    cin >> number_of_systems;

    while (number_of_systems--) {
        int number_of_equations;
        cin >> number_of_equations;

        vector<vector<double>> matrix(number_of_equations, vector<double>(number_of_equations + 1));


        for (int i = 0; i < number_of_equations; ++i) {
            for (int j = 0; j <= number_of_equations; ++j) {
                cin >> matrix[i][j];
            }
        }


        for (int i = 0; i < number_of_equations; ++i) {
            for (int j = 0; j < number_of_equations; ++j) {
                if (i != j) {
                    double ratio = matrix[j][i] / matrix[i][i];
                    for (int k = 0; k <= number_of_equations; ++k) {
                        matrix[j][k] -= ratio * matrix[i][k];
                    }
                }
            }
        }

    
        bool solvable = true;
        for (int i = 0; i < number_of_equations; ++i) {
            if (matrix[i][i] == 0 && matrix[i][number_of_equations] != 0) {
                solvable = false;
                break;
            }
        }

  
        if (!solvable) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < number_of_equations; ++i) {
                cout << fixed << setprecision(2) << matrix[i][number_of_equations] / matrix[i][i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
