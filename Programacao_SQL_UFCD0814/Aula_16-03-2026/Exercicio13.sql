CREATE UNIQUE INDEX idx_cc
ON Individual(CC);

DROP INDEX CC ON Individual;

SHOW INDEX FROM Individual;

