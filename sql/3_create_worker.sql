CREATE TABLE `openscheduler_main`.`worker` (
                          `id` int NOT NULL AUTO_INCREMENT COMMENT 'Entry ID, utility data',
                          `login_id` int NOT NULL COMMENT 'Login entry ID, FK',
                          `name` varchar(256) NOT NULL COMMENT 'Name',
                          `surname` varchar(256) NOT NULL COMMENT 'Surname',
                          `type` int NOT NULL DEFAULT '0' COMMENT 'Worker type, internal enum value',
                          PRIMARY KEY (`id`),
                          KEY `login_id_FK` (`login_id`),
                          CONSTRAINT `login_id_FK` FOREIGN KEY (`login_id`) REFERENCES `openscheduler_main`.`login` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Table, containing worker data, linked to login entry.'

