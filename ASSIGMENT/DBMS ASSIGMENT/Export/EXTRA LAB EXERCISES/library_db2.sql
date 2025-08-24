-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 24, 2025 at 09:08 AM
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
-- Database: `library_db`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `CheckBookPrice` (IN `p_book_id` INT)   BEGIN
    DECLARE v_price INT;
    DECLARE v_title VARCHAR(100);

    SELECT price, title INTO v_price, v_title
    FROM books
    WHERE book_id = p_book_id;
    
    IF v_price > 100 THEN
        SELECT CONCAT('Book "', v_title, '" (ID: ', p_book_id, ') has price above 100. Price = ', v_price) AS Message;
    ELSE
        SELECT CONCAT('Book "', v_title, '" (ID: ', p_book_id, ') has price 100 or less. Price = ', v_price) AS Message;
    END IF;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `GetBookPrice` (IN `p_book_id` INT)   BEGIN
    SELECT price
    FROM books
    WHERE book_id = p_book_id;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `GetBooksByAuthor` (IN `p_author_id` INT)   BEGIN
    SELECT b.book_id, b.title, b.publisher, b.year_of_publication, b.price, b.genre
    FROM books b
    INNER JOIN authors a ON b.author_id = a.author_id
    WHERE a.author_id = p_author_id;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_books_by_author` (IN `p_author_id` INT)   BEGIN

    DECLARE v_book_id INT;
    DECLARE v_title VARCHAR(100);
    DECLARE v_price DECIMAL(10,2);
    DECLARE v_year INT;
    DECLARE done INT DEFAULT 0;

   
    DECLARE cur CURSOR FOR
        SELECT book_id, title, price, year_of_publication
        FROM books
        WHERE author_id = p_author_id;

  
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur;

    read_loop: LOOP
        FETCH cur INTO v_book_id, v_title, v_price, v_year;
        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

       
        SELECT CONCAT('Book ID: ', v_book_id,
                      ', Title: ', v_title,
                      ', Price: ', v_price,
                      ', Year: ', v_year) AS Book_Details;
    END LOOP;

    CLOSE cur;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowBookDetails` ()   BEGIN
    DECLARE v_book_id INT DEFAULT 101;  
    DECLARE v_price   INT DEFAULT 250;  

 
    SELECT CONCAT('Book ID: ', v_book_id) AS Message1,
           CONCAT('Price: ', v_price) AS Message2;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowBooks` ()   BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_book_id INT;
    DECLARE v_title VARCHAR(100);
    DECLARE v_author_id INT;
    DECLARE v_price DECIMAL(10,2);
    DECLARE v_year INT;

  
    DECLARE book_cursor CURSOR FOR 
        SELECT book_id, title, author_id, price, year_of_publication FROM books;

   
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN book_cursor;

    book_loop: LOOP
        FETCH book_cursor INTO v_book_id, v_title, v_author_id, v_price, v_year;
        IF done = 1 THEN
            LEAVE book_loop;
        END IF;

       
        SELECT CONCAT('Book ID: ', v_book_id,
                      ', Title: ', v_title,
                      ', Author ID: ', v_author_id,
                      ', Price: ', v_price,
                      ', Year: ', v_year) AS Book_Details;
    END LOOP;

    CLOSE book_cursor;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `show_members` ()   BEGIN
    
    DECLARE v_member_id INT;
    DECLARE v_first_name VARCHAR(50);
    DECLARE v_last_name VARCHAR(50);
    DECLARE v_email VARCHAR(100);
    DECLARE v_join_date DATE;


    DECLARE done INT DEFAULT 0;

 
    DECLARE cur CURSOR FOR
        SELECT member_id, first_name, last_name, email, join_date FROM members;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur;

    read_loop: LOOP
        FETCH cur INTO v_member_id, v_first_name, v_last_name, v_email, v_join_date;
        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SELECT CONCAT('Member ID: ', v_member_id,
                      ', Name: ', v_first_name, ' ', v_last_name,
                      ', Email: ', v_email,
                      ', Join Date: ', v_join_date) AS Member_Details;
    END LOOP;

    CLOSE cur;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `authors`
--

CREATE TABLE `authors` (
  `author_id` int(11) NOT NULL,
  `first_name` varchar(50) NOT NULL,
  `last_name` varchar(50) NOT NULL,
  `country` varchar(50) NOT NULL,
  `book_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `authors`
--

INSERT INTO `authors` (`author_id`, `first_name`, `last_name`, `country`, `book_id`) VALUES
(1, 'ramdev', 'patanjali baba', 'india', NULL),
(2, 'Dennis ', 'Ritchie', 'usa', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `book_id` int(11) NOT NULL,
  `title` varchar(60) NOT NULL,
  `author` varchar(60) NOT NULL,
  `publisher` varchar(60) NOT NULL,
  `year_of_publication` int(11) NOT NULL,
  `price` int(11) NOT NULL,
  `genre` varchar(30) DEFAULT NULL,
  `author_id` int(11) DEFAULT NULL,
  `last_modified` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`book_id`, `title`, `author`, `publisher`, `year_of_publication`, `price`, `genre`, `author_id`, `last_modified`) VALUES
(101, 'c lan', 'Dennis Ritchie', 'Dennis Ritchie', 1972, 220, 'Programming', 2, '2025-08-24 06:07:58'),
(102, 'zindgi', 'osho', 'book new', 2000, 275, 'Spiritual', NULL, '2025-08-24 06:07:58'),
(103, 'yoga', 'baba ramdev', 'patanjali', 2025, 500, 'Health', 1, '2025-08-24 06:07:58');

--
-- Triggers `books`
--
DELIMITER $$
CREATE TRIGGER `after_book_delete` AFTER DELETE ON `books` FOR EACH ROW BEGIN
    INSERT INTO log_changes (book_id, title, deleted_at)
    VALUES (OLD.book_id, OLD.title, NOW());
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `update_last_modified` BEFORE UPDATE ON `books` FOR EACH ROW BEGIN
    SET NEW.last_modified = NOW();
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Stand-in structure for view `books_view`
-- (See below for the actual view)
--
CREATE TABLE `books_view` (
`title` varchar(60)
,`author` varchar(60)
,`price` int(11)
);

-- --------------------------------------------------------

--
-- Table structure for table `log_changes`
--

CREATE TABLE `log_changes` (
  `log_id` int(11) NOT NULL,
  `book_id` int(11) DEFAULT NULL,
  `title` varchar(60) DEFAULT NULL,
  `deleted_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `log_changes`
--

INSERT INTO `log_changes` (`log_id`, `book_id`, `title`, `deleted_at`) VALUES
(1, 105, 'jokes', '2025-08-24 06:16:57');

-- --------------------------------------------------------

--
-- Table structure for table `members`
--

CREATE TABLE `members` (
  `member_id` int(11) NOT NULL,
  `member_name` varchar(60) NOT NULL,
  `date_of_membership` date NOT NULL,
  `email` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `members`
--

INSERT INTO `members` (`member_id`, `member_name`, `date_of_membership`, `email`) VALUES
(1001, 'ved jani', '2022-01-01', 'vedjani@gmail.com'),
(1002, 'rushi jani', '2021-06-23', 'rushijani@gmail.com'),
(1004, 'abhay gajjar', '2025-08-21', 'abhay12@gmail.com'),
(1005, 'dev joshi', '2025-08-21', 'dj2311@gmail.com');

-- --------------------------------------------------------

--
-- Stand-in structure for view `members_before_2020`
-- (See below for the actual view)
--
CREATE TABLE `members_before_2020` (
`member_id` int(11)
,`member_name` varchar(60)
,`date_of_membership` date
,`email` varchar(60)
);

-- --------------------------------------------------------

--
-- Structure for view `books_view`
--
DROP TABLE IF EXISTS `books_view`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `books_view`  AS SELECT `books`.`title` AS `title`, `books`.`author` AS `author`, `books`.`price` AS `price` FROM `books` ;

-- --------------------------------------------------------

--
-- Structure for view `members_before_2020`
--
DROP TABLE IF EXISTS `members_before_2020`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `members_before_2020`  AS SELECT `members`.`member_id` AS `member_id`, `members`.`member_name` AS `member_name`, `members`.`date_of_membership` AS `date_of_membership`, `members`.`email` AS `email` FROM `members` WHERE `members`.`date_of_membership` < '2020-01-01' ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `authors`
--
ALTER TABLE `authors`
  ADD PRIMARY KEY (`author_id`),
  ADD KEY `book_fn` (`book_id`);

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`book_id`),
  ADD KEY `fork_author` (`author_id`);

--
-- Indexes for table `log_changes`
--
ALTER TABLE `log_changes`
  ADD PRIMARY KEY (`log_id`);

--
-- Indexes for table `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`member_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `authors`
--
ALTER TABLE `authors`
  MODIFY `author_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `books`
--
ALTER TABLE `books`
  MODIFY `book_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=106;

--
-- AUTO_INCREMENT for table `log_changes`
--
ALTER TABLE `log_changes`
  MODIFY `log_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `members`
--
ALTER TABLE `members`
  MODIFY `member_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1006;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `authors`
--
ALTER TABLE `authors`
  ADD CONSTRAINT `book_fn` FOREIGN KEY (`book_id`) REFERENCES `books` (`book_id`);

--
-- Constraints for table `books`
--
ALTER TABLE `books`
  ADD CONSTRAINT `fork_author` FOREIGN KEY (`author_id`) REFERENCES `authors` (`author_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
