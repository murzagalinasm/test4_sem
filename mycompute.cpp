#include <iostream>
#include <cmath>
#include <vector>
#include <string>

//#define CONCAT -4;
//#define MULT -3;
//#define PLUS -2;
//#define MINUS -1;

using namespace std;

enum OPERATORS {CONCAT = -4, MULT = -3, PLUS = -2, MINUS = -1 };


bool Calculate(vector<int>& numbers, vector<int>& operators, int result){
    vector<int> oper = operators;
    vector<int> num = numbers;

    
    
    for(int i = 0; i < oper.size();){
        if(oper[i] == CONCAT){
            num[i] = num[i]*10 + num[i+1];
            num.erase(num.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i = 0;
        } else{
            i++;
        }

    }

    for(int i = 0; i < oper.size();){
        if(oper[i] == MULT){
            num[i] = num[i] * num[i+1];
            num.erase(num.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i = 0;
        } else{
            i++;
        }
    }

    for(int i = 0; i < oper.size();){
        if(oper[i] == PLUS){
            num[i] = num[i] + num[i+1];
            num.erase(num.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i = 0;
        }else{
            i++;
        }
    }

    for(int i = 0; i < oper.size(); ){
        if(oper[i] == MINUS){
            num[i] = num[i] - num[i+1];
            num.erase(num.begin() + i + 1);
            oper.erase(oper.begin() + i);
            i = 0;
        }else{
            i++;
        }
    }
    
    return (num[0] == result);

}


void Change(vector<int>& oper){
    oper[oper.size()-1]++;
    for(int i = oper.size() - 1; i > 0; i--){
        if (oper[i] == 0){
            oper[i] = -4;
            oper[i-1]++;
        }
    }
}




void PrintOper(int a){
    switch (a){
        case CONCAT:
            break;
        case MULT:
        cout << "*";
            break;
        case PLUS:
        cout << "+";
            break;
        case MINUS:
        cout << "-";
            break;

    }
}



void PrintResult(int result, vector<int>& num, vector<int>& oper){
    int result_size = 2*num.size() - 1;
    int k = 0; //счётчик для значений
    int m = 0; //счётчик для знаков


    for(int i = 0; i < result_size; i++){
        if(i%2 == 0){
            cout << num[k];
            k++;
        }
        else{
            PrintOper(oper[m]);
            m++;
        }
    }
    cout << " " << "=" << " " << result << endl;
}



int main (int ac, char* av[]){
    int result = atoi(av[1]);
    int size = ac - 2;
    int k = 0;//счётчик кол-ва решений

    vector<int> num(size);
    vector<int> oper(size - 1);
    
    
    for(int i = 0; i < oper.size(); i++){
        oper[i] = CONCAT;
    }

    

    for(int i = 0; i < size; i++){
        num[i] = atoi(av[2+i]);
    }

    long long perebor = pow(4, size - 1);


    for(int i = 0; i < perebor; i++){
        if(Calculate(num, oper, result)){
            PrintResult(result, num, oper);
	    k++;
        }	
	
        Change(oper);
    }
    
    if(k == 0){
		cout << " has not found any combination " << endl;

    }

    return 0;
}
