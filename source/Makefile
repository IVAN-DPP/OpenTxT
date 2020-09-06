INCDIR=include
SRCDIR=src
OBJDIR=obj
CXX=g++

pruebas:	pruebas.o TxText.o TxTCtext.o TxTypes.o TxTPronouns.o TxTables.o
		$(CXX) -o pruebas $(OBJDIR)/pruebas.o $(OBJDIR)/TxText.o $(OBJDIR)/TxTCtext.o $(OBJDIR)/TxTypes.o $(OBJDIR)/TxTPronouns.o $(OBJDIR)/TxTables.o

pruebas.o:	pruebas.C
		$(CXX) -c -o $(OBJDIR)/pruebas.o pruebas.C

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
clean:
	rm -rd $(OBJDIR)/* pruebas
