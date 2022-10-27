

#include <iostream>
#include <cmath>   
//#include <easy_plot.hpp>
using namespace std;
double y_0 = -0.733026, h = 0.1;

double y (double x)// заголовок функции
{
  return x * log (log (x));
}

double f_d (double z, double q)// заголовок функции
{
  return q / z + 1 / log (z) ;
}

double euler (double x, double y)
{  
  return y = y + h * f_d (x, y) ;
}

double dy(double k_1, double k_2, double k_3, double k_4 )
{
    return h * (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
}

double *method_euler()
{
    double f[11];
    f[0] = euler(2, y_0);// запуск функции нахождения 
    cout << f[0] << " " << y(2) << endl; // печать начального значения 

    for (int i = 1; i < 11; i++)
    {
        f[i] = euler(2 + i * h, h * f[i - 1]);// запуск функции нахождения 
        cout << "x= " << 2 + i * h << " f= " << f[i] << " " << y(2 + i * h) << endl; // печать значения 
    }   
    return f;
}

double* method_rundi()
{
    double k1 = f_d(2, y_0);
    double k2 = f_d(2 + h / 2, y_0 + h * k1 / 2);
    double k3 = f_d(2 + h / 2, y_0 + h * k2 / 2);
    double k4 = f_d(2 + h, y_0 + h * k3);
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
    double  *otv1= method_euler();
    //cout << otv1[2]<<" ";
    //cout << otv1[2];
    // 2 решение методом Рунди-Кута 4 порядка
   
    cout << "met2:" << endl;
    double* otv2 = method_rundi();
    
    cout << "met1:" << endl;

     return 0;
}
