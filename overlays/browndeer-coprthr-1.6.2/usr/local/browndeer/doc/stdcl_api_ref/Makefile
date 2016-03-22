
NAME=stdcl_api_ref

all: $(NAME).html $(NAME).pdf $(NAME).txt

$(NAME).html: $(NAME).md
	pandoc -o $(NAME).html -s --toc -N \
	--template=template-app-note.html \
	-f markdown+definition_lists \
	$(NAME).md

$(NAME).pdf: $(NAME).md
	pandoc -o $(NAME).pdf -s -N \
	--template=template-app-note.tex \
	-f markdown+definition_lists \
	$(NAME).md

$(NAME).txt: $(NAME).md
	pandoc -o $(NAME).txt -s -N \
	-f markdown+definition_lists \
	$(NAME).md

clean:
	rm -f $(NAME).tex $(NAME).aux $(NAME).log $(NAME).out

distclean: clean 
	rm -f $(NAME).html $(NAME).pdf $(NAME).txt

install: $(NAME).html $(NAME).pdf $(NAME).txt
	cp -f $(NAME).html $(NAME).pdf $(NAME).txt ../

