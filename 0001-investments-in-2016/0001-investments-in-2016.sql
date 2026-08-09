# Write your MySQL query statement below
select round(sum(i1.tiv_2016),2) as tiv_2016
from insurance i1
where  i1.tiv_2015 in (
    select tiv_2015 from insurance
    group by tiv_2015
    having count(*)>1
)
and 
(i1.lat,i1.lon) in (
    select lat,lon 
    from insurance
    group by lat,lon
    having count(*)=1
);