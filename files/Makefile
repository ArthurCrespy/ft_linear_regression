# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:54:39 by acrespy           #+#    #+#              #
#    Updated: 2023/01/16 15:01:53 by acrespy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := ft_linear_regression

NAME_COMPUTE := compute
NAME_TRAIN := train

SRC_DIR     := srcs
SRCS_COMPUTE := \
			ft_len.c \
			ft_utils.c \
			get_next_line.c \
			compute.c \

SRCS_TRAIN := \
			ft_len.c \
			ft_split.c \
			ft_utils.c \
			get_next_line.c \
			train.c \

SRCS_COMPUTE := ${SRCS_COMPUTE:%=${SRC_DIR}/%}
SRCS_TRAIN := ${SRCS_TRAIN:%=${SRC_DIR}/%}

OBJ_DIR     := .objs
OBJS_COMPUTE := ${SRCS_COMPUTE:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
OBJS_TRAIN := ${SRCS_TRAIN:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g

RM          := rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p ${@D}

all: ${NAME_COMPUTE} ${NAME_TRAIN}

${NAME_COMPUTE}: ${OBJS_COMPUTE}
	${CC} ${OBJS_COMPUTE} -o ${NAME_COMPUTE}
	${info EXECUTABLE CREATED: ${NAME_COMPUTE}}

${NAME_TRAIN}: ${OBJS_TRAIN}
	${CC} ${OBJS_TRAIN} -o ${NAME_TRAIN}
	${info EXECUTABLE CREATED: ${NAME_TRAIN}}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} -c -o $@ $<
	${info OBJECT CREATED: $@}

clean:
	${RM} ${OBJS_COMPUTE} ${OBJS_TRAIN} ${OBJ_DIR}
	${info REMOVED OBJECTS: ${OBJS_COMPUTE} ${OBJS_TRAIN}}

fclean: clean
	${RM} ${NAME_COMPUTE} ${NAME_TRAIN} .tetha
	${info REMOVED EXECUTABLES: ${NAME_COMPUTE} ${NAME_TRAIN}}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: clean fclean re
.SILENT: ${OBJS_COMPUTE} ${OBJS_TRAIN} ${NAME_COMPUTE} ${NAME_TRAIN} clean fclean re