##
## makefile for space_invaders in /Users/flogro/grogne_f/projet_space
## 
## Made by GROGNET Florent
## Login   <grogne_f@etna-alternance.net>
## 
## Started on  Wed Jul  2 09:47:56 2014 GROGNET Florent
## Last update Wed Jul  2 11:03:39 2014 GROGNET Florent
##
CC	=	gcc
NAME	=	do-op
SRC	=	./src/main.c
OBJS	=	$(SRC:.c=.o)
EXEC	= 	space_invaders
CFLAGS	= 	-W -Wall -Werror
LDFLAGS =	-L./SDL2 -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa
RM	=	rm -f
ST_NAME =	./lib/libspace_invaders.a
DY_NAME =	./lib/libspace_invaders.so

$(NAME):
		$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(EXEC)

all:
		$(NAME) clean

space_invaders_static:
		$(CC) $(CFLAGS) -c $(SRC)
		mv *.o ./src
		ar rc $(ST_NAME) $(OBJS)
		ranlib $(ST_NAME)
		$(CC) $(LDFLAGS) $(ST_NAME) -o $(EXEC)

space_invaders_dynamic:
		$(CC) $(CFLAGS) -c $(SRC)
		mv *.o ./src
		$(CC) -shared -o $(DY_NAME) $(OBJS)
		$(CC) $(LDFLAGS) $(DY_NAME) -o $(EXEC)

clean:
		$(RM) $(OBJS) $(ST_NAME) $(DY_NAME)

fclean:
		$(RM) $(EXEC)
