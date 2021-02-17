#include <windows.h>
#include "resource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool choix_texture;
bool texture=false;
HWND hwndcombo, hwndcombo2, hwndcombo3, hwndcombo4,hwndcombo5, hwndcombo6,hwndcombo7, hwndcombo8,hwndcombo9, hwndcombo10,hwndcombo11, hwndcombo12;

double x,y,z,t,theta;

TCHAR text0[]=TEXT("<aucune>");
TCHAR text1[]=TEXT("dalles.jpg");
TCHAR text2[]=TEXT("gravier.jpg");
TCHAR text3[]=TEXT("herbe.jpg");
TCHAR text4[]=TEXT("metal_rouil.jpg");
TCHAR text5[]=TEXT("mi-neige.jpg");
TCHAR text6[]=TEXT("mur.jpg");
TCHAR text7[]=TEXT("papier.jpg");
TCHAR text8[]=TEXT("paves.jpg");
TCHAR text9[]=TEXT("quadrillage.jpg");
TCHAR text10[]=TEXT("tole_rouil.jpg");
TCHAR text11[]=TEXT("eau.jpg");
TCHAR text12[]=TEXT("WRLPOOL.mpg");

TCHAR police0[]=TEXT("SANS");
TCHAR police1[]=TEXT("SERIF");
TCHAR police2[]=TEXT("TYPEWRITER");


TCHAR style0[]=TEXT("PLAIN");
TCHAR style1[]=TEXT("ITALIC");
TCHAR style3[]=TEXT("BOLD");
TCHAR style2[]=TEXT("BOLDITALIC");




char urll[30],url2[30],url3[30],url4[30],url5[30],url6[30],url7[30],url8[30],url9[30],url10[30],url11[30],url12[30];


float mat[12];
int nb_objet=0;
int nb_sensor=0;
char ligne[100];


FILE *fich, *fich2;


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

TCHAR szAppName[] = TEXT ("prog") ;




int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     HWND     hwnd ;
     MSG      msg ;
     WNDCLASS wndclass ;
     
     wndclass.style         = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
     wndclass.lpszClassName = szAppName ;

     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("Ce programme fonctionne exclusivement sous Windows NT!"),
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, TEXT ("Interface VRML"),
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;

}





LRESULT CALLBACK matiere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_ambientIntensity[10]=TEXT("0.2"),vIDC_DIFFX[10]=TEXT("0.8"),vIDC_DIFFY[10]=TEXT("0.8"),vIDC_DIFFZ[10]=TEXT("0.8"),
		vIDC_EMX[10]=TEXT("0"),vIDC_EMY[10]=TEXT("0"),vIDC_EMZ[10]=TEXT("0"),vIDC_BRIL[10]=TEXT("0.2"),
		vIDC_SPECX[10]=TEXT("0"),vIDC_SPECY[10]=TEXT("0"),vIDC_SPECZ[10]=TEXT("0"),vIDC_TRANSP[10]=TEXT("0");
	
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity);

			SetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX);
			SetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY);
			SetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ);
			SetDlgItemText(hwnd, IDC_EMX,vIDC_EMX);
			SetDlgItemText(hwnd, IDC_EMY,vIDC_EMY);
			SetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ);
			SetDlgItemText(hwnd, IDC_BRIL,vIDC_BRIL);
			SetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX);
			SetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY);
			SetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ);
			SetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP);

		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity,10);
					GetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX,10);
					GetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY,10);
					GetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ,10);
					GetDlgItemText(hwnd, IDC_EMX,vIDC_EMX,10);
					GetDlgItemText(hwnd, IDC_EMY,vIDC_EMY,10);
					GetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ,10);
					GetDlgItemText(hwnd, IDC_BRIL,vIDC_BRIL,10);
					GetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX,10);
					GetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY,10);
					GetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ,10);
					GetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP,10);

                   	mat[0] = _wtof(vIDC_ambientIntensity);
					mat[1] = _wtof(vIDC_DIFFX);
					mat[2] = _wtof(vIDC_DIFFY);
					mat[3] = _wtof(vIDC_DIFFZ);
					mat[4] = _wtof(vIDC_EMX);
					mat[5] = _wtof(vIDC_EMY);
					mat[6] = _wtof(vIDC_EMZ);
					mat[7] = _wtof(vIDC_BRIL);
					mat[8] = _wtof(vIDC_SPECX);
					mat[9] = _wtof(vIDC_SPECY);
					mat[10] = _wtof(vIDC_SPECZ);
					mat[11] = _wtof(vIDC_TRANSP);
						
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK cylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Hauteur,vIDC_Hauteur);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_HAUT, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText(hwnd,IDC_Hauteur,vIDC_Hauteur,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					    }
				
					    }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Cylinder{\n");
					fwprintf(fich,L"radius %s \n height %s\n",vIDC_Rayon, vIDC_Hauteur);
					if(IsDlgButtonChecked(hwnd, IDC_HAUT) == BST_UNCHECKED) fprintf(fich, "top FALSE\n");
					if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_UNCHECKED) fprintf(fich, "bottom FALSE\n");
					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_UNCHECKED) fprintf(fich, "side FALSE\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				
				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sphere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"), vIDC_Rayon[10]=TEXT("1.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					    }
				
					    }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Sphere{\n");
					fwprintf(fich,L"radius %s \n",vIDC_Rayon);
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK boite(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_LX[10]=TEXT("1.0"),vIDC_LY[10]=TEXT("1.0"),vIDC_LZ[10]=TEXT("1.0");
	
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_LX,vIDC_LX);
			SetDlgItemText( hwnd, IDC_LY,vIDC_LY);
			SetDlgItemText( hwnd, IDC_LZ,vIDC_LZ);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);

		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_LX,vIDC_LX,10);
					GetDlgItemText(hwnd,IDC_LY,vIDC_LY,10);
					GetDlgItemText(hwnd,IDC_LZ,vIDC_LZ,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					    }
				
					    }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Box{\n");
					fwprintf(fich,L"size %s %s %s \n",vIDC_LX, vIDC_LY, vIDC_LZ);
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK cone(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Hauteur,vIDC_Hauteur);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					    }
				
					    }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Cone{\n");
					fwprintf(fich,L"bottomRadius %s \n height %s\n",vIDC_Rayon, vIDC_Hauteur);
					if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_UNCHECKED) fprintf(fich, "bottom FALSE\n");
					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_UNCHECKED) fprintf(fich, "side FALSE\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK texte(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Size[10]=TEXT("1");

	TCHAR vIDC_Text[100]=TEXT("EMPTY");

	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Text,vIDC_Text);
			SetDlgItemText( hwnd, IDC_Size,vIDC_Size);

			hwndcombo3 = GetDlgItem (hwnd, IDC_COMBO_POLICE);
			SendMessage(hwndcombo3, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) police0);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) police1);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) police2);

			hwndcombo4 = GetDlgItem (hwnd, IDC_COMBO_STYLE);
			SendMessage(hwndcombo4, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style0);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style1);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style2);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style3);

			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_GAUCHE, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_MILIEU, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_DROITE, BST_UNCHECKED);

			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Text,vIDC_Text,10);
					GetDlgItemText(hwnd,IDC_Size,vIDC_Size,10);

					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					SendDlgItemMessage(hwnd, IDC_COMBO_POLICE,WM_GETTEXT, sizeof(url3),(LPARAM) url3);
					SendDlgItemMessage(hwnd, IDC_COMBO_STYLE,WM_GETTEXT, sizeof(url4),(LPARAM) url4);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture anime


					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					    }
				
					    }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Text{\n");
					fwprintf(fich,L"string \"%s\" \n",vIDC_Text);
					fprintf(fich,"fontStyle FontStyle{\n");
					fwprintf(fich,L"family \"%s\" \n", url3);
					fprintf(fich,"horizontal TRUE \n");
					if(IsDlgButtonChecked(hwnd, IDC_GAUCHE) == BST_CHECKED && IsDlgButtonChecked(hwnd, IDC_MILIEU) == BST_UNCHECKED && IsDlgButtonChecked(hwnd, IDC_DROITE) == BST_UNCHECKED) fprintf(fich, "justify \"BEGIN\" \n");
					if(IsDlgButtonChecked(hwnd, IDC_GAUCHE) == BST_UNCHECKED && IsDlgButtonChecked(hwnd, IDC_MILIEU) == BST_CHECKED && IsDlgButtonChecked(hwnd, IDC_DROITE) == BST_UNCHECKED) fprintf(fich, "justify \"MIDDLE\" \n");
					if(IsDlgButtonChecked(hwnd, IDC_GAUCHE) == BST_UNCHECKED && IsDlgButtonChecked(hwnd, IDC_MILIEU) == BST_UNCHECKED && IsDlgButtonChecked(hwnd, IDC_DROITE) == BST_CHECKED) fprintf(fich, "justify \"END\" \n");

					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_UNCHECKED) fprintf(fich, "leftToRight FALSE\n");
					else fprintf(fich, "leftToRight TRUE\n");

					fwprintf(fich,L"size %s \n",vIDC_Size);
					fwprintf(fich,L"style \"%s\" \n",url4);

					if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_UNCHECKED) fprintf(fich, "topToBottom TRUE\n");
					else fprintf(fich, "topToBottom FALSE\n");

					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK lum_directionnelle(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	TCHAR vIDC_AMBIENT_INTENSITY[10]=TEXT("0"), vIDC_ROUGE[10]=TEXT("1"), vIDC_VERT[10]=TEXT("1"), vIDC_BLEU[10]=TEXT("1"), vIDC_DIRX[10]=TEXT("0");
	TCHAR vIDC_DIRY[10]=TEXT("0"), vIDC_DIRZ[10]=TEXT("-1"), vIDC_INTENSITY[10]=TEXT("1");

	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_AMBIENT_INTENSITY, vIDC_AMBIENT_INTENSITY);
			SetDlgItemText( hwnd, IDC_ROUGE, vIDC_ROUGE);
			SetDlgItemText( hwnd, IDC_VERT, vIDC_VERT);
			SetDlgItemText( hwnd, IDC_BLEU, vIDC_BLEU);
			SetDlgItemText( hwnd, IDC_DIRX, vIDC_DIRX);
			SetDlgItemText( hwnd, IDC_DIRY, vIDC_DIRY);
			SetDlgItemText( hwnd, IDC_DIRZ, vIDC_DIRZ);
			SetDlgItemText( hwnd, IDC_INTENSITY, vIDC_INTENSITY);			

		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_AMBIENT_INTENSITY,vIDC_AMBIENT_INTENSITY,10);
					GetDlgItemText(hwnd,IDC_ROUGE,vIDC_ROUGE,10);
					GetDlgItemText(hwnd,IDC_VERT,vIDC_VERT,10);
					GetDlgItemText(hwnd,IDC_BLEU,vIDC_BLEU,10);
					GetDlgItemText(hwnd,IDC_DIRX,vIDC_DIRX,10);
					GetDlgItemText(hwnd,IDC_DIRY,vIDC_DIRY,10);
					GetDlgItemText(hwnd,IDC_DIRZ,vIDC_DIRZ,10);
					GetDlgItemText(hwnd,IDC_INTENSITY,vIDC_INTENSITY,10);

					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DirectionalLight{\n");
					fprintf(fich,"ambientIntensity %s \n",vIDC_AMBIENT_INTENSITY);
					fwprintf(fich,L"color %s %s %s \n",vIDC_ROUGE,vIDC_VERT,vIDC_BLEU);
					fwprintf(fich,L"direction %s %s %s \n",vIDC_DIRX,vIDC_DIRY,vIDC_DIRZ);
					fwprintf(fich,L"intensity %s \n",vIDC_INTENSITY);
					fprintf(fich,"on TRUE \n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK lum_ponctuelle(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	TCHAR vIDC_AMBIENT_INTENSITY[10]=TEXT("0"), vIDC_ROUGE[10]=TEXT("1"), vIDC_VERT[10]=TEXT("1"), vIDC_BLEU[10]=TEXT("1"), vIDC_DIRX[10]=TEXT("1");
	TCHAR vIDC_DIRY[10]=TEXT("0"), vIDC_DIRZ[10]=TEXT("0"), vIDC_INTENSITY[10]=TEXT("1");
	TCHAR vIDC_X[10]=TEXT("0"), vIDC_Y[10]=TEXT("0"), vIDC_Z[10]=TEXT("2"), vIDC_Rayon[10]=TEXT("100") ;

	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :

			SetDlgItemText( hwnd, IDC_AMBIENT_INTENSITY, vIDC_AMBIENT_INTENSITY);
			SetDlgItemText( hwnd, IDC_ROUGE, vIDC_ROUGE);
			SetDlgItemText( hwnd, IDC_VERT, vIDC_VERT);
			SetDlgItemText( hwnd, IDC_BLEU, vIDC_BLEU);
			SetDlgItemText( hwnd, IDC_DIRX, vIDC_DIRX);
			SetDlgItemText( hwnd, IDC_DIRY, vIDC_DIRY);
			SetDlgItemText( hwnd, IDC_DIRZ, vIDC_DIRZ);
			SetDlgItemText( hwnd, IDC_INTENSITY, vIDC_INTENSITY);
			SetDlgItemText( hwnd, IDC_X, vIDC_X);
			SetDlgItemText( hwnd, IDC_Y, vIDC_Y);
			SetDlgItemText( hwnd, IDC_Z, vIDC_Z);
			SetDlgItemText( hwnd, IDC_Rayon, vIDC_Rayon);

		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_AMBIENT_INTENSITY,vIDC_AMBIENT_INTENSITY,10);
					GetDlgItemText(hwnd,IDC_ROUGE,vIDC_ROUGE,10);
					GetDlgItemText(hwnd,IDC_VERT,vIDC_VERT,10);
					GetDlgItemText(hwnd,IDC_BLEU,vIDC_BLEU,10);
					GetDlgItemText(hwnd,IDC_DIRX,vIDC_DIRX,10);
					GetDlgItemText(hwnd,IDC_DIRY,vIDC_DIRY,10);
					GetDlgItemText(hwnd,IDC_DIRZ,vIDC_DIRZ,10);
					GetDlgItemText(hwnd,IDC_INTENSITY,vIDC_INTENSITY,10);
					GetDlgItemText(hwnd,IDC_X,vIDC_X,10);
					GetDlgItemText(hwnd,IDC_Y,vIDC_Y,10);
					GetDlgItemText(hwnd,IDC_Z,vIDC_Z,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);

					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"PointLight{\n");
					fprintf(fich,"ambientIntensity %s \n",vIDC_AMBIENT_INTENSITY);
					fwprintf(fich,L"attenuation %s %s %s \n",vIDC_DIRX,vIDC_DIRY,vIDC_DIRZ);
					fwprintf(fich,L"color %s %s %s \n",vIDC_ROUGE,vIDC_VERT,vIDC_BLEU);
					fwprintf(fich,L"intensity %s \n",vIDC_INTENSITY);
					fwprintf(fich,L"location %s %s %s \n",vIDC_X,vIDC_Y,vIDC_Z);
					fprintf(fich,"on TRUE \n");
					fwprintf(fich,L"radius %s \n",vIDC_Rayon);
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK lum_spot(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	TCHAR vIDC_AMBIENT_INTENSITY[10]=TEXT("0"), vIDC_ROUGE[10]=TEXT("1"), vIDC_VERT[10]=TEXT("1"), vIDC_BLEU[10]=TEXT("1"), vIDC_DIRX[10]=TEXT("0");
	TCHAR vIDC_DIRY[10]=TEXT("0"), vIDC_DIRZ[10]=TEXT("1"), vIDC_INTENSITY[10]=TEXT("1"), vIDC_AttX[10]=TEXT("1"), vIDC_AttY[10]=TEXT("0"), vIDC_AttZ[10]=TEXT("0");
	TCHAR vIDC_X[10]=TEXT("0"), vIDC_Y[10]=TEXT("0"), vIDC_Z[10]=TEXT("2"), vIDC_Rayon[10]=TEXT("100"), vIDC_BeamWidth[10]=TEXT("1.570796"), vIDC_CutAngle[10]=TEXT("0.785398");

	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :

			SetDlgItemText( hwnd, IDC_AMBIENT_INTENSITY, vIDC_AMBIENT_INTENSITY);
			SetDlgItemText( hwnd, IDC_ROUGE, vIDC_ROUGE);
			SetDlgItemText( hwnd, IDC_VERT, vIDC_VERT);
			SetDlgItemText( hwnd, IDC_BLEU, vIDC_BLEU);
			SetDlgItemText( hwnd, IDC_DIRX, vIDC_DIRX);
			SetDlgItemText( hwnd, IDC_DIRY, vIDC_DIRY);
			SetDlgItemText( hwnd, IDC_DIRZ, vIDC_DIRZ);
			SetDlgItemText( hwnd, IDC_INTENSITY, vIDC_INTENSITY);
			SetDlgItemText( hwnd, IDC_X, vIDC_X);
			SetDlgItemText( hwnd, IDC_Y, vIDC_Y);
			SetDlgItemText( hwnd, IDC_Z, vIDC_Z);
			SetDlgItemText( hwnd, IDC_Rayon, vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_AttX, vIDC_AttX);
			SetDlgItemText( hwnd, IDC_AttY, vIDC_AttY);
			SetDlgItemText( hwnd, IDC_AttZ, vIDC_AttZ);
			SetDlgItemText( hwnd, IDC_BeamWidth, vIDC_BeamWidth);
			SetDlgItemText( hwnd, IDC_CutAngle, vIDC_CutAngle);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_AMBIENT_INTENSITY,vIDC_AMBIENT_INTENSITY,10);
					GetDlgItemText(hwnd,IDC_ROUGE,vIDC_ROUGE,10);
					GetDlgItemText(hwnd,IDC_VERT,vIDC_VERT,10);
					GetDlgItemText(hwnd,IDC_BLEU,vIDC_BLEU,10);
					GetDlgItemText(hwnd,IDC_DIRX,vIDC_DIRX,10);
					GetDlgItemText(hwnd,IDC_DIRY,vIDC_DIRY,10);
					GetDlgItemText(hwnd,IDC_DIRZ,vIDC_DIRZ,10);
					GetDlgItemText(hwnd,IDC_INTENSITY,vIDC_INTENSITY,10);
					GetDlgItemText(hwnd,IDC_X,vIDC_X,10);
					GetDlgItemText(hwnd,IDC_Y,vIDC_Y,10);
					GetDlgItemText(hwnd,IDC_Z,vIDC_Z,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText(hwnd,IDC_AttX,vIDC_AttX,10);
					GetDlgItemText(hwnd,IDC_AttY,vIDC_AttY,10);
					GetDlgItemText(hwnd,IDC_AttZ,vIDC_AttZ,10);
					GetDlgItemText(hwnd,IDC_BeamWidth,vIDC_BeamWidth,10);
					GetDlgItemText(hwnd,IDC_CutAngle,vIDC_CutAngle,10);

					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"SpotLight{\n");
					fprintf(fich,"ambientIntensity %s \n",vIDC_AMBIENT_INTENSITY);
					fwprintf(fich,L"attenuation %s %s %s \n",vIDC_AttX,vIDC_AttY,vIDC_AttZ);
					fwprintf(fich,L"beamWidth %s \n",vIDC_BeamWidth);
					fwprintf(fich,L"color %s %s %s \n",vIDC_ROUGE,vIDC_VERT,vIDC_BLEU);
					fwprintf(fich,L"cutOffAngle %s \n",vIDC_CutAngle);
					fwprintf(fich,L"direction %s %s %s \n",vIDC_DIRX,vIDC_DIRY,vIDC_DIRZ);
					fwprintf(fich,L"intensity %s \n",vIDC_INTENSITY);
					fwprintf(fich,L"location %s %s %s \n",vIDC_X,vIDC_Y,vIDC_Z);
					fprintf(fich,"on TRUE \n");
					fwprintf(fich,L"radius %s \n",vIDC_Rayon);
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK fond(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_AngleCiel1[10]=TEXT("0"), vIDC_ROUGE_CIEL1[10]=TEXT("0"),vIDC_VERT_CIEL1[10]=TEXT("0"),vIDC_BLEU_CIEL1[10]=TEXT("0");
	TCHAR vIDC_AngleCiel2[10]=TEXT("0"), vIDC_ROUGE_CIEL2[10]=TEXT("0"),vIDC_VERT_CIEL2[10]=TEXT("0"),vIDC_BLEU_CIEL2[10]=TEXT("0");
	TCHAR vIDC_AngleCiel3[10]=TEXT("0"), vIDC_ROUGE_CIEL3[10]=TEXT("0"),vIDC_VERT_CIEL3[10]=TEXT("0"),vIDC_BLEU_CIEL3[10]=TEXT("0");

	TCHAR vIDC_AngleSol1[10]=TEXT("0"), vIDC_ROUGE_SOL1[10]=TEXT("0"),vIDC_VERT_SOL1[10]=TEXT("0"),vIDC_BLEU_SOL1[10]=TEXT("0");
	TCHAR vIDC_AngleSol2[10]=TEXT("0"), vIDC_ROUGE_SOL2[10]=TEXT("0"),vIDC_VERT_SOL2[10]=TEXT("0"),vIDC_BLEU_SOL2[10]=TEXT("0");
	TCHAR vIDC_AngleSol3[10]=TEXT("0"), vIDC_ROUGE_SOL3[10]=TEXT("0"),vIDC_VERT_SOL3[10]=TEXT("0"),vIDC_BLEU_SOL3[10]=TEXT("0");

	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :

			SetDlgItemText( hwnd, IDC_AngleCiel1,vIDC_AngleCiel1);
			SetDlgItemText( hwnd, IDC_ROUGE_CIEL1,vIDC_ROUGE_CIEL1);
			SetDlgItemText( hwnd, IDC_VERT_CIEL1,vIDC_VERT_CIEL1);
			SetDlgItemText( hwnd, IDC_BLEU_CIEL1,vIDC_BLEU_CIEL1);

			SetDlgItemText( hwnd, IDC_AngleCiel2,vIDC_AngleCiel2);
			SetDlgItemText( hwnd, IDC_ROUGE_CIEL2,vIDC_ROUGE_CIEL2);
			SetDlgItemText( hwnd, IDC_VERT_CIEL2,vIDC_VERT_CIEL2);
			SetDlgItemText( hwnd, IDC_BLEU_CIEL2,vIDC_BLEU_CIEL2);

			SetDlgItemText( hwnd, IDC_AngleCiel3,vIDC_AngleCiel3);
			SetDlgItemText( hwnd, IDC_ROUGE_CIEL3,vIDC_ROUGE_CIEL3);
			SetDlgItemText( hwnd, IDC_VERT_CIEL3,vIDC_VERT_CIEL3);
			SetDlgItemText( hwnd, IDC_BLEU_CIEL3,vIDC_BLEU_CIEL3);

			SetDlgItemText( hwnd, IDC_AngleSol1,vIDC_AngleSol1);
			SetDlgItemText( hwnd, IDC_ROUGE_SOL1,vIDC_ROUGE_SOL1);
			SetDlgItemText( hwnd, IDC_VERT_SOL1,vIDC_VERT_SOL1);
			SetDlgItemText( hwnd, IDC_BLEU_SOL1,vIDC_BLEU_SOL1);

			SetDlgItemText( hwnd, IDC_AngleSol2,vIDC_AngleSol2);
			SetDlgItemText( hwnd, IDC_ROUGE_SOL2,vIDC_ROUGE_SOL2);
			SetDlgItemText( hwnd, IDC_VERT_SOL2,vIDC_VERT_SOL2);
			SetDlgItemText( hwnd, IDC_BLEU_SOL2,vIDC_BLEU_SOL2);

			SetDlgItemText( hwnd, IDC_AngleSol3,vIDC_AngleSol3);
			SetDlgItemText( hwnd, IDC_ROUGE_SOL3,vIDC_ROUGE_SOL3);
			SetDlgItemText( hwnd, IDC_VERT_SOL3,vIDC_VERT_SOL3);
			SetDlgItemText( hwnd, IDC_BLEU_SOL3,vIDC_BLEU_SOL3);



			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE_back);


			hwndcombo3 = GetDlgItem (hwnd, IDC_COMBO_FIXE_bottom);


			hwndcombo5 = GetDlgItem (hwnd, IDC_COMBO_FIXE_front);


			hwndcombo7 = GetDlgItem (hwnd, IDC_COMBO_FIXE_left);


			hwndcombo9 = GetDlgItem (hwnd, IDC_COMBO_FIXE_right);


			hwndcombo11 = GetDlgItem (hwnd, IDC_COMBO_FIXE_top);



			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);

			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo3, CB_SETCURSEL , 0, 0);

			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo5, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo5, CB_SETCURSEL , 0, 0);

			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo7, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo7, CB_SETCURSEL , 0, 0);

			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo9, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo9, CB_SETCURSEL , 0, 0);

			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo11, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo11, CB_SETCURSEL , 0, 0);

			
			CheckDlgButton(hwnd, IDC_HAUT, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_BAS, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_GAUCHE, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_DROITE, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_AVANT, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_ARRIERE, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_SOL, BST_UNCHECKED);
			CheckDlgButton(hwnd, IDC_CIEL, BST_UNCHECKED);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :

					GetDlgItemText(hwnd, IDC_AngleCiel1,vIDC_AngleCiel1,10);
					GetDlgItemText(hwnd, IDC_AngleCiel2,vIDC_AngleCiel2,10);
					GetDlgItemText(hwnd, IDC_AngleCiel3,vIDC_AngleCiel3,10);
					GetDlgItemText(hwnd, IDC_ROUGE_CIEL1,vIDC_ROUGE_CIEL1,10);
					GetDlgItemText(hwnd, IDC_VERT_CIEL1,vIDC_VERT_CIEL1,10);
					GetDlgItemText(hwnd, IDC_BLEU_CIEL1,vIDC_BLEU_CIEL1,10);
					GetDlgItemText(hwnd, IDC_ROUGE_CIEL2,vIDC_ROUGE_CIEL2,10);
					GetDlgItemText(hwnd, IDC_VERT_CIEL2,vIDC_VERT_CIEL2,10);
					GetDlgItemText(hwnd, IDC_BLEU_CIEL2,vIDC_BLEU_CIEL2,10);
					GetDlgItemText(hwnd, IDC_ROUGE_CIEL3,vIDC_ROUGE_CIEL3,10);
					GetDlgItemText(hwnd, IDC_VERT_CIEL3,vIDC_VERT_CIEL3,10);
					GetDlgItemText(hwnd, IDC_BLEU_CIEL3,vIDC_BLEU_CIEL3,10);

					GetDlgItemText(hwnd, IDC_AngleSol1,vIDC_AngleSol1,10);
					GetDlgItemText(hwnd, IDC_AngleSol2,vIDC_AngleSol2,10);
					GetDlgItemText(hwnd, IDC_AngleSol3,vIDC_AngleSol3,10);
					GetDlgItemText(hwnd, IDC_ROUGE_SOL1,vIDC_ROUGE_SOL1,10);
					GetDlgItemText(hwnd, IDC_VERT_SOL1,vIDC_VERT_SOL1,10);
					GetDlgItemText(hwnd, IDC_BLEU_SOL1,vIDC_BLEU_SOL1,10);
					GetDlgItemText(hwnd, IDC_ROUGE_SOL2,vIDC_ROUGE_SOL2,10);
					GetDlgItemText(hwnd, IDC_VERT_SOL2,vIDC_VERT_SOL2,10);
					GetDlgItemText(hwnd, IDC_BLEU_SOL2,vIDC_BLEU_SOL2,10);
					GetDlgItemText(hwnd, IDC_ROUGE_SOL3,vIDC_ROUGE_SOL3,10);
					GetDlgItemText(hwnd, IDC_VERT_SOL3,vIDC_VERT_SOL3,10);
					GetDlgItemText(hwnd, IDC_BLEU_SOL3,vIDC_BLEU_SOL3,10);

					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE_back,WM_GETTEXT, sizeof(urll),(LPARAM) urll);

					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE_bottom,WM_GETTEXT, sizeof(url3),(LPARAM) url3);

					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE_front,WM_GETTEXT, sizeof(url5),(LPARAM) url5);

					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE_left,WM_GETTEXT, sizeof(url7),(LPARAM) url7);

					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE_right,WM_GETTEXT, sizeof(url9),(LPARAM) url9);

					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE_top,WM_GETTEXT, sizeof(url11),(LPARAM) url11);

					
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");

					fprintf(fich,"Background {\n");
					if(IsDlgButtonChecked(hwnd, IDC_CIEL) == BST_CHECKED){
						fwprintf(fich,L"skyAngle [%s,%s,%s]\n",vIDC_AngleCiel1,vIDC_AngleCiel2,vIDC_AngleCiel3);
						fwprintf(fich,L"skyColor [%s %s %s,%s %s %s,%s %s %s]\n",vIDC_ROUGE_CIEL1,vIDC_VERT_CIEL1,vIDC_BLEU_CIEL1,vIDC_ROUGE_CIEL2,vIDC_VERT_CIEL2, vIDC_BLEU_CIEL2,vIDC_ROUGE_CIEL3, vIDC_VERT_CIEL3,vIDC_BLEU_CIEL3);
					}
					if(IsDlgButtonChecked(hwnd, IDC_SOL) == BST_CHECKED){
						fwprintf(fich,L"groundAngle [%s,%s,%s]\n",vIDC_AngleSol1,vIDC_AngleSol2,vIDC_AngleSol3);
						fwprintf(fich,L"groundColor [%s %s %s,%s %s %s,%s %s %s]\n",vIDC_ROUGE_SOL1,vIDC_VERT_SOL1,vIDC_BLEU_SOL1,vIDC_ROUGE_SOL2,vIDC_VERT_SOL2, vIDC_BLEU_SOL2,vIDC_ROUGE_SOL3, vIDC_VERT_SOL3,vIDC_BLEU_SOL3);
					}

					if(IsDlgButtonChecked(hwnd, IDC_AVANT) == BST_CHECKED) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"frontUrl [\".\\textures\\%s\"]",url5);
					    }				
	
					if(IsDlgButtonChecked(hwnd, IDC_ARRIERE) == BST_CHECKED) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"backUrl [\".\\textures\\%s\"]",urll);
					    }
					if(IsDlgButtonChecked(hwnd, IDC_HAUT) == BST_CHECKED) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"topUrl [\".\\textures\\%s\"]",url11);
					    }	
					if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_CHECKED) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"bottomUrl [\".\\textures\\%s\"]",url3);
					    }	
					if(IsDlgButtonChecked(hwnd, IDC_GAUCHE) == BST_CHECKED) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"leftUrl [\".\\textures\\%s\"]",url7);
					    }	
					if(IsDlgButtonChecked(hwnd, IDC_DROITE) == BST_CHECKED) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"rightUrl [\".\\textures\\%s\"]",url9);
					    }	

					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sensorcylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	TCHAR vIDC_Angle[10]=TEXT("0.1"),vIDC_AngleMin[10]=TEXT("0"),vIDC_AngleMax[10]=TEXT("-1"), vIDC_AngleOffset[10]=TEXT("0");
	
    char nom[10]="objet";

	switch (msg) {

		case WM_INITDIALOG :

			SetDlgItemText(hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText(hwnd, IDC_AngleMin,vIDC_AngleMin);
			SetDlgItemText(hwnd, IDC_AngleMax,vIDC_AngleMax);
			SetDlgItemText(hwnd, IDC_AngleOffset,vIDC_AngleOffset);
			CheckDlgButton(hwnd, IDC_Offset, BST_CHECKED);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd, IDC_AngleMin,vIDC_AngleMin,10);
					GetDlgItemText(hwnd, IDC_AngleMax,vIDC_AngleMax,10);
					GetDlgItemText(hwnd, IDC_AngleOffset,vIDC_AngleOffset,10);
					nb_sensor++;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF capteur%d CylinderSensor{\n",nb_sensor);

					if(IsDlgButtonChecked(hwnd, IDC_Offset) == BST_CHECKED){
					fprintf(fich,"autoOffset TRUE\n");
					}
					else{ fprintf(fich,"autoOffset FALSE\n");
					}
					fwprintf(fich,L"diskAngle %s\n",vIDC_Angle);
					fwprintf(fich,L"maxAngle %s\n",vIDC_AngleMax);
					fwprintf(fich,L"minAngle %s\n",vIDC_AngleMin);
					fwprintf(fich,L"offset %s\n",vIDC_AngleOffset);
					fprintf(fich,"isActive ON \n");
					fprintf(fich,"},\n");
					fclose(fich);

					fopen_s(&fich2,"sensor.txt","a");
					fprintf(fich2,"ROUTE capteur%d.rotation_changed TO %s%d.set_rotation \n",nb_sensor,nom,nb_objet);
					fclose(fich2);

					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sensorsphere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Offset0[10]=TEXT("0"),vIDC_Offset1[10]=TEXT("1"),vIDC_Offset2[10]=TEXT("0"), vIDC_Offset3[10]=TEXT("0");
	
    char nom[10]="objet";

	switch (msg) {

		case WM_INITDIALOG :

			SetDlgItemText(hwnd, IDC_Offset0,vIDC_Offset0);
			SetDlgItemText(hwnd, IDC_Offset1,vIDC_Offset1);
			SetDlgItemText(hwnd, IDC_Offset2,vIDC_Offset2);
			SetDlgItemText(hwnd, IDC_Offset3,vIDC_Offset3);
			CheckDlgButton(hwnd, IDC_Offset, BST_CHECKED);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_Offset0,vIDC_Offset0,10);
					GetDlgItemText(hwnd, IDC_Offset1,vIDC_Offset1,10);
					GetDlgItemText(hwnd, IDC_Offset2,vIDC_Offset2,10);
					GetDlgItemText(hwnd, IDC_Offset3,vIDC_Offset3,10);
					nb_sensor++;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF capteur%d SphereSensor{\n",nb_sensor);

					if(IsDlgButtonChecked(hwnd, IDC_Offset) == BST_CHECKED){
					fprintf(fich,"autoOffset TRUE\n");
					}
					else{ fprintf(fich,"autoOffset FALSE\n");
					}
					fwprintf(fich,L"offset %s %s %s %s \n",vIDC_Offset0,vIDC_Offset1,vIDC_Offset2,vIDC_Offset3);
					fprintf(fich,"isActive ON\n");
					fprintf(fich,"},\n");
					fclose(fich);

					fopen_s(&fich2,"sensor.txt","a");
					fprintf(fich2,"ROUTE capteur%d.rotation_changed TO %s%d.set_rotation \n",nb_sensor,nom,nb_objet);
					fclose(fich2);

					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sensorplan(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Offset0[10]=TEXT("0"),vIDC_Offset4[10]=TEXT("0"),vIDC_Offset5[10]=TEXT("0"), vIDC_MinPos0[10]=TEXT("0"), vIDC_MinPos1[10]=TEXT("0"),
		vIDC_MaxPos0[10]=TEXT("-1"), vIDC_MaxPos1[10]=TEXT("-1");


	
    char nom[10]="objet";

	switch (msg) {

		case WM_INITDIALOG :

			SetDlgItemText(hwnd, IDC_Offset0,vIDC_Offset0);
			SetDlgItemText(hwnd, IDC_Offset4,vIDC_Offset4);
			SetDlgItemText(hwnd, IDC_Offset5,vIDC_Offset5);
			SetDlgItemText(hwnd, IDC_MinPos0,vIDC_MinPos0);
			SetDlgItemText(hwnd, IDC_MinPos1,vIDC_MinPos1);
			SetDlgItemText(hwnd, IDC_MaxPos0,vIDC_MaxPos0);
			SetDlgItemText(hwnd, IDC_MaxPos1,vIDC_MaxPos1);
			CheckDlgButton(hwnd, IDC_Offset, BST_CHECKED);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_Offset0,vIDC_Offset0,10);
					GetDlgItemText(hwnd, IDC_Offset4,vIDC_Offset4,10);
					GetDlgItemText(hwnd, IDC_Offset5,vIDC_Offset5,10);
					GetDlgItemText(hwnd, IDC_MinPos0,vIDC_MinPos0,10);
					GetDlgItemText(hwnd, IDC_MinPos1,vIDC_MinPos1,10);
					GetDlgItemText(hwnd, IDC_MaxPos0,vIDC_MaxPos0,10);
					GetDlgItemText(hwnd, IDC_MaxPos1,vIDC_MaxPos1,10);
					nb_sensor++;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF capteur%d PlaneSensor{\n",nb_sensor);

					if(IsDlgButtonChecked(hwnd, IDC_Offset) == BST_CHECKED){
					fprintf(fich,"autoOffset TRUE\n");
					}
					else{ fprintf(fich,"autoOffset FALSE\n");
					}
					fprintf(fich,"enabled TRUE \n");
					fwprintf(fich,L"maxPosition %s %s \n",vIDC_MaxPos0,vIDC_MaxPos1);
					fwprintf(fich,L"minPosition %s %s \n",vIDC_MinPos0,vIDC_MinPos1);
					fwprintf(fich,L"offset %s %s %s \n",vIDC_Offset0,vIDC_Offset4,vIDC_Offset5);
					fprintf(fich,"isActive ON\n");
					fprintf(fich,"},\n");
					fclose(fich);

					fopen_s(&fich2,"sensor.txt","a");
					fprintf(fich2,"ROUTE capteur%d.translation_changed TO %s%d.set_translation \n",nb_sensor,nom,nb_objet);
					fclose(fich2);

					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}


LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     
     HMENU      hMenu ;
     char nom[20]="objet";
	 
	 
     switch (message)
     {
     case WM_COMMAND:
          hMenu = GetMenu (hwnd) ;
          
          switch (LOWORD (wParam))
          {
         

          case ID_EDITION_QUIT :

			   fopen_s(&fich,"toto.wrl","a");
			   fprintf(fich,"] }\n");

			   fopen_s(&fich2,"sensor.txt","r");

			   while(!feof(fich2)){

				   fgets(ligne,100,fich2);
				   fputs(ligne,fich);
			   }
			   fclose(fich2);

			   //fprintf(fich,"\n Inline{\n");
			   //fprintf(fich,"url \"axes.wrl\" }\n");
			   SendMessage (hwnd, WM_CLOSE, 0, 0) ;
			   fclose(fich);
			   return 0;
			  
          case ID_EDITION_NEW :
			   fopen_s(&fich2,"sensor.txt","w");
			   fclose(fich2);

			   fopen_s(&fich,"toto.wrl","w");
			   fprintf(fich,"#VRML V2.0 utf8 \n");
			   fprintf(fich,"Group { \n");
			   fprintf(fich,"children [\n");
			   
			   fclose(fich);
			   EnableMenuItem(hMenu, ID_EDITION_NEW, MF_GRAYED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_CYLINDRE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_SPHERE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_BOITE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_CONE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_TEXTE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_DIRECTIONNELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_PONCTUELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_SPOT, MF_ENABLED);
			   //EnableMenuItem(hMenu, ID_ANIMATION_TRANSLATION, MF_ENABLED);
			   //EnableMenuItem(hMenu, ID_ANIMATION_ROTATION, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_FOND_FOND, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_FOND_FOND, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_CYLINDRE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_SPHERE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_PLAN, MF_ENABLED);
			   InvalidateRect (hwnd, NULL, TRUE) ;
               return 0;

          
		  
          case ID_GEOMETRIE_CYLINDRE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CYLINDRE), hwnd, (DLGPROC)cylindre);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_SPHERE: 
			  
			   DialogBox(NULL,MAKEINTRESOURCE(IDD_SPHERE), hwnd, (DLGPROC)sphere);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_BOITE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_BOITE), hwnd, (DLGPROC)boite);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_CONE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CONE), hwnd, (DLGPROC)cone);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_GEOMETRIE_TEXTE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_TEXTE), hwnd, (DLGPROC)texte);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
		  
			case ID_LUMIERE_DIRECTIONNELLE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_DIRECTIONNELLE), hwnd, (DLGPROC)lum_directionnelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_PONCTUELLE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_PONCTUELLE), hwnd, (DLGPROC)lum_ponctuelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_SPOT: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_SPOT), hwnd, (DLGPROC)lum_spot);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			/*case ID_ANIMATION_TRANSLATION: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_ANIMTRANSLATE), hwnd, (DLGPROC)animTranslate);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;*/

			/*case ID_ANIMATION_ROTATION: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_ANIMROTATE), hwnd, (DLGPROC)animRotate);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;*/

			case ID_SENSOR_CYLINDRE:
				DialogBox(NULL,MAKEINTRESOURCE(IDD_SENSOR_CYLINDRE), hwnd,(DLGPROC)sensorcylindre);
				InvalidateRect (hwnd, NULL, TRUE) ;
				return 0;

			case ID_SENSOR_PLAN :
				DialogBox(NULL,MAKEINTRESOURCE(IDD_SENSOR_PLAN), hwnd,(DLGPROC)sensorplan);
				InvalidateRect (hwnd, NULL, TRUE) ;
				return 0;

			case ID_SENSOR_SPHERE :
				DialogBox(NULL,MAKEINTRESOURCE(IDD_SENSOR_SPHERE), hwnd,(DLGPROC)sensorsphere);
				InvalidateRect (hwnd, NULL, TRUE) ;
				return 0;
				

			case ID_FOND_FOND: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_FOND), hwnd, (DLGPROC)fond);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_AIDE: 
			  
              // DialogBox(NULL,MAKEINTRESOURCE(IDD_AIDE), hwnd, (DLGPROC)aide);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  }
          
          return 0 ;
		  case WM_CLOSE:
	           	DestroyWindow(hwnd);
		
			case WM_DESTROY:
			  PostQuitMessage(0);
			return 0;
     }
         
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}