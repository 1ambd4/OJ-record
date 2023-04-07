insert into exam_record_before_2021
(uid, exam_id, start_time, submit_time, score)
!-- values 是不需要写的
select uid, exam_id, start_time, submit_time, score
from exam_record
where year(submit_time) < '2021' and score is not null;

!-- 还可以如下简写
insert into exam_record_before_2021
select null, uid, exam_id, start_time, submit_time, score
from exam_record
where year(submit_time) < '2021' and score is not null;
