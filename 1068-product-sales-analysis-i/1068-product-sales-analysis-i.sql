# Write your MySQL query statement below
Select product_name,year,price from Sales 
INNER JOIN Product ON 
Sales.product_id = Product.product_id;