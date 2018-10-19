# Author Anshu Verma
# Author Arpit Jain

TARGET = prodcomm

all: main.c reader.c reader.h munch1.c munch1.h queue.c queue.h constants.c constants.h
	gcc -g -Wall -Wextra -pedantic -o $(TARGET) main.c reader.c reader.h munch1.c munch1.h queue.c queue.h constants.c constants.h

clean:
	$(RM) $(TARGET)