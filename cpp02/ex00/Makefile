NAME		= fixed
TEST_NAME	= tests

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Fixed.cpp
OBJS		= $(SRCS:.cpp=.o)

TEST_SRCS	= tests.cpp Fixed.cpp
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_NAME) $(TEST_OBJS)
	./$(TEST_NAME)

%.o: %.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all test clean fclean re
