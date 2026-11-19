#include <iostream>
#include <string>
#include <vector>
#include "Player_info.h"
using namespace std;

//플레이어의 파티 정보, 소지금, 보유 아이템 상태를 텍스트나 바이너리 파일로 직렬화하여 저장
class Player{
public:
    vector<string> PC{};
    //PC = 포획한 포켓몬을 모두 저장하는 장치 <- 동적배열사용
    string Party[3] = {};
    //파티 = 포획한 포켓몬들 중 당장 꺼내 쓸 수 있게 준비한 스쿼드
    //원작에서는 파티에 최대 6마리까지 들어감 
    //최종 보스전에서 초보자에게 배틀이 너무 어려워질것을 고려해 최대 3마리
    int money = 0;
    int Berry = 0; 
    //원작에는 열매 말고도 배틀에서 사용하는 다양한 아이템이 있음
    //본 게임에서는 아이템은 열매만 취급
};