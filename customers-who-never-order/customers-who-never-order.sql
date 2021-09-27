# Write your MySQL query statement below

select Customers.Name as 'Customers'  from Customers Left Join Orders On Customers.Id = Orders.CustomerId where Orders.CustomerId is null;