//
//  receiver.cpp
//  fso
//
//  Created by Earl Co on 3/10/13.
//  Copyright (c) 2013 Earl Co. All rights reserved.
//

#include <iostream>
#include "SerialClass.h"

char buffer[20];
char buf0[200];

int _tmain(int argc, _TCHAR* argv[])
{
    Serial oSerial("COM6:");
    
    while(1){
        sprintf_s(buffer,"0");
        int x=0;
        int char_rev;
        
        while(buf0[x]!='\r') {
            
            char_rev = oSerial.ReadData(buf0[x],1);
            if (char_rev==1) {
                x++;
            }
        }
        buf0[x]=0;
        Sleep(1000);
        oSerial.ReadData(buf0,4);
        printf("Sensor 0: %s \n",buf0);
        Sleep(1000); }
}