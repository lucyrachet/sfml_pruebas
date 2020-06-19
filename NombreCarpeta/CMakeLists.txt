#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/clase1.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/clase2.cpp"
)

#Y donde se encuentran los .h  # Esto no tocar
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}"
)

