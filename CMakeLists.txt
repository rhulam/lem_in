cmake_minimum_required(VERSION 3.7)
project(lem_in)

set(CMAKE_C_STANDARD 99)

FILE(GLOB libft_sources libft/*.c libft/*.h libft/get_next_line/*.c libft/ft_printf/*.c)

ADD_LIBRARY(libft.a STATIC ${libft_sources})

set(SOURCE_FILES main.c lem_in.h)
add_executable(lem_in ${SOURCE_FILES})
target_link_libraries(lem_in libft.a)