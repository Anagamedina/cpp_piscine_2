# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assistant                                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 00:00:00 by assistant         #+#    #+#              #
#    Updated: 2025/10/16 00:00:00 by assistant        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ===========================
# CONFIGURATION
# ===========================

# Executable name
NAME = easyfind

# Compiler
CXX = c++

# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

# Directories
OBJ_DIR = objs/
DEP_DIR = deps/


# ===========================
# SOURCES AND OBJECTS
# ===========================

SRCS = main.cpp

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS = $(addprefix $(DEP_DIR), $(SRCS:.cpp=.d))


# ===========================
# RULES
# ===========================

.PHONY: all clean fclean re

# Compile everything
all: $(NAME)

# Create executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compile each .cpp to .o and generate dependencies
objs/%.o: %.cpp Makefile
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@mv $(@:.o=.d) $(DEP_DIR)

# Remove object files and dependencies
clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

# Remove everything including executable
fclean: clean
	rm -f $(NAME)

# Recompile from scratch
re: fclean all

# Include dependencies automatically (headers are handled by -MMD)
-include $(DEPS)


