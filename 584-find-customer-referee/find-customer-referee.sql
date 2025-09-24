# Write your MySQL query statement below
Select c.name
From Customer c
Where c.referee_id != 2 OR c.referee_id Is Null;