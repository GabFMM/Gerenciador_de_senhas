# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\Gerenciador_de_senhas_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Gerenciador_de_senhas_autogen.dir\\ParseCache.txt"
  "Gerenciador_de_senhas_autogen"
  )
endif()
