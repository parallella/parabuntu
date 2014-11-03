
NAME=coprthr_primer-1.6.0

MDFILES= coprthr_primer_front.md \
	coprthr_primer_overview.md \
	coprthr_primer_tests.md \
	coprthr_primer_libocl.md\
	coprthr_primer_hello_stdcl.md \
	coprthr_primer_stdcl_examples.md \
	coprthr_primer_tools.md \
	coprthr_primer_clrpc.md 

all: $(NAME).html $(NAME).pdf $(NAME).txt $(NAME).epub

$(NAME).html: $(MDFILES)
	pandoc -o $(NAME).html -s --toc -N \
	--template=template-book.html \
	$(MDFILES)

$(NAME).pdf: $(MDFILES)
	pandoc -o $(NAME).pdf -s --toc -N -V graphics \
	--template=template-book.tex \
	$(MDFILES)

$(NAME).txt: $(MDFILES)
	pandoc -o $(NAME).txt -s --toc -N -V graphics \
	$(MDFILES)

$(NAME).epub: $(MDFILES)
	pandoc -o $(NAME).epub --toc -N -V graphics \
	$(MDFILES)

clean:
	rm -f $(NAME).tex $(NAME).aux $(NAME).log $(NAME).out

distclean: clean
	rm -f $(NAME).html $(NAME).pdf $(NAME).txt $(NAME).epub

install: $(NAME).html $(NAME).pdf $(NAME).txt $(NAME).epub
	cp -f $(NAME).html $(NAME).pdf $(NAME).txt $(NAME).epub ../
	cp -f bdt_logo.jpg COPRTHR_SDK_software_stack.png ../

