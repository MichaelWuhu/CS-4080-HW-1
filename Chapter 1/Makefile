CC := cc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -Werror -g -O0
JAVA_BUILD := build/java
C_BUILD := build/c

.PHONY: all java c test debug-java debug-c clean

all: java c

java: $(JAVA_BUILD)/Hello.class
	java -cp $(JAVA_BUILD) Hello

$(JAVA_BUILD)/Hello.class: Hello.java
	mkdir -p $(JAVA_BUILD)
	javac -g -d $(JAVA_BUILD) Hello.java

c: $(C_BUILD)/dlist
	./$(C_BUILD)/dlist

$(C_BUILD)/dlist: dlist.c
	mkdir -p $(C_BUILD)
	$(CC) $(CFLAGS) dlist.c -o $(C_BUILD)/dlist

test: all

debug-java: $(JAVA_BUILD)/Hello.class
	jdb -classpath $(JAVA_BUILD) Hello

debug-c: $(C_BUILD)/dlist
	gdb ./$(C_BUILD)/dlist

clean:
	rm -rf build
