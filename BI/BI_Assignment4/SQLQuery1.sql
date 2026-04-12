USE BI_Practical;

SELECT 
    S.Name,
    Sub.SubjectName,
    F.Marks
FROM FactMarks F
JOIN DimStudent S ON F.StudentID = S.StudentID
JOIN DimSubject Sub ON F.SubjectID = Sub.SubjectID;