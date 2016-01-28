CC = g++
OBJS = obj/Animation.o obj/Enemy.o obj/Engine.o obj/Entity.o obj/Graphics.o obj/Hero.o obj/main.o
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
INCLUDE = -Iinclude
LIBS = -lSDL2 -lSDL2_image

complete: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o bin/build 

clean:
	\rm -R obj/*.o bin/build










obj/main.o : include/Engine.h src/main.cpp
	$(CC) $(INCLUDE) $(CFLAGS) src/main.cpp -o obj/main.o

obj/Engine.o : include/Engine.h include/Enemy.h include/Hero.h include/Entity.h include/Animation.h include/Graphics.h src/Engine.cpp
	$(CC) $(INCLUDE) $(CFLAGS) src/Engine.cpp -o obj/Engine.o

obj/Enemy.o : include/Enemy.h include/Hero.h src/Enemy.cpp
	$(CC) $(INCLUDE) $(CFLAGS) src/Enemy.cpp -o obj/Enemy.o

obj/Hero.o : include/Hero.h include/Animation.h include/Entity.h src/Hero.cpp
	$(CC) $(INCLUDE) $(CFLAGS) src/Hero.cpp -o obj/Hero.o

obj/Entity.o : include/Entity.h include/Animation.h src/Entity.cpp
	$(CC) $(INCLUDE) $(CFLAGS) src/Entity.cpp -o obj/Entity.o

obj/Animation.o : include/Animation.h include/Graphics.h src/Animation.cpp
	$(CC) $(INCLUDE) $(CFLAGS) src/Animation.cpp -o obj/Animation.o

obj/Graphics.o : include/Graphics.h src/Graphics.cpp
	$(CC) $(INCLUDE) $(CFLAGS) src/Graphics.cpp -o obj/Graphics.o
