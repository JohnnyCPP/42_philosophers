# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 20:27:13 by jonnavar          #+#    #+#              #
#    Updated: 2025/03/06 17:30:33 by jonnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## VARIABLE DECLARATIONS ##
###########################


INCLUDES_PATH	= ./include/
OBJECTS_PATH	= ./object/
SOURCES_PATH    = ./src/


NAME			= philo
CC				= cc
DEBUG_SYMBOLS	= -g3
CFLAGS			= -Wall -Wextra -Werror ${DEBUG_SYMBOLS}
GDB				= gdb
# both "-g" or "-g3" flags can be used.
# "-g3" includes everything included with "-g", but with 
# additional information to debug preprocessor directives
SANITIZE_FLAGS	= -fsanitize=thread ${DEBUG_SYMBOLS}
# "--track-origin=yes" tracks the origin of uninitialized values
# "-s" display a summary of the results directly in the terminal
# "--leak-check=full" enable detailed memory leak detection, and 
#                     report every possible memory leak
VALGRIND_FLAGS	= --track-origins=yes -s --leak-check=full --show-leak-kinds=all
# "-I <path>" instructs the compiler where to look for header files
# "-L <path>" instructs the linker where to look for static (.a) or 
#             shared (.so) libraries
# "-l<file>" instructs the linker to add a specific library by its name.
#            the linker will consider the "lib" prefix and ".a"/".so" sufix.
#            e.g. "-lft" links against "libft.a" or "libft.so".
#            note: this flag can't have a space in between, it's 
#                  processed as a single token
INCLUDE			= -I ${INCLUDES_PATH}


ALL				= all
CLEAN			= clean
FCLEAN			= fclean
RE				= re
HELP			= help
CC_SANITIZER	= sanitize
VALGRIND		= valgrind


PHONY			= .PHONY
STD_PHONY		= ${ALL} ${CLEAN} ${FCLEAN} ${RE} ${HELP}
DEBUG_PHONY		= ${CC_SANITIZER} ${VALGRIND} ${GDB}


SOURCE_FILES	= $(wildcard ${SOURCES_PATH}*.c)
# "patsubst": pattern substitution
# parameters: pattern, replacement, text
#
# pattern: the pattern to match. Supports wildcards
# replacement: the string to replace the pattern with. By using wildcards, 
#              Make keeps the original text matched by the same 
#              wildcard in the pattern
# text: the list of strings on which the substitution will be performed
OBJECT_FILES	= ${patsubst ${SOURCES_PATH}%.c, ${OBJECTS_PATH}%.o, ${SOURCE_FILES}}


CREATE_PATH		= mkdir -p
DELETE_FILE		= rm -f
DELETE_PATH		= rm -fr


## RULES ##
###########


${ALL}: ${NAME}


# "$@" refers to the target (%.o)
# "$<" refers to the dependency (%.c)
#
# "|" the pipe syntax indicates that the ${OBJECTS_PATH} is 
#     an Order-Only Prerequisite of the "${OBJECTS_PATH}%.o" target.
#     Order-Only Prerequisites are required, but don't trigger a rebuild.
#     This means that if an Order-Only Prerequisite changes, its target 
#     is not built again
#
#     note: the pipe "|" has been replaced with the create path instruction 
#           in the recipe.
${OBJECTS_PATH}%.o: ${SOURCES_PATH}%.c
	@${CREATE_PATH} $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


${NAME}: ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${OBJECT_FILES} -o ${NAME}
	@echo "The program \"${NAME}\" has been compiled."


${CLEAN}:
	@${DELETE_FILE} ${OBJECT_FILES}
	@${DELETE_PATH} ${OBJECTS_PATH}
	@echo "The objects of program \"${NAME}\" have been deleted."


${FCLEAN}: ${CLEAN}
	@${DELETE_FILE} ${NAME}
	@echo "The program \"${NAME}\" has been deleted."


${RE}: ${FCLEAN} ${ALL}


${CC_SANITIZER}: ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${OBJECT_FILES} -o ${NAME}
	@echo "C compiler's sanitizer has been added to debug thread issues."


#${VALGRIND}:
#	@${VALGRIND} ${VALGRIND_FLAGS} ./${NAME}


#${GDB}:
#	@${GDB} ./${NAME}


${HELP}:
	@echo "Available targets:"
	@echo "    all            - Build the project (default)"
	@echo "    clean          - Remove object files"
	@echo "    fclean         - Remove object files and the executable"
	@echo "    re             - Rebuild the project"
	@echo "    sanitize       - Build with address sanitizer for debugging"


${PHONY}: ${STD_PHONY} ${DEBUG_PHONY}
