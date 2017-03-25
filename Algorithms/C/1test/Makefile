#------------------------------------------------------------------------------
# MakeFile Básico.
BUILDID=$(shell date +%Y%m%d-%H%M%S)
MYINCLUDES=/home/spacial/Nextcloud/mestrado/algoritmos/flood/
CC=gcc
# flags que transformam warning em erros
WARNFLAGS=-Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum
WF2=-Wswitch-default -Wextra -Wall -Werror -Winvalid-pch -Wredundant-decls -Wmissing-prototypes
WF3=-Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral  -Wodr
# flags de traps e assembly
ASMFL=-fverbose-asm
TRAPSF=-finstrument-functions -flto -ftrapv
#------------------------------------------------------------------------------
PROGRAMS:= 1_granizo 2_substring 3_ordenador 4_quicksort
#------------------------------------------------------------------------------
# Somente os warning, se quiser melhorar, só adicionar no final..
FLAGS:= $(WARNFLAGS) $(WF2) $(WF3)
#------------------------------------------------------------------------------
all: $(PROGRAMS)
	$(info Todos compilados.)
#	$(call git)

$(PROGRAMS):%:%.c
# TODO: fazer o compilador só adicionar o ld para quem usar double
	$(info Compilando: $(^))
	@$(CC) -o $@ $^ $(FLAGS)

#.PHONY: clean cleanest
.PHONY: clean

git: clean
	git add -A .
	git commit -m 'Commit automático. ID: $(BUILDID)'

clean:
	-rm  -f $(PROGRAMS)

showvars:
		$(info $(shell   echo  -e "\nVariáveis do Make:\n"))
		$(info $(shell   echo  -e "\t PROGRAMS\t: $(PROGRAMS)"))
		$(info $(shell   echo  -e "\t SOURCES\t: $(SOURCES)"))
		$(info $(shell   echo  -e "\t INICIO\t\t: $(INICIO)"))
		$(info $(shell   echo  -e "\t FIM\t\t: $(FIM)"))
		$(info $(shell   echo  -e "\t CC\t\t: $(CC)"))
		$(info $(shell   echo  -e "\t FLAGS\t\t: $(FLAGS)"))
help:
		$(info $(shell   echo  -e "\nPara compilar, opções:\n"))
		$(info $(shell   echo  -e "\t all\t\t: compila todos os programas"))
		$(info $(shell   echo  -e "\t clean\t\t: limpa todos os *.o e todos os programas compilados"))
		$(info $(shell   echo  -e "\t git\t\t:  cria um commit automático"))
		$(info $(shell   echo  -e "\t showvars\t: mostra as variáveis do Makefile"))
		$(info $(shell   echo  -e "\t showlinks\t: mostra alguns links que ajudaram a criar este Makefile"))
