CREATE TABLE Wydatki
(
	ID					INTEGER		PRIMARY KEY,
	Koszt				MONEY		NOT NULL CHECK (Koszt > 0),
	Nazwa				VARCHAR(25) NOT NULL
);

CREATE TABLE Zakup
(
	Nazwa				VARCHAR(20) PRIMARY KEY,
	Kategoria			VARCHAR(20) NOT NULL
);

CREATE TABLE Pozycje_Wydatku
(
	Cena				MONEY		NOT NULL CHECK (Cena > 0),
	Dla_Kogo			CHAR(5)		NOT NULL CHECK (Dla_Kogo IN (
		'gbadw','Gbadw','gBadw','GBadw','gbAdw','GbAdw','gBAdw','GBAdw','gbaDw','GbaDw','gBaDw','GBaDw','gbADw','GbADw','gBADw','GBADw',
		'gbadW','GbadW','gBadW','GBadW','gbAdW','GbAdW','gBAdW','GBAdW','gbaDW','GbaDW','gBaDW','GBaDW','gbADW','GbADW','gBADW','GBADW'
	)),
	Ilosc				SMALLINT	NOT NULL CHECK (Ilosc > 0),
	ID_Wydatku			INTEGER		REFERENCES Wydatki ON DELETE CASCADE ON UPDATE CASCADE,
	Nazwa_Zakupu		VARCHAR(20) REFERENCES Zakup ON UPDATE CASCADE
	PRIMARY KEY(ID_Wydatku, Nazwa_Zakupu)
);

CREATE TABLE Wydatki_Zaplanowane (
	ID_Wydatku			INTEGER		NOT NULL REFERENCES Wydatki ON DELETE CASCADE ON UPDATE CASCADE,
	Na_Kiedy			DATE		NOT NULL CHECK (Na_Kiedy > '2023-08-01')
);

CREATE TABLE Czlonkowie_Rodziny (
	Imie				VARCHAR(8)		NOT NULL PRIMARY KEY CHECK (Imie IN ('Grzegorz', 'Bogdan', 'Alicja', 'Wojciech', 'Dagmara')),
	Rola_W_Rodzinie		VARCHAR(7)		NOT NULL CHECK (Rola_W_Rodzinie IN ('Ojciec', 'Matka', 'Dziecko'))
);

CREATE TABLE Zarobki (
	ID					INTEGER		NOT NULL PRIMARY KEY,
	Kategoria			VARCHAR(20) NOT NULL,
	Wysokosc_Zarobku	MONEY		NOT NULL CHECK (Wysokosc_Zarobku > 0),
	Data_Pozyskania		DATE		NOT NULL CHECK (Data_Pozyskania > '2000-01-01'),
	Zarobione_Przez		VARCHAR(8)	NOT NULL REFERENCES Czlonkowie_Rodziny ON UPDATE CASCADE
);

CREATE TABLE Sprzedawca (
	Nazwa				VARCHAR(40) NOT NULL,
	Nr_Podatkowy		VARCHAR(32) PRIMARY KEY,
	Skala_Dzialalnosci	VARCHAR(23) NOT NULL CHECK (Skala_Dzialalnosci IN ('Lokalnie','Regionowo','Narodowo','Miêdzynarodowo','Ma³y biznes internetowy')),
	Kraj_Pochodzenia	VARCHAR(20) NOT NULL
);

CREATE TABLE Wydatki_Dokonane (
	ID_Wydatku			INTEGER		NOT NULL REFERENCES Wydatki ON DELETE CASCADE ON UPDATE CASCADE,
	Data_Zakupu			DATE		NOT NULL CHECK (Data_Zakupu > '2000-01-01'),
	Dokonany_Przez		VARCHAR(8)	NOT NULL REFERENCES Czlonkowie_Rodziny ON UPDATE CASCADE,
	Sprzedane_Przez		VARCHAR(32) REFERENCES Sprzedawca DEFAULT NULL,
	PRIMARY KEY(ID_Wydatku)
);

CREATE TABLE Dowody_Zakupu (
	Typ_Dokumnetu		VARCHAR(16) NOT NULL,
	Nr_Segregatora		VARCHAR(10)	NOT NULL,
	Nr_Dokumentu		VARCHAR(32) NOT NULL PRIMARY KEY,
	Na_Wydatek			INTEGER NOT NULL REFERENCES Wydatki_Dokonane ON UPDATE CASCADE
);