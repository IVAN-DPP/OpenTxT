INCDIR=include
SRCDIR=src
OBJDIR=obj
CXX=g++

pruebas:	pruebas.o TxText.o TxTCtext.o TxTypes.o TxTPronouns.o TxTPrepositions.o TxTConjunctions.o TxTables.o
		$(CXX) -o pruebas $(OBJDIR)/pruebas.o $(OBJDIR)/TxText.o $(OBJDIR)/TxTCtext.o $(OBJDIR)/TxTypes.o $(OBJDIR)/TxTPronouns.o $(OBJDIR)/TxTConjunctions.o $(OBJDIR)/TxTPrepositions.o $(OBJDIR)/TxTables.o 

pruebas.o:	MultipleFiles.C
		$(CXX) -c -o $(OBJDIR)/pruebas.o MultipleFiles.C

TxText.o:	$(INCDIR)/TxText.h $(SRCDIR)/TxText.cc
		$(CXX) -c -o $(OBJDIR)/TxText.o $(SRCDIR)/TxText.cc

TxTCtext.o:	$(INCDIR)/TxTCtext.h $(SRCDIR)/TxTCtext.cc
		$(CXX) -c -o $(OBJDIR)/TxTCtext.o $(SRCDIR)/TxTCtext.cc

TxTypes.o:	$(INCDIR)/TxTypes.h $(SRCDIR)/TxTypes.cc
		$(CXX) -c -o $(OBJDIR)/TxTypes.o $(SRCDIR)/TxTypes.cc

TxTables.o:	$(INCDIR)/TxTables.h $(SRCDIR)/TxTables.cc
		$(CXX) -c -o $(OBJDIR)/TxTables.o $(SRCDIR)/TxTables.cc

TxTPronouns.o:	$(INCDIR)/TxTPronouns.h $(SRCDIR)/TxTPronouns.cc
		$(CXX) -c -o $(OBJDIR)/TxTPronouns.o $(SRCDIR)/TxTPronouns.cc

TxTPrepositions.o:	$(INCDIR)/TxTPrepositions.h $(SRCDIR)/TxTPrepositions.cc
			$(CXX) -c -o $(OBJDIR)/TxTPrepositions.o $(SRCDIR)/TxTPrepositions.cc

TxTConjunctions.o:	$(INCDIR)/TxTConjunctions.h $(SRCDIR)/TxTConjunctions.cc
			$(CXX) -c -o $(OBJDIR)/TxTConjunctions.o $(SRCDIR)/TxTConjunctions.cc
clean:
	rm -rd $(OBJDIR)/* pruebas
