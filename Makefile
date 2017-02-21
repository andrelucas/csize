BIN = csize

all: $(BIN) run

.PHONY: run
run: csize
	./csize

clean:
	rm -f $(BIN)
