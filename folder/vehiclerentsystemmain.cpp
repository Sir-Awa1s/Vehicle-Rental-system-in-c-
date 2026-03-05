#include<iostream>
#include"vehiclerentsys.h"
#include<windows.h>

int main(){

    Filesystem admin;

    int mainmenuchoice{mainmenu()};
    if(mainmenuchoice == 1){
        system("clear");
        admin.administratorMenu();
    }else if(mainmenuchoice == 2){
        system("clear");
        userMenu();
    }else if(mainmenuchoice <= 0 || mainmenuchoice > 2){
        std::cout<<"ERROR!, out-of-bounds or undefined option on main menu! >> "<<std::endl;
    }   
    return 0;
}