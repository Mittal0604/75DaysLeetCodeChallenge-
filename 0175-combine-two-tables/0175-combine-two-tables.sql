# Write your MySQL query statement below
Select p.firstName, p.lastName, ad.city, ad.state from Address as ad RIGHT JOIN Person as p ON ad.personId = p.personId;