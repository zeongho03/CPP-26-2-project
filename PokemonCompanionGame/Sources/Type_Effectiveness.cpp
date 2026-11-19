#include <iostream>
#include <windows.h>
#include "Type_Effectiveness.h"
using namespace std;

void typeEffectiveness()
{//1-(1)
    cout << "                      타입 상성표"<< endl;
    cout << endl;

    cout << "       Vulneravle To <-  Type  -> Strong Against" << endl;
    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<<endl;
    cout << "        불 비행 바위 <-  벌레  -> 악 풀 에스퍼" << endl;
    cout << "    벌레 페어리 격투 <-   악   -> 고스트 에스퍼" << endl;
    cout << "  드래곤 페어리 얼음 <- 드래곤 -> 드래곤" << endl;
    cout << "                  땅 <-  전기  -> 비행 물" << endl;
    cout << "             독 강철 <- 페어리 -> 악 드래곤 격투" << endl;
    cout << "  페어리 비행 에스퍼 <-  격투  -> 악 얼음 노말 바위 강철" << endl;
    cout << "          땅 바위 물 <-   불   -> 벌레 풀 얼음 강철" << endl;
    cout << "      전기 얼음 바위 <-  비행  -> 벌레 풀 격투" << endl;
    cout << "           악 고스트 <- 고스트 -> 고스트 에스퍼" << endl;
    cout << "벌레 불 비행 얼음 독 <-   풀   -> 땅 바위 물" << endl;
    cout << "          풀 얼음 물 <-   땅   -> 전기 불 독 바위 강철" << endl;
    cout << "   격투 불 바위 강철 <-  얼음  -> 드래곤 비행 풀 땅" << endl;
    cout << "                격투 <-  노말  ->" << endl;
    cout << "           땅 에스퍼 <-   독   -> 페어리 풀" << endl;
    cout << "      벌레 악 고스트 <- 에스퍼 -> 격투 독" << endl;
    cout << "  격투 풀 땅 강철 물 <-  바위  -> 벌레 불 비행 얼음" << endl;
    cout << "          격투 불 땅 <-  강철  -> 페어리 얼음 바위" << endl;
    cout << "             전기 풀 <-   물   -> 불 땅 바위" << endl << endl;

    cout << "<-뒤로";//Esc
};
