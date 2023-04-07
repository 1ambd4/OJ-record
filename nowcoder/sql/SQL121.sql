!-- 普通索引
create index idx_duration on examination_info(duration);
!-- 唯一索引
create unique index uniq_idx_exam_id on examination_info(exam_id);
!-- 全文索引
create fulltext index full_idx_tag on examination_info(tag);

!-- 修改表的方式增加索引
alter table examination_info add index idx_duration(duration);
alter table examination_info add unique index uniq_idx_exam_id(exam_id);
alter table examination_info add fulltext index full_idx_tag(tag);
