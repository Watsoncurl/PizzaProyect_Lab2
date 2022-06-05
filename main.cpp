#include <iostream>

using namespace std;

int main()
{
    int opc;
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"----------------"<<endl;
    cout<<"1) OPCION 1"<<endl;
    cout<<"2) OPCION 2"<<endl;
    cout<<"3) OPCION 3"<<endl;
    cout<<"4) OPCION 4"<<endl;
    cout<<"5) OPCION 5"<<endl;
    cout<<"----------------"<<endl;
    cout<<"0) FIN DEL PROGRAMA"<<endl;
    cin>>opc;
    while(true)
    {
        switch(opc)
        {
        case 1:
            system("cls");
            cout<<"OPCION 1"<<endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"OPCION 2"<<endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"OPCION 3"<<endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout<<"OPCION 4"<<endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout<<"OPCION 5"<<endl;
            system("pause");
            break;
        case 0:
            return 0;
            break;
        default:
            system("cls");
            cout<<"OPCION INCORRECTA"<<endl;
            system("pause");
            break;
        }
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"----------------"<<endl;
        cout<<"1) OPCION 1"<<endl;
        cout<<"2) OPCION 2"<<endl;
        cout<<"3) OPCION 3"<<endl;
        cout<<"4) OPCION 4"<<endl;
        cout<<"5) OPCION 5"<<endl;
        cout<<"----------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl;
        cin>>opc;
    }
    return 0;
}
