# Write your MySQL query statement below
select s.student_id,student_name,sub.subject_name,count(e.subject_name) as attended_exams
from students s cross join subjects sub
left join examinations e
on s.student_id=e.student_id and e.subject_name=sub.subject_name
group by student_id,subject_name
order by student_id,subject_name;