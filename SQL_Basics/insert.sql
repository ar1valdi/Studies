INSERT INTO Czlonkowie_Rodziny
	([Imie], [Rola_W_Rodzinie])
VALUES
	('Grzegorz', 'Dziecko'),
	('Bogdan', 'Dziecko'),
	('Alicja', 'Dziecko'),
	('Dagmara', 'Matka'),
	('Wojciech', 'Ojciec');

INSERT INTO Zakup
	([Nazwa], [Kategoria])
VALUES
	('Pomidor', 'Jedzenie'),
	('Chleb', 'Jedzenie'),
	('Mas³o', 'Jedzenie'),
	('Ser', 'Jedzenie'),
	('Szynka', 'Jedzenie'),
	('Myd³o', 'Kosmetyki'),
	('Jedzenie dla kota', 'Zwierzêta'),
	('Myszka', 'Elektronika'),
	('Kabel USB', 'Elektronika'),
	('Bilety do kina', 'Rozrywka'),
	('Mechanik', 'Us³ugi'),
	('Karnet na si³owniê', 'Us³ugi'),
	('Piwo (poza domem)', 'Alkohol poza domem'),
	('Wpisowe na pubquiz', 'Rozrywka'),
	('Spaghetti Carbonara', 'Jedzenie poza domem'),
	('Lasagne', 'Jedzenie poza domem'),
	('Makaron z kurczakiem', 'Jedzenie poza domem'),
	('Drwal', 'Jedzenie poza domem'),
	('Zapiekanka', 'Jedzenie poza domem'),
	('Czekolada', 'S³odzycze'),
	('Sok pomarañczowy', 'Napoje'),
	('Pierœ z kurczaka', 'Jedzenie'),
	('Ziemniaki', 'Jedzenie'),
	('Od¿ywka do w³osów', 'Kosmetyki'),
	('Szampon', 'Kosmetyki'),
	('Wino (poza domem)', 'Alkohol poza domem'),
	('MacBook M2', 'Elektronika'),
	('Ortodonta', 'Zdrowie'),
	('Stomatolog', 'Zdrowie'),
	('Czesne', 'Nauka'),
	('Popcorn', 'Jedzenie');

INSERT INTO Wydatki
	([ID], [Koszt], [Nazwa])
VALUES
	(1, 101.4, 'Zakupy spo¿ywcze'),
	(2, 7049, 'Laptop na studia'),
	(3, 76, 'Wyjœcie do kina'),
	(4, 23, 'Zakupy spo¿ywcze'),
	(5, 52, 'Zakupy w drogerii'),
	(6, 15, 'Obiad w szkole'),
	(7, 160, 'Wyjœcie do kina'),
	(8, 119, 'Karnet na si³owniê'),
	(9, 100, 'Wizyta u ortodonty'),			-- zaplanowany
	(10, 71, 'Wyjœcie do pubu'),
	(11, 97, 'Zakupy spo¿ywcze'),
	(12, 2000, 'Op³acenie czesnych'),		-- zaplanowany
	(13, 18, 'Obiad na uczelni'),
	(14, 2000, 'Op³acenie czesnych'),
	(15, 97, 'Zakupy spo¿ywcze'),
	(16, 13, 'Obiad na uczelni'),
	(17, 120, 'Wizyta u stomatologa'),		-- zaplanowany
	(18, 16, 'Obiad w szkole'),
	(19, 42, 'Wyjœcie do pubu'),
	(20, 173, 'Randka'),
	(21, 51, 'Zakupy spo¿ywcze'),
	(22, 400, 'Przegl¹d auta'),
	(23, 24, 'Lunch w MCDonalds'),
	(24, 40, 'Zakupy w drogerii'),
	(25, 166, 'Zakupy spo¿ywcze'),
	(26, 400, 'Przegl¹d auta'),				-- zaplanowany
	(27, 120, 'Wizyta u stomatologa'),		-- zaplanowany
	(28, 120, 'Wizyta u stomatologa'),		-- zaplanowany
	(29, 120, 'Wizyta u stomatologa'),		-- zaplanowany
	(30, 120, 'Wizyta u stomatologa'),		-- zaplanowany
	(31, 2000, 'Op³acenie czesnych'),		-- zaplanowany
	(32, 357, 'Karnety na si³owniê');		-- zaplanowany

INSERT INTO Pozycje_Wydatku
	([ID_Wydatku], [Nazwa_Zakupu],[Ilosc], [Cena], [Dla_Kogo])
VALUES
	-- 1, zakupy spo¿ywcze
	(1, 'Pomidor', 3, 3, 'GBADW'),
	(1, 'Ser', 1, 14, 'GBADW'),
	(1, 'Szynka', 1, 12, 'GBADW'),
	(1, 'Sok pomarañczowy', 1, 5, 'GBADW'),
	(1, 'Ziemniaki', 9, 0.6, 'GBADW'),
	(1, 'Pierœ z kurczaka', 4, 10, 'GBADW'),
	(1, 'Jedzenie dla kota', 2, 8, 'GBADW'),
	
	-- 2, laptop na studia
	(2, 'MacBook M2', 1, 7000, 'Gbadw'),
	(2, 'Myszka', 1, 19, 'Gbadw'),
	(2, 'Kabel USB', 1, 30, 'Gbadw'),
	
	-- 3, wyjœcie do kina
	(3, 'Bilety do kina', 2, 23, 'gBAdw'),
	(3, 'Popcorn', 2, 15, 'gBAdw'),
	
	-- 4, zakupy spo¿ywcze
	(4, 'Czekolada', 1, 7, 'gbAdw'),
	(4, 'Mas³o', 1, 6, 'GBADW'),
	(4, 'Sok pomarañczowy', 2, 5, 'GBADW'),
	
	-- 5, zakupy w drogerii
	(5, 'Myd³o', 2, 14, 'gBaDw'),
	(5, 'Szampon', 1, 14, 'gbadW'),
	(5, 'Od¿ywka do w³osów', 1, 16, 'gbaDw'),
	
	-- 6, obiad w szkole
	(6, 'Makaron z kurczakiem', 1, 15, 'gBadw'),
	
	-- 7, wyjœcie do kina
	(7, 'Bilety do kina', 5, 23, 'GBADW'),
	(7, 'Popcorn', 3, 15, 'GBAdw'),
	
	-- 8, karnet na si³ownie
	(8, 'Karnet na si³owniê', 1, 119, 'gbAdw'),
	
	-- 9, wizyta u ortodonty
	(9, 'Ortodonta', 1, 100, 'gBadw'),
	
	-- 10, wyjœcie do pubu
	(10, 'Piwo (poza domem)', 4, 14, 'Gbadw'),
	(10, 'Wpisowe na pubquiz', 1, 15, 'Gbadw'),
	
	-- 11, zakupy spo¿ywcze
	(11, 'Szynka', 1, 12, 'GBADW'),
	(11, 'Pomidor', 5, 3, 'GBADW'),
	(11, 'Sok pomarañczowy', 2, 5, 'GBADW'),
	(11, 'Mas³o', 2, 6, 'GBADW'),
	(11, 'Pierœ z kurczaka', 6, 8, 'GBADW'),
	
	-- 12, op³acenie czesnych
	(12, 'Czesne', 1, 2000, 'Gbadw'),
	
	-- 13, obiad na uczelni
	(13, 'Zapiekanka', 1, 13, 'gbAdw'),
	(13, 'Sok pomarañczowy', 1, 5, 'gbAdw'),
	
	--14, Op³acenie czesnych
	(14, 'Czesne', 1, 2000, 'gbAdw'),
	
	--15, Zakupy spo¿ywcze
	(15, 'Pomidor', 4, 3, 'GBADW'),
	(15, 'Chleb', 2, 4, 'GBADW'),
	(15, 'Mas³o', 3, 7, 'GBADW'),
	(15, 'Ser', 2, 15, 'GBADW'),
	(15, 'Szynka', 2, 13, 'GBADW'),
	
	--16, Obiad na uczelni
	(16, 'Lasagne', 1, 13, 'Gbadw'),
	
	--17, Wizyta u stomatologa
	(17, 'Stomatolog', 1, 120, 'gbaDw'),
	
	--18, Obiad w szkole
	(18, 'Zapiekanka', 1, 16, 'gBadw'),
	
	--19, Wyjœcie do pubu
	(19, 'Piwo (poza domem)', 3, 14, 'gbAdw'),
	
	--20, Randka
	(20, 'Spaghetti Carbonara', 1, 43, 'gbaDw'),
	(20, 'Lasagne', 1, 46, 'gbadW'),
	(20, 'Wino (poza domem)', 4, 21, 'gbaDW'),
	
	--21, Zakupy spo¿ywcze
	(21, 'Jedzenie dla kota', 2, 14, 'GBADW'),
	(21, 'Sok pomarañczowy', 1, 5, 'GBADW'),
	(21, 'Chleb', 3, 6, 'GBADW'),

	--22, Przegl¹d auta
	(22, 'Mechanik', 1, 400, 'gbaDW'),

	--23, Lunch w MCDonalds
	(23, 'Drwal', 1, 24, 'gBadw'),

	--24, Zakupy w drogerii
	(24, 'Myd³o', 1, 16, 'gbAdw'),
	(24, 'Od¿ywka do w³osów', 1, 24, 'gbAdw'),

	--25, Zakupy spo¿ywcze
	(25, 'Pomidor', 3, 3, 'GBADW'),
	(25, 'Chleb', 2, 14, 'GBADW'),
	(25, 'Mas³o', 1, 13, 'GBADW'),	
	(25, 'Ser', 1, 14, 'GBADW'),
	(25, 'Szynka', 2, 12, 'GBADW'),
	(25, 'Sok pomarañczowy', 1, 5, 'GBADW'),
	(25, 'Ziemniaki', 10, 0.5, 'GBADW'),
	(25, 'Pierœ z kurczaka', 5, 10, 'GBADW'),
	(25, 'Jedzenie dla kota', 2, 9, 'GBADW'),

	--26, Przegl¹d auta	
	(26, 'Mechanik', 1, 400, 'GBADW'),

	--27, Wizyta u stomatologa		
	(27, 'Stomatolog', 1, 120, 'gbadW'),

	--28, Wizyta u stomatologa		
	(28, 'Stomatolog', 1, 120, 'gbAdw'),
	
	--29, Wizyta u stomatologa		
	(29, 'Stomatolog', 1, 120, 'gBadw'),

	--30, Wizyta u stomatologa		
	(30, 'Stomatolog', 1, 120, 'Gbadw'),

	--31, Op³acenie czesnych		
	(31, 'Czesne', 1, 2000, 'Gbadw'),

	--32, Karnety na si³owniê		
	(32, 'Karnet na si³owniê', 3, 119, 'GBAdw');

INSERT INTO Sprzedawca
	([Nazwa], [Nr_Podatkowy], [Kraj_Pochodzenia], [Skala_Dzialalnosci])
VALUES
	('Biedronka', '779-10-11-327', 'Portugalia', 'Miêdzynarodowo'),
	('goodlaptops sp. z.o.o', '992-58-29-192', 'Polska', 'Ma³y biznes internetowy'),
	('Helios', '725-14-82-632', 'Polska', 'Narodowo'),
	('Kaufland', '899-23-67-273', 'Niemcy', 'Miêdzynarodowo'),
	('Rossmann', '727-00-19-183', 'Niemcy', 'Miêdzynarodowo'),
	('Pasibrzuch', '929-12-51-423', 'Polska', 'Lokalnie'),
	('Multikino', '521-28-93-057', 'Polska', 'Narodowo'),
	('Zdrofit', '836-16-76-510', 'Polska', 'Narodowo'),
	('Nowy Browar', '957-11-14-345', 'Polska', 'Lokalnie'),
	('Lidl', 'DE145803808', 'Niemcy', 'Miêdzynarodowo'),
	('i-100-gram', '532-76-36-279', 'Polska', 'Lokalnie'),
	('Smacznie i Zdrowo', '934-63-43-536', 'Polska', 'Regionowo'),
	('Mechaniczna Pomarañcza', '834-45-57-235', 'Polska', 'Lokalnie'),
	('Pasta Miasta', '899-65-74-356', 'Polska', 'Regionowo'),
	('Adrian Belczak Us³ugi Samochodowe', '925-42-72-473', 'Polska', 'Lokalnie'),
	('MC Donalds', '521-00-88-110', 'Kalifornia', 'Miêdzynarodowo'),
	('PJATK', '732-85-35-135', 'Polska', 'Miêdzynarodowo');

INSERT INTO Wydatki_Dokonane
	([ID_Wydatku], [Data_Zakupu], [Dokonany_Przez], [Sprzedane_Przez])
VALUES
	(1, '2023-08-14', 'Wojciech', '779-10-11-327'),
	(2, '2023-08-19', 'Wojciech', '992-58-29-192'),
	(3, '2023-08-17', 'Bogdan', '725-14-82-632'),
	(4, '2023-08-20', 'Dagmara', '899-23-67-273'),
	(5, '2023-08-24', 'Alicja', '727-00-19-183'),
	(6, '2023-08-22', 'Bogdan', '929-12-51-423'),
	(7, '2023-08-27', 'Wojciech', '521-28-93-057'),
	(8, '2023-08-25', 'Grzegorz', '836-16-76-510'),
	(10, '2023-09-01', 'Grzegorz', '957-11-14-345'),
	(11, '2023-09-02', 'Alicja', 'DE145803808'),
	(13, '2023-09-04', 'Alicja', '532-76-36-279'),
	(14, '2023-09-09', 'Wojciech', '732-85-35-135'),
	(15, '2023-09-11', 'Dagmara', NULL),
	(16, '2023-09-15', 'Grzegorz', '532-76-36-279'),
	(18, '2023-10-14', 'Bogdan', '934-63-43-536'),
	(19, '2023-09-22', 'Alicja', '834-45-57-235'),
	(20, '2023-09-26', 'Wojciech', '899-65-74-356'),
	(21, '2023-09-29', 'Wojciech', '779-10-11-327'),
	(22, '2023-10-03', 'Dagmara', '925-42-72-473'),
	(23, '2023-10-06', 'Bogdan', '521-00-88-110'),
	(24, '2023-10-09', 'Dagmara', '727-00-19-183'),
	(25, '2023-10-12', 'Grzegorz', '779-10-11-327');

INSERT INTO Wydatki_Zaplanowane
	([ID_Wydatku], [Na_Kiedy])
VALUES
	(9, '2023-12-03'), 
	(12, '2024-01-31'),
	(17, '2023-12-07'),
	(26, '2024-01-13'),
	(27, '2023-12-03'),
	(28, '2023-12-04'),
	(29, '2023-12-02'),
	(30, '2023-12-02'),
	(31, '2023-12-03'),
	(32, '2024-01-01');

INSERT INTO Zarobki
	([ID], [Wysokosc_Zarobku], [Zarobione_Przez], [Kategoria], [Data_Pozyskania])
VALUES
	(1, 7340, 'Wojciech', 'Pensja', '2023-08-10'),
	(2, 7832, 'Dagmara', 'Pensja', '2023-08-10'),
	(3, 320, 'Wojciech', 'Dodatkowe zlecenia', '2023-08-11'),
	(4, 120, 'Dagmara', 'Dodatkowe zlecenia', '2023-08-12'),
	(5, 1020, 'Wojciech', 'Wynajem mieszkania', '2023-08-13'),
	(6, 840, 'Wojciech', 'Wynajem mieszkania', '2023-08-24'),
	(7, 12000, 'Dagmara', 'Dywidenda', '2023-09-01'),
	(8, 2400, 'Wojciech', 'Wynajem mieszkania', '2023-09-01'),
	(9, 7340, 'Wojciech', 'Pensja', '2023-09-10'),
	(10, 7832, 'Dagmara', 'Pensja', '2023-09-10'),
	(11, 360, 'Wojciech', 'Dodatkowe zlecenia', '2023-09-11'),
	(12, 140, 'Dagmara', 'Dodatkowe zlecenia', '2023-09-11'),
	(13, 500, 'Wojciech', 'Premia', '2023-09-11'),
	(14, 200, 'Grzegorz', 'Wk³ad w dom', '2023-09-13'),
	(15, 200, 'Alicja', 'Wk³ad w dom', '2023-09-21'),
	(16, 2400, 'Wojciech', 'Wynajem mieszkania', '2023-10-01'),
	(17, 7340, 'Wojciech', 'Pensja', '2023-10-10'),
	(18, 7832, 'Dagmara', 'Pensja', '2023-10-10'),
	(19, 290, 'Wojciech', 'Dodatkowe zlecenia', '2023-10-11'),
	(20, 190, 'Dagmara', 'Dodatkowe zlecenia', '2023-10-11'),
	(21, 300, 'Dagmara', 'Premia', '2023-09-14');

INSERT INTO Dowody_Zakupu
	([Na_Wydatek], [Typ_Dokumnetu], [Nr_Dokumentu], [Nr_Segregatora])
VALUES
	(2, 'Faktura bez VAT', 'FBV123/2023', 'SB002'),
	(3, 'Paragon', 'PAR0018292', 'SP002'),
	(4, 'Paragon', 'PAR0027123', 'SP002'),
	(6, 'Paragon', 'PAR0019376', 'SP002'),
	(7, 'Paragon', 'PAR8492427', 'SP002'),
	(8, 'Faktura VAT', 'VAT432/08/2023', 'SV002'),
	(10, 'Paragon', 'PAR0082922', 'SP002'),
	(11, 'Paragon', 'PAR9398314', 'SP002'),
	(13, 'Paragon', 'PAR8591841', 'SP002'),
	(14, 'Faktura VAT', 'VAT3023/09/2023', 'SV002'),
	(15, 'Paragon', 'PAR0283821', 'SP002'),
	(16, 'Paragon', 'PAR8492048', 'SP002'),
	(18, 'Paragon', 'PAR8394710', 'SP002'),
	(19, 'Paragon', 'PAR7583922', 'SP002'),
	(20, 'Paragon', 'PAR0028948', 'SP002'),
	(21, 'Paragon', 'PAR5729482', 'SP002'),
	(22, 'Faktura bez VAT', 'FBV5/10/2023', 'SB002'),
	(23, 'Paragon', 'PAR7498729', 'SP002'),
	(24, 'Paragon', 'PAR2580298', 'SP002'),
	(25, 'Paragon', 'PAR8809842', 'SP002');