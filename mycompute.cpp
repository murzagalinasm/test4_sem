#include<cmath>
#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
int Flag = 0;
//0 - nothing;
//1 - +;
//2 - -;
//3 - *;
//4 - /;
int *Sum(int *count, int size, int i)
{
    count[i] = count[i] + count[i + 1];
    i++;
    while (i < size)
    {
        count[i] = count[i + 1];
        i++;
    }
    count[i] = NULL;
    return count;
}
 
int *Minus(int *count, int size, int i)
{
    count[i] = count[i] - count[i + 1];
    i++;
    while (i < size)
    {
        count[i] = count[i + 1];
        i++;
    }
    count[i] = NULL;
    return count;
}
 
int *Mult(int *count, int size, int i)
{
    count[i] = count[i] * count[i + 1];
    i++;
    while (i < size)
    {
        count[i] = count[i + 1];
        i++;
    }
    count[i] = NULL;
    return count;
}
 
int *Divide(int *count, int size, int i)
{
    count[i] = count[i] / count[i + 1];
    i++;
    while (i < size)
    {
        count[i] = count[i + 1];
        i++;
    }
    count[i] = NULL;
    return count;
}
 
void calculate(int*oper,int*count,int ansv,int sizeoper)
{
    int i;
    int m = sizeoper + 1;
    int*count2 = new int[m];
    for (i = 0; i < m; i++)
        count2[i] = count[i];
    int c=0;
    i = 0;
    while (i<sizeoper)
    {
        if (oper[i] == 3)
        {
            Divide(count2, m,i-c);
            m--;
            c++;
        }
        else
            if((oper[i] == 4))
            {
                Mult(count2, m, i-c);
                m--;
                c++;
            }
        i++;
    }
    c = 0;
    i = 0;
    while (i<sizeoper)
    {
        if (oper[i] == 1)
        {
            Sum(count2, m, i-c);
            m--;
            c++;
        }
        else
            if ((oper[i] == 2))
            {
                Minus(count2, m, i-c);
                m--;
                c++;
            }
        i++;
    }
    int a = 0;
    int b = 0;
    for (int k = 0; k < sizeoper; k++)
        cout << oper[k];
    cout << endl;
    for (int k = 0; k < m; k++) 
    {
        a += count2[k] * pow(10, m - k-1);
    }
    cout << a <<  "This A"<<endl;
    if (a == ansv)
    {
        cout << "TRUE";
        Flag = 1;
        for (int k = 0; k < sizeoper+1; k++)
        {
            cout << count[k];
            if ((oper[k] != 0) && (k != sizeoper + 1))
            {
                if (oper[k] == 1)
                {
                    cout << " + ";
                }
                if (oper[k] == 2)
                {
                    cout << " - ";
                }
                if (oper[k] == 3)
                {
                    cout << " * ";
                }
                if (oper[k] == 4)
                {
                    cout << " / ";
                }
            }
        }
        if (Flag == 1)
            exit(1);
    }
    
    system("PAUSE");
}
 
void Perebor(int *oper, int size, int sizeoper, int*count, int b, int m = 0)
{
    int i = m;
    int l = 0;
    if (i == sizeoper)
        {
            
            calculate(oper, count, b, sizeoper);
        }
    else
        while ( l < size)
        {
            oper[i] = l;
            Perebor(oper, size, sizeoper,count, b, m + 1);
            l++;
        }
}
 
 
int main()
{
    int a,b,i,pos,q;
    i = 0;
   
    string num,num1,num2;
    getline(cin, num);
    num.find(' ', pos);
    num.copy(num1,pos-1,0);
    q = num.length();
    num.copy(num2,q-pos,pos);
        
    a = stoi(num1);
    int *count = new int[i-1];
    int *oper = new int[i - 2];
    for (int k = 0; k < i - 2; k++)
        oper[k] = 0;
    int t = i-2;
    while (t+1)
    {
        count[t] = a % 10;
        a = a / 10;
        t--;
    }
    b = stoi(num2);
    Perebor(oper, 5,i-2,count,b);
    system("PAUSE");
    return 0;
}
