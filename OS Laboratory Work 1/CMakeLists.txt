cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OS_Laboratory_Work_1")

function(add_exe target_name source_file extra_sources)
    add_executable(${target_name}
        ${source_file}
        ${extra_sources}
    )
	if (CMAKE_VERSION VERSION_GREATER 3.12)
		set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 20)
	endif()
endfunction()

add_exe(Main Main.cpp employee.cpp)
add_exe(Creator Creator.cpp employee.cpp)
add_exe(Reporter Reporter.cpp employee.cpp)

# Поддиректория с тестами

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(tests)