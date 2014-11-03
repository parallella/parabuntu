
NAME=coprthr_release_notes-1.6.0

all: $(NAME).html $(NAME).pdf $(NAME).txt

$(NAME).html: $(NAME).md
	pandoc -o $(NAME).html -s --toc -N \
	--template=template-release-notes.html \
	$(NAME).md

$(NAME).pdf: $(NAME).md
	pandoc -o $(NAME).pdf -s -N \
	--template=template-release-notes.tex \
	$(NAME).md

$(NAME).txt: $(NAME).md
	pandoc -o $(NAME).txt -s -N \
	$(NAME).md

clean:
	rm -f $(NAME).tex $(NAME).aux $(NAME).log $(NAME).out

distclean: clean 
	rm -f $(NAME).html $(NAME).pdf $(NAME).txt

install: $(NAME).html $(NAME).pdf $(NAME).txt
	cp -f $(NAME).html $(NAME).pdf $(NAME).txt ../../
