#include <iostream>
#include <windows.h>
#include "Guide.h"
using namespace std;

void Guide(){//1-(1)
    cout << "1. 조작" << endl << endl;
    cout << "   w            ^   " << endl;
    cout << "a     d 또는 <     >" << endl;
    cout << "   s            v   " << endl << endl;

    cout << "2. 전투" << endl << endl;
    cout << "포켓몬과 배틀을 시작하면 4개의 선택지가 나옵니다.(플레이어와 전투 시 3개)" << endl;
    cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<< endl;
    cout << "| 1. 싸운다   | 2. 포켓몬   |"<< endl;
    cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<< endl;
    cout << "| 3. 잡는다   | 4. 도망간다 |"<< endl;
    cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<< endl << endl;
    cout << "싸운다 : 현재 포켓몬이 지닌 기술 4개중 하나를 선택해 사용합니다." << endl;
    cout << "포켓몬 : 파티에 있는 다른 포켓몬으로 교체합니다." << endl;
    cout << "잡는다 : 대상에게 몬스터볼을 던집니다." << endl; // 플레이어와 전투시에는 없는 선택지.
    cout << "도망간다 : 배틀을 종료합니다."<< endl << endl;
    cout << "턴마다 자신과 상대방이 4개의 선택지 중 하나를 골라 행동합니다." << endl;
    cout << "선공여부는 개체나 기술의 스피드 우위에 따라 정해집니다." << endl << endl;
    
    cout << "3. 재화"<< endl;
    cout << "포켓몬을 포획, 방생하거나 열매를 수집하고 상점에서 판매하면 골드를 획득할 수 있습니다." << endl;
    cout << "얻은 골드로 상점에서 아이템을 구매할 수 있습니다." << endl << endl;

    cout << "<-뒤로"; //Esc
}
