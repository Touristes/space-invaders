##
## makefile for space_invaders in /Users/flogro/grogne_f/projet_space
## 
## Made by GROGNET Florent
## Login   <grogne_f@etna-alternance.net>
## 
## Started on  Wed Jul  2 09:47:56 2014 GROGNET Florent
## Last update Wed Jul 16 17:37:20 2014 GROGNET Florent
##
CC		=	gcc
NAME	=	space_invaders
SRC		=	$(wildcard src/core/*.c)	\
			$(wildcard src/part_MainMenu/*.c)	\
			$(wildcard src/x_func/*.c)

OBJS	=	$(SRC:.c=.o)
EXEC	= 	space_invaders
CFLAGS	= 	-W -Wall -Werror
#LDFLAGS =	-L../SDL2 -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework SDL2_ttf -framework Cocoa
LDFLAGS =	-L../SDL2 -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa
RM		=	rm -f

$(NAME):
		$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(EXEC)

all:
		$(NAME) clean

clean:
		$(RM) $(OBJS)

fclean:
		$(RM) $(EXEC)
