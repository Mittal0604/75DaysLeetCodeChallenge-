# Write your MySQL query statement below
Select e.name,eu.unique_id from Employees as e LEFT JOIN EmployeeUNI as eu ON e.id = eu.id;