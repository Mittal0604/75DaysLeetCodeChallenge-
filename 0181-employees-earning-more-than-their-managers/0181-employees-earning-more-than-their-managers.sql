# Write your MySQL query statement below
SELECT e.name as Employee from Employee e Join Employee m 
ON e.managerId = m.id
WHERE e.salary > m.salary;