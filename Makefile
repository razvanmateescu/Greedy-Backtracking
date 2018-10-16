build: frati.cpp numaratoare.cpp
	g++ frati.cpp -o frati
	g++ numaratoare.cpp -o numaratoare
run-p1: frati
	./frati

run-p4: numaratoare
	./numaratoare
clean:
	rm -rf frati numaratoare
