cmake_minimum_required(VERSION 3.27)
project(OctavianGaming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)




add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/Game/Game.h
	src/Game/Game.cpp
	src/InputHandler/InputHandler.h
	src/InputHandler/InputHandler.cpp
	src/Render/Render.h
	src/Render/Render.cpp
	src/SlotMachine/SlotMachine.h
	src/SlotMachine/SlotMachine.cpp
	src/SlotMachine/Reel.h
	src/SlotMachine/Reel.cpp
	src/SlotMachine/Symbol.h
	src/SlotMachine/Symbol.cpp
	src/StateMachine/State.h
	src/StateMachine/StateMachine.h
	src/StateMachine/StateMachine.cpp
	src/StateMachine/IdleState.h
	src/StateMachine/IdleState.cpp
	src/StateMachine/SpinningState.h
	src/StateMachine/SpinningState.cpp
	src/StateMachine/ResultState.h
	src/StateMachine/ResultState.cpp
	src/Button/Button.h
	src/Button/Button.cpp)

set(SFML_DIR "external/SFML-2.6.0/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system)
endif()

set_target_properties (${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)


