cmake_minimum_required(VERSION 3.22)
project(RaycastRenderer)

set(CMAKE_CXX_STANDARD 14)

include_directories(Source/public SDL2)

# Must set the path to the main.cpp, for example: scripts/main.cpp if it is inside a folder
add_executable(${PROJECT_NAME} Source/main.cpp
        Source/public/AssetManager.h
        Source/public/BaseGameObject.h
        Source/public/Config.h
        Source/public/DeltaTime.h
        Source/public/ExampleGameObject.h
        Source/public/GameEngine.h
        Source/public/GameWindow.h
        Source/public/ICollidableObject.h
        Source/public/IDamageable.h
        Source/public/InputManager.h
        Source/public/IRenderableObject.h
        Source/public/Level.h
        Source/public/LevelFactory.h
        Source/public/LevelManager.h
        Source/public/Player.h
        Source/public/RaycastRenderer.h
        Source/public/Renderer.h
        Source/public/RenderInstanceManager.h
        Source/public/Singleton.h
        Source/public/TempTestLevel.h
        Source/public/Wall.h
        Source/public/Vector2.h
        Source/public/Camera.h
        Source/public/Component.h
        Source/public/HealthComponent.h
        #Source/public/TextureManager.h

        Source/private/AssetManager.cpp
        Source/private/DeltaTime.cpp
        Source/private/ExampleGameObject.cpp
        Source/private/GameEngine.cpp
        Source/private/GameWindow.cpp
        Source/private/InputManager.cpp
        Source/private/Level.cpp
        Source/private/LevelFactory.cpp
        Source/private/LevelManager.cpp
        Source/private/Player.cpp
        Source/private/RaycastRenderer.cpp
        Source/private/Renderer.cpp
        Source/private/RenderInstanceManager.cpp
        Source/private/Vector2.cpp
        Source/private/Camera.cpp
        Source/private/Wall.cpp
        Source/private/Component.cpp
        Source/private/BaseGameObject.cpp
        Source/private/HealthComponent.cpp
        #Source/private/TextureManager.cpp
)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH        "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY}
