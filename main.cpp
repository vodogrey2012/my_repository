#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cassert>


struct equation // структура данныйх уравнения
{
    float a, b, c; //ax^2+bx+c=0
    float D;     //Дсикриминант
    float x1, x2; // Корни
    bool type_a, type_b; //Нулевые ли коэффициенты a и b
};


void write_equation(equation); //Показ введенных данных
float solver_sqrt(equation* pone); // Решение квадратного ураванения
float solver_lin(equation* pone); // Решение линейного уравнения
bool solver_const(equation* pone); // Решение при коэффициентах при х и х^2 равными 0
bool read_float(float* number); // Правильность ввод данных
void read(equation* one); //Ввод данных
void myresult(equation* one); // вывод результата
bool unit_test();



int main()
{
    if(!unit_test()) return 0;
    else printf("checked\n");

    equation one;
    one.a=0;
    one.b=0;
    one.c=0;  // инициализация начальных элементов

    read(&one);
    write_equation(one);
    myresult(&one);



    return 0;
}


void read(equation* pone)
{

    assert(pone!=NULL);
    float d=0; // Четвертый коэффициент не объявленный в структуре
    float* pd=&d;

    printf("Enter the coefficients ax^2+bx+c=d \n")  ;
    printf("a=");
    while (!read_float(&pone->a)) printf ("ERROR! Try again. \na=");
    printf("b=");
    while (!read_float(&pone->b)) printf ("ERROR! Try again. \nb=");
    printf("c=");
    while (!read_float(&pone->c)) printf ("ERROR! Try again. \nc=");
    printf("d=");
    while (!read_float(pd)) printf ("ERROR! Try again. \nd=");

    pone->c=pone->c-d;

    if (pone->a==0) pone->type_a=false;
    else pone->type_a=true;

    if (pone->b==0) pone->type_b=false;
    else pone->type_b=true;
}


bool read_float(float* variable)
{
    assert(variable!=NULL);
    char* data=new char; // ввод числа
    unsigned int i; // длинна введенного числа, счетчик
    int current; //символ числа, который проверяется


    scanf ("%s" , data);

    for (i=0; i<strlen(data); i++)
    {
        current=data[i];
        if ( (current>=58 || current<=47) && (current!=43) && (current!=45) && (current!=46)  ) // проверка символа 0-9,".", "+", "-"
        {
            return false;
        }
    }

    *variable=atof(data);

    return true;

}


void write_equation(equation one)
{
    printf("--------------\n");

    if ((one.b>=0) && (one.c>=0)) printf("%gx^2+%gx+%g=0\n" , one.a , one.b , one.c);
    if ((one.b>=0) && (one.c<0)) printf("%gx^2+%gx%g=0\n" , one.a , one.b , one.c);
    if ((one.b<0) && (one.c>=0)) printf("%gx^2%gx+%g=0\n" , one.a , one.b , one.c);
    printf("--------------\n");
}


float solver_sqrt(equation* pone)
{
    assert(pone!=NULL);
    float d;
    d=pone->b*pone->b-4*pone->a*pone->c; // Дискриминант
    pone->x1=(-pone->b-sqrt(fabs(d)))/(2*pone->a);
    pone->x2=(-pone->b+sqrt(fabs(d)))/(2*pone->a);

    return d;
}


float solver_lin(equation* pone)
{
    assert(pone!=NULL);
    return (-(pone->c/pone->b));
}


bool solver_const(equation* pone)
{
    assert(pone!=NULL);
    return (pone->c == 0);
}

void myresult(equation* pone)
{

    assert(pone!=NULL);
    if ((pone->type_a==false)&&(pone->type_b==true))
    {
        printf ("Linear equation\n") ;
        printf("x=%g" , solver_lin(pone));
    }



    if ((pone->type_a==true))
    {
        printf("Square equation\n");

        if (solver_sqrt(pone)>=0)
        {
            if (pone->x1==pone->x2) printf("Similar real solutions:\n"
                                       "x1=x2=%g" , pone->x1);
            else printf("Different real solutions:\n"
                        "x1=%g, x2=%g" , pone->x1 , pone->x2);
        }
        else // x=re+-i*im
        {
            float re,im;
            re=(-pone->b/(2*pone->a));
            im=(sqrt(-pone->D)/(2*pone->a));
            printf("Complex solutions:\n"
                   "x1=%g-i*%g, x2=%g+i*%g" , re , im , re, im);
        }
    }



    if ((pone->type_a==false)&&(pone->type_b==false))
    {
        printf("Constant\n");
        if (solver_const(pone)) printf("x - Any value");
        else printf("No solution");
    }
}

bool unit_test()
{
    equation test;
    float D=0, x1=0, x2=0;


    FILE* f=fopen("unit_test.txt", "r");
    //fscanf(f, "%e %e %e %e %e %e\n" , &test.a, &test.b, &test.c, &D, &x1, &x2);

    while(fscanf(f, "%g %g %g %g %g %g\n" , &test.a, &test.b, &test.c, &D, &x1, &x2)!=EOF)
    {
        test.D=solver_sqrt(&test);
        if ((D!=test.D) || (x1!=test.x1) || (x2!=test.x2))
        {
            printf("ERROR! Test:\n"
                   "a=%g ; b=%g ; c=%g\n"
                   "D=%g; should be D=%g\n"
                   "x1=%g; should be x1=%g\n"
                   "x2=%g; should be x2=%g\n"
                   "unit_test.txt\n"
                   "----------" , test.a, test.b, test.c, test.D, D, test.x1, x1, test.x2, x2);
            return 0;
        }
    }
    fclose(f);

    return 1;

}





