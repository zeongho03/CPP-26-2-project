#include "Map.h"
#include <iostream>
#include <vector>

using namespace std;

const int MID_X = MAP_WIDTH / 2;
const int MID_Y = MAP_HEIGHT / 2;

//미리 지정된 (x, y) 좌표 목록을 순회하며 맵의 해당 칸을 지정한 타일 타입으로 변경
void applyCoordList(
    MapData& map,
    const vector<pair<int, int>>& coords,//배치할 (x, y) 좌표 쌍의 목록
    TileType type
) {
    for (const auto& [x, y] : coords) {
        if (isInsideMap(x, y)) {//맵 범위를 벗어난 좌표는 isInsideMap 검사를 통해 안전하게 무시
            map.tiles[y][x] = type;
        }
    }
}

//특정 좌표 (x, y)에서 아직 포획되지 않은 활성 야생 포켓몬 인카운터를 찾습니다.
int findActiveEncounterIndex(const MapData& map, int x, int y) {
    for (size_t i = 0; i < map.encounters.size(); ++i) {
        const auto& enc = map.encounters[i];
        if (!enc.captured && enc.x == x && enc.y == y) {
            return size_t(i);
            //조건에 맞는 인카운터가 있으면 map.encounters 내 인덱스(0 이상)를 반환
        }
    }
    return -1;
    //없거나 이미 포획(captured == true)된 경우 -1을 반환
}


//맵의 기본 지형, 지정된 장식 타일(나무/풀/눈), 야생 포켓몬 출현 좌표를 초기화
void initMap(MapData& map) {
    map.hasEncounterPrompt = false;
    map.activeEncounterIndex = -1;
    map.encounters.clear();

    // 1. 기본 바탕 및 외곽 벽 / 호수 구역 설정
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            if (x == 0 || x == MAP_WIDTH - 1 || y == 0 || y == MAP_HEIGHT - 1) {
                //외곽 테두리는 벽(Wall)
                map.tiles[y][x] = TileType::Wall;
            } else if (x < 20 && y >= 13) {
                // 왼쪽 아래 구역: 물(~)
                map.tiles[y][x] = TileType::Water;
            } else {
                // 나머지 기본 칸: 빈칸
                map.tiles[y][x] = TileType::Normal;
            }
        }
    }

    // 2. 미리 지정한 좌표로 나무(🌲), 풀(🌱), 눈(❄️) 듬성듬성 배치
    const vector<pair<int, int>> treeCoords = {
        {3, 2}, {7, 3}, {12, 2}, {17, 4}, {22, 2},
        {5, 6}, {11, 6}, {16, 7}, {21, 8},
        {4, 8}, {14, 8}
    };
    const vector<pair<int, int>> grassCoords = {
        {27, 2}, {32, 3}, {38, 2}, {44, 4},
        {29, 5}, {35, 6}, {41, 5}, {46, 7},
        {26, 8}, {33, 8}, {39, 8}
    };
    const vector<pair<int, int>> snowCoords = {
        {28, 11}, {34, 12}, {40, 11}, {46, 13},
        {27, 14}, {33, 15}, {39, 15}, {44, 16},
        {30, 17}, {37, 18}, {45, 18}
    };

    applyCoordList(map, treeCoords, TileType::Tree);
    applyCoordList(map, grassCoords, TileType::Grass);
    applyCoordList(map, snowCoords, TileType::Snow);

    // 시작 위치(맵 정가운데)는 이동 가능하게 빈칸 확보
    map.tiles[MID_Y][MID_X] = TileType::Normal;

    // 3. 미리 지정한 야생 포켓몬 출현 위치 (맵에는 별도 표시하지 않음)
    map.encounters = {
        {28, 3, "이상해씨", false},
        {36, 6, "꼬부기", false},
        {10, 14, "잉어킹", false},
        {35, 14, "잠만보", false},
        {15, 5, "캐터피", false}
    };
}

//좌표가 맵을 벗어나지 않는지 검사
bool isInsideMap(int x, int y) {
    return x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT;
}

//플레이어가 지정된 좌표 (x, y)로 이동할 수 있는지 판별
bool isWalkable(const MapData& map, int x, int y) {
    if (!isInsideMap(x, y)) return false;
    TileType t = map.tiles[y][x];
    // wall과 tree만 이동 불가
    return t != TileType::Wall && t != TileType::Tree;
}


//플레이어의 키 입력을 처리하여 포획 선택, 알림 닫기, 좌표 이동 및 인카운터 발생을 제어
bool handlePlayerInput(MapData& map, int& playerX, int& playerY, char input) {
    char c = tolower(input);
    bool isMoveKey = (c == 'w' || c == 'a' || c == 's' || c == 'd');

    map.statusMessage.clear();

    //포획 알림(hasEncounterPrompt)이 켜진 상태에서
    //-'y': 현재 활성 야생 포켓몬을 포획 처리(captured = true)하고 알림 닫기
    //-'n': 제자리에 머물며 알림만 닫기
    //-'wasd' 등 다른 키: 알림을 닫은 뒤 이어지는 이동 로직 수행
    //이동 키 입력 시 목표 좌표가 이동 가능하면 플레이어 좌표를 옮기고,
    //해당 위치에 미포획 야생 포켓몬이 있으면 포획 알림 상태를 활성화
    
    // 포획 알림 텍스트가 떠 있는 상태 처리
    if (map.hasEncounterPrompt) {
        if (c == 'y') {
            if (map.activeEncounterIndex >= 0 &&
                map.activeEncounterIndex < map.encounters.size()) {
                map.encounters[map.activeEncounterIndex].captured = true;
                map.statusMessage = "[포획 완료] " +
                                    map.encounters[map.activeEncounterIndex].pokemonName +
                                    "을(를) 포획했습니다! 이제 이 위치는 일반 길입니다.";
            }
            map.hasEncounterPrompt = false;
            map.activeEncounterIndex = -1;
            return true;
        }

        if (c == 'n') {
            // 제자리에 머물며 알림 텍스트만 닫기
            map.hasEncounterPrompt = false;
            map.activeEncounterIndex = -1;
            return true;
        }

        if (isMoveKey) {
            // wasd 또는 방향키 입력 시 알림 텍스트를 닫고 아래 이동 로직 진행
            map.hasEncounterPrompt = false;
            map.activeEncounterIndex = -1;
        } else {
            return false;
        }
    }

    if (!isMoveKey) {
        return false;
    }

    int nextX = playerX;
    int nextY = playerY;

    if (c == 'w') --nextY;
    else if (c == 's') ++nextY;
    else if (c == 'a') --nextX;
    else if (c == 'd') ++nextX;

    if (isWalkable(map, nextX, nextY)) {
        playerX = nextX;
        playerY = nextY;

        int encIdx = findActiveEncounterIndex(map, playerX, playerY);
        if (encIdx != -1) {
            map.hasEncounterPrompt = true;
            map.activeEncounterIndex = encIdx;
        }
        return true;
    }

    return false;
}


//전체 50x20 맵과 플레이어 위치, 그리고 활성화된 포획 알림 문구를 콘솔에 출력
void printMap(const MapData& map, int playerX, int playerY) {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            // grass, water, snow 등 어느 타일이든 플레이어와 겹치면 플레이어 이모지 출력
            if (x == playerX && y == playerY) {
                //물(Water) 타일 위에 있을 때는 '⛵', 그 외 타일에서는 '🧑'를 표시
                if (map.tiles[y][x] == TileType::Water) {
                    std::cout << "⛵";
                } else {
                    std::cout << "🧑";
                }
                continue;
            }

            switch (map.tiles[y][x]) {
                case TileType::Normal: std::cout << "  "; break;
                case TileType::Wall:   std::cout << "# "; break;
                case TileType::Tree:   std::cout << "🌲"; break;
                case TileType::Grass:  std::cout << "🌱"; break;
                case TileType::Water:  std::cout << "~ "; break;
                case TileType::Snow:   std::cout << "❄️"; break;
            }
        }
        std::cout << '\n';
    }
    //hasEncounterPrompt가 true이면 맵 하단에 포획 여부를 묻는 안내 문구를 함께 출력
    if (map.hasEncounterPrompt) {
        std::cout << "\n야생포켓몬이 튀어나왔다! 포획하시겠습니까?[y/n]\n";
    }
}

//게임스크린 출력
void renderGameScreen(const MapData& map, int playerX, int playerY)
{
    system("cls");
    cout << "WASD 또는 방향키로 이동하세요. (메뉴: ESC)\n\n";
    printMap(map, playerX, playerY);
}