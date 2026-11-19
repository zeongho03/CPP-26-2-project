#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "Skill_manage.h"
using namespace std;
//3-(2)
//각 포켓몬마다 배울 수 있는 스킬들을 미리 정해놓습니다.
//타입 & 스토리를 고려합니다.
//배울 수 있는 스킬이 너무 많은 경우에는, 본 게임의 목적에 초점을 맞춰, 유저가 혼란스럽지 않게 그 수를 임의로 조정했습니다.
//추가 및 삭제가 쉽습니다.

//각 포켓몬별 스킬풀 통합 관리
vector<string> getLearnableSkills(const string& pokemonName) {
    if (pokemonName == "피카츄"){
        return {"전기쇼크", "플래시", "스파크","방전", "10만볼트", "번개", 
            "전광석화", "페인트", "힘껏치기", "고속이동", "일렉트릭네트"};
    }
    else if (pokemonName == "라이츄"){
        return {"전기쇼크", "플래시", "스파크","방전", "10만볼트", "번개", 
            "전광석화", "페인트", "힘껏치기", "고속이동", "일렉트릭네트", 
            "나쁜음모", "번개번치", "불꽃펀치", "파괴광선"};
    }
    else if (pokemonName == "꼬부기"){
        return {"물대포", "물의파동", "아쿠아테일", "하이드로펌프", "방어", "몸통박치기"};
    }
    else if (pokemonName == "어니부기"){
        return {"물대포", "물의파동", "아쿠아테일", "하이드로펌프", "방어", "몸통박치기", "한랭주의보", "회전부리", "하이드로캐논"};
    }
    else if (pokemonName == "거북왕"){
        return {"물대포", "물의파동", "아쿠아테일", "하이드로펌프", "방어", "몸통박치기", 
            "한랭주의보", "회전부리", "하이드로캐논", "러스터캐논", "철벽", "웨이브태클"};
    }
    else if (pokemonName == "파이리"){
        return  {"불꽃세례", "불꽃어금니", "회오리불꽃", "화염방사", "불대문자", "무서운얼굴"};
    }
    else if (pokemonName == "리자드"){
        return {"불꽃세례", "불꽃어금니", "회오리불꽃", "화염방사", "불대문자", "무서운얼굴", 
            "플레어드라이브", "번개펀치", "섀도클로"};
    }
    else if (pokemonName == "리자몽"){
        return {"불꽃세례", "불꽃어금니", "회오리불꽃", "화염방사", "불대문자", "무서운얼굴", 
            "플레어드라이브", "번개펀치", "섀도클로", "에어슬래시", "날개쉬기", "열풍", 
            "플레어드라이브"};
    }
    else if (pokemonName == "링곰"){
        return {"할퀴기", "베어가르기", "힘껏치기", "이판사판태클", "속여때리기", 
            "치근거리기", "지진"};
    }
    else if (pokemonName == "다투곰"){
        return {"할퀴기", "베어가르기", "힘껏치기", "이판사판태클", "속여때리기", 
            "치근거리기", "지진", "10만마력", "인파이트", "깨물어부수기", "하품"};
    }
    else if (pokemonName == "랄토스"){
        return {"염동력", "사이코쇼크", "드레인키스"};
    }
    else if (pokemonName == "킬리아"){
        return {"염동력", "사이코쇼크", "드레인키스", "매지컬샤인", "리프레시", 
            "문포스", "사이코키네시스"};
    }
    else if (pokemonName == "가디안"){
        return {"염동력", "사이코쇼크", "드레인키스", "매지컬샤인", "리프레시", 
            "문포스", "사이코키네시스", "치유소원", "미래예지", "기합구슬"};
    }
    else if (pokemonName == "해너츠"){
        return {"잎날가르기", "몸통박치기", "성장"};
    }
    else if (pokemonName == "해루미"){
        return {"잎날가르기", "몸통박치기", "성장", "화염방사", "리프스톰", "쾌청", "기가드레인"};
    }
    else {}
}


//스킬 데이터 - 스킬 타입, 카테고리, 수치 등 상세정보
Skill getSkillData(const string& name) {
    // --- 전기 타입 ---
    if (name == "전기쇼크") return {"전기쇼크", "전기", "special", 40, 30, 0, 0};
    if (name == "플래시")   return {"플래시", "노말", "buff", 0, 20, 2, -1};
    if (name == "스파크")   return {"스파크", "전기", "physical", 65, 20, 0, 0};
    if (name == "방전")     return {"방전", "전기", "special", 80, 15, 0, 0};
    if (name == "10만볼트") return {"10만볼트", "전기", "special", 90, 15, 0, 0};
    if (name == "번개")     return {"번개", "전기", "special", 110, 10, 0, 0};
    if (name == "일렉트릭네트") return {"일렉트릭네트", "전기", "special", 55, 15, 0, 0};
    if (name == "번개펀치") return {"번개펀치", "전기", "physical", 75, 15, 0, 0};
    if (name == "번개번치") return {"번개번치", "전기", "physical", 90, 15, 0, 0};

    // --- 물 타입 ---
    if (name == "물대포")   return {"물대포", "물", "special", 40, 25, 0, 0};
    if (name == "물의파동") return {"물의파동", "물", "special", 60, 20, 0, 0};
    if (name == "아쿠아테일") return {"아쿠아테일", "물", "physical", 90, 10, 0, 0};
    if (name == "하이드로펌프") return {"하이드로펌프", "물", "special", 110, 5, 0, 0};
    if (name == "한랭주의보") return {"한랭주의보", "얼음", "special", 70, 15, 0, 0};
    if (name == "회전부리") return {"회전부리", "비행", "physical", 80, 20, 0, 0};
    if (name == "하이드로캐논") return {"하이드로캐논", "물", "special", 150, 5, 0, 0};
    if (name == "러스터캐논") return {"러스터캐논", "강철", "special", 80, 10, 0, 0};
    if (name == "웨이브태클") return {"웨이브태클", "물", "physical", 120, 15, 0, 0};

    // --- 불꽃 타입 ---
    if (name == "불꽃세례") return {"불꽃세례", "불꽃", "special", 40, 25, 0, 0};
    if (name == "불꽃어금니") return {"불꽃어금니", "불꽃", "physical", 65, 15, 0, 0};
    if (name == "회오리불꽃") return {"회오리불꽃", "불꽃", "special", 35, 15, 0, 0};
    if (name == "화염방사") return {"화염방사", "불꽃", "special", 90, 15, 0, 0};
    if (name == "불대문자") return {"불대문자", "불꽃", "special", 110, 5, 0, 0};
    if (name == "플레어드라이브") return {"플레어드라이브", "불꽃", "physical", 120, 15, 0, 0};
    if (name == "열풍")     return {"열풍", "불꽃", "special", 95, 10, 0, 0};

    // --- 풀 타입 ---
    if (name == "잎날가르기") return {"잎날가르기", "풀", "physical", 55, 25, 0, 0};
    if (name == "성장")     return {"성장", "노말", "buff", 0, 20, 3, 1};        // 특수공격(3) 1단계 상승
    if (name == "리프스톰") return {"리프스톰", "풀", "special", 130, 5, 0, 0};
    if (name == "쾌청")     return {"쾌청", "불꽃", "buff", 0, 5, 0, 0};        // 날씨 변경기
    if (name == "기가드레인") return {"기가드레인", "풀", "special", 75, 10, 0, 0};

    // --- 에스퍼 / 페어리 타입 ---
    if (name == "염동력")   return {"염동력", "에스퍼", "special", 50, 25, 0, 0};
    if (name == "사이코쇼크") return {"사이코쇼크", "에스퍼", "special", 80, 10, 0, 0};
    if (name == "드레인키스") return {"드레인키스", "페어리", "special", 50, 10, 0, 0};
    if (name == "매지컬샤인") return {"매지컬샤인", "페어리", "special", 80, 10, 0, 0};
    if (name == "문포스")   return {"문포스", "페어리", "special", 95, 15, 0, 0};
    if (name == "사이코키네시스") return {"사이코키네시스", "에스퍼", "special", 90, 10, 0, 0};
    if (name == "치유소원") return {"치유소원", "에스퍼", "heal", 0, 10, 0, 100};    // 대량 체력 회복
    if (name == "미래예지") return {"미래예지", "에스퍼", "special", 120, 10, 0, 0};
    if (name == "고속이동") return {"고속이동", "에스퍼", "buff", 0, 30, 5, 2};     // 스피드(5) 2단계 상승
    if (name == "치근거리기") return {"치근거리기", "페어리", "physical", 90, 10, 0, 0};
    
    // --- 노말 타입 ---
    if (name == "전광석화") return {"전광석화", "노말", "physical", 40, 30, 0, 0};
    if (name == "페인트")   return {"페인트", "노말", "physical", 30, 10, 0, 0};
    if (name == "파괴광선") return {"파괴광선", "노말", "special", 150, 5, 0, 0};
    if (name == "무서운얼굴") return {"무서운얼굴", "노말", "buff", 0, 10, 5, -2};   // 상대 스피드 하락용
    if (name == "할퀴기")   return {"할퀴기", "노말", "physical", 40, 35, 0, 0};
    if (name == "베어가르기") return {"베어가르기", "노말", "physical", 70, 20, 0, 0};
    if (name == "이판사판태클") return {"이판사판태클", "노말", "physical", 120, 15, 0, 0};
    if (name == "몸통박치기") return {"몸통박치기", "노말", "physical", 40, 35, 0, 0};
    if (name == "리프레시") return {"리프레시", "노말", "heal", 0, 20, 0, 20};      // 상태 및 소량 회복
    
    // --- 격투 타입 ---
    if (name == "힘껏치기") return {"힘껏치기", "격투", "physical", 40, 35, 0, 0};
    if (name == "인파이트") return {"인파이트", "격투", "physical", 120, 5, 0, 0};
    if (name == "기합구슬") return {"기합구슬", "격투", "special", 120, 5, 0, 0};

    // --- 악 타입 ---
    if (name == "나쁜음모") return {"나쁜음모", "악", "buff", 0, 20, 3, 2};         // 특수공격(3) 2단계 상승
    if (name == "속여때리기") return {"속여때리기", "악", "physical", 60, 20, 0, 0};
    if (name == "깨물어부수기") return {"깨물어부수기", "악", "physical", 80, 15, 0, 0};
    
    // --- 고스트 타입 ---
    if (name == "섀도클로") return {"섀도클로", "고스트", "physical", 70, 15, 0, 0};
    
    // --- 비행 타입 ---
    if (name == "에어슬래시") return {"에어슬래시", "비행", "special", 75, 15, 0, 0};
    if (name == "날개쉬기") return {"날개쉬기", "비행", "heal", 0, 10, 0, 50};       // 체력 50 회복
   
    // --- 땅 타입 ---
    if (name == "지진")     return {"지진", "땅", "physical", 100, 10, 0, 0};
    if (name == "10만마력") return {"10만마력", "땅", "physical", 95, 10, 0, 0};
    
    // 예외 처리
    return {"알수없음", "노말", "none", 0, 0, 0, 0};
}