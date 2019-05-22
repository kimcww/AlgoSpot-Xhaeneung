#include<map>
#include<iostream>
#include<string.h>

using namespace std;

map<string,int> Value;
map<int,string> Value2;

char FailBuffer[11];
char ResultBuffer[11];

void mapping(){

    Value["zero"] = 0;
    Value["one"] = 1;
    Value["two"] = 2;
    Value["three"] = 3;
    Value["four"] = 4;
    Value["five"] = 5;
    Value["six"] = 6;
    Value["seven"] = 7;
    Value["eight"] = 8;
    Value["nine"] = 9;
    Value["ten"] = 10;

    Value2[0] = "zero";
    Value2[1] = "one";
    Value2[2] = "two";
    Value2[3] = "three";
    Value2[4] = "four";
    Value2[5] = "five";
    Value2[6] = "six";
    Value2[7] = "seven";
    Value2[8] = "eight";
    Value2[9] = "nine";
    Value2[10] = "ten";
}

int main()
{
    mapping();
    int Input;
    cin>>Input;

    for(int i = 0; i < Input ; i++){
        string FirstValue;
        char Operation;
        string SecondValue;
        string equal;
        string strResult;

        int Result = 0;

        cin>>FirstValue>>Operation>>SecondValue>>equal>>strResult;

        switch (Operation) {
        case '+' :{
            Result = Value[FirstValue] + Value[SecondValue];
            break;
        }
        case '-' :{
            Result = Value[FirstValue] - Value[SecondValue];
            break;
        }
        case '*' :{
            Result = Value[FirstValue] * Value[SecondValue];
            break;
        }
        case '/' : {
            Result = Value[FirstValue] / Value[SecondValue];
        }
        }
        if( Result > 10 || Result < 0){
            cout<<"No"<<endl;
        }else {
            if( Value[strResult] == Result ){
                cout<<"Yes"<<endl;
            } else{

                memset(FailBuffer, 0, sizeof(FailBuffer));
                memset(ResultBuffer, 0 , sizeof(ResultBuffer));
                strcpy(FailBuffer,strResult.c_str());
                strcpy(ResultBuffer,Value2[Result].c_str());

                for(unsigned long long l = 0; l < strResult.size(); l++){
                    for(unsigned long long k = 0; k < strResult.size(); k++){
                        if(ResultBuffer[l] == FailBuffer[k]){
                            ResultBuffer[l] = 0;
                            FailBuffer[k]= 0;
                            break;
                        }
                    }

                }

                for(unsigned long long l = 0; l < Value2.size(); l++){
                    if( ResultBuffer[l] != 0){
                        cout<<"No"<<endl;
                        break;
                    }

                    if( l == Value2.size()-1 ){
                        cout<<"Yes"<<endl;
                        break;
                    }
                }

            }
        }

    }
    return 0;
}
