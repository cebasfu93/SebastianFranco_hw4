placas.pdf : potencial.txt grafica.py
	python grafica.py

potencial.txt : a.out
	./a.out > potencial.txt

a.out : placas.c
	gcc placas.c -lm

clean:
	rm -f a.out potencial.txt M.txt placas.pdf
