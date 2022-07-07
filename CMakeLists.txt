cmake_minimum_required(VERSION 3.15)
project(GreenBeret)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
add_compile_options(-Wall -Wextra)


if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})



endif(UNIX)

if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )

    set ( SFML_DIR "D:/Karol/SFML/SFML-2.5.1/lib/cmake/SFML")
endif(WIN32)
find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(GreenBeret main.cpp Engine/Board.cpp Engine/Board.h Engine/Character.cpp Engine/Character.h Characters/Hero.cpp Characters/Hero.h Characters/Enemy.cpp Characters/Enemy.h Engine/SFMLView.cpp Engine/SFMLView.h Engine/SFMLControler.cpp Engine/SFMLControler.h Engine/GameManager.cpp Engine/GameManager.h Engine/GameStateControler.h States/MainMenu/MainMenuControler.cpp States/MainMenu/MainMenuControler.h States/LevelOptions/LevelOptionsControler.cpp States/LevelOptions/LevelOptionsControler.h States/Game/GameControler.cpp States/Game/GameControler.h States/Pauza/PauzaControler.cpp States/Pauza/PauzaControler.h States/GameOver/GameOverControler.cpp States/GameOver/GameOverControler.h)

target_link_libraries(GreenBeret sfml-system sfml-graphics sfml-window sfml-audio)