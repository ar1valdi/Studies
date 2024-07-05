-- update przyklad 1
SELECT *
FROM Pozycje_Wydatku
WHERE Nazwa_Zakupu = 'Pomidor';

UPDATE Zakup
SET Nazwa = 'Cebula'
WHERE Nazwa = 'Pomidor';

SELECT *
FROM Pozycje_Wydatku
WHERE Nazwa_Zakupu = 'Pomidor';

SELECT *
FROM Pozycje_Wydatku
WHERE Nazwa_Zakupu = 'Cebula';

-- update przyklad 2

SELECT *
FROM Wydatki_Dokonane
WHERE ID_Wydatku = 1;

UPDATE Wydatki
SET ID = 100
WHERE ID = 1;

SELECT *
FROM Wydatki_Dokonane
WHERE ID_Wydatku = 1;

SELECT *
FROM Wydatki_Dokonane
WHERE ID_Wydatku = 100;

-- delete przyklad 1

SELECT *
FROM Pozycje_Wydatku
WHERE Pozycje_Wydatku.ID_Wydatku = 100

DELETE FROM Wydatki
WHERE Wydatki.ID = 100

SELECT *
FROM Pozycje_Wydatku
WHERE Pozycje_Wydatku.ID_Wydatku = 100
