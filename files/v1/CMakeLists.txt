cmake_minimum_required(VERSION 3.24)
project(ft_linear_regression C)

set(CMAKE_C_STANDARD 23)

add_executable(train files/v1/srcs/ft_utils.c files/v1/srcs/get_next_line.c files/v1/srcs/train.c files/v1/srcs/ft_split.c files/v1/srcs/ft_len.c files/v1/srcs/dataset.c files/v1/srcs/theta.c)
add_executable(compute files/v1/srcs/ft_len.c files/v1/srcs/ft_utils.c files/v1/srcs/get_next_line.c files/v1/srcs/compute.c)
