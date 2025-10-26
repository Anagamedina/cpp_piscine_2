# ===========================
# CONFIGURATION
# ===========================

# Executable name
NAME = identify
# Compiler
CXX = c++

# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g #-fsanitize=address

# Directories
OBJ_DIR = objs/
DEP_DIR = deps/

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# ===========================
# SOURCES AND OBJECTS
# ===========================

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp

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
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

# Compile each .cpp to .o and generate dependencies
# $(OBJ_DIR)/%.o: %.cpp Makefile
objs/%.o: %.cpp Makefile
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@echo "$(YELLOW)📝 Compiling: $(CYAN)$<$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@mv $(@:.o=.d) $(DEP_DIR)

# Remove object files and dependencies
clean:
	@echo "$(PURPLE)🧹 Cleaning object files and dependencies...$(RESET)"
	rm -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "$(GREEN)✅ Clean completed!$(RESET)"

# Remove everything including executable
fclean: clean
	@echo "$(PURPLE)🧹 Removing executable...$(RESET)"
	rm -f $(NAME)
	@echo "$(GREEN)✅ Full clean completed!$(RESET)"

# Recompile from scratch
re: fclean all

# Include dependencies automatically (headers are handled by -MMD)
-include $(DEPS)









