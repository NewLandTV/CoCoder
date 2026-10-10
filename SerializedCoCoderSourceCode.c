#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#define CONSOLE_WIDTH 180
#define CONSOLE_HEIGHT 40
#define HALF_CONSOLE_WIDTH (CONSOLE_WIDTH >> 1)
#define HALF_CONSOLE_HEIGHT (CONSOLE_HEIGHT >> 1)
#define CODE_SAVE_PATH "C:\\NewLand\\CoCoder\\source.c"
#define CODE_EXECUTE_PATH "C:\\NewLand\\CoCoder\\source.exe"
char code[(CONSOLE_WIDTH-3)*CONSOLE_HEIGHT];void Init();void DrawNumber();void MoveCursor(int newX,int newY,const char ch);void Update();int Input();void ClearCode();void
EditCode(const char ch);void PrintCode();void GotoLineEndOfCode();void SaveCode();void RunCode();void Gotoxy(int x,int y);int currentCursorX=3;int currentCursorY;int main(void
){Init();while(1)Update();return 0;}void Init(){system("title CoCoder");system("mode con cols=180 lines=40");CONSOLE_CURSOR_INFO consoleCursorInfo;consoleCursorInfo.bVisible=0;
consoleCursorInfo.dwSize=1;SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&consoleCursorInfo);ClearCode();DrawNumber();Gotoxy(currentCursorX,currentCursorY);printf("_");
}void DrawNumber(){int i;for(i=0;i<CONSOLE_HEIGHT;i++){Gotoxy(1,i);if(i<9){printf(" ");}printf("%d",i+1);}Gotoxy(3,0);}void MoveCursor(int newX,int newY,const char ch){if(3<=
newX&&newX<CONSOLE_WIDTH&&0<=newY&&newY<CONSOLE_HEIGHT){Gotoxy(currentCursorX,currentCursorY);printf("%c",ch);currentCursorX=newX;currentCursorY=newY;Gotoxy(currentCursorX,
currentCursorY);printf("_");}}void Update(){int i;int key=Input();if(key!=-2){switch(key){case 8:if(currentCursorX==3&&currentCursorY>=0){MoveCursor(currentCursorX,
currentCursorY-1,' ');GotoLineEndOfCode();break;}MoveCursor(currentCursorX-1,currentCursorY,' ');EditCode(' ');break;case 9:for(i=0;i<4;i++){MoveCursor(currentCursorX+1,
currentCursorY,' ');EditCode(' ');}break;case 13:MoveCursor(3,currentCursorY+1,code[currentCursorX+1+(CONSOLE_WIDTH-3)*currentCursorY]==0?' ':code[currentCursorX+1+(
CONSOLE_WIDTH-3)*currentCursorY]);break;case 27:RunCode();break;case 224:switch(_getch()){case 75:
MoveCursor(currentCursorX - 1, currentCursorY, code[currentCursorX + 1 + (CONSOLE_WIDTH - 3)*currentCursorY]==0?' ':code[currentCursorX+1+(CONSOLE_WIDTH-3)*currentCursorY]);
break;case 77:
MoveCursor(currentCursorX + 1, currentCursorY, code[currentCursorX + 1 + (CONSOLE_WIDTH - 3)*currentCursorY] == 0?' ':code[currentCursorX+1+(CONSOLE_WIDTH-3)*currentCursorY]);
break;case 72:
MoveCursor(currentCursorX, currentCursorY - 1, code[currentCursorX + 1 + (CONSOLE_WIDTH - 3)*currentCursorY] == 0?' ':code[currentCursorX+1+(CONSOLE_WIDTH-3)*currentCursorY]);
break;case 80:
MoveCursor(currentCursorX,currentCursorY+1,code[currentCursorX+1+(CONSOLE_WIDTH-3)*currentCursorY]==0?' ':code[currentCursorX+1+(CONSOLE_WIDTH-3)*currentCursorY]);
break;}break;default:MoveCursor(currentCursorX+1,currentCursorY,key);EditCode(key);break;}}}int Input(){return _kbhit()?_getch():-2;}void ClearCode(){int i;for(i=0;i<(
CONSOLE_WIDTH-3)*CONSOLE_HEIGHT;i++){code[i]=' ';}}void EditCode(const char ch){code[currentCursorX+(CONSOLE_WIDTH-3)*currentCursorY]=ch;}void PrintCode(){int x;int y;
for(y=0;y<CONSOLE_HEIGHT;y++){for(x=0;x<CONSOLE_WIDTH-3; x++){Gotoxy(x+3,y);printf("%c", code[x + (CONSOLE_WIDTH - 3) * y]);}}}
void GotoLineEndOfCode(){int x;for(x=CONSOLE_WIDTH-3;x>=3;x--){if(code[x+(CONSOLE_WIDTH-3)*currentCursorY]==' '){MoveCursor(x,currentCursorY,code[currentCursorX+1+(
CONSOLE_WIDTH-3)*currentCursorY]==0?' ':code[currentCursorX+1+(CONSOLE_WIDTH-3)*currentCursorY]);return;}}}void SaveCode(){int x;int y;FILE* fp;fp=fopen(CODE_SAVE_PATH,"w");	
for(y=0;y<CONSOLE_HEIGHT;y++){for(x=0;x<CONSOLE_WIDTH-3;x++){if(code[x+(CONSOLE_WIDTH-3)*y]!=0){fprintf(fp,"%c",code[x+(CONSOLE_WIDTH-3)*y]);}}
fprintf(fp, "\n");}fclose(fp);}void RunCode(){SaveCode();system("gcc C:\\NewLand\\CoCoder\\source.c -o C:\\NewLand\\CoCoder\\source.exe"
);system("cls");system(CODE_EXECUTE_PATH);system("pause");system("cls");DrawNumber();ClearCode();currentCursorX=3;currentCursorY
=0;Gotoxy(currentCursorX,currentCursorY);printf("_");}void Gotoxy(int x,int y){COORD position={x,y};SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);}
