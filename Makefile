CFLAGS = libs/draw.c -I libs
BUILDDIR = build

# Note: Oui ce makefile est nul, j'ai la flemme ;)

# Misc
.PHONY: all
all: serie1 serie2 serie5 serie6

.PHONY: clean
clean:
	rm $(BUILDDIR)/serie1/*
	rm $(BUILDDIR)/serie2/*
	rm $(BUILDDIR)/serie5/*
	rm $(BUILDDIR)/serie6/*

# Séries 1
SERIES1_EXEC = $(BUILDDIR)/serie1/exercice1
SERIES1_EXEC += $(BUILDDIR)/serie1/exercice2
SERIES1_EXEC += $(BUILDDIR)/serie1/exercice3
SERIES1_EXEC += $(BUILDDIR)/serie1/exercice4
SERIES1_EXEC += $(BUILDDIR)/serie1/exercice5
SERIES1_EXEC += $(BUILDDIR)/serie1/exercice6

.PHONY: serie1
serie1: $(SERIES1_EXEC)

$(BUILDDIR)/serie1/exercice1: serie1/exercice1.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie1/exercice2: serie1/exercice2.c
	gcc $^ -o $@ $(CFLAGS) -lm

$(BUILDDIR)/serie1/exercice3: serie1/exercice3.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie1/exercice4: serie1/exercice4.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie1/exercice5: serie1/exercice5.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie1/exercice6: serie1/exercice6.c
	gcc $^ -o $@ $(CFLAGS) -lm


# Séries 2
SERIES2_EXEC = $(BUILDDIR)/serie2/exercice1
SERIES2_EXEC += $(BUILDDIR)/serie2/exercice2
SERIES2_EXEC += $(BUILDDIR)/serie2/exercice3
SERIES2_EXEC += $(BUILDDIR)/serie2/exercice4

.PHONY: serie2
serie2: $(SERIES2_EXEC)

$(BUILDDIR)/serie2/exercice1: serie2/exercice1.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie2/exercice2: serie2/exercice2.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie2/exercice3: serie2/exercice3.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie2/exercice4: serie2/exercice4.c
	gcc $^ -o $@ $(CFLAGS)


# Pas de code dans la série 3


# Séries 5
SERIES5_EXEC = $(BUILDDIR)/serie5/exercice1
SERIES5_EXEC += $(BUILDDIR)/serie5/exercice2
SERIES5_EXEC += $(BUILDDIR)/serie5/exercice3
SERIES5_EXEC += $(BUILDDIR)/serie5/exercice4
SERIES5_EXEC += $(BUILDDIR)/serie5/exercice5
SERIES5_EXEC += $(BUILDDIR)/serie5/exercice6

.PHONY: serie5
serie5: $(SERIES5_EXEC)

$(BUILDDIR)/serie5/exercice1: serie5/exercice1.c
	gcc $^ -o $@ $(CFLAGS) -lm

$(BUILDDIR)/serie5/exercice2: serie5/exercice2.c
	gcc $^ -o $@ $(CFLAGS) -lm

$(BUILDDIR)/serie5/exercice3: serie5/exercice3.c
	gcc $^ -o $@ $(CFLAGS) -lm

$(BUILDDIR)/serie5/exercice4: serie5/exercice4.c
	gcc $^ -o $@ $(CFLAGS) -lm

$(BUILDDIR)/serie5/exercice5: serie5/exercice5.c
	gcc $^ -o $@ $(CFLAGS) -lm

$(BUILDDIR)/serie5/exercice6: serie5/exercice6.c
	gcc $^ -o $@ $(CFLAGS) -lm

# Séries 6
SERIES6_EXEC = $(BUILDDIR)/serie6/exercice1
SERIES6_EXEC += $(BUILDDIR)/serie6/exercice2

.PHONY: serie6
serie6: $(SERIES6_EXEC)

$(BUILDDIR)/serie6/exercice1: serie6/exercice1.c
	gcc $^ -o $@ $(CFLAGS)

$(BUILDDIR)/serie6/exercice2: serie6/exercice2.c
	gcc $^ -o $@ $(CFLAGS)

