cmake_minimum_required(VERSION 3.10)
project(Handlers)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindPkgConfig)
pkg_search_module(SDL2 required SDL2)
pkg_search_module(SDL2IMAGE required SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF required SDL2_ttf>=2.0.0)
pkg_search_module(SDL2MIXER required SDL2_mixer>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS})

add_library(Handlers
CameraHandler.h
DisplayHandler.h
EventsHandler.h
Handler.h
HandlerError.h
ImageHandler.h
InputHandler.h
WindowHandler.h
SceneHandler.h
GameObjectHandler.h
Scene.h
CameraHandler.cpp
DisplayHandler.cpp
EventCallback.cpp
EventCallback.h
EventsHandler.cpp
Handler.cpp
HandlerError.cpp
ImageHandler.cpp
InputHandler.cpp
WindowHandler.cpp
SceneHandler.cpp
GameObjectHandler.cpp
Scene.cpp
)
target_link_libraries(Handlers ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2MIXER_LIBRARIES})
