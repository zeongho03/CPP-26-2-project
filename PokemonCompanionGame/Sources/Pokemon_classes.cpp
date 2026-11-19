#include <iostream>
#include <vector>
#include <string>
#include "Skill_manage.h"
#include "Pokemon_classes.h"

using namespace std;


//추가 필요
PokemonData getPokemonMasterData(const string& name) {
    // 전기 계열
    if (name == "피카츄") return {"피카츄", {"전기"}, 35, 55, 30, 90};
    if (name == "라이츄") return {"라이츄", {"전기"}, 60, 90, 55, 110};

    // 물 계열
    if (name == "꼬부기") return {"꼬부기", {"물"}, 44, 48, 65, 43};
    if (name == "어니부기") return {"어니부기", {"물"}, 59, 63, 80, 58};
    if (name == "거북왕") return {"거북왕", {"물"}, 79, 83, 100, 78};

    // 불꽃 계열
    if (name == "파이리") return {"파이리", {"불꽃"}, 39, 52, 43, 65};
    if (name == "리자드") return {"리자드", {"불꽃"}, 58, 64, 58, 80};
    if (name == "리자몽") return {"리자몽", {"불꽃", "비행"}, 78, 84, 78, 100};

    // 노말 / 땅 계열
    if (name == "링곰") return {"링곰", {"노말"}, 90, 130, 75, 55};
    if (name == "다투곰") return {"다투곰", {"땅", "노말"}, 130, 140, 105, 50};

    // 에스퍼 / 페어리 계열
    if (name == "랄토스") return {"랄토스", {"에스퍼", "페어리"}, 28, 25, 25, 40};
    if (name == "킬리아") return {"킬리아", {"에스퍼", "페어리"}, 38, 35, 35, 50};
    if (name == "가디안") return {"가디안", {"에스퍼", "페어리"}, 68, 65, 65, 80};

    // 풀 계열
    if (name == "해너츠") return {"해너츠", {"풀"}, 30, 30, 30, 30};
    if (name == "해루미") return {"해루미", {"풀"}, 75, 75, 55, 30};

    return {name, {"노말"}, 25, 10, 10, 10};
}


class PokemonInstance {
private:
    PokemonData baseData;            
    vector<string> learnableSkills;  // Skill_manage.h에서 가져온 전체 습득 가능 기술 풀

public:
    int level;
    int exp;
    int currentHp;
    Skill skillSet[4]; // 현재 장착 중인 스킬 4슬롯

    PokemonInstance(string pokemonName, int startLevel) {
        baseData = getPokemonMasterData(pokemonName);
        level = startLevel;
        exp = 0;
        currentHp = baseData.baseHp;

        // 전체 스킬 풀 가져오기
        learnableSkills = getLearnableSkills(pokemonName);

        // 초기 장착 스킬 설정 (처음엔 빈 슬롯으로 두고 시작하거나 기본 장착)
        for (int i = 0; i < 4; i++) {
            if (i < learnableSkills.size() && i < 2) {
                skillSet[i] = {learnableSkills[i], "노말", "",  40, 35, 0, 0}; 
            } else {
                skillSet[i] = {"", "", 0, 0};
            }
        }
    }
    //상태 출력 함수 선언
    void showStatus() const {
        cout << "========================================\n";
        cout << " [포켓몬 정보] " << baseData.name << " (Lv." << level << ")\n";
        cout << " 타입: ";
        for (const auto& t : baseData.types) cout << t << " ";
        cout << "\n HP: " << currentHp << " / " << baseData.baseHp << "\n";
        
        cout << " [장착 스킬셋]\n";
        for (int i = 0; i < 4; i++) {
            if (!skillSet[i].name.empty()) {
                cout << "   슬롯 [" << i + 1 << "] " << skillSet[i].name << "\n";
            } else {
                cout << "   슬롯 [" << i + 1 << "] (비어있음)\n";
            }
        }
        cout << "========================================\n";
    }

    // 유저가 리스트를 보고 직접 골라서 장착하는 핵심 함수
    void changeSkillMenu() {
        system("cls"); // 화면 정리 (Windows 기준)
        cout << "=== " << baseData.name << " 스킬 장착 관리 ===\n";
        cout << "현재 장착된 스킬:\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << (skillSet[i].name.empty() ? "(비어있음)" : skillSet[i].name) << "\n";
        }
        cout << "----------------------------------------\n";
        
        // 1. 이 포켓몬이 배울 수 있는 전체 스킬 풀 출력
        cout << "[" << baseData.name << "가 배울 수 있는 전체 기술 목록]\n";
        for (size_t i = 0; i < learnableSkills.size(); i++) {
            cout << i + 1 << ". " << learnableSkills[i] << "\n";
        }
        cout << "----------------------------------------\n";

        // 2. 바꿀 슬롯 선택 (1~4)
        int slotChoice;
        cout << "변경할 스킬 슬롯 번호를 선택하세요 (1~4, 취소는 0): ";
        cin >> slotChoice;
        if (slotChoice < 1 || slotChoice > 4) return;

        // 3. 배울 스킬 번호 선택
        int skillChoice;
        cout << "장착할 기술의 번호를 선택하세요: ";
        cin >> skillChoice;

        if (skillChoice < 1 || skillChoice > (int)learnableSkills.size()) {
            cout << "잘못된 번호입니다.\n";
            return;
        }

        // 선택한 스킬 이름 가져오기
        string selectedSkillName = learnableSkills[skillChoice - 1];

        // 4. 중복 장착 검사 (이미 장착된 기술인지 확인)
        for (int i = 0; i < 4; i++) {
            if (skillSet[i].name == selectedSkillName) {
                cout << "이미 장착되어 있는 기술입니다!\n";
                return;
            }
        }

        // 5. 최종 장착 처리 (위력과 타입은 임시 데이터 부여, 추후 스킬 데이터베이스에서 상세 값 연동 가능)
        skillSet[slotChoice - 1] = {selectedSkillName, "속성", "", 60, 20, 0, 0};
        cout << "성공적으로 [" << selectedSkillName << "]을(를) " << slotChoice << "번 슬롯에 장착했습니다!\n";
    }
};