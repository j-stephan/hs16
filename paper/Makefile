BIBLIOGRAPHY_SOURCE = bibliography.bib

PAPER_SOURCE = main.tex
PAPER_AUX = main.aux
PAPER_TARGET = main.pdf

$(PAPER_TARGET): $(PAPER_SOURCE) $(BIBLIOGRAPHY_SOURCE)
	@echo ">>> PRERUN PDFLATEX <<<"
	@echo ""
	pdflatex -shell-escape -interaction=nonstopmode $(PAPER_SOURCE) 1> /dev/null 2> /dev/null
	@echo ""
	@echo ">>> BIBTEX <<<"
	@echo ""
	bibtex $(PAPER_AUX)
	@echo ""
	@echo ">>> PRERUN PDFLATEX <<<"
	@echo ""
	pdflatex -shell-escape -interaction=nonstopmode $(PAPER_SOURCE) 1> /dev/null 2> /dev/null
	@echo ""
	@echo ">>> PDFLATEX <<<"
	@echo ""
	pdflatex -shell-escape -interaction=nonstopmode $(PAPER_SOURCE)

all: $(PAPER_TARGET)

.PHONY: clean
clean:
	@rm -f *.out *.aux *.log *.pdf *.bbl *.blg *.dvi *.toc *.lof *.lot
