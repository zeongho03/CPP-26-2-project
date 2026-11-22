#include <iostream>
#include <conio.h>              // _kbhit(), _getch()
#include <windows.h>            // SetConsoleOutputCP, Sleep
#include "Type_Effectiveness.h" // 타입상성표 헤더파일
//#include "Skill_manage.h"         // 스킬풀 헤더파일
#include "Guide.h"              // 가이드표 헤더파일
//#include "Player_info.h"        // 플레이어 정보 헤더파일
//#include "Pokemon_classes.h"
#include "Map.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    MapData gameMap;
    initMap(gameMap);

    // 사용자 시작 위치: 맵 정가운데
    int playerX = MAP_WIDTH / 2;
    int playerY = MAP_HEIGHT / 2;

    bool isPlaying = true; // 게임 플레이 화면 상태

    renderGameScreen(gameMap, playerX, playerY);

    while (isPlaying)
    {
        // 키보드 입력이 들어왔을 때만 실행
        if (_kbhit())
        {
            int key = _getch();

            // ESC 키를 누르면 메뉴 출력
            // 1-(2)
            if (key == 27)
            {
                bool inMenu = true;
                
                // 메뉴에 진입할 때 한 번 화면을 정리하고 메뉴를 그림
                system("cls");

                while (inMenu)
                {
                    // 메뉴 UI 출력
                    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
                    cout << "|    가이드[G]     |\n";
                    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
                    cout << "|    상성표[T]     |\n";
                    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
                    cout << "|     종료[X]      |\n";
                    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
                    cout << "(메뉴 나가기: ESC)\n";

                    int menuKey = _getch(); // 메뉴 안에서의 입력

                    if (menuKey == 27) // 메뉴에서 ESC를 누르면 -> 게임 플레이 화면으로 복귀
                    {
                        inMenu = false;
                    }
                    else if (menuKey == 71 || menuKey == 103) // G 또는 g 입력
                    { 
                        system("cls"); // 메뉴판을 지우고 가이드 출력
                        Guide();
                        cout << "\n\n[메뉴로 돌아가려면 아무 키나 누르세요...]";
                        _getch(); 
                        system("cls"); // 가이드 화면을 지우고 다시 메뉴로 돌아갈 준비
                    }
                    else if (menuKey == 84 || menuKey == 116) // T 또는 t 입력
                    { 
                        system("cls"); // 메뉴판을 지우고 상성표 출력
                        typeEffectiveness();
                        cout << "\n\n[메뉴로 돌아가려면 아무 키나 누르세요...]";
                        _getch(); 
                        system("cls"); // 상성표 화면을 지우고 다시 메뉴로 돌아갈 준비
                    }
                    else if (menuKey == 88 || menuKey == 120) // X 또는 x 입력
                    {
                        isPlaying = false;
                        inMenu = false;
                    }
                    else
                    {
                        // 다른 키를 누르면 메뉴를 지우고 다시 깔끔하게 출력
                        system("cls");
                    }
                }

                // 메뉴에서 완전히 빠져나올 때 화면 정리(수정 11/22)
                if (isPlaying)
                {
                    renderGameScreen(gameMap, playerX, playerY);
                }
            }
            // 방향키 입력 처리 (맵 구현에 따라 수정 11/22)
            else
            {
                char inputChar = '\0';//쓰레기값 방지

                // 방향키(224 또는 0)와 WASD를 동일한 문자로 통합
                if (key == 224 || key == 0)
                {
                    int subKey = _getch();
                    if (subKey == 72)      inputChar = 'w'; // 위
                    else if (subKey == 80) inputChar = 's'; // 아래
                    else if (subKey == 75) inputChar = 'a'; // 왼쪽
                    else if (subKey == 77) inputChar = 'd'; // 오른쪽
                }
                else
                {
                    char ch = tolower(key);
                    if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
                    {
                        inputChar = ch; // WASD 이동
                    }
                    else if (ch == 'y' || ch == 'n')
                    {
                        inputChar = ch; // 야생 포켓몬 포획 여부 선택
                    }
                    else
                    {
                        inputChar = ch; // 그 외 키 입력도 handlePlayerInput으로 전달
                    }
                }

                if (inputChar != '\0' && handlePlayerInput(gameMap, playerX, playerY, inputChar))
                {
                    renderGameScreen(gameMap, playerX, playerY);
                }
            }
        }

        Sleep(10);
    }

    return 0;
}