#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> fdriver( int n, vector<int> primes, vector<int> &f){
    for(int p = 0; p < primes.size(); p++){
        if(n==primes[p]){
            f.push_back(primes[p]);
            return f;
        }else if(n%primes[p]== 0){
            f.push_back(primes[p]);
            return fdriver(n/primes[p],primes,f);
        }
    }
    return f;
}


vector<int> factors(int num, vector<int> primes){
    vector<int> f;
    for(int p = 0; p < primes.size(); p++){
        if(num==primes[p]){
            f.push_back(primes[p]);
            return f;
        }else if(num%primes[p]== 0){
            f.push_back(primes[p]);
            return fdriver(num/primes[p],primes,f);
        }
    }
    return f;
}



int main(){
    vector<int> primes;
    vector<vector <int> > fs;
    primes.push_back(2);
    bool prime;
    for(int num = 3; num<1001; num++){
        prime = true;
        for(int p = 0; p < primes.size(); p++){
            if(num%primes[p]==0){
                prime = false;
                break;
            }
        }
        if(prime){
            primes.push_back(num);
        }
        fs.push_back(factors(num,primes));
    }
    cout << "PRIMES: ";
    for(int p = 0; p < primes.size(); p++){
        cout << primes[p] << " ";
    }
    cout << "\n";
    cout << "Prime Factorization: " << endl;
    for(int f = 0; f < fs.size(); f++){
        cout << f+3 << ": ";
        for(int x = 0; x < fs[f].size(); x++){
            cout << fs[f][x] << " ";
        }
        cout << endl;
    }
    return 0;
}
