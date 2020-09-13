// Question 1
for (i = 2; i < 100000; i *= 2) {
    j += i;
}

// Question 2
for (p = premier(); !est_dernier(p); p = suivant(p)) {
    traiter(p);
}

// Question 3
for (; attendre(););

// Question 4
for (i = 0, j = 0; j < k; j += i++);