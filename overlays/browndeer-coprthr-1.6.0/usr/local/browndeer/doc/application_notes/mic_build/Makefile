
NAME=app_note_mic_build

all: $(NAME).html $(NAME).pdf $(NAME).txt

$(NAME).html: $(NAME).md
	pandoc -o $(NAME).html -s --toc -N \
	--template=template-app-note.html \
	$(NAME).md

$(NAME).pdf: $(NAME).md
	pandoc -o $(NAME).pdf -s -N \
	--template=template-app-note.tex \
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

