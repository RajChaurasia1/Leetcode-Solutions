# Write your MySQL query statement below

SELECT A.Name AS 'EMPLOYEE' FROM EMPLOYEE AS A JOIN EMPLOYEE AS B ON A.ManagerId = B.Id and A.Salary > B.SALARY;  