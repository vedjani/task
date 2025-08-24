-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 19, 2025 at 12:08 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `school_db`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `GetCourseDetails` (IN `p_course_id` INT)   BEGIN
    SELECT course_id, course_name, course_duration
    FROM courses
    WHERE course_id = p_course_id;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowAllCourses` ()   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(100);
    DECLARE v_duration VARCHAR(50);

   
    DECLARE course_cursor CURSOR FOR
        SELECT course_id, course_name, course_duration FROM courses;

   
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

   
    OPEN course_cursor;

    course_loop: LOOP
        FETCH course_cursor INTO v_id, v_name, v_duration;

        IF done THEN
            LEAVE course_loop;
        END IF;

      
        SELECT 
            v_id AS Course_ID,
            v_name AS Course_Name,
            v_duration AS Duration;

    END LOOP;


    CLOSE course_cursor;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE `courses` (
  `course_id` int(11) NOT NULL,
  `course_name` varchar(50) DEFAULT NULL,
  `course_duration` varchar(60) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`course_id`, `course_name`, `course_duration`) VALUES
(1, 'python', '9 months'),
(3, 'full stack', '24 months'),
(4, 'soft skill', '2 months'),
(5, 'ai', '10 months');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
  ADD PRIMARY KEY (`course_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
