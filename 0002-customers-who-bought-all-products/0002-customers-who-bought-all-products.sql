# Write your MySQL query statement below
select c.customer_id 
from customer c 
right join product p 
on c.product_key=p.product_key
group by customer_id
having count(distinct c.product_key)=(select count(*) from product);