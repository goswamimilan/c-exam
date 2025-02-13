#include<iostream>

using namespace std;

int main(){
        int grade;
        cout<<"enter your score :-"<<endl;
        cin>>grade;

        (grade >= 0 && grade <= 100) ? 
            (grade >= 90) ?     
               cout<<"your grade is A-"<<endl
            :
                (grade >=75) ? 
                    cout<<"your grade is B-"<<endl
                :
                    (grade >= 60) ? 
                            cout<<"your grade is C-"<<endl
                        :
                        (grade >= 50) ? 
                                cout<<"your grade is D-"<<endl
                            :
                                (grade >= 40) ? 
                                        cout<<"your grade is E-"<<endl
                                    :
                                        cout<<"your grade is F-"<<endl

        : 
            cout<<"enter valid number"<<endl;

            switch (grade)
            {
            case 90:
            case 91:
            case 92:
            case 93:
            case 94:
            case 95:
            case 96:
            case 97:
            case 98:
            case 99:
            case 100:
                    cout<<"Exellent Work!"<<endl;
                break;
            case 75:
            case 76:
            case 77:
            case 78:
            case 79:
            case 80:
            case 81:
            case 82:
            case 83:
            case 84:
            case 85:
            case 86:
            case 87:
            case 88:
            case 89:
                cout<<"Well Done"<<endl;
            break;
            case 60:
            case 61:
            case 62:
            case 63:
            case 64:
            case 65:
            case 66:
            case 67:
            case 68:
            case 69:
            case 70:
            case 71:
            case 72:
            case 73:
            case 74:
                cout<<"Good Job"<<endl;
            break;
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
            case 58:
            case 59:
                cout<<"You pass but you could do better"<<endl;
            break;
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
                cout<<"You pass out badly"<<endl;
            break;
            default:
                cout<<"you fail!"<<endl;
                break;
            }

            if(grade >= 50 && grade <= 100)
            {
                cout<<"you are eligible for next leavel"<<endl;
            }else if(grade >= 0 && grade <50){
                cout<<"Try again next time"<<endl;
            }else{
                cout<<"enter valid number"<<endl;
            }
            

    return 0;
}