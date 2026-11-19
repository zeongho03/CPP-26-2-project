#include <iostream>
#include <conio.h>              // _kbhit(), _getch()
#include <windows.h>            // SetConsoleOutputCP, Sleep
#include "Type_Effectiveness.h" // 타입상성표 헤더파일
//#include "Skill_manage.h"         // 스킬풀 헤더파일
#include "Guide.h"              // 가이드표 헤더파일
//#include "Player_info.h"        // 플레이어 정보 헤더파일
//#include "Pokemon_classes.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    bool isPlaying = true; // 게임 플레이 화면 상태

    cout << "WASD 또는 방향키를 눌러보세요. (종료: ESC 키)\n\n";

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

                // 메뉴에서 완전히 빠져나올 때 화면 정리
                system("cls");
                cout << "WASD 또는 방향키를 눌러보세요. (종료: ESC 키)\n\n";
            }
            // 방향키 입력 처리 -> 추후 맵과 플레이어 위치 설정 시 키입력에 따른 이동 구현으로 수정예정
            else if (key == 224 || key == 0)
            {
                int subKey = _getch();
                switch (subKey)
                {
                case 72: cout << "위"; break;
                case 80: cout << "아래"; break;
                case 75: cout << "왼쪽"; break;
                case 77: cout << "오른쪽"; break;
                }
            }
            // 일반 키 입력 처리
            else
            {
                char ch = tolower(key);
                if (ch == 'w') cout << "W" << endl;
                else if (ch == 'a') cout << "A" << endl;
                else if (ch == 's') cout << "S" << endl;
                else if (ch == 'd') cout << "D" << endl;
            }
        }

        Sleep(10);
    }

    return 0;
}