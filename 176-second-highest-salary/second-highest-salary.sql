# Write your MySQL query statement below
SELECT (select DISTINCT salary
FROM Employee
Order By salary DESC
LIMIT 1 OFFSET 1) AS SecondHighestSalary;