CREATE TABLE `logins` (
   `id` int NOT NULL AUTO_INCREMENT,
   `username` varchar(45) NOT NULL,
   `passwd_sha256` varchar(45) NOT NULL,
   PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
