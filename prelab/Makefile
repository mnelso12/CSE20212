CMP = g++
MAIN = main
FUNC = mortgage
EXEC = $(MAIN)

$(EXEC): $(MAIN).o $(FUNC).o
		$(CMP) $(MAIN).o $(FUNC).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp $(FUNC).h
		$(CMP) -c $(MAIN).cpp

$(FUNC).o: $(FUNC).cpp
		$(CMP) -c $(FUNC).cpp

clean:
	rm *.o $(EXEC)
