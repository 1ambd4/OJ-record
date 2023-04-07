update exam_record
set score = 0, submit_time = '2099-01-01 00:00:00'
where start_time < '2021-09-01 00:00:00' and score is null;
