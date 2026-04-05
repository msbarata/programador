-- MariaDB dump 10.19  Distrib 10.4.32-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: servico_casa
-- ------------------------------------------------------
-- Server version	10.4.32-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `agendamento`
--

DROP TABLE IF EXISTS `agendamento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `agendamento` (
  `numero_entrada` int(11) NOT NULL AUTO_INCREMENT,
  `NISS_utilizador` int(11) DEFAULT NULL,
  `ID_empresa` int(11) DEFAULT NULL,
  PRIMARY KEY (`numero_entrada`),
  KEY `fk_utilizador` (`NISS_utilizador`),
  KEY `fk_empresa` (`ID_empresa`),
  CONSTRAINT `fk_empresa` FOREIGN KEY (`ID_empresa`) REFERENCES `dadosempresa` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_utilizador` FOREIGN KEY (`NISS_utilizador`) REFERENCES `dadosutilizadores` (`NISS`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `agendamento`
--

LOCK TABLES `agendamento` WRITE;
/*!40000 ALTER TABLE `agendamento` DISABLE KEYS */;
INSERT INTO `agendamento` VALUES (1,1001,1),(2,1002,2),(3,1003,3),(4,1004,4),(5,1005,5);
/*!40000 ALTER TABLE `agendamento` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dadosempresa`
--

DROP TABLE IF EXISTS `dadosempresa`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dadosempresa` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(100) NOT NULL,
  `Tiposservico` varchar(100) DEFAULT NULL,
  `Localidade` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dadosempresa`
--

LOCK TABLES `dadosempresa` WRITE;
/*!40000 ALTER TABLE `dadosempresa` DISABLE KEYS */;
INSERT INTO `dadosempresa` VALUES (1,'LimpaTudo','Limpeza','Lisboa'),(2,'CanosFix','Limpeza','Porto'),(3,'LuzCerta','Eletricidade','Porto'),(4,'VerdeVivo','Jardinagem','Coimbra'),(5,'PintaBem','Pintura','Lisboa');
/*!40000 ALTER TABLE `dadosempresa` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dadosutilizadores`
--

DROP TABLE IF EXISTS `dadosutilizadores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dadosutilizadores` (
  `NISS` int(11) NOT NULL,
  `Nome` varchar(100) NOT NULL,
  `Morada` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`NISS`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dadosutilizadores`
--

LOCK TABLES `dadosutilizadores` WRITE;
/*!40000 ALTER TABLE `dadosutilizadores` DISABLE KEYS */;
INSERT INTO `dadosutilizadores` VALUES (1001,'Ana Silva','Rua A, Lisboa'),(1002,'Bruno Costa','Rua B, Porto'),(1003,'Carla Mendes','Rua C, Braga'),(1004,'Daniel Rocha','Rua D, Coimbra'),(1005,'Eva Santos','Rua E, Faro');
/*!40000 ALTER TABLE `dadosutilizadores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tiposservicos`
--

DROP TABLE IF EXISTS `tiposservicos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tiposservicos` (
  `Nome` varchar(100) NOT NULL,
  PRIMARY KEY (`Nome`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tiposservicos`
--

LOCK TABLES `tiposservicos` WRITE;
/*!40000 ALTER TABLE `tiposservicos` DISABLE KEYS */;
INSERT INTO `tiposservicos` VALUES ('Canalização'),('Eletricidade'),('Jardinagem'),('Limpeza'),('Pintura');
/*!40000 ALTER TABLE `tiposservicos` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-03-25 20:35:01
