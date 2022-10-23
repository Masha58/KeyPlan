CREATE DATABASE IF NOT EXISTS bdd

CREATE TABLE IF NOT EXISTS PROJET (
id_projet INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
statut INT,
nom_projet VARCHAR(100),
type_projet VARCHAR(100),
nom_client VARCHAR(100),
description VARCHAR(300),
commentaire VARCHAR(300)
);

CREATE TABLE IF NOT EXISTS PLUGIN(
id_projet INTEGER NOT NULL PRIMARY KEY,
nom_logiciel VARCHAR(100),
FOREIGN KEY(id_projet) REFERENCES PROJET(id_projet)
);

CREATE TABLE IF NOT EXISTS TACHE(
id_projet INTEGER NOT NULL PRIMARY KEY,
type_tache VARCHAR(200),
FOREIGN KEY(id_projet) REFERENCES PROJET(id_projet)
);

CREATE TABLE IF NOT EXISTS APPLICATION(
id_projet INTEGER NOT NULL PRIMARY KEY,
type_logiciel VARCHAR(200),
plateforme VARCHAR(100),
FOREIGN KEY(id_projet) REFERENCES PROJET(id_projet)
);

CREATE TABLE IF NOT EXISTS USER(
id_user INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
nom_user VARCHAR(50),
prenom_user VARCHAR(50),
mail_user VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS PROJET_USER(
id_user INTEGER NOT NULL,
id_projet INTEGER NOT NULL,
PRIMARY KEY(id_user, id_projet)
);



INSERT INTO USER (nom_user, prenom_user, mail_user) VALUES ("Seguin", "Justine", "justineseguin3@gmail.com");
INSERT INTO USER (nom_user, prenom_user, mail_user) VALUES ("Kalae","Masha", "masha.kalae@gmail.com");