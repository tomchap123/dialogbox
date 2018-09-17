//Project:	CIS023_F2018_HW11 Tom Chaparas
//Module:	CIS023_F2018_HW11 Tom Chaparas.cpp 
//Author:	Tom Chaparas
//Date:		September 16, 2018
//Purpose:	Create a base class with default methods and members.
//			Derive a class from the base class.
//			Interact with the derived classes.
//			Perform dialog box interaction.

#include "stdafx.h"
#include "CIS023_F2018_HW11 Tom Chaparas.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                         // current instance
WCHAR szTitle[MAX_LOADSTRING];           // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];     // the main window class name

TCHAR szUserInput[200];                  //Global variables to hold input data
TCHAR szPartNum[200];	
TCHAR szDescription[200];                //
int iQuantity;                           //
BOOL ConversionSucceeded;                //

DescriptionClass* DescriptionObject;     //Object derived base PartNoClass 
QuantityClass* QuantityObject;           // 

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//Declaration of Callback function created for Dialog boxes
INT_PTR CALLBACK Input(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK View(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CIS023_F2018_HW11TOMCHAPARAS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_F2018_HW11TOMCHAPARAS));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_F2018_HW11TOMCHAPARAS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023_F2018_HW11TOMCHAPARAS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 400, 300, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_FILE_ADD:
            {
                DialogBox(                              //launch Data Input dialog box
                    hInst,                              //attached to this program
                    MAKEINTRESOURCE(IDD_InputDialog),   //the Input Dialog box
                    hWnd,                               //child of this program
                    Input);                             //name of Callback function
            }
            break;
            case ID_FILE_VIEW:
            {
                DialogBox(                              //launch Data View dialog box
                    hInst,                              //attached to this program
                    MAKEINTRESOURCE(IDD_ViewDialog),    //the View Dialog box
                    hWnd,                               //child of this program
                    View);                              //name of Callback function	

            }
            break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CREATE:
    {

        DescriptionObject = new DescriptionClass;   //Object created
        QuantityObject = new QuantityClass;         //Object created
    }
    break;
    case WM_DESTROY:
        if (DescriptionObject)
            delete DescriptionObject;               //Object destroyed
        if (QuantityObject)
            delete QuantityObject;                  //Object destroyed

        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
//Message Handler for InputBox
INT_PTR CALLBACK Input(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        
        return (INT_PTR)TRUE;

    case WM_COMMAND:

        //Save/OK Button
        if (LOWORD(wParam) == IDOK)
        {
            GetDlgItemText(                //get text item in dialogbox
                hDlg,                      //handle to the dialogbox
                IDC_PartEdit,              //control ID in the dialog box
                DescriptionObject->        //return value from object
                GetPartNo(),								
                200);                      //max # of chars to get
            

            GetDlgItemText(								
                hDlg,									
                IDC_DescriptEdit,						
                DescriptionObject->
                GetDescription(),							
                200);									

            iQuantity = GetDlgItemInt(      //get int item in dialogbox					
                hDlg,                       //handle									
                IDC_QuantityEdit,           //control ID
                &ConversionSucceeded,       //					
                TRUE);									
            
            if (ConversionSucceeded)
            {
                QuantityObject->SetQuantity(iQuantity);
            }

            EndDialog(hDlg, LOWORD(wParam));   //Close dialog box
            return (INT_PTR)TRUE;
        
        }

        //Cancel Button
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
//Message handler for View box
INT_PTR CALLBACK View(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
        // dialog box is created
    case WM_INITDIALOG:

        SetDlgItemText(              //set item in View dialogox
            hDlg,                    //dialogbox handle
            IDC_ViewPart,            //control ID
            DescriptionObject->      //retrieving data from object
            GetPartNo());

        SetDlgItemText(
            hDlg,
            IDC_ViewDescript,
            DescriptionObject->
            GetDescription());

        SetDlgItemInt(
            hDlg,
            IDC_ViewQuantity,
            QuantityObject->
            GetQuantity(),
            TRUE);
            
        return (INT_PTR)TRUE;

    case WM_COMMAND:

       //Close dialog box
        if (LOWORD(wParam) == IDOK)
        {
            EndDialog(hDlg, LOWORD(wParam));			
            return (INT_PTR)TRUE;
        }
        //Cancel Button
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

