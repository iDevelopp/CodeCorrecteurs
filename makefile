# Variables
CC = gcc
CFLAGS = -g -Wall -Wextra
EXEC = code_correcteur.out
SRCS = main.c vecteurs.c mots.c codage.c controle.c bruitage.c correction_decodage.c
OBJS = $(SRCS:.c=.o)
DEPS = code_correcteur.h

all: $(EXEC)

# créer l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# compile les fichiers sources en objets
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

main.o: code_correcteur.h
vecteurs.o: code_correcteur.h
mots.o: code_correcteur.h
codage.o: code_correcteur.h
controle.o: code_correcteur.h
bruitage.o: code_correcteur.h
correction_decodage.o: code_correcteur.h
