cmake_minimum_required(VERSION 3.22)
project(RaycastRenderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(Source/public)

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
)

if(WIN32)
    find_package(Vulkan REQUIRED)
    target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS} $ENV{VULKAN_SDK}/include/glm ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/include)
    target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan $ENV{VULKAN_SDK}/lib/SDL2.lib ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/lib-mingw-w64/libglfw3.a)
elseif(UNIX)
    find_package(Vulkan REQUIRED)
    find_package(glfw3 REQUIRED)
    find_package(glm REQUIRED)
    find_package(SDL2 REQUIRED)
    include_directories(${GLFW3_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

    target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw glm::glm SDL2)
endif()
