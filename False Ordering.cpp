#include <iostream>

using namespace std;

bool prime[1001] = {false} ;
bool t_prime[1001] = {false} ;
bool almost_prime[1001] = {false};

void setPrime(){
    prime [1] = true;
    for(int i=2; i<=31; i++){
        if(!prime[i]){
            for(int j= i*i; j<=1000; j+=i){
                prime[j]= true;
            }
        }
    }
}
void setT_prime(){
    setPrime();
    for(int i=2; i<=32; i++){
        if(!prime[i]){
            t_prime[i*i] = true;
        }
    }

}
void setAlmost_prime(){
    setT_prime();
    for(int i=6;i < 1000; i++){
        if(prime[i] && !t_prime[i]){
            int mark = 0;
            for(int j=2; j<i; j++){
                if(i%j==0){
                    if(prime[j])
                        break;
                    if(prime[i/j])
                        break;
                    mark++;
                }
            }
            if(mark==2)
                almost_prime[i]= true;
        }
    }

}

int main() {
    setAlmost_prime();
    int  count = 0;
    for(int i=0; i < 1000; i++){
        if(almost_prime[i]){
            cout << i << endl;
            count++;
        }

    }
    cout << count << endl;
    return 0;
}