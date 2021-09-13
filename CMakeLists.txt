add_compile_options(-std=c++17 -Wall -Werror -pedantic-errors -DNDEBUG)
add_executable(game part_b/game_test.cpp part_b/Auxiliaries.cpp part_b/Game.cpp part_b/TileItem.cpp part_b/Character.cpp part_b/Soldier.cpp part_b/Medic.cpp part_b/Sniper.cpp)
add_executable(part_a part_a/part_a_test.cpp part_a/examDetails.cpp)
add_executable(partA_group_test part_a/test_from_group.cpp part_a/examDetails.cpp)

add_executable(autot_part_a auto_testing/autot_part_a.cpp auto_testing/PtrArray.cpp auto_testing/Auxiliaries.cpp)
add_executable(autot_part_b auto_testing/autot_part_b.cpp auto_testing/PtrArray.cpp auto_testing/Auxiliaries.cpp)
