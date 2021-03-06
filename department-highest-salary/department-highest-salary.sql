# Write your MySQL query statement below


SELECT DEPARTMENT.NAME AS Department, EMPLOYEE.NAME AS Employee, EMPLOYEE.SALARY As Salary FROM EMPLOYEE INNER JOIN DEPARTMENT ON EMPLOYEE.DEPARTMENTID = DEPARTMENT.ID WHERE EMPLOYEE.SALARY =
    (
        SELECT MAX(SALARY) FROM EMPLOYEE  
        WHERE EMPLOYEE.DEPARTMENTID = DEPARTMENT.ID 
    );

