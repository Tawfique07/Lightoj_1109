#include <iostream>
#include <utility>
#include <cmath>


using namespace std;

struct Order{
    int number;
    int divisor;
};

 Order falseOrder[1001];

int divisor(int num);
void order();
void sort();

int main(){
    order();
    int T;
    cin >> T;

    for(int i=1; i<=T; i++){
        int num;
        cin >> num;
        cout << "Case " << i << ": " << falseOrder[num].number << endl;
    }

}


int divisor(int num){
    int count = 0;
    int test = sqrt(num);
    for(int i=1; i<=test;i++){
        if(num%i==0){
            if(i*i==num){
                count+=1;
            }
            else{
                count+=2;
            }
        }
    }

    return count;
}


void order(){
    falseOrder[0].number=0;
    falseOrder[0].divisor=0;
    int n=1001;
    while (--n){
        falseOrder[n].number = n;
        falseOrder[n].divisor = divisor(n);
    }

    sort();

}

void sort(){
    for(int i=0;i<1000;i++){
        for(int j=i+1; j<=1000; j++){
            if(falseOrder[i].divisor >= falseOrder[j].divisor){
                swap(falseOrder[i],falseOrder[j]);
            }
        }
    }
}