#define ll long long
#include <ctime>
#include <iostream>
using namespace std;


// Disclaimer: the following code uses linear congruential method for generating random numbers

// coefficient used for generation of random numbers
ll par;

// variable that stores random values
ll seed = time(0);

// function setting "par" variable, depending on the array length (for more efficient generation)
void par_set(ll n){
    ll b = 1;
    ll k = 2;
    while (k * k <= n){
        if (n % k == 0){
            if (b % k != 0){
                b *= k;
            }
            n /= k;
        }
        else{
            k++;
        }
    }
    if (n > 1 and b % n != 0){
        b *= n;
    }
    par = 2 * b + 1;
}


// function generating random numbers from 0 to n
ll new_rand(ll n){
    
    par_set(n);
    
    seed = (seed * par + par - 2) % n;
    return seed;
}


// function performing summation of k random array values
double ran_sum(double* a, ll n, ll k){
    double s = 0;
    for (int i = 0; i < k; i++){
        ll ind = new_rand(n);
        s += a[ind];
    }
    return s;
}








int main()
{
    // testing the implemented fuction

    ll n, k;
    cin >> n >> k;
    
    double* a = new double[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cout << ran_sum(a, n, k) << endl;
    
    
    return 0;
}