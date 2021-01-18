ALTER TABLE `player`
ADD COLUMN `rank`  int(11) UNSIGNED NOT NULL DEFAULT 0 AFTER `gold`,
ADD COLUMN `rank_point`  int(11) UNSIGNED NOT NULL DEFAULT 0 AFTER `rank`,
ADD COLUMN `first_duel`  int(11) UNSIGNED NOT NULL DEFAULT 0 AFTER `rank_point`;

ALTER TABLE `player_deleted`
ADD COLUMN `rank`  int(11) UNSIGNED NOT NULL DEFAULT 0 AFTER `gold`,
ADD COLUMN `rank_point`  int(11) UNSIGNED NOT NULL DEFAULT 0 AFTER `rank`,
ADD COLUMN `first_duel`  int(11) UNSIGNED NOT NULL DEFAULT 0 AFTER `rank_point`;
