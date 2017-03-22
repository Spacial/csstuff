#------------------------------------------------------------------------------
# MakeFile Básico.
BUILDID=$(shell date +%Y%m%d-%H%M%S)
MYINCLUDES=/home/spacial/Nextcloud/mestrado/algoritmos/1lista/
MYLIBRARIES=
CC=gcc
CFLAGS=-I. -Wall
# flags que transformam warning em erros
WARNFLAGS=-Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum
WF2=-Wswitch-default -Wextra -Wall -Werror -Winvalid-pch -Wredundant-decls -Wmissing-prototypes
WF3=-Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral  -Wodr
# flags de traps e assembly
ASMFL=-fverbose-asm
TRAPSF=-finstrument-functions -flto -ftrapv
# quem procurar
WILDCARDS=exerc
INICIO=01
FIM=09
# Cria o wildcard dos exercicios
PROGRAMS := $(shell for i in `seq -f "%02g" $(INICIO) $(FIM)`; do echo $(WILDCARDS)$${i}; done)
#SOURCES := $(shell for i in `seq -f "%02g" $(INICIO) $(FIM)`; do echo $(WILDCARDS)$${i}.c; done)
SOURCES := $(shell ls *.c)
#------------------------------------------------------------------------------
# Somente os warning, se quiser melhorar, só adicionar no final..
FLAGS:= $(WARNFLAGS) $(WF2) $(WF3)
#------------------------------------------------------------------------------
# verifica se há um double e adiciona nas flags
ifeq (,$(findstring double,$(SOURCES)))
  	FLAGS += -lm
endif
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
#	$(foreach p,$(PROGRAMS),  test -s $(P) || rm -f $(P) ;)
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
		$(info $(shell   echo  -e "\t clean\t\t: limpa todos os *.o"))
		$(info $(shell   echo  -e "\t cleanest\t: limpa todos os *.o e todos os programas compilados"))

showlinks:
		$(info $(shell   echo  -e "\nLinks úteis:\n"))
		$(info $(shell   echo  -e "--Makefile:\n"))
		$(info $(shell   echo  -e "\thttps://www.gnu.org/software/make/manual/html_node/Quick-Reference.html\n"))
		$(info $(shell   echo  -e "\thttp://www.cplusplus.com/forum/unices/12499/\n"))
		$(info $(shell   echo  -e "\thttps://www.gnu.org/prep/standards/html_node/Makefile-Basics.html\n"))
		$(info $(shell   echo  -e "\thttps://www.gnu.org/prep/standards/html_node/index.html\n"))
		$(info $(shell   echo  -e "\thttps://stackoverflow.com/questions/9270788/is-there-a-utility-for-validating-makefiles\n"))
		$(info $(shell   echo  -e "\thttps://www.gnu.org/software/make/manual/html_node/Conditional-Syntax.html\n"))
		$(info $(shell   echo  -e "\thttps://www.gnu.org/software/make/manual/make.html#Errors\n"))
		$(info $(shell   echo  -e "\thttp://makefiletutorial.com/\n"))
		$(info $(shell   echo  -e "--GCC flags:\n"))
		$(info $(shell   echo  -e "\thttp://www.artificialworlds.net/blog/2014/07/18/best-gcc-warning-flags-for-compiling-c/\n"))
		$(info $(shell   echo  -e "\thttps://stackoverflow.com/questions/3375697/useful-gcc-flags-for-c\n"))
		$(info $(shell   echo  -e "\t\n"))

