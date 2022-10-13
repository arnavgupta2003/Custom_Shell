all: cr clean
cr:
	@echo "\n**Compiling Kernel** \n"
	
	gcc -w -o res_ls res_ls.c
	gcc -w -o res_date res_date.c
	gcc -w -o res_rm res_rm.c
	gcc -w -o res_cat res_cat.c
	gcc -w -o res_mkdir res_mkdir.c
	gcc -w -o run main.c
	@echo "\n**Completed Compiling Kernel** \n"
	@echo "**Running Kernel** \n"
	./run
	@echo "**Exiting Kernel** \n"
clean:
	@echo "**Removing Redundant Files** "
	rm -f res_ls res_mkdir res_rm res_cat res_date run
	@echo "\n**Removed Redundant Files** \n"