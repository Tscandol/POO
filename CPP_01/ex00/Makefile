# Colors for terminal output
M_RED = \033[1;31m
M_GREEN = \033[1;32m
M_BLUE = \033[1;34m
M_WHITE = \033[1;37m

################################################################
# Compilation target
NAME = ex00
CXX = c++
################################################################

################################################################
# Source files
SRCS = \
    main.cpp \
    Shovel.cpp \
    Hammer.cpp \
    Worker.cpp \
    Workshop.cpp
################################################################

################################################################
# Header files
HEADERS = \
    Position.hpp \
    Statistic.hpp \
    Tool.hpp \
    Shovel.hpp \
    Hammer.hpp \
    Worker.hpp \
    Workshop.hpp
################################################################

################################################################
# Object files
OBJS = $(SRCS:.cpp=.o)
################################################################

################################################################
# Dependency files
DEP = $(OBJS:.o=.d)
################################################################

################################################################
# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
################################################################

# Default target
all: $(NAME)

# Link object files into the final executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(M_GREEN)$(NAME) built$(M_WHITE)"

# Include dependency files (if present)
-include $(DEP)

# Compile .cpp -> .o and generate .d deps
%.o: %.cpp $(HEADERS)
	$(CXX) -MMD -MP $(CXXFLAGS) -c $< -o $@

# Clean object and dependency files
clean:
	@$(RM) $(OBJS) $(DEP)
	@echo "$(M_BLUE)OBJ AND DEP DELETED$(M_WHITE)"

# Clean everything, including the final executable
fclean: clean
	@$(RM) $(NAME)
	@echo "$(M_RED) $(NAME) has been removed$(M_WHITE)"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re