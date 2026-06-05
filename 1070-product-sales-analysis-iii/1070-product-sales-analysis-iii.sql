# Write your MySQL query statement below
Select product_id, year as first_year, quantity, price from Sales WHERE (PRODUCT_ID, YEAR) in(
    select product_id, min(year)
 FROM SALES GROUP BY product_id
)
