#include <iostream>
#include <vector>

using namespace std;

const long long int M = 21474836479;   // modulus
const long long int A1 = 4001139;       // multiplier for LCG 1
const long long int A2 = 40697;       // multiplier for LCG 2
const long long int C = 0;            // increment
const long long int K = 4096;         // number of output values to generate

// LCG 1 initial seed value
long long int x1 = 1;

// LCG 2 initial seed value
long long int x2 = 1;

// Generate next random number using LCG 1
long long int lcg1() {
    x1 = (A1 * x1 + C) % M;
    return x1;
}

// Generate next random number using LCG 2
long long int lcg2() {
    x2 = (A2 * x2 + C) % M;
    return x2;
}

// Generate next random number using the CLCG algorithm
long long int clcg() {
    long long int z = (lcg1() - lcg2()) % M;
    if (z < 0) {
        z += M;
    }
    return z;
}

int main() {

    // disable default 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // set our properties
    #ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt","r",stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt","w",stdout);
    #endif


    vector<long long int> rand_nums(K);

    // Generate K random numbers using CLCG
    for (long long int i = 0; i < K; i++) {
        rand_nums[i] = clcg();
    }

    // Prlong long int the generated random numbers
    for (long long int i = 0; i < K; i++) {
        cout << rand_nums[i] << endl;
    }

    return 0;
}
