# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/09 19:30:00 by anamedin          #+#    #+#              #
#    Updated: 2025/10/09 19:30:00 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = identify
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -MMD -g
RM          = rm -f

# Directorios
OBJDIR      = objs
DEPDIR      = deps

# Archivos fuente
SRCS        = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS        = $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS        = $(SRCS:%.cpp=$(DEPDIR)/%.d)

# Colores
GREEN       = \033[0;32m
BLUE        = \033[0;34m
RED         = \033[0;31m
RESET       = \033[0m

# Regla principal
all: $(NAME)

# Compilar el ejecutable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) compilado correctamente$(RESET)"

# Compilar objetos
$(OBJDIR)/%.o: %.cpp | $(OBJDIR) $(DEPDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(BLUE)Compilando: $<$(RESET)"

# Crear directorios
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

# Limpiar objetos
clean:
	@$(RM) -r $(OBJDIR)/ $(DEPDIR)/
	@echo "$(RED)✓ Objetos eliminados$(RESET)"

# Limpiar todo
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✓ $(NAME) eliminado$(RESET)"

# Recompilar
re: fclean all

# Phony targets
.PHONY: all clean fclean re

# Incluir dependencias
-include $(DEPS)

