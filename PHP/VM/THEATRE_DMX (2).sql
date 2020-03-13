-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Ven 13 Mars 2020 à 06:34
-- Version du serveur :  10.1.44-MariaDB-0+deb9u1
-- Version de PHP :  7.0.33-0+deb9u6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `THEATRE_DMX`
--

-- --------------------------------------------------------

--
-- Structure de la table `NB_Parametre`
--

CREATE TABLE `NB_Parametre` (
  `ID_Parametre` int(20) NOT NULL,
  `Parametre1` int(255) NOT NULL DEFAULT '0',
  `Parametre2` int(255) NOT NULL DEFAULT '0',
  `Parametre3` int(255) NOT NULL DEFAULT '0',
  `Parametre4` int(255) NOT NULL DEFAULT '0',
  `Parametre5` int(255) NOT NULL DEFAULT '0',
  `Parametre6` int(255) NOT NULL DEFAULT '0',
  `Parametre7` int(255) NOT NULL DEFAULT '0',
  `Parametre8` int(255) NOT NULL DEFAULT '0',
  `Parametre9` int(255) NOT NULL DEFAULT '0',
  `Parametre10` int(255) NOT NULL DEFAULT '0',
  `Parametre11` int(255) NOT NULL DEFAULT '0',
  `Parametre12` int(255) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `NB_Parametre`
--

INSERT INTO `NB_Parametre` (`ID_Parametre`, `Parametre1`, `Parametre2`, `Parametre3`, `Parametre4`, `Parametre5`, `Parametre6`, `Parametre7`, `Parametre8`, `Parametre9`, `Parametre10`, `Parametre11`, `Parametre12`) VALUES
(1, 150, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0),
(2, 150, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Structure de la table `Programme`
--

CREATE TABLE `Programme` (
  `ID_Prog` int(20) NOT NULL,
  `ID_Scene` int(20) NOT NULL,
  `nom` varchar(100) NOT NULL,
  `nbScene` int(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `Scene`
--

CREATE TABLE `Scene` (
  `ID_Scene` int(20) NOT NULL,
  `ID_Sequence` int(20) NOT NULL,
  `nom` varchar(100) NOT NULL,
  `tpsPause` int(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `Sequence`
--

CREATE TABLE `Sequence` (
  `ID_Sequence` int(20) NOT NULL,
  `ID_Parametre` int(20) NOT NULL DEFAULT '1',
  `Duree` int(11) NOT NULL,
  `NbSeqAdresseEq` int(50) DEFAULT NULL,
  `NB_Parametre` int(11) DEFAULT NULL,
  `Parametre1` int(11) NOT NULL,
  `Parametre2` int(11) NOT NULL,
  `Parametre3` int(11) NOT NULL,
  `Parametre4` int(11) NOT NULL,
  `Parametre5` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `Sequence`
--

INSERT INTO `Sequence` (`ID_Sequence`, `ID_Parametre`, `Duree`, `NbSeqAdresseEq`, `NB_Parametre`, `Parametre1`, `Parametre2`, `Parametre3`, `Parametre4`, `Parametre5`) VALUES
(1, 1, 0, NULL, 6, 0, 0, 0, 0, 0),
(2, 1, 15, NULL, 6, 0, 0, 0, 0, 0),
(3, 1, 14, NULL, 6, 157, 61, 189, 121, 198),
(4, 1, 13, NULL, 6, 50, 157, 207, 171, 221),
(5, 1, 0, NULL, 6, 59, 200, 203, 221, 198);

-- --------------------------------------------------------

--
-- Structure de la table `User`
--

CREATE TABLE `User` (
  `ID_User` int(20) NOT NULL,
  `Nom` varchar(50) NOT NULL,
  `Prenom` varchar(50) NOT NULL,
  `username` varchar(50) NOT NULL,
  `Motdepasse` varchar(50) NOT NULL,
  `admin` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `User`
--

INSERT INTO `User` (`ID_User`, `Nom`, `Prenom`, `username`, `Motdepasse`, `admin`) VALUES
(1, 'Lhermitte', 'Nathan', 'nathan', 'n', 1),
(2, 'Henry', 'Robin', 'robin', 'r', 1),
(3, 'Boury', 'Aurelien', 'aurel', 'a', 1),
(5, 'test', 'test', 'test', 'test', 0);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `NB_Parametre`
--
ALTER TABLE `NB_Parametre`
  ADD PRIMARY KEY (`ID_Parametre`);

--
-- Index pour la table `Programme`
--
ALTER TABLE `Programme`
  ADD PRIMARY KEY (`ID_Prog`),
  ADD KEY `ID_Scene` (`ID_Scene`);

--
-- Index pour la table `Scene`
--
ALTER TABLE `Scene`
  ADD PRIMARY KEY (`ID_Scene`),
  ADD KEY `ID_Sequence` (`ID_Sequence`);

--
-- Index pour la table `Sequence`
--
ALTER TABLE `Sequence`
  ADD PRIMARY KEY (`ID_Sequence`),
  ADD KEY `ID_Parametre` (`ID_Parametre`);

--
-- Index pour la table `User`
--
ALTER TABLE `User`
  ADD PRIMARY KEY (`ID_User`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `NB_Parametre`
--
ALTER TABLE `NB_Parametre`
  MODIFY `ID_Parametre` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT pour la table `Programme`
--
ALTER TABLE `Programme`
  MODIFY `ID_Prog` int(20) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `Scene`
--
ALTER TABLE `Scene`
  MODIFY `ID_Scene` int(20) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `Sequence`
--
ALTER TABLE `Sequence`
  MODIFY `ID_Sequence` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `User`
--
ALTER TABLE `User`
  MODIFY `ID_User` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `Programme`
--
ALTER TABLE `Programme`
  ADD CONSTRAINT `Programme_ibfk_1` FOREIGN KEY (`ID_Scene`) REFERENCES `Scene` (`ID_Scene`);

--
-- Contraintes pour la table `Scene`
--
ALTER TABLE `Scene`
  ADD CONSTRAINT `Scene_ibfk_1` FOREIGN KEY (`ID_Sequence`) REFERENCES `Sequence` (`ID_Sequence`);

--
-- Contraintes pour la table `Sequence`
--
ALTER TABLE `Sequence`
  ADD CONSTRAINT `Sequence_ibfk_1` FOREIGN KEY (`ID_Parametre`) REFERENCES `NB_Parametre` (`ID_Parametre`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
