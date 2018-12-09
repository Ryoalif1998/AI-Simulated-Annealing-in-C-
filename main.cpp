#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include<time.h>
#include<math.h>
#include<cmath>

#define PI 3.14159265
using namespace std;

int main()
{
    //pendefinisian nilai dari t, x1, dan juga x2 yang akan dilakukan pencarian
    double t = 780;
    srand(time(NULL));
    double x1 = 0;
    double x2 = 0;
    //lakukan pendefinisian nilai sin dan cos berdasarkan nilai dari x1 dan x2
    double nilaisin = sin(x1);
    double nilaicos = cos(x2);
    //melakukan perhitungan nilaipangkat menggunakan rumus matematis fungsi yang akan dilakukan pencarian
    double nilaipangkat = exp(abs(1-(sqrt((x1*x1)+(x2*x2))/PI)));
    double fx = -abs(nilaisin*nilaicos*nilaipangkat);
    //dikarenakan belum terdapat perbandingan nilai fungsi, maka nilai fxb terbaik diisi oleh nilai fungsi fx
    double fxb = fx;
    double eb = fxb;
    double e = fx;
    double x1b = x1;
    double x2b = x2;
    //melakukan perulangan saampai nilai t lebih kecil daripada 0
    while (t >= 0){
        //nilai x2 baru didapatkan dari nilai x2 sebelumnya dikurang oleh 0.1 sehingga pencarian yang dilakukan akan berurut
        double x2n = x2 - 0.1;
        double x1n;
        //jika nilai dari x2 baru msh lebih besar dari -10 maka nilai dari x2 yang baru akan diisi tetap
        if (x2n>=-10){
            x2n = x2n;
        }
        //jika nilai x2 baru lebih kecil dari -10, maka nilai x2 baru akan direset kembali ke angka 0, dan nilai x1 baru akan dikurangi 0.1
        else{
            x1n = x1n - 0.1;
            x2n = 0;
            if (x1n <= -10){
                x1n = x1b;
            }
        }
        //nilai dari x1 baru dan x2 baru akan dimasukkan kedalam pendefinisian sin dan cos
        nilaisin = sin(x1n);
        nilaicos = cos(x2n);
        //akan dilakukan perhitungan matematis terhadap fungsi berdasarkan nilai x1 baru dan x2 baru
        nilaipangkat = exp(abs(1-(sqrt((x1n*x1n)+(x2n*x2n))/PI)));
        double fxn = -abs(nilaisin*nilaicos*nilaipangkat);
        double en = fxn;
        double deltaE = en - e;
        //jika hasil dari deltae yang didapatkan dari pengurangan hasil energy baru dikurangi energy lama
        if (deltaE<0){
            //jika hasil dari deltae lebihkecil dari 0 maka nilai x1 dan x2 akan diganti dengan nilai x1 dan x2 baru
            x1 = x1n;
            x2 = x2n;
            //lakukan oengecekan pada hasil nilai ebergy baru dengan nilai energy terbaik yang dimiliki saat ini
            if (en<eb){
                //jika nilai energy baru lebih kecil dari energy terbaik yang dimiliki, maka nilai energy terbaik akan diisi oleh nilai energy baru, begitu juga dengan nilai x1 terbaik dan x2 terbaik
                eb = en;
                x1b = x1n;
                x2b = x2n;
            }
        }
        //jika hasil delta e lebihbesar dari 0
        else {
            //nilai p akan diisi oleh hasil perhitungan exp negatif deltae dibagi oleh t, dan nilai r akan dirandom
            double p = exp(-deltaE/t);
            double r = rand();
            //jika nilai r hasil random lebh kecil dari nilai hasil perhitungan p, maka nilai x1 akan diisi oleh nilai x1 baru, begitu juga dengan x2
            if (r < p) {
                x1 = x1n;
                x2 = x2n;
            }
        }
        //lakukan output hasil dari x1 terbaik, x2 terbaik, dan juga energy terbaik yang didapatkan

        t = t-0.1;
    }
    printf ("Nilai =  X1 Terbaik = %f X2 Terbaik = %f Energy = %f\n", x1b, x2b, eb );
}
