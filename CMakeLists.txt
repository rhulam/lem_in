cmake_minimum_required(VERSION 3.7)
project(lem_in)

set(CMAKE_C_STANDARD 99)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/)
FILE(GLOB libft_sources libft/*.c libft/*.h libft/get_next_line/*.c libft/ft_printf/*.c)

ADD_LIBRARY(libft.a STATIC ${libft_sources})

set(SOURCE_FILES main.c lem_in.h error.c free.c validation_after_read.c list_create.c help_fill_list.c)
add_executable(lem_in ${SOURCE_FILES})
target_link_libraries(lem_in libft.a)