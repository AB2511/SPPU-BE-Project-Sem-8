USE BI_Practical;

-- Dimension Table 1
CREATE TABLE DimStudent (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    City VARCHAR(50)
);

-- Dimension Table 2
CREATE TABLE DimSubject (
    SubjectID INT PRIMARY KEY,
    SubjectName VARCHAR(50)
);

-- Fact Table
CREATE TABLE FactMarks (
    StudentID INT,
    SubjectID INT,
    Marks INT
);