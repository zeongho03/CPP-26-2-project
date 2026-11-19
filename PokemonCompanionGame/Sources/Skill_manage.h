vector<string> getLearnableSkills(const string& pokemonName);

struct Skill {
    string name; //기술 이름
    string type; //기술 타입(특정 타입의 포켓몬이 다른 타입의 기술을 사용할 수 있음)
    string category; // "physical"(물리공격), "buff"(능력치업), "heal"(회복)      
    int power;  //위력(공격기가 아니면 0)       
    int pp;   //스킬 사용 가능 횟수         
    int statType;// 어떤 능력치를 올릴지 (예: 1=공격, 2=방어, 3=스피드 등)
    int effectValue; // 버프량 또는 회복량 (예: +1단계, 혹은 체력 50 회복)
};
Skill getSkillData(const string& name){};
