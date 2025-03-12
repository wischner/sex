# Collect all the source files for the program
set(SRC_FILES
    main.cpp
)

# Create the executable for the main application
add_executable(HaikuSex ${SRC_FILES})

# Haiku system includes and libraries
find_path(HAIKU_INCLUDE_DIR
    NAMES app/Application.h
    PATHS /boot/system/develop/headers/be
)

find_library(HAIKU_LIB_BE
    NAMES be
    PATHS /boot/system/develop/lib
)

# Include the Haiku system headers
target_include_directories(HaikuSex
    PRIVATE ${HAIKU_INCLUDE_DIR}
)

# Link against the BeAPI (Haiku's UI API)
target_link_libraries(HaikuSex
    PRIVATE ${HAIKU_LIB_BE}
)