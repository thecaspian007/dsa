# Write your MySQL query statement below
select Customers.name as Customers
From Customers
Left Join Orders
On Orders.customerId = Customers.id
WHERE Orders.id IS NULL;