tokenizer: tokenizer.o mainCode.o history.o
	cc -o tokenizer tokenizer.o mainCode.o history.o

clean:
	rm -f *.o tokenizer

tokenizer.o: tokenizer.h tokenizer.c

mainCode.o: mainCode.c tokenizer.h history.h

history.o: history.h history.c tokenizer.h
