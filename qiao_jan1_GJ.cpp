#include<iostream>
#include<iomanip>
using namespace std;

double** Matrix(int n, int m) {
    double** A = new double*[n];
    if (!A)
        return NULL;
    for (int i = 0; i < n; ++i) {
        A[i] = new double[m];
        if (!A[i])
            return NULL;
    }
    return A;
}

void DeleteMatrix(double** A, int n, int m) {
    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;
    A = NULL;
}

void PrintMatrix(double** A, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << setw(6) << A[i][j];
        cout << endl;
    }
    cout << endl;
}

void GE(double** P, double** A, int n, int m) {
    int ge_level;
    if (n < m)
        ge_level = n;
    else
        ge_level = m;

    for (int p = 0; p < ge_level; p++) {
        double pivot = A[p][p];
        int count = p, tmp;
        while (pivot == 0 && count < n)
            pivot = A[++count][p];

        if (count == n)
            continue;

        if (count != p) {
            double* temp = A[p];
            A[p] = A[count];
            A[count] = temp;

            temp = P[p];
            P[p] = P[count];
            P[count] = temp;
        }

        for (int i = p + 1; i < n; ++i) {
            double elim = A[i][p];
            for (int j = p; j < m; ++j)
                A[i][j] = A[i][j] - (A[p][j] * elim) / pivot;
        }
    }
}

int main() {
    cout << fixed << setprecision(2);
    int n, m;
    cin >> n >> m;

    // initialize P as a identity matrix
    double** P = Matrix(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            P[i][j] = 0;
        P[i][i] = 1;
    }

    // read in A
    double** A = Matrix(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];

    GE(P, A, n, m);
    // cout << endl << "P =" << endl;
    // PrintMatrix(P, n, n);
    cout << "Ans: " << endl;
    PrintMatrix(A, n, m);

    DeleteMatrix(A, n, m);
    DeleteMatrix(P, n, n);
    return 0;
}