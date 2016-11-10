cuerda.gif : cuerda.txt animacion.py
	python animacion.py

cuerda.txt : a.out
	./a.out > cuerda.txt

a.out : cuerda.c
	gcc cuerda.c -lm

clean:
	rm -r a.out cuerda.txt cuerda.gif
