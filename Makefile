CC = cc
CFLAGS = -Wall -Wextra -Werror

N = norminette -R CheckForbiddenSourceHeader -R CheckDefine

SRCDIR = src
OBJDIR = obj
DICTDIR = dict
PARSERDIR = parser
PRINTDIR = print
UTILSDIR = utils

SRC = $(SRCDIR)/main.c
OBJ = $(OBJDIR)/main.o \
	$(OBJDIR)/$(DICTDIR)/create_dict.o \
	$(OBJDIR)/$(DICTDIR)/destroy_dict.o \
	$(OBJDIR)/$(DICTDIR)/get_value.o \
	$(OBJDIR)/$(DICTDIR)/set_value.o \
	$(OBJDIR)/$(PARSERDIR)/parse_dict_file.o \
	$(OBJDIR)/$(PARSERDIR)/parse_line.o \
	$(OBJDIR)/$(PARSERDIR)/parse_number.o \
	$(OBJDIR)/$(PRINTDIR)/print_group.o \
	$(OBJDIR)/$(PRINTDIR)/print_digit.o \
	$(OBJDIR)/$(PRINTDIR)/print_number.o \
	$(OBJDIR)/$(PRINTDIR)/put_str.o \
	$(OBJDIR)/$(UTILSDIR)/copy_strlen.o \
	$(OBJDIR)/$(UTILSDIR)/get_file_size.o \
	$(OBJDIR)/$(UTILSDIR)/pad_number.o \
	$(OBJDIR)/$(UTILSDIR)/str_equals.o \
	$(OBJDIR)/$(UTILSDIR)/str_len.o \
	$(OBJDIR)/$(UTILSDIR)/trim_space.o \

NAME = rush-02

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h $(SRCDIR)/errors.h $(SRCDIR)/$(DICTDIR)/dict_types.h
	@$(N) $^
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/$(DICTDIR)/%.o: $(SRCDIR)/$(DICTDIR)/%.c $(SRCDIR)/$(DICTDIR)/%.h
	@$(N) $^
	@mkdir -p $(OBJDIR)/$(DICTDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/$(PARSERDIR)/%.o: $(SRCDIR)/$(PARSERDIR)/%.c $(SRCDIR)/$(PARSERDIR)/%.h
	@$(N) $^
	@mkdir -p $(OBJDIR)/$(PARSERDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/$(PRINTDIR)/%.o: $(SRCDIR)/$(PRINTDIR)/%.c $(SRCDIR)/$(PRINTDIR)/%.h
	@$(N) $^
	@mkdir -p $(OBJDIR)/$(PRINTDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/$(UTILSDIR)/%.o: $(SRCDIR)/$(UTILSDIR)/%.c $(SRCDIR)/$(UTILSDIR)/%.h
	@$(N) $^
	@mkdir -p $(OBJDIR)/$(UTILSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

fclean:
	rm -rf $(OBJDIR)
	rm -f $(NAME)

run: $(NAME)
	./$(NAME) 42

test: $(NAME)
	./$(NAME) ref/too_large.dict 42

debug: $(OBJ)
	$(CC) $(CFLAGS) -g $^ -o $(NAME)

.PHONY: fclean run test debug