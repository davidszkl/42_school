all:
	gcc -Wall -Wextra -Werror mini_serv.c -o server &&\
	gcc -Wall -Wextra -Werror client_Read.c -o read &&\
	gcc -Wall -Wextra -Werror client_Write.c -o write &&\
	gcc -Wall -Wextra -Werror client_Write-multiline.c -o multi

clean:
	rm server read write multi