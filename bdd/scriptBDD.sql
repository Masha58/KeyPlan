CREATE DATABASE IF NOT EXISTS bdd

CREATE TABLE IF NOT EXISTS PROJETS (
id_projet INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
statut INT,
nom_projet VARCHAR(100),
type_projet VARCHAR(100),
nom_client VARCHAR(100),
description VARCHAR(300)
);

CREATE TABLE IF NOT EXISTS JOBS(
id_projet INTEGER NOT NULL PRIMARY KEY,
nom_job VARCHAR(200),
FOREIGN KEY(id_projet) REFERENCES PROJET(id_projet)
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

INSERT INTO PROJET (statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(0, "Hydrogène", "Application", "Service Hydrogène", "Simulation de centrale Hydrogène", "Première version déployable amorcée");
INSERT INTO PROJET (statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(1, "Hydrogène2", "Application", "Service Hydrogène", "Simulation de centrale Hydrogène", "Première version déployable amorcée");
INSERT INTO PROJET (statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(2, "Hydrogène3", "Application", "Service Hydrogène", "Simulation de centrale Hydrogène", "Première version déployable amorcée");

INSERT INTO PROJET(statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(1, "InChart", "Application", "Service BIM", "Logiciel comme PowerBI", "Première version déployable amorcée");
INSERT INTO PROJET(statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(0, "Passage Git", "Task", "Justine", "Mettre les derniers logiciels sur Git", "");
INSERT INTO PROJET(statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(1, "JavaSript", "Task", "Justine", "Finir cours JS", "");


INSERT INTO PROJET(statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(0, "Test", "Plugin", "Test", "Test", "Test");
INSERT INTO PROJET(statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(1, "Test", "Plugin", "Test", "Test", "Test");
INSERT INTO PROJET(statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(2, "Test", "Plugin", "Test", "Test", "Test");
INSERT INTO PROJET(statut, nom_projet, type_projet, nom_client, description, commentaire) VALUES(2, "Test", "Application", "Test", "Test", "Test");