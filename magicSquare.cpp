#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>


// graph:
// https://www.desmos.com/calculator/er9zmnzxj7

using namespace std;

void generateMagicSquare(int n)
{
    vector<vector<int>> magicSquare;
    magicSquare = vector<vector<int>>(n, vector<int>(n, 0));

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;

        j++;
        i--;
    }
}


int main()
{

    int input_size = 1;

    while (input_size < 9999)
    {
        //
        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            generateMagicSquare(input_size);

        end = clock();

        // total time taken for running an algorithm 100 times for a specific input
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // avearge time time_taken/100
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        input_size = input_size + 100;
    }
    return 0;
}

// output:

// Average Time taken by for input size 1 is : 0.000071 sec 
// Average Time taken by for input size 101 is : 0.01220 sec 
// Average Time taken by for input size 201 is : 0.04550 sec 
// Average Time taken by for input size 301 is : 0.11222 sec 
// Average Time taken by for input size 401 is : 0.20062 sec 
// Average Time taken by for input size 501 is : 0.30087 sec 
// Average Time taken by for input size 601 is : 0.44390 sec 
// Average Time taken by for input size 701 is : 0.60828 sec 
// Average Time taken by for input size 801 is : 0.89931 sec 
// Average Time taken by for input size 901 is : 1.13723 sec 
// Average Time taken by for input size 1001 is : 1.47044 sec 
// Average Time taken by for input size 1101 is : 1.84373 sec 
// Average Time taken by for input size 1201 is : 2.15753 sec 
// Average Time taken by for input size 1301 is : 2.44503 sec 
// Average Time taken by for input size 1401 is : 2.87189 sec 
// Average Time taken by for input size 1501 is : 3.62417 sec 
