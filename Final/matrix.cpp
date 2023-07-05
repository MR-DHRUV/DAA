#include <iostream>
#include <vector>
#include <random>

template <typename T>
class Matrix
{
private:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols)
    {
        // Initialize the matrix with default values
        data.resize(rows, std::vector<T>(cols));
    }

    void set(int row, int col, const T &value)
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            data[row][col] = value;
        }
        else
        {
            std::cout << "Error: Invalid row or column index!" << std::endl;
        }
    }

    T get(int row, int col) const
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            return data[row][col];
        }
        else
        {
            std::cout << "Error: Invalid row or column index!" << std::endl;
            return T(); // Return a default value
        }
    }

    int numRows() const
    {
        return rows;
    }

    int numCols() const
    {
        return cols;
    }

    void print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix<T> operator+(const Matrix<T> &other) const
    {
        if (rows != other.numRows() || cols != other.numCols())
        {
            std::cout << "Error: Matrix dimensions mismatch!" << std::endl;
            return Matrix<T>(0, 0);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.set(i, j, data[i][j] + other.get(i, j));
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T> &other) const
    {
        if (rows != other.numRows() || cols != other.numCols())
        {
            std::cout << "Error: Matrix dimensions mismatch!" << std::endl;
            return Matrix<T>(0, 0);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.set(i, j, data[i][j] - other.get(i, j));
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T> &other) const
    {
        if (cols != other.numRows())
        {
            std::cout << "Error: Matrix dimensions mismatch!" << std::endl;
            return Matrix<T>(0, 0);
        }

        Matrix<T> result(rows, other.numCols());
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.numCols(); j++)
            {
                T sum = T();
                for (int k = 0; k < cols; k++)
                {
                    sum += data[i][k] * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }
    void initializeRandom()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T> dis(0.0, 1.0);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = dis(gen);
            }
        }
    }
};
int main()
{
    Matrix<double> matrix(3, 3);

    matrix.initializeRandom();

    matrix.print();

    return 0;
}