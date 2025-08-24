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
-- Database: `company`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `calculate_total_sales` ()   BEGIN
    DECLARE v_total_sales INT;
    SELECT SUM(order_amount) INTO v_total_sales
    FROM orders;
    SELECT CONCAT('Total Sales = ', v_total_sales) AS message;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `CheckDepartment` (IN `p_emp_id` INT)   BEGIN
    DECLARE dep INT;

    SELECT depid INTO dep FROM employees WHERE emp_id = p_emp_id;

    IF dep = 2 THEN
        SELECT 'Employee belongs to Coding department' AS message;
    ELSE
        SELECT 'Employee is in a different department' AS message;
    END IF;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `GetEmployeesByDepartment` (IN `deptName` VARCHAR(50))   BEGIN
    SELECT e.emp_id, e.emp_name, e.salary, d.dep_name
    FROM employees e
    JOIN departments d ON e.depid = d.dep_id
    WHERE d.dep_name = deptName;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowEmployeeDetails` ()   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE v_emp_id INT;
    DECLARE v_emp_name VARCHAR(100);
    DECLARE v_depid INT;
    DECLARE v_salary INT;

 
    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name, depid, salary FROM employees;

    
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

  
    OPEN emp_cursor;

    emp_loop: LOOP
        FETCH emp_cursor INTO v_emp_id, v_emp_name, v_depid, v_salary;

        IF done THEN
            LEAVE emp_loop;
        END IF;


        SELECT 
            v_emp_id AS ID,
            v_emp_name AS Name,
            v_depid AS Department_ID,
            v_salary AS Salary;

    END LOOP;

 
    CLOSE emp_cursor;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowEmployeeNames` ()   BEGIN
DECLARE done INT DEFAULT FALSE;
DECLARE empName VARCHAR(100);
DECLARE emp_cursor CURSOR FOR
SELECT emp_name FROM employees;
DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
OPEN emp_cursor;
emp_loop: LOOP
FETCH emp_cursor INTO empName;
IF done THEN
LEAVE emp_loop;
END IF;
SELECT empName AS Employee_Name;
END LOOP;
CLOSE emp_cursor;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `total_employees` ()   BEGIN
    DECLARE v_total INT;

    SELECT COUNT(*) INTO v_total FROM employees;

    SELECT CONCAT('Total Number of Employees: ', v_total) AS message;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `departments`
--

CREATE TABLE `departments` (
  `dep_id` int(11) NOT NULL,
  `dep_name` varchar(60) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `departments`
--

INSERT INTO `departments` (`dep_id`, `dep_name`) VALUES
(1, 'HR'),
(2, 'Coding'),
(3, 'Testing');

-- --------------------------------------------------------

--
-- Table structure for table `employees`
--

CREATE TABLE `employees` (
  `emp_id` int(11) NOT NULL,
  `emp_name` varchar(60) DEFAULT NULL,
  `depid` int(11) DEFAULT NULL,
  `salary` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `employees`
--

INSERT INTO `employees` (`emp_id`, `emp_name`, `depid`, `salary`) VALUES
(101, 'ved', 2, 20000),
(102, 'manshi', 1, 60000),
(103, 'Mukesh', 3, 55000),
(104, 'rushi', 2, 70000),
(105, 'dev', 3, 15000),
(106, 'jayesh', 3, 20000),
(107, 'lukhesh', 2, 30000);

--
-- Triggers `employees`
--
DELIMITER $$
CREATE TRIGGER `emp_log` AFTER INSERT ON `employees` FOR EACH ROW BEGIN
    INSERT INTO employee_log (emp_id, emp_name, depid, salary, action)
    VALUES (NEW.emp_id, NEW.emp_name, NEW.depid, NEW.salary, 'INSERT');
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `emp_log_UPD` BEFORE UPDATE ON `employees` FOR EACH ROW BEGIN
    INSERT INTO employee_log (emp_id, emp_name, depid, salary, action)
    VALUES (NEW.emp_id, NEW.emp_name, NEW.depid, NEW.salary, 'UPDATE');
   
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `employee_log`
--

CREATE TABLE `employee_log` (
  `log_id` int(11) NOT NULL,
  `emp_id` int(11) DEFAULT NULL,
  `emp_name` varchar(60) DEFAULT NULL,
  `depid` int(11) DEFAULT NULL,
  `salary` int(11) DEFAULT NULL,
  `action` varchar(20) DEFAULT NULL,
  `log_time` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `employee_log`
--

INSERT INTO `employee_log` (`log_id`, `emp_id`, `emp_name`, `depid`, `salary`, `action`, `log_time`) VALUES
(1, 0, 'jayesh', 3, 20000, 'INSERT', '2025-08-11 07:43:10'),
(2, 106, 'jayesh', 3, 20000, 'INSERT', '2025-08-11 07:43:46'),
(3, 103, 'Mukesh', 3, 55000, 'UPDATE', '2025-08-11 08:18:24'),
(4, 107, 'lukhesh', 2, 30000, 'INSERT', '2025-08-11 08:32:22');

-- --------------------------------------------------------

--
-- Stand-in structure for view `emp_view_dep`
-- (See below for the actual view)
--
CREATE TABLE `emp_view_dep` (
`emp_id` int(11)
,`emp_name` varchar(60)
,`salary` int(11)
,`dep_name` varchar(60)
);

-- --------------------------------------------------------

--
-- Stand-in structure for view `newsalarys`
-- (See below for the actual view)
--
CREATE TABLE `newsalarys` (
`emp_name` varchar(60)
,`salary` int(11)
);

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `order_id` int(11) NOT NULL,
  `customer_name` varchar(50) NOT NULL,
  `order_date` varchar(60) NOT NULL,
  `order_amount` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`order_id`, `customer_name`, `order_date`, `order_amount`) VALUES
(1, 'Amit Sharma', '2025-08-01', 1500),
(2, 'Riya Patel', '2025-08-02', 2300),
(3, 'John Smith', '2025-08-03', 800),
(4, 'Ananya Gupta', '2025-08-04', 1200),
(5, 'David Johnson', '2025-08-05', 3000);

-- --------------------------------------------------------

--
-- Structure for view `emp_view_dep`
--
DROP TABLE IF EXISTS `emp_view_dep`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `emp_view_dep`  AS SELECT `employees`.`emp_id` AS `emp_id`, `employees`.`emp_name` AS `emp_name`, `employees`.`salary` AS `salary`, `departments`.`dep_name` AS `dep_name` FROM (`employees` join `departments` on(`employees`.`depid` = `departments`.`dep_id`)) ;

-- --------------------------------------------------------

--
-- Structure for view `newsalarys`
--
DROP TABLE IF EXISTS `newsalarys`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `newsalarys`  AS SELECT `employees`.`emp_name` AS `emp_name`, `employees`.`salary` AS `salary` FROM `employees` WHERE `employees`.`salary` > 50000 ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `departments`
--
ALTER TABLE `departments`
  ADD PRIMARY KEY (`dep_id`);

--
-- Indexes for table `employees`
--
ALTER TABLE `employees`
  ADD PRIMARY KEY (`emp_id`),
  ADD KEY `depid` (`depid`);

--
-- Indexes for table `employee_log`
--
ALTER TABLE `employee_log`
  ADD PRIMARY KEY (`log_id`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`order_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `employee_log`
--
ALTER TABLE `employee_log`
  MODIFY `log_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `orders`
--
ALTER TABLE `orders`
  MODIFY `order_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `employees`
--
ALTER TABLE `employees`
  ADD CONSTRAINT `employees_ibfk_1` FOREIGN KEY (`depid`) REFERENCES `departments` (`dep_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
