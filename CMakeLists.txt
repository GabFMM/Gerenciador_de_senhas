cmake_minimum_required(VERSION 3.19)
project(Gerenciador_de_senhas LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

qt_add_executable(Gerenciador_de_senhas
    WIN32 MACOSX_BUNDLE
    main.cpp
    fazerlogin.cpp
    fazerlogin.h
    fazerlogin.ui
    menu.h
    menu.cpp
    menu.ui
    conexaobd.h
    conexaobd.cpp
)

target_link_libraries(Gerenciador_de_senhas
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)

target_link_libraries(Gerenciador_de_senhas PRIVATE	${CMAKE_CURRENT_SOURCE_DIR}/libsodium/lib/libsodium.a
)

target_include_directories(Gerenciador_de_senhas PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/libsodium/include
)

include(GNUInstallDirs)

install(TARGETS Gerenciador_de_senhas
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Gerenciador_de_senhas
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
