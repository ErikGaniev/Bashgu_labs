#include <iostream>
#include <cmath>   
//#include <easy_plot.hpp>
using namespace std;
double y_0 = -0.733026, h = 0.1;
double xi[11], yi[11], yr3[11];

double y(double x)// заголовок функции
{
    return x * log(log(abs(x)));
}

double f_d(double z, double q)// заголовок функции
{
    return q / z + 1 / log(abs(z));
}

double euler(double x, double y)
{
    return y = y + h * f_d(x, y);
}

double dy(double k_1, double k_2, double k_3, double k_4)
{
    return h * (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
}

double* method_euler()
{
    double f[11];
    f[0] =y_0;// запуск функции нахождения 
    cout << f[0] << " " << y(2) << endl; // печать начального значения 

    for (int i = 1; i < 11; i++)
    {
        f[i] = euler(xi[i-1],  f[i - 1]);// запуск функции нахождения 
        cout << "x= " << xi[i] << " f= " << f[i] << " y= " << yi[i] << " ut-up= " << abs(f[i] -yi[i] ) << endl; // печать значения 
    }

    return f;
}

double* method_rundi()
{
     double yrk[11];
    yrk[0] = y_0;// запуск функции нахождения 

    cout << "x= " << 2 << " y=f= " << yrk[0] << endl; // печать начального значения 

    for (int i = 1; i < 11; i++)
    {
        double  k1 = f_d(xi[i-1], yrk[i - 1]);
        double k2 = f_d(xi[i-1] + h / 2, yrk[i - 1] + h * k1 / 2);
        double k3 = f_d(xi[i-1] + h / 2, yrk[i - 1] + h * k2 / 2);
        double k4 = f_d(xi[i-1] + h, yrk[i - 1] + h * k3);
        yrk[i] = yrk[i - 1] + dy(k1, k2, k3, k4);// запуск функции нахождения 
        cout << "x= " << xi[i] << " y= " << yi[i] << " f= " << yrk[i] << " ut-up= " << abs(yrk[i] - yi[i]) << endl; // печать начального значения 

    }

    return yrk;
}


int main()
{
    for (int i = 0; i < 11; i++)
    {
        xi[i] = 2 + i * h;
        yi[i] = y(xi[i]);
        cout << xi[i] << " " << yi[i] << endl;
    }

    // 1 решение методом Эйлера
    cout << "met1 :" << endl;

    double* otv1 = method_euler();
    //cout << otv1[2]<<" ";
    //cout << otv1[2];
    // 2 решение методом Рунди-Кута 4 порядка

    cout << "met2:" << endl;
    double* otv2 = method_rundi();


    cout << "met3:" << endl;


    yr3[0] = yi[0];
    // метод рунди кута третьего порядка
    double k13 = f_d(xi[0], yr3[0]);
    double k23 = f_d(xi[0] + h / 2, yr3[0] + h * k13 / 2);
    double k33 = f_d(xi[0] + h, yr3[0] - h * k13 + 2 * h * k23);


    for (int i = 1; i < 11; i++)
    {
        yr3[i] = yr3[i - 1] + h * (k13 + 4 * k23 + k33) / 6;
        k13 = f_d(xi[i], yr3[i]);
        k23 = f_d(xi[i] + h / 2, yr3[i] + h * k13 / 2);
        k33 = f_d(xi[i] + h, yr3[i] - h * k13 + 2 * h * k23);
        cout << "x=" << xi[i] << " y=" << yr3[i] << " ut-up= " << abs(yr3[i] - y(2 + i * h + h)) << endl;
    }


    return 0;
}
