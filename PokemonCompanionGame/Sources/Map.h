#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;

//맵 구현
const int MAP_WIDTH = 50;
const int MAP_HEIGHT = 20;

enum class TileType { //enum(열거형) 기능에 관한 부분 AI사용
    Normal = 0, // 빈칸
    Grass = 1,  // 🌱
    Wall = 2,   // # (이동 불가)
    Tree = 3,   // 🌲 (이동 불가)
    Water = 4,  // ~ - 이동 시 ⛵
    Snow = 5    // ❄️
};

struct WildEncounter {
    int x = 0;
    int y = 0;
    string pokemonName = "야생 포켓몬";
    bool captured = false; // true가 되면 이벤트 소멸
};

struct MapData {
    std::string name = "기본 맵";
    std::array<std::array<TileType, MAP_WIDTH>, MAP_HEIGHT> tiles{};
    std::vector<WildEncounter> encounters;
    bool hasEncounterPrompt = false;
    int activeEncounterIndex = -1;
    std::string statusMessage; // 포획 완료 등 단발성 안내 메시지
};

void initMap(MapData& map);
bool isInsideMap(int x, int y);
bool isWalkable(const MapData& map, int x, int y);

// 이동 및 포획 알림 처리 함수
// 반환값: 입력이 처리되었는지 여부 (종료 키 입력 시 false)
bool handlePlayerInput(MapData& map, int& playerX, int& playerY, char input);

void printMap(const MapData& map, int playerX, int playerY);
void renderGameScreen(const MapData& map, int playerX, int playerY);