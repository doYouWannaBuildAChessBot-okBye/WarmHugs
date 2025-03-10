.PHONY	:

INCDIR	=	inc
SRCDIR	=	src
OBJ		=	$(SRC:.c=.o)
OBJDIR	=	bin/
SRC		=	main.c
INC		=	$(addprefix -I,$(INCDIR))
VPATH	=	$(INCDIR) $(SRCDIR) $(OBJDIR)
CFLAGS	=	$(INC)
NAME	=	O1-af

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $@

clean	:
	rm -f $(OBJ)
fclean	:
	$(MAKE) clean
	rm -f $(NAME)
