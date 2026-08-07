# Write your MySQL query statement below
(select u.name as results
from movies m 
inner join movierating mr
on m.movie_id=mr.movie_id 
inner join users u on
u.user_id = mr.user_id
group by u.name 
order by count(u.name) desc, u.name asc
limit 1 )
union all
(select m.title
from movies m 
inner join movierating mr
on m.movie_id=mr.movie_id 
where mr.created_at between '2020-02-01' and '2020-02-29'
group by m.title 
order by avg(mr.rating) desc, title asc
limit 1) ;


