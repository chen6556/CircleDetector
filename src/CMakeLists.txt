aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/ui _UI_SOURCES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/base _BASE_SOURCES)

set(_UI_SOURCES ${_UI_SOURCES} PARENT_SCOPE)
set(_BASE_SOURCES ${_BASE_SOURCES} PARENT_SCOPE)