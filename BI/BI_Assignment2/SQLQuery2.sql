CREATE TABLE StudentData (
    ID INT,
    Name VARCHAR(50),
    Marks INT
);
INSERT INTO StudentData VALUES
(1, 'A', 80),
(2, 'B', 70),
(3, 'C', 90);
SELECT Name, Marks*1.1 AS UpdatedMarks
FROM StudentData;
SELECT * FROM StudentData;

