include("C:/Users/gabri/OneDrive/Área de Trabalho/Gerenciador_de_senhas/build/Meu_Qt_MinGW-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Gerenciador_de_senhas-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/gabri/OneDrive/Área de Trabalho/Gerenciador_de_senhas/build/Meu_Qt_MinGW-Debug/Gerenciador_de_senhas.exe
    GENERATE_QT_CONF
)
