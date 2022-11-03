PROJECT=stack
CC=clang
C_FLAGS=-c			\
		-W			\
		-Wall		\
		-std=c17	\
		-pedantic

C_SRC=$(wildcard src/*.c)
H_SRC=$(wildcard src/*.h)
OBJ=$(subst .c,.o,$(subst src,obj,$(C_SRC)))

all: mk_tmp_dir $(PROJECT)

$(PROJECT): $(OBJ)
	$(CC) $^ -o bin/$@

obj/%.o: src/%.c src/%.h
	$(CC) $< $(C_FLAGS) -o $@

obj/main.o: src/main.c $(H_SRC)
	$(CC) $< $(C_FLAGS) -o $@

mk_tmp_dir:
	mkdir -p bin obj

clean:
	rm -rf bin obj

