
#include <iostream>
#include <cmath>   
//#include <easy_plot.hpp>
using namespace std;
double x_0=1, y_0 = 1,z_0=1, h = 0.1;

double y(double x)// заголовок функции
{
    return exp(2*x/2)/3+(3*x+1)*exp(x-1)/3;
}

double U(double x, double y,double z)// заголовок функции
{
    return (1+x)*z / x + 2*(x-1)*y / x;
}



double dy(double k_1, double k_2, double k_3, double k_4)
{
    return h * (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
}


double* method_rundi()
{
    double q0 = U(x_0, y_0,z_0);
    double k0 = z_0;
    double DY = k0, DZ = q0;
     
    double x[11];
    x[0] = x_0;
    x[1] = x_0 + h / 2;

    double y[11];
    y[0] = y_0;
    y[1] = y_0 + k0*h / 2;

    double z[11];
    z[0] = z_0;
    z[1] = z_0 + q0*h / 2;

    double q1 = U(x_0 + h / 2, y_0 + h * k0 / 2 ,z_0+q0*h/2);
    double k1 = z[1];
    DY = 2*k1, DZ = 2*q1;

    x[2] = x_0 + h / 2;
    y[2] = y_0 + k1 * h / 2;
    z[2] = z_0 + q1 * h / 2;


    double q2 = U(x_0 + h / 2, y_0 + h * k1 / 2 ,z_0+q1*h/2);
    double k2 = z[2];

    x[3] = x_0 + h ;
    y[3] = y_0 + k2 * h ;
    z[3] = z_0 + q2 * h ;
    double q3 = U(x_0 + h    , y_0 + h * k2     ,z_0+q2*h);
    double k3 = z[3];


    double yrk[11];
    yrk[0] = y_0 + dy(k1, k2, k3, k4);// запуск функции нахождения 
    cout << "x= " << 2 + h << " " << yrk[0] << endl; // печать начального значения 

    for (int i = 1; i < 10; i++)
    {
        k1 = f_d(2 + i * h, yrk[i - 1]);
        k2 = f_d(2 + i * h + h / 2, yrk[i - 1] + h * k1 / 2);
        k3 = f_d(2 + i * h + h / 2, yrk[i - 1] + h * k2 / 2);
        k4 = f_d(2 + i * h + h, yrk[i - 1] + h * k3);
        yrk[i] = yrk[i - 1] + dy(k1, k2, k3, k4);// запуск функции нахождения 
        cout << "x= " << 2 + i * h + h << " " << yrk[i] << endl; // печать начального значения 

    }
    return yrk;
}


int main()
{

    // 1 решение методом Эйлера
    cout << "met1:" << endl;
    double* otv1 = method_euler();
    //cout << otv1[2]<<" ";
    //cout << otv1[2];
    // 2 решение методом Рунди-Кута 4 порядка

    cout << "met2:" << endl;
    double* otv2 = method_rundi();

    cout << "met1:" << endl;

    return 0;
}
