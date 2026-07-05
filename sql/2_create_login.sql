CREATE TABLE `openscheduler_main`.`login` (
    `id` int NOT NULL AUTO_INCREMENT,
    `username` varchar(256) NOT NULL,
    `passwd_sha256` varchar(256) NOT NULL,
    `role` int NOT NULL DEFAULT '0',
    PRIMARY KEY (`id`),
    UNIQUE KEY `username_UNIQUE` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
