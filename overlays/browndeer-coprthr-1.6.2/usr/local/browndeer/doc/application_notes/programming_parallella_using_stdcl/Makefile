
NAME=app_note_programming_parallella_using_stdcl

all: $(NAME).html $(NAME).pdf $(NAME).txt

$(NAME).html: $(NAME).md
	pandoc -o $(NAME).html -s --toc -N \
	-f markdown+footnotes \
	--template=template-app-note.html \
	$(NAME).md

$(NAME).pdf: $(NAME).md
	pandoc -o $(NAME).pdf -s --toc -N \
	-f markdown+footnotes \
	--template=template-app-note.tex \
	$(NAME).md

$(NAME).txt: $(NAME).md 
	pandoc -o $(NAME).txt -s --toc -N \
	-f markdown+footnotes \
	$(NAME).md

clean:
	rm -f $(NAME).tex $(NAME).aux $(NAME).log $(NAME).out

distclean: clean 
	rm -f $(NAME).html $(NAME).pdf $(NAME).txt

install: $(NAME).html $(NAME).pdf $(NAME).txt
	cp -f $(NAME).html $(NAME).pdf $(NAME).txt ../../


