delete from exam_record
where
    !-- 时间计算函数
    timestampdiff(minute, start_time, submit_time) < 5
    and score < 60;
