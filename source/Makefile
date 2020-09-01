INCDIR=include
SRCDIR=src
OBJDIR=obj
CXX=g++

pruebas:	pruebas.o TxText.o TxTCtext.o
		$(CXX) -o pruebas $(OBJDIR)/pruebas.o $(OBJDIR)/TxText.o $(OBJDIR)/TxTCtext.o

pruebas.o:	pruebas.C
		$(CXX) -c -o $(OBJDIR)/pruebas.o pruebas.C

TxText.o:	$(INCDIR)/TxText.h $(SRCDIR)/TxText.cc
		$(CXX) -c -o $(OBJDIR)/TxText.o $(SRCDIR)/TxText.cc

TxTCtext.o:	$(INCDIR)/TxTCtext.h $(SRCDIR)/TxTCtext.cc
		$(CXX) -c -o $(OBJDIR)/TxTCtext.o $(SRCDIR)/TxTCtext.cc

clean:
	rm -rd $(OBJDIR)/* pruebas
