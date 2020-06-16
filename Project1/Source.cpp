#include <windows.h>
#include <gdiplus.h>
#include <iostream>
using namespace std;

const int SCREEN_X = (10);
const int SCREEN_Y = (9);

int main(void)
{
    // pixel detect
    ///*HWND hWnd;
    //hWnd = FindWindowA(NULL, "UTi165K v1.33");
    //cout << "Waiting for window." << endl;
    //while (hWnd == 0)
    //{
    //    hWnd = FindWindowA(NULL, "UTi165K v1.33");
    //    Sleep(10);
    //}

    //cout << "there is a window";
    //HDC hdc = GetWindowDC(hWnd);
    //short int R, G, B;
    //COLORREF lcolor;
    //lcolor = GetPixel(hdc, SCREEN_X, SCREEN_Y);
    //R = GetRValue(lcolor);
    //G = GetGValue(lcolor);
    //B = GetBValue(lcolor);
    //cout << R << ", " << G << ", " << B << endl;
    //cin.get();
    //return 0;*/

    POINT p;
    COLORREF color;
    HDC hDC;
    BOOL b;

    // Get the device context for the screen
    hDC = GetDC(NULL);
    if (hDC == NULL)
        return 3;

    // Get the current cursor position
    b = GetCursorPos(&p);
    if (!b)
        return 2;

    // Retrieve the color at that position
    color = GetPixel(hDC, 10, 9);
    if (color == CLR_INVALID)
        return 1;

    // Release the device context again
    ReleaseDC(GetDesktopWindow(), hDC);

    printf("%i %i %i\n", GetRValue(color), GetGValue(color), GetBValue(color));
    printf("%i %i", p.x, p.y);
    return 0;
}