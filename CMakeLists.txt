cmake_minimum_required(VERSION 3.22)
project(RaycastRenderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        src/thirdparty
        src/Engine
        src
)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Engine/Core/Config.h

        src/Engine/Core/GameEngine.cpp
        src/Engine/Core/DeltaTime.cpp
        src/Engine/Core/InputManager.cpp
        src/Engine/Core/Singleton.h
        src/Engine/Core/AssetManager.cpp

        src/Engine/Core/Math/Vector2.h

        src/Engine/Rendering/Renderer.cpp
        src/Engine/Rendering/Camera.cpp
        src/Engine/Rendering/GameWindow.cpp
        src/Engine/Rendering/RaycastRenderer.cpp
        src/Engine/Rendering/RenderInstanceManager.cpp

        src/Engine/Level/Level.cpp
        src/Engine/Level/LevelManager.cpp
        src/Engine/Level/LevelFactory.cpp

        src/Engine/GameObject/BaseGameObject.cpp
        src/Engine/GameObject/Component.cpp

        src/Game/Level/TempTestLevel.h
        src/Game/Components/HealthComponent.cpp
        src/Game/GameObject/ExampleGameObject.cpp
        src/Game/GameObject/Player.cpp
        src/Game/GameObject/Wall.cpp
        src/main.cpp
)

if(WIN32)
    find_package(Vulkan REQUIRED)
    target_include_directories(${PROJECT_NAME} PUBLIC
            ${Vulkan_INCLUDE_DIRS}
            $ENV{VULKAN_SDK}/include/glm
            ${CMAKE_CURRENT_SOURCE_DIR}/src/thirdparty/glfw/include
    )

    target_link_libraries(${PROJECT_NAME}
            Vulkan::Vulkan
            $ENV{VULKAN_SDK}/lib/SDL2.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/src/thirdparty/glfw/lib-mingw-w64/libglfw3.a
    )

elseif(UNIX)
    find_package(Vulkan REQUIRED)
    find_package(glfw3 REQUIRED)
    find_package(glm REQUIRED)
    find_package(SDL2 REQUIRED)
    include_directories(
            ${GLFW3_INCLUDE_DIRS}
            ${GLM_INCLUDE_DIRS}
            ${SDL2_INCLUDE_DIRS})

    target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw glm::glm SDL2)
endif()
