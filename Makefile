G++						=	g++
###############################################
PART0_PATH 				= 	./Parser
PART0_SRC_PATH			=	./Parser/src
PART0_TST_PATH			=	./Parser/tests
PART0_INC_PATH			=	./Parser/include
NAME_PARSER				=	Parser
PART0_SRC				=	$(PART0_SRC_PATH)/Parser.cpp

PART0_SRC_TEST			=	$(PART0_TST_PATH)/$(NAME_PARSER)_test.cpp
TEST_NAME_PARSER 		= 	test_$(NAME_PARSER)

###############################################
PART1_PATH 				= 	./Vector
PART1_SRC_PATH			=	./Vector/src
PART1_TST_PATH			=	./Vector/tests
PART1_INC_PATH			=	./Vector/include
NAME_VECTOR				=	Vector
PART1_SRC				=	$(PART1_SRC_PATH)/DomesticKoala.cpp \
							$(PART1_SRC_PATH)/KoalaAction.cpp

PART1_SRC_TEST			=	$(PART1_TST_PATH)/$(NAME_VECTOR)_test.cpp
TEST_NAME_VECTOR 		= 	test_$(NAME_VECTOR)

###############################################
PART2_PATH 				= 	./List
PART2_SRC_PATH			=	./List/src
PART2_TST_PATH			=	./List/tests
PART2_INC_PATH			=	./List/include
NAME_LIST				=	List
PART2_SRC				=	$(PART1_SRC_PATH)/Event.cpp \
							$(PART1_SRC_PATH)/EventManager.cpp

PART2_SRC_TEST			=	$(PART2_TST_PATH)/$(NAME_LIST)_test.cpp
TEST_NAME_LIST 			= 	test_$(NAME_LIST)

# ###############################################


# BIN_PATH				=	./bin

# NAME					=	Fruit
# TEST_NAME 				= 	test_$(NAME)

# INCFLAGS				+=	-I $(PART2_INC_PATH)

# CPPFLAGS				+= 	-Wall -Wextra -Werror $(INCFLAGS) -std=c++20

# SRCS 					= 	$(PART2_SRC) \
# 							$(BIN_PATH)/main.cpp							

OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean

# all						:	$(NAME)

# $(NAME)					:	$(OBJS)
# 							$(G++) $(OBJS) $(CPPFLAGS) -o $(NAME)

RM						=	rm -rf

clean					:
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART2_TST_PATH)

fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_PATH)

re						: 	fclean all

parser 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_PARSER)

tests_run_parser		:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_PARSER)

vector 					: 	fclean
							@$(MAKE) -C $(PART1_PATH)
							$(PART1_PATH)/$(NAME_VECTOR)

tests_run_vector		:	fclean
							@$(MAKE) -C $(PART1_TST_PATH)
							$(PART1_TST_PATH)/$(TEST_NAME_VECTOR)

list 					: 	fclean
							@$(MAKE) -C $(PART2_PATH)
							$(PART2_PATH)/$(NAME_LIST)

tests_run_list			:	fclean
							@$(MAKE) -C $(PART2_TST_PATH)
							$(PART2_TST_PATH)/$(TEST_NAME_LIST)

tests_run				:	fclean
							@$(MAKE) tests_run_prser
							@$(MAKE) tests_run_vector
							@$(MAKE) tests_run_list

.PHONY					: 	all clean fclean re parser tests_run_parser vector tests_run_vector tests_run
