CREATE TABLE `openscheduler_main`.`record` (
   `id` INT NOT NULL AUTO_INCREMENT,
   `visitor_id` INT NOT NULL,
   `start` DATETIME NOT NULL,
   `end` DATETIME NOT NULL,
   `comment` VARCHAR(256) NULL,
   PRIMARY KEY (`id`));