#include <iostream>

using namespace std;
void fenyou(int x,int y,int z,int targ);
int main()
{
    int x = 80,y = 50,z = 30,targ = 40;
    fenyou(x,y,z,targ);
}

void fenyou(int x,int y,int z,int targ)
{
    int  myqueue [1000][5];
    string  mystat[1000];
    myqueue[0][1] = 80;
    myqueue[0][2] = 0;
    myqueue[0][3]=0;
    myqueue[0][4] = 0;
    myqueue[0][5] = -1;
    mystat[0] = "null";
    int ptr = -1;
    int length = 0;
    int step = 0;
    while(myqueue[length][1]!=40&&myqueue[length][2]!=40&&myqueue[length][3]!=40)
    {
        ptr = ptr + 1;
        int temp1,temp2,temp3;
        string stats;
        for(int i  = 1 ; i <= 3; i++)
        {
            if(i == 1)
            {
                if(myqueue[ptr][1]>0)
                {
                    if(myqueue[ptr][2]<y)
                    {
                        if(myqueue[ptr][1]+myqueue[ptr][2]<=y)
                        {
                            temp1 = 0;
                            temp2 = myqueue[ptr][1]+myqueue[ptr][2];
                            temp3 = myqueue[ptr][3];
                        }
                        else
                        {
                            temp1 = myqueue[ptr][1] - (y - myqueue[ptr][2]);
                            temp2 = y;
                            temp3 = myqueue[ptr][3];

                        }
                        bool flag = true;
                        for(int k = 0; k<=length; k++)
                        {
                            if(myqueue[k][1] == temp1 && myqueue[k][2] == temp2&& myqueue[k][3] == temp3)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag == true)
                        {
                            length = length + 1;
                            mystat[length] = "X->Y";
                            myqueue[length][1] = temp1;
                            myqueue[length][2] = temp2;
                            myqueue[length][3] = temp3;
                            myqueue[length][4] = myqueue[ptr][4]+1;
                            myqueue[length][5] = ptr;
                        }
                    }

                    if(myqueue[ptr][3]<z)
                    {
                        if(myqueue[ptr][1]+myqueue[ptr][3]<=z)
                        {
                            temp1 = 0;
                            temp2 = myqueue[ptr][2];
                            temp3 = myqueue[ptr][3] + myqueue[ptr][1];
                        }
                        else
                        {
                            temp1 = myqueue[ptr][1] - (z - myqueue[ptr][3]);
                            temp2 = myqueue[ptr][2];
                            temp3 = z;

                        }
                        bool flag = true;
                        for(int k = 0; k<=length; k++)
                        {
                            if(myqueue[k][1] == temp1 && myqueue[k][2] == temp2&& myqueue[k][3] == temp3)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag == true)
                        {
                            length = length + 1;
                            mystat[length] = "X->Z";
                            myqueue[length][1] = temp1;
                            myqueue[length][2] = temp2;
                            myqueue[length][3] = temp3;
                            myqueue[length][4] = myqueue[ptr][4]+1;
                            myqueue[length][5] = ptr;
                        }
                    }

                }
            }
            if (i == 2)
            {
                if(myqueue[ptr][2]>0)
                {
                    if(myqueue[ptr][1]<x)
                    {
                        if(myqueue[ptr][1]+myqueue[ptr][2]<=x)
                        {
                            temp1 = myqueue[ptr][1]+myqueue[ptr][2];
                            temp2 = 0;
                            temp3 = myqueue[ptr][3];
                        }
                        else
                        {
                            temp1 = x;
                            temp2 = myqueue[ptr][2]-(x - myqueue[ptr][1]);
                            temp3 = myqueue[ptr][3];

                        }
                        bool flag = true;
                        for(int k = 0; k<=length; k++)
                        {
                            if(myqueue[k][1] == temp1 && myqueue[k][2] == temp2&& myqueue[k][3] == temp3)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag == true)
                        {
                            length = length + 1;
                            mystat[length] = "Y->X";
                            myqueue[length][1] = temp1;
                            myqueue[length][2] = temp2;
                            myqueue[length][3] = temp3;
                            myqueue[length][4] = myqueue[ptr][4]+1;
                            myqueue[length][5] = ptr;
                        }
                    }

                    if(myqueue[ptr][3]<z)
                    {
                        if(myqueue[ptr][2]+myqueue[ptr][3]<=z)
                        {
                            temp1 = myqueue[ptr][1];
                            temp2 = 0;
                            temp3 = myqueue[ptr][2] + myqueue[ptr][3];
                        }
                        else
                        {
                            temp1 = myqueue[ptr][1];
                            temp2 = myqueue[ptr][2]-(z-myqueue[ptr][3]);
                            temp3 = z;

                        }
                        bool flag = true;
                        for(int k = 0; k<=length; k++)
                        {
                            if(myqueue[k][1] == temp1 && myqueue[k][2] == temp2&& myqueue[k][3] == temp3)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag == true)
                        {
                            length = length + 1;
                            mystat[length] = "Y->Z";
                            myqueue[length][1] = temp1;
                            myqueue[length][2] = temp2;
                            myqueue[length][3] = temp3;
                            myqueue[length][4] = myqueue[ptr][4]+1;
                            myqueue[length][5] = ptr;
                        }
                    }

                }
            }
            if(i == 3)
            {
                if(myqueue[ptr][3]>0)
                {
                    if(myqueue[ptr][1]<x)
                    {
                        if(myqueue[ptr][1]+myqueue[ptr][3]<=x)
                        {
                            temp1 = myqueue[ptr][1]+myqueue[ptr][3];
                            temp2 = myqueue[ptr][2];
                            temp3 = 0;
                        }
                        else
                        {
                            temp1 = x;
                            temp2 = myqueue[ptr][2];
                            temp3 = myqueue[ptr][3]-(x- myqueue[ptr][1]);

                        }
                        bool flag = true;
                        for(int k = 0; k<=length; k++)
                        {
                            if(myqueue[k][1] == temp1 && myqueue[k][2] == temp2&& myqueue[k][3] == temp3)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag == true)
                        {
                            length = length + 1;
                            mystat[length] = "Z->X";
                            myqueue[length][1] = temp1;
                            myqueue[length][2] = temp2;
                            myqueue[length][3] = temp3;
                            myqueue[length][4] = myqueue[ptr][4]+1;
                            myqueue[length][5] = ptr;
                        }
                    }

                    if(myqueue[ptr][2]<y)
                    {
                        if(myqueue[ptr][2]+myqueue[ptr][3]<=y)
                        {
                            temp1 = myqueue[ptr][1];
                            temp2 = myqueue[ptr][2] + myqueue[ptr][3];
                            temp3 = 0;
                        }
                        else
                        {
                            temp1 = myqueue[ptr][1];
                            temp2 = y;
                            temp3 = myqueue[ptr][3] - (y-myqueue[ptr][2]);

                        }
                        bool flag = true;
                        for(int k = 0; k<=length; k++)
                        {
                            if(myqueue[k][1] == temp1 && myqueue[k][2] == temp2&& myqueue[k][3] == temp3)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag == true)
                        {
                            length = length + 1;
                            mystat[length] = "Z->Y";
                            myqueue[length][1] = temp1;
                            myqueue[length][2] = temp2;
                            myqueue[length][3] = temp3;
                            myqueue[length][4] = myqueue[ptr][4]+1;
                            myqueue[length][5] = ptr;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0 ; i <= length;i++)
    {
       cout<<mystat[i]<<" | "<<myqueue[i][1]<<" | "<<myqueue[i][2]<<" | "<<myqueue[i][3]<<" | "<<myqueue[i][4]<<" | "<<myqueue[i][5]<<endl;
    }
    int index = length;
    cout<<endl;
    while(index!=-1)
    {
        cout<<mystat[index]<<" | "<<myqueue[index][1]<<" | "<<myqueue[index][2]<<" | "<<myqueue[index][3]<<" | "<<myqueue[index][4]<<" | "<<myqueue[index][5]<<endl;
        index = myqueue[index][5];
    }
}
