# Write your MySQL query statement below

select Person.Email as 'Email' from Person group by Email having count(Email) > 1 ;