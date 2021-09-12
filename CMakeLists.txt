add_compile_options(-std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG)
add_executable(game part_b/game_test.cpp part_b/Auxiliaries.cpp part_b/Game.cpp part_b/TileItem.cpp part_b/Character.cpp part_b/Soldier.cpp part_b/Medic.cpp part_b/Sniper.cpp)
add_executable(board part_b/board_test.cpp part_b/Auxiliaries.cpp)
add_executable(part_a part_a/part_a_test.cpp part_a/examDetails.cpp)
add_executable(partA_group_test part_a/test_from_group.cpp part_a/examDetails.cpp)

