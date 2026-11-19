PokemonData getPokemonMasterData(const string& name){};

struct PokemonData {
    string name;                 
    vector<string> types;        
    int baseHp;                  
    int baseAtk;                 
    int baseDef;                 
    int baseSpd;                 
};

//포켓몬 개체 공통 클래스
class PokemonInstance {
private:
    PokemonData baseData;            
    vector<string> learnableSkills;  // 전체 습득 가능 기술 풀

public:
    int level;
    int exp;
    int currentHp;
    Skill skillSet[4]; // 현재 장착 중인 스킬 4슬롯

    // 생성자 선언
    PokemonInstance(string pokemonName, int startLevel);

    // 상태 출력 함수 선언
    void showStatus() const;

    // 스킬 장착 관리 메뉴 함수 선언
    void changeSkillMenu();
};