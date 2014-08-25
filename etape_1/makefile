CC		=	gcc
NAME	=	space_invaders
SRC		=	$(wildcard src/core/*.c)	\
			$(wildcard src/part_MainMenu/*.c)	\
			$(wildcard src/part_Opt/*.c)	\
			$(wildcard src/part_HS/*.c)	\
			$(wildcard src/part_Game/*.c)	\
			$(wildcard src/x_func/*.c)

OBJS	=	$(SRC:.c=.o)
EXEC	= 	space_invaders
CFLAGS	= 	-W -Wall -Werror
#LDFLAGS =	-L../SDL2 -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework SDL2_ttf -framework Cocoa
LDFLAGS =	-L../SDL2 -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa
RM		=	rm -f

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(EXEC)

all:
		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(EXEC)

re:		fclean $(NAME)

