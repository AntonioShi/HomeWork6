//
// Created by antonio on 17-11-14.
//
/*
 * [ 发布人： 曲超   截止时间：2017-11-28 23:59:59  ]
    委员会问题是:从一个有n个人的团体中抽出k (k≤n)个人组成一个委员会，
     计算共有多少种构成方法，设计求解委员会问题的算法。
 */

#include <iostream>
using namespace std ;

class Arrangement{
private:
    int m, n ;
    long sum ;

public:
    void input(){
        cout << "下标："; cin >> m ;
        cout << "上标："; cin >> n ;//
    }

    void output(){
        cout << "C(" << m << "," << n << ") = " << sum << endl ;
    }

    int Combination(int m, int n){//排列
        int sum = 1 ;
        if (m < 0 || n < 0 || m < n){
            return -1;
        } else{

            if (n == 1){
                return m;
            } else {
                for (int i = m; i > m-n; i--) {
                    sum *= i ;
                }
            }
        }
        return sum ;
    }

    void Calculate(){//组合
        if (n <= 0 || m <= 0 || n > m){
            cout << "输入错误，请反思自己的行为" << endl ;
            return;
        }
        else if (n == m-1){
            sum = m ;
        }
        else{
            sum = Combination(m, n) / Combination(n, n) ;
            return;
        }
    }

};


int main(){
    Arrangement a ;
    a.input() ;
    a.Calculate() ;
    a.output() ;
    return 0 ;
}