SELECT 
    S.Name,
    Sub.SubjectName,
    SUM(F.Marks) AS TotalMarks
FROM FactMarks F
JOIN DimStudent S ON F.StudentID = S.StudentID
JOIN DimSubject Sub ON F.SubjectID = Sub.SubjectID
GROUP BY S.Name, Sub.SubjectName;