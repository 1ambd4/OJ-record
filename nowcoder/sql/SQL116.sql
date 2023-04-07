delete from exam_record
where
    submit_time is null
    or timestampdiff(minute, start_time, submit_time) < 5
order by start_time asc
limit 3;
!-- delete from 居然也能接 limit
